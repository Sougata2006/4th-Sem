% ---------------------------------------------------------
% Purpose:
% Determines the grade of a student based on marks.
%
% Technique Used:
% Facts & Rules, Conditional Checks, Cut Operator (!)
% ---------------------------------------------------------

% Rule for Grade A
grade(Marks, 'A') :-
    Marks >= 80,
    !.

% Rule for Grade B
grade(Marks, 'B') :-
    Marks >= 60,
    !.

% Rule for Grade C
grade(Marks, 'C') :-
    Marks >= 40,
    !.

% If none of the above conditions are satisfied,
% assign Grade F
grade(_, 'F').

/*---------------------------------------------------------

Consult

?- consult('C:/Users/YourName/Documents/prolog/grade.pl').

----------------------------------------------------------

Query

?- grade(85, X).

----------------------------------------------------------

Output

X = 'A'.

----------------------------------------------------------

Another Query

?- grade(72, X).

----------------------------------------------------------

Output

X = 'B'.

----------------------------------------------------------

Another Query

?- grade(50, X).

----------------------------------------------------------

Output

X = 'C'.

----------------------------------------------------------

Another Query

?- grade(30, X).

----------------------------------------------------------

Output

X = 'F'.

----------------------------------------------------------

How it Works

1. The program checks the marks from top to bottom.
2. If Marks >= 80, it returns Grade 'A'.
3. Otherwise, if Marks >= 60, it returns Grade 'B'.
4. Otherwise, if Marks >= 40, it returns Grade 'C'.
5. If none of the above conditions are true, it returns
   Grade 'F'.
6. The Cut Operator (!) stops Prolog from checking the
   remaining rules once a matching grade is found.

---------------------------------------------------------*/