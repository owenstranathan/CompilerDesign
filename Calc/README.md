#The Greatest of all Calculators
####by Owen Stranathan
Calc is a simple calculator language compiler that take's as input math
expressions written to conform with the following concrete grammar:

expr -> expr + factor | expr - factor | factor
factor -> factor * term | factor / term | factor % term | term
term -> digit | ( expr )
digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
