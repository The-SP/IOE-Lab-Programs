# HCF of two numbers

hcf(X,Y,Z):- X=0, Z=Y.
hcf(X,Y,Z):- Y=0, Z=X.
hcf(X,Y,Z):- X<Y, hcf(Y,X,Z).
hcf(X,Y,Z):- X>Y, R is X mod Y, hcf(Y,R,Z).

?- hcf(8, 34, X).