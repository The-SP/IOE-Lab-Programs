# PREMISES:
# 1. All pompeians are romans.
# 2. All Romans were either loyal to Caesar or hated him.
# 3. Everyone is loyal to someone.
# 4. People only try to assassinate rulers they are not loyal to.
# 5. Marcus tried to assassinate Caesar.
# 6. Marcus was Pompeian

# QUERY:
# Did Marcus hate Caesar?

PREDICATES
pompeian ( symbol )
nondeterm roman ( symbol )
nondeterm loyal ( symbol , symbol ) nondeterm hate ( symbol , symbol )
nondeterm assassinate ( symbol , symbol ) nondeterm not_loyal ( symbol , symbol )

CLAUSES
roman (X):- pompeian (X) .
assassinate ( marcus , caesar ) . pompeian ( marcus ) .
hate (X, caesar ): − roman (X) , not_loyal (X, caesar ) .
loyal (X, caesar ): − roman (X) , not ( hate (X, caesar ) ) . not_loyal (X, Y): −
assasinate (X, Y) .

GOAL
hate ( marcus , caesar ) .