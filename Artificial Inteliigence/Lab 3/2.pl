# PREMISES:
# 1. All people who are not poor and are smart are happy.
# 2. Those people who read are not stupid.
# 3. John can read and is wealthy.
# 4. Happy people have exciting lives.

# QUERY:
# Can anyone be found with an exciting life?

PREDICATES
not_poor (STRING) smart (STRING) happy (STRING)
not_stupid (STRING)
read (STRING)
wealthy (STRING)
exciting _ life (STRING)

CLAUSES
exciting _ life (X):-
happy (X) .
happy (X):-
not_poor (X) , smart (X) .
smart (X):-
not_stupid (X) .
not_stupid (X):-
read (X) .
not_poor (X):-
wealthy (X) .
read ("John") .
wealthy (" John") .

GOAL
exciting _ life ("John")