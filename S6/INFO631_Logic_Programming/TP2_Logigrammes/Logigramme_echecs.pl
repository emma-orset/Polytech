/* Gare à garry */
/* Vainqueur, perdant, pièce, durée */

solution :- tournoi(Matchs), 
    
    %Indice 1 :
    membre(match(Vr,_,reine,D1), Matchs), 
    membre(Vr,[dominique, francois, marc]),
    membre(match(marc,_,_,D2), Matchs), 
    D2 is D1 - 15,
    membre(match(_,roger,_,D3), Matchs),
    D3 is D1 + 15,
    
    %Indice 2 :
    membre(match(Vtour,_,tour,D4), Matchs),
    membre(match(Vt,therese,_,D5), Matchs),
    membre(Vt,[dominique, annick, sylviane]),
    Vtour\=Vt,
    D5 is D4 - 15,

    %Indice 3 :
    membre(match(sylviane,P1,_,D6), Matchs), 
    membre(D6, [30, 45, 60, 75]),
    membre(P1, [alain, pascale, roger, therese]),

    %Indice 4 :
    membre(match(annick,_,Pi1,D7), Matchs),
    membre(Pi1, [fou, pion, reine, tour]),
    membre(match(_,alain,_,D8), Matchs),
    D8 is D7 - 15,

    %Indice 5 :
    membre(match(_,Pp,pion,75), Matchs), 
    membre(Pp,[therese, pascale, jacqueline]),

    membre(match(dominique,_,_,_), Matchs),
    membre(match(francois,_,_,_), Matchs),
    membre(match(_,jacqueline,_,_), Matchs),
    membre(match(_,pascale,_,_), Matchs),
    membre(match(_,_,cavalier,_), Matchs),
    membre(match(_,_,fou,_), Matchs),
    
    print_matchs(Matchs).

tournoi([match(_,_,_,15),
           match(_,_,_,30),
           match(_,_,_,45),
           match(_,_,_,60),
           match(_,_,_,75)]).

/*
max(M, [M]).
max(M, [T|[U|Q]]) :- max(M, [U|Q]), T =< U.
max(M, [T|[U|Q]]) :- max(M, [T|Q]), U < T.

min(M, [M]).
min(M, [T|[U|Q]]) :- max(M, [T|Q]), T =< U.
min(M, [T|[U|Q]]) :- max(M, [U|Q]), U < T.

%appartient(X, [X]).
appartient(X, [_|X]).
appartient(X, [X|_]).
appartient(X, [_|Q]) :- appartient(X, Q).
*/

different_de(X, Y) :- X\=Y.

membre(X, [X|_]).
membre(X, [_|Y]) :- membre(X, Y).

print_matchs([]).
print_matchs([A | L]) :- print(A), print_matchs(L).



