is_member(X,[X|_]):- !.

is_member(X,[_| Rest]) :- is_member(X,Rest).