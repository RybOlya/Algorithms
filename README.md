# Algorithms
# A chain of words
## Problem code: WCHAIN
 - Two participants play a linguistic game. At the beginning of the game, a list of N words is given.
The first player chooses an arbitrary word w1 and crosses out one arbitrary letter from it
so to get another word w2 from this list. After that, the turn goes to
another player, and he tries to do the same with the word w2.
 - The game ends in one of two cases:
• One letter word remains.
• It is not possible to cross out any letter to get another word from the dictionary.

### Determine the length of the maximum chain that can be achieved in this game at given words
## Input data
The input file wchain .in consists of N + 1 lines.
• The first line contains N — the number of words in the dictionary, 1 ≤ N ≤ 105
.

• Each of the following N lines contains a word from 1 to 50 characters long, which
consists of small Latin letters from a to z.
## Output data
The output file wchain .out must contain one number — the length of the maximum
chain