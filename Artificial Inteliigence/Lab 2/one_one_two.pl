% Crypto arithmetic problem
% ONE + ONE = TWO

DOMAINS
int_list=integer*

PREDICATES
solution(int_list)
member(integer,int_list)

CLAUSES
solution([]).
solution([O,N,E,T,W]):-
    % C1, C2 will have values 0 or 1
    member(C1,[0,1]),
    member(C2,[0,1]),

    % O must be even as it is result of 2E.
    % O can't be 0 as O+O+Carry=T
    % O can't be 6,8 as O+O will give carry in 3rd column.
    member(O,[2,4]),

    % N,E,T,W will have values between 0 and 9.
    member(N,[0,1,2,3,4,5,6,7,8,9]),
    member(E,[0,1,2,3,4,5,6,7,8,9]),
    member(T,[0,1,2,3,4,5,6,7,8,9]),
    member(W,[0,1,2,3,4,5,6,7,8,9]),

    % The values of O,N,E,T,W must not be equal.
    O<>N, O<>E, O<>T, O<>W,
    N<>E, N<>T, N<>W,
    E<>T, E<>W,
    T<>W,
    

    % Computation for Solution
    2*E=10*C1+O,
    C1+2*N=10*C2+W,
    C2+2*O=T.

member(X, [X|_]).
member(X, [_|Z]):-
    member(X,Z).

GOAL
solution([O,N,E,T,W]).


% 16 Solution
% O=2, N=3, E=1, T=4, W=6
% O=4, N=3, E=2, T=8, W=6
% O=2, N=7, E=1, T=5, W=4
% O=2, N=8, E=1, T=5, W=6
% O=2, N=9, E=1, T=5, W=8
% O=4, N=5, E=2, T=9, W=0
% O=4, N=8, E=2, T=9, W=6
% O=2, N=0, E=6, T=4, W=1
% O=2, N=1, E=6, T=4, W=3
% O=2, N=3, E=6, T=4, W=7
% O=4, N=0, E=7, T=8, W=1
% O=4, N=1, E=7, T=8, W=3
% O=4, N=2, E=7, T=8, W=5
% O=2, N=8, E=6, T=5, W=7
% O=4, N=5, E=7, T=9, W=1
% O=4, N=6, E=7, T=9, W=3