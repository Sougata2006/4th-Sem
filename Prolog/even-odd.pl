% ---------------------------------------------------------
% Purpose:
% Checks whether a given number is Even or Odd.
%
% Technique Used:
% Facts & Rules, Arithmetic Evaluation
% ---------------------------------------------------------

% Rule to check if a number is even
even(X) :-
    0 is X mod 2.

% Rule to check if a number is odd
odd(X) :-
    1 is X mod 2.

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/even_odd.pl').

----------------------------------------------------------

Query

?- even(8).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- odd(15).

----------------------------------------------------------

Output

true.

----------------------------------------------------------

Another Query

?- even(15).

----------------------------------------------------------

Output

false.

----------------------------------------------------------

How it Works

1. The even/1 predicate checks whether the remainder of
   X divided by 2 is 0 using the mod operator.
2. If the remainder is 0, Prolog returns true.
3. The odd/1 predicate checks whether the remainder of
   X divided by 2 is 1.
4. If the remainder is 1, Prolog returns true;
   otherwise, it returns false.

---------------------------------------------------------*/