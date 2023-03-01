# PREMISES:
# Dave and Fred are members of a dancing club in which no member can both waltz and jive.
# Fred's dad can"t waltz and Dave can do whatever Fred cant do. If a child can do something, then their parents can do it also

# Prove that there is a member of the dancing club who can't jive


PREDICATES
nondeterm can_do (STRING, STRING)
nondeterm member (STRING,STRING)
nondeterm parent (STRING, STRING)
nondeterm cant_do (STRING, STRING)

CLAUSES
member("dave” , ”dancingclub") .
member("fred” , ”dancingclub") .
cant_do ("freddad” , ”waltz") .
cant_do (X, Y):-
parent ( Z , X) , cant_do ( Z , Y) .
cant_do (X, ”waltz"):-
member(X, ”dancingclub") , can_do (X, ”jive") .
cant_do (X, ”jive"):-
member(X, ”dancingclub") , can_do (X, ”waltz") .
can_do ("dave” ,X):-
cant_do ("fred” , X) .
parent (" freddad ” , ”fred") .

GOAL
member(X, ”dancingclub") , cant_do (X, ”jive") .