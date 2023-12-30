%homme(X) signifie que X est un homme
homme(françoisI).
homme(henriII).
homme(françoisII).
homme(charlesIX).
homme(henriIII).
homme(emmanuel_Philiber).
homme(charles_Emmanuel).
homme(victor_Amédée).

%femme(X) signifie que X est une femme
femme(madelaine).
femme(marguerite).
femme(cathérine_de_Médicis).
femme(margot).
femme(elisabeth).

%parent(X,Y) signifie que X est parent de Y
parent(françoisI,madelaine).
parent(françoisI,henriII).
parent(françoisI,marguerite).

parent(henriII,françoisII).
parent(henriII, charlesIX).
parent(henriII, henriIII).
parent(henriII, margot).

parent(cathérine_de_Médicis,françoisII).
parent(cathérine_de_Médicis,charlesIX).
parent(cathérine_de_Médicis,henriIII).
parent(cathérine_de_Médicis,margot).

parent(charlesIX,elisabeth).

parent(marguerite,charles_Emmanuel).
parent(emmanuel_Philiber,charles_Emmanuel).
parent(charles_Emmanuel,victor_Amédée).

%pere(X,Y) signifie que X est le père de Y
pere(X,Y) :- parent(X,Y),homme(X).

%mere(X,Y) signifie que X est la mère de Y
mere(X,Y) :- parent(X,Y),femme(X).

%fille(X,Y) signifie que X est la fille de Y
fille(X,Y) :- parent(Y,X),femme(X).

%fils(X,Y) signifie que X est le fils de Y
fils(X,Y) :- parent(Y,X),homme(X).

%procreer(X,Y) signifie que X (homme) a copulé avec Y (femme) et ont fait des enfants
procreer(X,Y) :- parent(X,Z),parent(Y,Z),homme(X),femme(Y).

%gdparent(X,Y) signifie que X est grand parent de Y
gdparent(X,Y) :- parent(X,Z),parent(Z,Y).

%gdpere(X,Y) signifie que X est le grand père de Y
gdpere(X,Y) :- gdparent(X,Y),homme(X).

%gdmere(X,Y) signifie que X est la grand mère de Y
gdmere(X,Y) :- gdparent(X,Y),femme(X).

%ancetre(X,Y) signifie que X est l'ancètre de Y
ancetre(X,Y) :- parent(X,Y).
ancetre(X,Y) :- parent(Z,Y),ancetre(X,Z).

%frere_demi_frere(X,Y) signifie que X est le frère ou demi-frère de Y
frere_demi_frere(X,Y) :- parent(Z,X),parent(Z,Y),homme(X),X\=Y.

%frere(X,Y) signifie que X est le frère (mais pas demi-frère) de Y
frere(X,Y) :- pere(Z,X),pere(Z,Y),mere(V,X),mere(V,Y),homme(X),X\=Y.

%soeur_demi_soeur(X,Y) signifie que X est la soeur ou demi-soeur de Y
soeur_demi_soeur(X,Y) :- parent(Z,X),parent(Z,Y),femme(X),X\=Y.

%soeur(X,Y) signifie que X est la soeur (mais pas demi-soeur) de Y
soeur(X,Y) :- pere(Z,X),pere(Z,Y),mere(V,X),mere(V,Y),femme(X),X\=Y.

%oncle(X,Y) signifie que X est l'oncle de Y
oncle(X,Y) :- parent(Z,Y),frere(X,Z).

%tante(X,Y) signifie que X est la tante de Y
tante(X,Y) :- parent(Z,Y),soeur(X,Z).

