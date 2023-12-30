/* Du cachet */
/* Societe, cachet, effectif, creation */

solution :- entreprises(Societes), 
    
    %Indice 1 :
    membre(societe(sopy, Ts, 4, _), Societes),
    membre(societe(aguigo, Tag, _, _), Societes),
    membre(societe(acfin, Tac, _, _), Societes),
    membre(Ts, [4, 5]),
    membre(Tag, [2, 3]),
    membre(Tac, [5, 6]),
    Ts is Tag + 2,
    Tac is Ts + 1,
    
    %Indice 2 :
    membre(societe(himvest, Th, _, Dh), Societes),
    membre(societe(_, _, 5, D5), Societes),
    membre(societe(_, 2, _, D2), Societes),
    membre(Th, [4, 5, 6]),
    membre(Dh, [2000, 2005]),
    membre(D5, [2005, 2010]),
    membre(D2, [1990, 1995, 2000]),
    D5 is Dh + 5,
    D2 is Dh - 10,
    
    %Indice 3 :
    membre(societe(colshop, _, Mc, _), Societes),
    membre(Mc, [4, 5, 6]),
    
    %Indice 4 :
    membre(societe(_, 6, M6, 1990), Societes),
	membre(M6, [4, 5, 6, 7]),
    
    %Autres :
    membre(societe(_, 3, _, _), Societes),
    membre(societe(_, 4, _, _), Societes),
    membre(societe(_, 5, _, _), Societes),
    membre(societe(_, _, 3, _), Societes),
    membre(societe(_, _, 6, _), Societes),
    membre(societe(_, _, 7, _), Societes),
    membre(societe(_, _, _, 1995), Societes),
    membre(societe(_, _, _, 2000), Societes),
    membre(societe(_, _, _, 2005), Societes),
    membre(societe(_, _, _, 2010), Societes),

	print_societes(Societes).

entreprises([societe(acfin,_,_,_),
           societe(aguigo,_,_,_),
           societe(colshop,_,_,_),
           societe(himvest,_,_,_),
           societe(sopy,_,_,_)]).

different_de(X, Y) :- X\=Y.

membre(X, [X|_]).
membre(X, [_|Y]) :- membre(X, Y).

print_societes([]).
print_societes([A | L]) :- print(A), print_societes(L).