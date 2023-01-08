#  Display only 1s and 2s in a list. 
# ( If the input is [1,2,4,5,2,4,5,1,1] the solution list should be [1,2,2,1,1]. )

modify_list([], []).
modify_list([1|Tail], [1|Result]) :-
    modify_list(Tail, Result).
modify_list([2|Tail], [2|Result]) :-
    modify_list(Tail, Result).
modify_list([_|Tail], Result) :-
    modify_list(Tail, Result).

?- modify_list([1,2,4,5,2,4,5,1,1], Result).
# Result = [1, 2, 2, 1, 1]