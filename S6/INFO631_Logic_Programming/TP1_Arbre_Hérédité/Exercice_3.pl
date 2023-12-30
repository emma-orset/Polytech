concat([],L,L).
concat([X|Y],L,[X|R]) :- concat(Y,L,R).

traduit([0],[zero]).
traduit([1],[un]).
traduit([2],[deux]).
traduit([3],[trois]).
traduit([4],[quatre]).
traduit([5],[cinq]).
traduit([6],[six]).
traduit([7],[sept]).
traduit([8],[huit]).
traduit([9],[neuf]).

traduit([E|L],LT) :- traduit(L,T1), traduit([E],T2), concat(T2,T1,LT).

plus_symb(M1,M2,R) :- traduit([X],M1),traduit([Y],M2), R is X+Y.
%?-plus_symb([quatre],[deux],X).

fois_symb(M1,M2,R) :- traduit([X],M1),traduit([Y],M2), R is X*Y.

plus_symb_bis(M1,M2,R) :- traduit([X],M1),traduit([Y],M2), R is X+Y, X=<Y.