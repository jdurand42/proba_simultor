# proba_simultor
Simple toy to simulate n chances on n2 and stop when it got a succefull draw
It's kind of useless, i just did it as a pratical toy to illustrate borel theorems.

compilator:
clang++ no flags

Parameters:
[N chances] [on n] [optional: n successfull draws] [optional: successfull_draws need to be consecutive]

expemple:
./proba 1 2 -> simulate 1 chance over 2;

./proba 1 2 10 -> simulate 1 chance over 2 and stop when it got 10 successfull_draws;

./proba 1 2 10 on -> same as precedent but shows input

./proba 1 2 10 off yes -> simulate 1 chance over 2 and stop when it got 10 consecutive successfull_draws with output off

