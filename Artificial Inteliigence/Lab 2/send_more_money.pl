# Crypto arithmetic problem
# SEND + MORE = MONEY

DOMAINS
int_list=integer*

PREDICATES
solution(int_list)
member(integer,int_list)

CLAUSES
solution([]).
solution([S,E,N,D,M,O,R,Y]):-
    # c4 must be 1 otherwise no need to mention M.
    C4=1,
    # C1, C2, C3 will have values 0 or 1
    member(C1,[0,1]),
    member(C2,[0,1]),
    member(C3,[0,1]),

    # S,E,N, D, M, O, R, Y will have values between 0 and 9.
    member(E,[0,1,2,3,4,5,6,7,8,9]),
    member(N,[0,1,2,3,4,5,6,7,8,9]),
    member(D,[0,1,2,3,4,5,6,7,8,9]),
    member(M,[0,1,2,3,4,5,6,7,8,9]),
    member(O,[0,1,2,3,4,5,6,7,8,9]),
    member(R,[0,1,2,3,4,5,6,7,8,9]),
    member(Y,[0,1,2,3,4,5,6,7,8,9]),
    member(S,[0,1,2,3,4,5,6,7,8,9]),

    # The values of S,E,N, D, M, O, R, Y must not be equal.
    S<>E, S<>N, S<>D, S<>M, S<>O, S<>R, S<>Y,
    E<>N, E<>D, E<>M, E<>O, E<>R, E<>Y,
    N<>D, N<>M, N<>O, N<>R, N<>Y,
    D<>M, D<>O, D<>R, D<>Y, 
    M<>O, M<>R, M<>Y, 
    O<>R, O<>Y,
    R<>Y,

    # Computation for solution
    D+E=Y+10*C1,
    N+R+C1=E+10*C2,
    E+O+C2=N+10*C3,
    S+M+C3=O+10*C4,
    M=C4.

member(X, [X|_]).
member(X, [_|Z]):-
member(X,Z).

GOAL
solution([S,E,N,D,M,O,R,Y]).


# Solution
# S=9, E=5, N=6, D=7, M=1, O=0, R=8, Y=2