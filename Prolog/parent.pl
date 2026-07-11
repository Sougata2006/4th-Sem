parent(john,mary).
parent(mary,sam).
male(john).
female(mary).

father(X,Y):-male(X),parent(X,Y).
mother(X,Y):-female(X),parent(X,Y).
