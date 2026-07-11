parent(john, mary).
parent(john, sam).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
