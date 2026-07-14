% ---------------------------------------------------------
% Purpose:
% Checks whether a given element is present in a list.
%
% Technique Used:
% Recursion, List Processing, Pattern Matching,
% Cut Operator (!)
% ---------------------------------------------------------

% Base Case:
% If the first element of the list matches X,
% then X is a member of the list.
is_member(X, [X|_]) :-
    !.

% Recursive Case:
% Ignore the first element and search in the
% remaining list.
is_member(X, [_|Rest]) :-
    is_member(X, Rest).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/member.pl').

----------------------------------------------------------

Query

?- is_member(3, [1,2,3,4,5]).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- is_member(10, [1,2,3,4,5]).

----------------------------------------------------------

Output

false.

----------------------------------------------------------

Another Query

?- is_member(a, [b,c,d,a]).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

How it Works

1. The program compares X with the first element of
   the list.
2. If they are equal, it returns true and the Cut
   Operator (!) stops further searching.
3. Otherwise, the first element is ignored.
4. The program recursively searches the remaining
   elements of the list.
5. If X is found, Prolog returns true.
6. If the list becomes empty without finding X,
   Prolog returns false.

---------------------------------------------------------*/