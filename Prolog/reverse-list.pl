conc([], L, L).

conc([H|T], L, [H|R]) :-
    conc(T, L, R).

my_reverse([], []).

my_reverse([H|T], R) :-
    my_reverse(T, R1),
    conc(R1, [H], R).