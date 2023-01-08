# Find length of the list

DOMAINS 
int_list=integer* 

PREDICATES 
length(int_list,integer) 

CLAUSES 
length([],0). 
length([H|T],L):- 
 length(T,L1), 
 L=L1+1. 
 
GOAL 
length([1,2,5,3,4,6,7],X).