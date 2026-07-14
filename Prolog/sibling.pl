% ---------------------------------------------------------
% Purpose:
% Determines whether two persons are siblings by
% checking if they have the same parent.
%
% Technique Used:
% Facts & Rules
% ---------------------------------------------------------

% Parent Facts
parent(john, mary).
parent(john, sam).

% Rule to find Siblings
sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/sibling.pl').

----------------------------------------------------------

Query

?- sibling(mary, sam).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- sibling(X, sam).

----------------------------------------------------------

Output

X = mary.

----------------------------------------------------------

Another Query

?- sibling(mary, X).

----------------------------------------------------------

Output

X = sam.

----------------------------------------------------------

Another Query

?- sibling(mary, mary).

----------------------------------------------------------

Output

false.

----------------------------------------------------------

How it Works

1. The parent/2 facts define the parent-child
   relationships.
2. The sibling/2 rule checks whether X and Y have
   the same parent Z.
3. The condition X \= Y ensures that a person
   cannot be their own sibling.
4. If both persons share the same parent and are
   different individuals, Prolog returns true.

---------------------------------------------------------*/