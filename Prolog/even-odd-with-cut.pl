% ---------------------------------------------------------
% Purpose:
% Checks whether a given number is Even or Odd.
%
% Technique Used:
% Facts & Rules, Arithmetic, Cut Operator (!)
% ---------------------------------------------------------

% Rule to check if a number is even
even_odd(X, even) :-
    0 is X mod 2,
    !.

% If the first rule fails, the number is odd
even_odd(_, odd).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/even_odd.pl').

----------------------------------------------------------

Query

?- even_odd(8, X).

----------------------------------------------------------

Output

X = even.

----------------------------------------------------------

Another Query

?- even_odd(15, X).

----------------------------------------------------------

Output

X = odd.

----------------------------------------------------------

How it Works

1. The predicate checks whether the remainder of X divided
   by 2 is 0 using the mod operator.
2. If the condition is true, X is even.
3. The Cut Operator (!) stops Prolog from checking any
   further rules once the number is identified as even.
4. If the first rule fails, Prolog automatically executes
   the second rule and returns odd.

---------------------------------------------------------*/