% ---------------------------------------------------------
% Purpose:
% Determines the action to be taken based on the
% traffic light color.
%
% Technique Used:
% Facts & Rules, Pattern Matching, Cut Operator (!)
% ---------------------------------------------------------

% Rule for Red Signal
action(red, stop) :-
    !.

% Rule for Yellow Signal
action(yellow, wait) :-
    !.

% Rule for Green Signal
action(green, go).

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/traffic.pl').

----------------------------------------------------------

Query

?- action(red, X).

----------------------------------------------------------

Output

X = stop.

----------------------------------------------------------

Another Query

?- action(yellow, X).

----------------------------------------------------------

Output

X = wait.

----------------------------------------------------------

Another Query

?- action(green, X).

----------------------------------------------------------

Output

X = go.

----------------------------------------------------------

How it Works

1. The program checks the traffic light color.
2. If the color is red, it returns stop.
3. The Cut Operator (!) prevents Prolog from checking
   the remaining rules once a match is found.
4. If the color is yellow, it returns wait.
5. If the color is green, it returns go.

---------------------------------------------------------*/