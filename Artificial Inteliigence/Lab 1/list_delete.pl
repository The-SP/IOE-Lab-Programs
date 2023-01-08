# Delete a given element from the list.

delete(_, [], []).
delete(X, [X|Tail], NewTail) :- delete(X, Tail, NewTail).
delete(X, [Y|Tail], [Y|NewTail]) :- X \= Y, delete(X, Tail, NewTail).

?- delete(2, [1,2,3,4], X).