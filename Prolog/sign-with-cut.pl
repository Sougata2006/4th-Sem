% ---------------------------------------------------------
% Purpose:
% Determines whether a given number is Positive,
% Negative, or Zero.
%
% Technique Used:
% Facts & Rules, Conditional Checks, Cut Operator (!)
% ---------------------------------------------------------

% Rule to check if the number is Positive
sign(X, positive) :-
    X > 0,
    !.

% Rule to check if the number is Negative
sign(X, negative) :-
    X < 0,
    !.

% Rule to check if the number is Zero
sign(0, zero).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/sign.pl').

----------------------------------------------------------

Query

?- sign(15, X).

----------------------------------------------------------

Output

X = positive.

----------------------------------------------------------

Another Query

?- sign(-8, X).

----------------------------------------------------------

Output

X = negative.

----------------------------------------------------------

Another Query

?- sign(0, X).

----------------------------------------------------------

Output

X = zero.

----------------------------------------------------------

How it Works

1. The program first checks whether the number is
   greater than 0.
2. If true, it returns positive and the Cut Operator
   (!) prevents Prolog from checking the remaining rules.
3. If the first condition fails, it checks whether
   the number is less than 0.
4. If true, it returns negative.
5. If neither condition is satisfied, the number
   must be 0, so the last rule returns zero.

---------------------------------------------------------*/