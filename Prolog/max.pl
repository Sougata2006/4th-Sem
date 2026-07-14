% ---------------------------------------------------------
% Purpose:
% Finds the maximum of two numbers.
%
% Technique Used:
% Facts & Rules, Conditional Check
% ---------------------------------------------------------

% Rule:
% If X is greater than or equal to Y,
% then X is the maximum.
max(X, Y, X) :-
    X >= Y.

% Rule:
% If Y is greater than X,
% then Y is the maximum.
max(X, Y, Y) :-
    Y > X.

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/max.pl').

----------------------------------------------------------

Query

?- max(10, 20, X).

----------------------------------------------------------

Output

X = 20.

----------------------------------------------------------

Another Query

?- max(50, 30, X).

----------------------------------------------------------

Output

X = 50.

----------------------------------------------------------

Another Query

?- max(25, 25, X).

----------------------------------------------------------

Output

X = 25.

----------------------------------------------------------

How it Works

1. The program first checks whether X is greater than
   or equal to Y.
2. If the condition is true, X is returned as the
   maximum.
3. Otherwise, it checks whether Y is greater than X.
4. If true, Y is returned as the maximum.
5. Since the conditions are mutually exclusive, a
   Cut Operator (!) is not required.

---------------------------------------------------------*/