% Evaluation module 
%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Partitions                                                                                %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
partition(contenu, [passable, suffisant, bon], [(0, 40), (30, 70), (60, 100)]).
partition(enseignement, [passable, suffisant, bon], [(0, 40), (30, 70), (60, 100)]).
partition(organisation, [passable, suffisant, bon], [(0, 40), (30, 70), (60, 100)]).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Règles                                                                                    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
regle(contenu_enseignement, passable, passable, tres_mauvais).
regle(contenu_enseignement, passable, suffisant, mauvais).
regle(contenu_enseignement, passable, bon, moyen).
regle(contenu_enseignement, suffisant, passable, mauvais).
regle(contenu_enseignement, suffisant, suffisant, moyen).
regle(contenu_enseignement, suffisant, bon, bien).
regle(contenu_enseignement, bon, passable, moyen).
regle(contenu_enseignement, bon, suffisant, bien).
regle(contenu_enseignement, bon, bon, tres_bien).

regle(module, tres_mauvais, passable, irrecuperable).
regle(module, mauvais, passable, nul).
regle(module, tres_mauvais, suffisant, nul).
regle(module, moyen, passable, ameliorable).
regle(module, mauvais, suffisant, ameliorable).
regle(module, tres_mauvais, bon, ameliorable).
regle(module, bien, passable, neutre).
regle(module, moyen, suffisant, neutre).
regle(module, mauvais, bon, neutre).
regle(module, tres_bien, passable, bien).
regle(module, bien, suffisant, bien).
regle(module, moyen, bon, bien).
regle(module, tres_bien, suffisant, tres_bien).
regle(module, bien, bon, tres_bien).
regle(module, tres_bien, bon, excellent).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Calculs                                                                                  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Structure                                                                                %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
systeme(contenu_enseignement, Contenu, Enseignement, DL1) :- description(contenu, Contenu, DLx),
                                 							 description(enseignement, Enseignement, DLy),
                                 							 inference(contenu_enseignement, DLx, DLy, DL1).

systeme(module, ResCE, Organisation, DLs) :- description(organisation, Organisation, DL2),
                    	         			 inference(module, ResCE, DL2, DLs).

systeme(avis_final, Contenu, Enseignement, Organisation, DLs) :- systeme(contenu_enseignement, Contenu, Enseignement, DLr),
    															 systeme(module, DLr, Organisation, DLs).







