%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Description des éléments du système                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

partition(x, [court, long], [(0, 60), (40, 100)]).
partition(y, [etroit, large], [(0, 60), (40, 100)]).
partition(z, [bas, haut], [(0, 60), (40, 100)]).
partition(s, [tres_petit, petit, grand, tres_grand], [(0, 25), (25, 50), (50, 75), (75, 100)]).

regle(xyr, court, etroit, petit).
regle(xyr, court, large, moyen).
regle(xyr, long, etroit, moyen).
regle(xyr, long, large, grand).

% A complèter
regle(rzs, petit, bas, tres_petit).
regle(rzs, petit, haut, petit).
regle(rzs, moyen, bas, petit).
regle(rzs, moyen, haut, grand).
regle(rzs, grand, bas, grand).
regle(rzs, grand, haut, tres_grand).




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Calcul                                                            %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

entre(X, Min, Max) :- X >= Min, X < Max.

appart(Val, Domaine) :- Domaine = (Min, Max), entre(Val, Min, Max).                                    
                                  
appartenance(Val, Symb, [Symb|_], [Domaine|_]) :- appart(Val, Domaine). 
appartenance(Val, Symb, [_|QSymb], [_|QDom]) :- appartenance(Val, Symb, QSymb, QDom).   

descrip(NomVar, ValNum, Symb) :- partition(NomVar, LS, LDomaine),
                                 appartenance(ValNum, Symb, LS, LDomaine).
description(NomVar, ValNum, LS) :- setof(Symb, descrip(NomVar, ValNum, Symb), LS).

infer1(NomRel, [Symb1|_], Symb2, SymbS) :- regle(NomRel, Symb1, Symb2, SymbS).
infer1(NomRel, [_|QS1], Symb2, SymbS) :- infer1(NomRel, QS1, Symb2, SymbS).

infer2(NomRel, LS1, [Symb2|_], SymbS) :- infer1(NomRel, LS1, Symb2, SymbS).
infer2(NomRel, LS1, [_|QS2], SymbS) :- infer2(NomRel, LS1, QS2, SymbS).

inference(NomRel, DS1, DS2, DescS) :- setof(SymbS, infer2(NomRel, DS1, DS2, SymbS), DescS).

%conversion_numerique(Var, DLs, ValNum) :- partition(Var, [DLs,_,_,_], [ValNum,_,_,_]);
%    partition(Var, [_,DLs,_,_], [_,ValNum,_,_]);
%    partition(Var, [_,_,DLs,_], [_,_,ValNum,_]);
%    partition(Var, [_,_,_,DLs], [_,_,_,ValNum]).

convNumAux(_, DLs, ValNum, [DLs|_], [ValNum|_]).
convNumAux(NomVar, DLs, ValNum, [_|T1], [_|T2]) :- convNumAux(NomVar, DLs, ValNum, T1, T2).

conversion_numerique(NomVar, DLs, ValNum) :- partition(NomVar, [DLs|_], [ValNum|_]);
    										 partition(NomVar, [_|T1], [_|T2]),
    									     convNumAux(NomVar, DLs, ValNum, T1, T2).
    										

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Structure du système                                              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

systeme(xyr, Numx, Numy, DLr) :- description(x, Numx, DLx),
                                 description(y, Numy, DLy),
                                 inference(xyr, DLx, DLy, DLr).

systeme(rzs, Valr, Numz, DLs) :- description(z, Numz, DLz),
                    	         inference(rzs, Valr, DLz, DLs).

systeme(xyzs, Numx, Numy, Numz, DLs) :- systeme(xyr, Numx, Numy, DLr),
    									systeme(rzs, DLr, Numz, DLs).

systemeNum(xyzs, Numx, Numy, Numz, Valeur) :- systeme(xyr, Numx, Numy, DLr),
    										  systeme(rzs, DLr, Numz, DLs),
										  	  conversion_numerique(s, DDLs, Valeur),
											  DLs = [DDLs].





