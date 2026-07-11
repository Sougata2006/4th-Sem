length_list([], 0).

length_list([_|T], N) :-
    length_list(T, N1),
    N is N1 + 1.