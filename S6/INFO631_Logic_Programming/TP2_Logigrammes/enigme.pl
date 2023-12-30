solution :-  village(Maisons),
	     membre(maison(rouge, anglais, _, _, _), Maisons),
	     membre(maison(_, espagnol, cultivateur, _, _), Maisons),
	     membre(maison(verte, _, _, cafe, _), Maisons),

% codage indice 5 - A faire

	     droite_de(maison(verte,_,_,_,_), maison(blanche,_,_,_,_), Maisons),
	     membre(maison(_, _, prof_russe, _, bernard), Maisons),
	     Maisons = [_, _, maison(_, _, _, lait, _), _,_],
	     membre(maison(jaune, _, _, _, paul), Maisons),
	     Maisons = [maison(_, francais, _, _, _)|_],
	     voisin_de(maison(_,_,_,_,jacques), maison(_,_,dentiste,_,_), Maisons),
	     voisin_de(maison(_,_,_,_,paul), maison(_,_,boucher,_,_), Maisons),
	     membre(maison(_, _, _, cidre, henri), Maisons),
             membre(maison(_, italien, _, _, andre), Maisons),

% Codage indice 15 - A faire
	     
	     membre(maison(_, _, fleuriste, _, _), Maisons),
	     membre(maison(_, _, _, eau, _), Maisons),
	     print_maisons(Maisons).

village( [ maison(_, _, _, _, _),
	   maison(_, _, _, _, _),
	   maison(_, _, _, _, _),
	   maison(_, _, _, _, _),
	   maison(_, _, _, _, _) ]).

droite_de(A, B, [B, A | _]).
droite_de(A, B, [_ | Y]) :- droite_de(A, B, Y).

%   définition du prédicat voisin_de   -  A faire

membre(X, [X|_]).
membre(X, [_|Y]) :- membre(X, Y).

%   définition du prédicat print_maisons   -  A faire


