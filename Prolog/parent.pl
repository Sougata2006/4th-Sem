% ---------------------------------------------------------
% Purpose:
% Determines whether a person is the father or mother
% of another person using parent and gender facts.
%
% Technique Used:
% Facts & Rules
% ---------------------------------------------------------

% Parent Facts
parent(john, mary).
parent(mary, sam).

% Gender Facts
male(john).
female(mary).

% Rule to find Father
father(X, Y) :-
    male(X),
    parent(X, Y).

% Rule to find Mother
mother(X, Y) :-
    female(X),
    parent(X, Y).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/family.pl').

----------------------------------------------------------

Query

?- father(john, mary).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- mother(mary, sam).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- father(X, mary).

----------------------------------------------------------

Output

X = john.

----------------------------------------------------------

Another Query

?- mother(X, sam).

----------------------------------------------------------

Output

X = mary.

----------------------------------------------------------

How it Works

1. The parent/2 facts define the parent-child
   relationships.
2. The male/1 and female/1 facts define the gender
   of each person.
3. The father/2 rule checks whether a person is male
   and is also the parent of the given child.
4. The mother/2 rule checks whether a person is female
   and is also the parent of the given child.
5. If both conditions are satisfied, Prolog returns
   true or the matching person.

---------------------------------------------------------*/