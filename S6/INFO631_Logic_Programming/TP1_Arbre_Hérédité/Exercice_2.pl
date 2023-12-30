appartient(E,[E|_]).
appartient(E,[_|L]) :- appartient(E,L).

doubler([],[]).
doubler([E|L],[E|[E|LD]]) :- doubler(L,LD).

const_liste(0,_,[]).
const_liste(N,E,[E|L]) :- M is N-1,const_liste(M,E,L).

concat([],L,L).
concat([X|Y],L,[X|R]) :- concat(Y,L,R).

developper(_,[],[]).
developper(N,[E|L],LD) :- const_liste(N,E,L1),developper(N,L,L2), concat(L1,L2,LD).



