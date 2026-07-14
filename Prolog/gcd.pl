% ---------------------------------------------------------
% Purpose:
% Finds the Greatest Common Divisor (GCD) of two numbers
% using Euclid's Algorithm.
%
% Technique Used:
% Recursion, Arithmetic Evaluation
% ---------------------------------------------------------

% Base Case:
% If the second number is 0, the first number is the GCD.
gcd(X, 0, X).

% Recursive Case
gcd(X, Y, G) :-
    Y > 0,
    R is X mod Y,
    gcd(Y, R, G).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/gcd.pl').

----------------------------------------------------------

Query

?- gcd(24, 18, X).

----------------------------------------------------------

Output

X = 6.

----------------------------------------------------------

Another Query

?- gcd(100, 25, X).

----------------------------------------------------------

Output

X = 25.

----------------------------------------------------------

How it Works

1. If the second number (Y) becomes 0, the first number
   (X) is the GCD (Base Case).
2. Otherwise, calculate the remainder of X divided by Y.
3. Call gcd(Y, R, G) recursively.
4. Repeat the process until the remainder becomes 0.
5. The last non-zero divisor is returned as the GCD.

---------------------------------------------------------*/