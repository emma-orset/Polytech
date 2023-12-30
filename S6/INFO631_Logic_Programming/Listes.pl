longueur(0, []).
longueur(N, [_|Q]) :- longueur(M, Q), N is M + 1.

sommeliste(S, [S]).
sommeliste(S, [M|Q]) :- sommeliste(SQ, Q), S is SQ + M.

moyliste(M, L) :- sommeliste(X, L), longueur(Y, L), M is X/Y.

max(X, X, X).
max(X, Y, Z) :- X =< Y, Z is Y.
max(X, Y, Z) :- Y < X, Z is X.

maxliste(M, [M]).
maxliste(M, [T|[U|Q]]) :- maxliste(M, [U|Q]), T =< U.
maxliste(M, [T|[U|Q]]) :- maxliste(M, [T|Q]), U < T.

inserer(E, [A|B], [E|[A|B]]).
inserer(E, [], [E]).
inserer(E, [A|B], [A|C]) :- inserer(E, B, C).

permuter([L], [L]).


