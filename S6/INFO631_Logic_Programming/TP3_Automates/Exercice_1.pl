%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%                             Automate                                         
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


etat(e1).

etat(e2).

etat(e3).

etat(e4).



initial(e1).

final(e1).



transition(e1, a, e1).

transition(e1, b, e2).

transition(e2, a, e1).

transition(e2, b, e3).

transition(e3, a, e2).

transition(e3, b, e3).

transition(e3, c, e4).

transition(e4, a, e5).

transition(e4, b, e3).

transition(e5, a, e5).


reconnu(Mot) :- initial(EI), 
		
                parcours(Mot,EI,EF), 
		
                final(EF).



% ECRIRE parcours
parcours([], EF, EF).
parcours([E|X], EI, EF) :- transition(EI, E, EC), parcours(X, EC, EF).






reconnu_ch(Mot,CH) :- initial(EI), 
		      
                      parcours_ch(Mot,EI,EF,CH), 
		      
                      final(EF).



% ECRIRE parcours_ch
parcours_ch([], EF, EF, [EF]).
parcours_ch([E|X], EI, EF, [EI|RESTE]):-transition(EI,E,EC),parcours_ch(X, EC, EF, RESTE).






chemin(ED, EA) :- existe_parcours(ED, EA, []).



% ECRIRE existe_parcours
appartient(X, [X|_]).
appartient(X, [_|Y]) :- appartient(X, Y).

existe_parcours(EA, EA, _).
existe_parcours(ED, EA, LInterdits):- transition(ED, _, EC),
    								not(appartient(EC, LInterdits)),
    								existe_parcours(EC, EA, [EC|LInterdits]).
    								



% ECRIRE est_accessible
liste_etat(X) :- X = [e1, e2, e3, e4, e5].
est_accessible(E) :- liste_etat(X), setof(L, chemin(L, E), LX), X = LX.


% ECRIRE permet_acces
permet_acces(E):-liste_etat(X), setof(L, chemin(E,L), LX), X = LX.
