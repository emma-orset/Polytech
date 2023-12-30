/* Sévigné */
/* Jour, destinataire, durée, feuilles */

solution :- courriers(Courriers), 
    
    %Indice 1 :
    membre(courrier(Jp, parrain, _, _), Courriers),
    membre(courrier(J5, _, _, 5), Courriers),
    membre(courrier(J90, _, 90, _), Courriers),
    membre(Jp, [2, 3, 4]),
    membre(J5, [1, 2, 3]),
    membre(J90, [3, 4, 5]),
    J5 is Jp - 1,
    J90 is Jp + 1,
    
    %Indice 2 :
    membre(courrier(2, _, _, Fma), Courriers),
    membre(courrier(_, frere, _, Ff), Courriers),
    membre(courrier(_, _, 75, F75), Courriers),
    membre(Fma, [2, 3, 4]),
    membre(Ff, [1, 2, 3]),
    membre(F75, [3, 4, 5]),
    Ff is Fma - 1,
    F75 is Fma + 1,
    
    %Indice 3 :
    membre(courrier(_, _, D2, 2), Courriers),
    membre(D2, [60, 75, 90, 105]),
    
    %Indice 4 :
    membre(courrier(1, D1, _, F1), Courriers),
    membre(F1, [1, 2, 4, 5]),
    membre(D1, [ami, frere, mere, parrain]),
    
    %Indice 5 :
    membre(courrier(_, De1f, Du1f, 1), Courriers),
    membre(courrier(_, ami, Da, _), Courriers),
    membre(courrier(3, _, Dm, _), Courriers),
    membre(De1f, [cousine, frere, parrain]),
    membre(Du1f, [60, 75, 90]),
    membre(Da, [45, 60, 75]),
    membre(Dm, [75, 90, 105]),
    Da is Du1f - 15,
    Dm is Du1f + 15,
    
    %Autres :
    membre(courrier(_, cousine, _, _), Courriers),
    membre(courrier(_, mere, _, _), Courriers),
    membre(courrier(_, _, 45, _), Courriers),
    membre(courrier(_, _, 60, _), Courriers),
    membre(courrier(_, _, 105, _), Courriers),
    membre(courrier(_, _, _, 3), Courriers),
    membre(courrier(_, _, _, 4), Courriers),
    
	print_courriers(Courriers).

courriers([courrier(1,_,_,_),
           courrier(2,_,_,_),
           courrier(3,_,_,_),
           courrier(4,_,_,_),
           courrier(5,_,_,_)]).

membre(X, [X|_]).
membre(X, [_|Y]) :- membre(X, Y).

print_courriers([]).
print_courriers([A | L]) :- print(A), print_courriers(L).