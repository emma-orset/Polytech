automate(aut1,
         [e1,e2,e3],
         [e1],
         [[e1,a,e1],
         [e1,b,e2],
         [e2,a,e1],
         [e2,b,e3],
         [e3,a,e2],
           [e3,b,e3]],
         [e1]).

automate(aut2,
         [e1,e2,e3,e4,e5],
         [e1,e4],
         [[e1,a,e1],
         [e1,b,e2],
         [e2,a,e1],
         [e2,b,e3],
         [e3,a,e2],
           [e3,b,e3],
           [e3,c,e4],
           [e4,a,e5],
           [e4,b,e3],
           [e5,a,e5]],
         [e1,e2]).


appartient(X, [X|_]).
appartient(X, [_|Y]) :- appartient(X, Y).

initial(LI, EI) :- automate(_, _, LI, _, _), appartient(EI, LI).

etat(LE, E) :- automate(_, LE, _, _, _), appartient(E, LE).

transition(LT, T) :- automate(_, _, _, LT, _), appartient(T, LT).

final(LF, EF) :- automate(_, _, _, _, LF), appartient(EF, LF).

reconnu(Aut, Mot) :- automate(Aut, _, LI, _, LF),
    				initial(LI, EI), 
		
                	parcours(Aut, Mot,EI,EF), 
		
                	final(LF, EF).

parcours(_, [], EF, EF).
parcours(Aut, [E|X], EI, EF) :- automate(Aut, _, _, LT, _), appartient([EI, E, EC], LT) , parcours(Aut, X, EC, EF).



reconnu_ch(Aut, Mot,CH) :- automate(Aut, _, LI, _, LF),
    				initial(LI, EI), 
		
                	parcours_ch(Aut, Mot,EI,EF, CH), 
		
                	final(LF, EF).


parcours_ch(_, [], EF, EF, [EF]).
parcours_ch(Aut, [E|X], EI, EF, [EI|RESTE]):- automate(Aut, _, _, LT, _),
    										appartient([EI,E,EC], LT), parcours_ch(Aut, X, EC, EF, RESTE).



chemin(Aut, ED, EA) :- existe_parcours(Aut, ED, EA, []).


existe_parcours(_, EA, EA, _).
existe_parcours(Aut, ED, EA, LInterdits):- automate(Aut, _, _, LT, _),
    								appartient([ED, _, EC], LT),
    								not(appartient(EC, LInterdits)),
    								existe_parcours(Aut, EC, EA, [EC|LInterdits]).





est_accessible(Aut, E) :- automate(Aut,X,_,_,_), setof(L, chemin(Aut, L, E), LX), X = LX.



permet_acces(Aut, E):-automate(Aut,X,_,_,_), setof(L, chemin(Aut, E,L), LX), X = LX.












