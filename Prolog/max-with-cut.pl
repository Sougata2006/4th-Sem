% ---------------------------------------------------------
% Purpose:
% Finds the maximum of two numbers.
%
% Technique Used:
% Facts & Rules, Conditional Check, Cut Operator (!)
% ---------------------------------------------------------

% Rule:
% If X is greater than or equal to Y,
% then X is the maximum.
max(X, Y, X) :-
    X >= Y,
    !.

% Otherwise, Y is the maximum.
max(_, Y, Y).

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
3. The Cut Operator (!) prevents Prolog from checking
   the next rule once the maximum is found.
4. If the first condition fails, the second rule is
   executed and Y is returned as the maximum.

---------------------------------------------------------*/