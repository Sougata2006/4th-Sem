% ---------------------------------------------------------
% Purpose:
% Finds the grandparent relationship using parent facts.
%
% Technique Used:
% Facts & Rules
% ---------------------------------------------------------

% Parent Facts
parent(john, mary).
parent(mary, sam).

% Rule to find Grandparent
grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/grandparent.pl').

----------------------------------------------------------

Query

?- grandparent(john, sam).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- grandparent(X, sam).

----------------------------------------------------------

Output

X = john.

----------------------------------------------------------

Another Query

?- grandparent(john, X).

----------------------------------------------------------

Output

X = sam.

----------------------------------------------------------

How it Works

1. The parent/2 facts define the parent-child
   relationships.
2. The grandparent/2 rule first checks if X is the
   parent of some person Z.
3. Then it checks whether Z is the parent of Y.
4. If both conditions are true, X is the grandparent
   of Y.
5. Prolog automatically searches the facts and applies
   the rule to produce the correct result.

---------------------------------------------------------*/