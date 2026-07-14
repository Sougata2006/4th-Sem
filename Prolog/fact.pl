% ---------------------------------------------------------
% Purpose:
% Finds the factorial of a given number.
%
% Technique Used:
% Recursion, Arithmetic Evaluation
% ---------------------------------------------------------

% Base Case:
% Factorial of 0 is 1
fact(0, 1).

% Recursive Case
fact(N, F) :-
    N > 0,
    N1 is N - 1,
    fact(N1, F1),
    F is N * F1.

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/fact.pl').

----------------------------------------------------------

Query

?- fact(5, X).

----------------------------------------------------------

Output

X = 120.

----------------------------------------------------------

Another Query

?- fact(0, X).

----------------------------------------------------------

Output

X = 1.

----------------------------------------------------------

How it Works

1. If N is 0, the factorial is 1 (Base Case).
2. Otherwise, decrease N by 1.
3. Recursively calculate the factorial of (N - 1).
4. Multiply N with the factorial of (N - 1).
5. Continue until the base case is reached.
6. The final factorial value is returned in X.

---------------------------------------------------------*/