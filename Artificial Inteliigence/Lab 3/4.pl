# PREMISES:
# Bhogendra likes all kinds of food. Oranges are food. Chicken is food. Anything anyone eats and
# isn’t killed by is food. If a person likes a food means that person has eaten it. Jogendra eats
# peanuts and is still alive. Shailendra eats everything Bhogendra eats.

# QUERY:
# Does Shailendra like chicken?

PREDICATES
nondeterm likes (STRING, STRING) nondeterm food (STRING)
nondeterm eats(STRING, STRING) nondeterm kils(STRING, STRING)

CLAUSES
food ("orange") .
food ("chicken ") .
food (X):- likes (Y, X) ,
not (kills (X, Y) ) .
eats ("sailenda” ,Y):- eats("bhogendra ” , Y) .
eats (X, Y):- likes (X, Y) , food (Y) .
likes ("bhogendra ” ,X):-
food (X) . kills (_, _) .

GOAL
likes ("sailenda” , "chicken ")