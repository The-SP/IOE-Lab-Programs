# Append two list

append([], L, L).
append([Head|Tail], L, [Head|Result]) :-
    append(Tail, L, Result).

?- append([1,2], [3,4], Result).