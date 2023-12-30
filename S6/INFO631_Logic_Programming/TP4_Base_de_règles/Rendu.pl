%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Description des éléments du système                               %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% partition(x, [court, long], [(0, 50), (50, 100)]).
% partition(y, [etroit, large], [(0, 50), (50, 100)]).

%%% 1.2 %%%

partition(x, [court, long], [(0, 60), (40, 100)]).
partition(y, [etroit, large], [(0, 60), (40, 100)]).

%%% FIN 1.2 %%%

%%% 1.3 %%%

partition(z, [bas, haut], [(0, 60), (40, 100)]).

%%% 1.4 %%%

partition(s, [tres_petit,petit,grand,tres_grand],[(0,25),(25,50),(50,75),(75,100)]).

%%% FIN 1.4 %%%% 

%%% 1.2 %%%

regle(xyr, court, etroit, petit).
regle(xyr, court, large, moyen).
regle(xyr, long, etroit, moyen).
regle(xyr, long, large, grand).

%%% FIN 1.2 %%%

regle(rzs, petit, bas, tres_petit).
regle(rzs, moyen, bas, petit).
regle(rzs, grand, bas, grand).
regle(rzs, petit, haut, petit).
regle(rzs, moyen, haut, grand).
regle(rzs, grand, haut, tres_grand).

%%% FIN 1.3 %%%%



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

%%% 1.4 %%%
averageRange((ValMin,ValMax), Avg) :- Avg is (ValMax + ValMin)/2. 

parcourpara(Symb, [Symb|_], [Domaine|_], Domaine).
parcourpara(Symb, [_|Q], [_|D], Domaine) :- parcourpara(Symb, Q, D, Domaine).

getDomaine(NomVar, Symb, Domaine) :- partition(NomVar, LS, LD),
    								parcourpara(Symb, LS, LD, Domaine).

conversion_numerique(NomVar, Symb, Valnum) :- getDomaine(NomVar, Symb, Domaine),
    											averageRange(Domaine, Valnum).

%%% FIN 1.4 %%%% 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Structure du système                                              %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

systeme(xyr, Numx, Numy, DLr) :- description(x, Numx, DLx),
                                 description(y, Numy, DLy),
                                 inference(xyr, DLx, DLy, DLr).

%%% 1.3 %%%

systeme(rzs, DLr, Numz, DLs) :- description(z, Numz, DLz), 
    							inference(rzs, DLr, DLz, DLs).
systeme(xyzs, Numx, Numy, Numz, DLs) :- systeme(xyr, Numx, Numy, DLr), 
    									systeme(rzs, DLr, Numz, DLs).

%%% FIN 1.3 %%%% 




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Réponses                                                          %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% 1.1 %%%
% descrip(x,45,Z)
% Z = court

% systeme(xyr,45,70,R)
% R = [moyen]

%%% 1.2 %%%
% systeme(xyr,10,70,R)
% R = [moyen]

% systeme(xyr,45,70,R)
% R = [grand, moyen]

% systeme(xyr,45,55,R)
% R = [grand, moyen, petit]

%%% 1.3 %%%
% systeme(rzs,[petit],99,R)
% R = [petit]

% systeme(xyzs,10,40,99,R)
% R = [grand, petit]

