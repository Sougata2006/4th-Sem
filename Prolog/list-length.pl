% ---------------------------------------------------------
% Purpose:
% Finds the length (number of elements) of a list.
%
% Technique Used:
% Recursion, List Processing, Pattern Matching
% ---------------------------------------------------------

% Base Case:
% The length of an empty list is 0.
length_list([], 0).

% Recursive Case:
% Ignore the first element, find the length of the
% remaining list, then add 1.
length_list([_|T], N) :-
    length_list(T, N1),
    N is N1 + 1.

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/length_list.pl').

----------------------------------------------------------

Query

?- length_list([1,2,3,4,5], X).

----------------------------------------------------------

Output

X = 5.

----------------------------------------------------------

Another Query

?- length_list([a,b,c], X).

----------------------------------------------------------

Output

X = 3.

----------------------------------------------------------

Another Query

?- length_list([], X).

----------------------------------------------------------

Output

X = 0.

----------------------------------------------------------

How it Works

1. If the list is empty ([]), its length is 0
   (Base Case).
2. Otherwise, ignore the first element of the list.
3. Recursively find the length of the remaining list.
4. Add 1 for the ignored element.
5. Continue until the list becomes empty.
6. The final count is returned as the length of the list.

---------------------------------------------------------*/