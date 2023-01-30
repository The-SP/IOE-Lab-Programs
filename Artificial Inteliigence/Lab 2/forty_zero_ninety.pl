# Crypto arithmetic problem
# FORTY + FORTY + ZERO + ZERO = NINETY

DOMAINS
int_list=integer*

PREDICATES
solution(int_list)
member(integer,int_list)

CLAUSES
solution([]).
solution([F,O,R,T,Y,Z,E,N,I]):-
    # C5 will have values [0,1,2]
    member(C5,[0,1,2]),
    # C1, C2, C3, C4 will have values [0,1,2,3]
    member(C1,[0,1,2,3]),
    member(C2,[0,1,2,3]),
    member(C3,[0,1,2,3]),
    member(C4,[0,1,2,3]),

    # F,O,R,T,Y,Z,E,N,I will have values between 0 and 9.
    member(F,[0,1,2,3,4,5,6,7,8,9]),
    member(O,[0,1,2,3,4,5,6,7,8,9]),
    member(R,[0,1,2,3,4,5,6,7,8,9]),
    member(T,[0,1,2,3,4,5,6,7,8,9]),
    member(Y,[0,1,2,3,4,5,6,7,8,9]),
    member(Z,[0,1,2,3,4,5,6,7,8,9]),
    member(E,[0,1,2,3,4,5,6,7,8,9]),
    member(N,[0,1,2,3,4,5,6,7,8,9]),
    member(I,[0,1,2,3,4,5,6,7,8,9]),

    # The values of F,O,R,T,Y,Z,E,N,I must not be equal.
    F<>O, F<>R, F<>T, F<>Y, F<>Z, F<>E, F<>N, F<>I,
    O<>R, O<>T, O<>Y, O<>Z, O<>E, O<>N, O<>I,
    R<>T, R<>Y, R<>Z, R<>E, R<>N, R<>I,
    T<>Y, T<>Z, T<>E, T<>N, T<>I
    Y<>Z, Y<>E, Y<>N, Y<>I,
    Z<>E, Z<>N, Z<>I,
    E<>N, E<>I,
    N<>I,
    

    # Computation for Solution
    2*Y+2*O=10*C1+Y,
    C1+2*T+2*R=10*C2+T,
    C2+2*R+2*E=10*C3+E,
    C3+2*O+2*Z=10*C4+N,
    C4+2*F=10*C5+I,
    N=C5.

member(X, [X|_]).
member(X, [_|Z]):-
    member(X,Z).

GOAL
solution([F,O,R,T,Y,Z,E,N,I]).


# Solution
