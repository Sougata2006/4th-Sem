% ---------------------------------------------------------
% Purpose:
% Finds the Fibonacci number at a given position.
%
% Technique Used:
% Recursion, Arithmetic Evaluation
% ---------------------------------------------------------

% Base Case:
% Fibonacci of 0 is 0
fib(0, 0).

% Base Case:
% Fibonacci of 1 is 1
fib(1, 1).

% Recursive Case
fib(N, F) :-
    N > 1,
    N1 is N - 1,
    N2 is N - 2,
    fib(N1, F1),
    fib(N2, F2),
    F is F1 + F2.

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/fib.pl').

----------------------------------------------------------

Query

?- fib(6, X).

----------------------------------------------------------

Output

X = 8.

----------------------------------------------------------

Another Query

?- fib(8, X).

----------------------------------------------------------

Output

X = 21.

----------------------------------------------------------

How it Works

1. If N is 0, the Fibonacci number is 0 (Base Case).
2. If N is 1, the Fibonacci number is 1 (Base Case).
3. Otherwise, recursively calculate:
      Fibonacci(N-1) and Fibonacci(N-2).
4. Add both values to get Fibonacci(N).
5. Continue until the base cases are reached.
6. The final Fibonacci value is returned in X.

---------------------------------------------------------*/