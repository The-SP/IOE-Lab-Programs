# ASSIGNMENT 1:

# PREMISES:
# 1. Horses, cows, pigs are mammals.
# 2. An offspring of a horse is a horse.
# 3. Bluebeard is a horse.
# 4. Bluebeard is Charlie’s parent.
# 5. Offspring and parent are inverse relations.
# 6. Every mammal has a parent

# QUERY:
# Is Charlie a horse?

PREDICATES
horse (STRING) mammal(STRING) cow (STRING)
pig (STRING)
is_offspring (STRING, STRING) is_parent (STRING, STRING)

CLAUSES
mammal(X):-
horse (X) ,
cow (X) ,
pig (X) ,
is_parent (_, X).

horse (Y):
is_parent (X, Y), horse (X) . horse ("Bluebeard") .

is_offspring (X, Y):-
is_parent (Y, X) .

is_parent ("Bluebeard” , "Charlie") . 
cow (" ␣") .
pig (" ␣") .

GOAL
horse ("Charlie ").