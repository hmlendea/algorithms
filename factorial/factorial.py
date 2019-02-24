#!/bin/python

def factorial (n):
	if n is 0:
		return 1
	else:
		return n * factorial (n - 1)

n = int (input ("Factorial de "))
r = factorial (n)

print (str (r))

# PROLOG 1:
# factorial(0,1):-!.
# factorial(N,F):-
#    N>0,
#    N1 is N-1,
#    factorial(N1,F1),
#    F is N*F1.

# PROLOG 2:
# factorial(0,1):-!.
# factorial(N,F):-fact_aux(N,F,1,1).
#
# fact_aux(N,F,N,F):-!.
# fact_aux(N,F,I,P):-
#     I1 is I+1,
#     P1 is P*I1,
#     fact_aux(N,F,I1,P1).
