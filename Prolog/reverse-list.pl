% ---------------------------------------------------------
% Purpose:
% Reverses a given list using recursion and list
% concatenation.
%
% Technique Used:
% Recursion, List Processing, Pattern Matching
% ---------------------------------------------------------

% Predicate to concatenate two lists

conc([], L, L).

conc([H|T], L, [H|R]) :-
    conc(T, L, R).

% Base Case:
% Reverse of an empty list is an empty list.

my_reverse([], []).

% Recursive Case:
% Reverse the tail of the list and then append
% the head element at the end.

my_reverse([H|T], R) :-
    my_reverse(T, R1),
    conc(R1, [H], R).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/reverse.pl').

----------------------------------------------------------

Query

?- my_reverse([1,2,3,4,5], X).

----------------------------------------------------------

Output

X = [5,4,3,2,1].

----------------------------------------------------------

Another Query

?- my_reverse([a,b,c,d], X).

----------------------------------------------------------

Output

X = [d,c,b,a].

----------------------------------------------------------

Another Query

?- my_reverse([], X).

----------------------------------------------------------

Output

X = [].

----------------------------------------------------------

How it Works

1. The conc/3 predicate joins (concatenates) two lists.
2. If the list is empty ([]), its reverse is also
   an empty list (Base Case).
3. Otherwise, the head element is separated from
   the tail.
4. The tail is recursively reversed.
5. The head element is appended to the end of the
   reversed tail using conc/3.
6. The process continues until the entire list is
   reversed.

---------------------------------------------------------*/