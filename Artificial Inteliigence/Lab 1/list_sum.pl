# Add content of the integer list

DOMAINS
list=integer*

PREDICATES
sum(list, integer)

CLAUSES
sum([], 0).
sum([H|T], L):-
    sum(T, L1),
    L=L1+H.

GOAL
sum([1, 2, 3, 4, 5], X).