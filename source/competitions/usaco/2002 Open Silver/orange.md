                          ORANGE PROBLEMS
                 Four problems numbered 6 through 9

# PROBLEM 6: Wiggle Numbers [Top Coder/Piele, 2002]

These positive integers:  3748, 67, 869, 32435465768 are all wiggle numbers
because if you examine the digits of each number they go up, down, up,
down, ...  or  down, up, down, up, down, up, ... For example:

3 &lt; 7 &gt; 4 &lt; 8  and  3 &gt; 2 &lt; 4 &gt; 3 &lt; 5 &gt; 4 &lt; 6 &gt; 5 &lt; 7 &gt; 6 &lt; 8  

A single digit is a wiggle number of length 1.

Write a program that will determine how many of the initial digits of a
number form a wiggle number.  The answer could, of course, be the length
of the number in some cases.

PROBLEM NAME: wiggle

## INPUT FORMAT:

A single line with a single positive integer no longer than 75 digits.

### SAMPLE INPUT (file wiggle.in):

```text
3748
```

## OUTPUT FORMAT:

A single integer that is the number of initial digits of the number that
form a wiggle number.

### SAMPLE OUTPUT (file wiggle.out):

```text
4
```

**********************************************************************

# PROBLEM 7: Life Cycle [Piele, 2002]

The cows are calculating the "life cycle" for each of their identification
tag numbers.

Take any positive integer N (1 &lt;= N &lt;= 9999), say 57, square the digits
and add them up:  5^2 + 7^2 to get 25 + 49 = 74. Now do the same procedure
with the result 74 to get the next number in the sequence 65. Continuing
to apply this procedure to a sequence of terms eventually repeats one
number of the sequence.

When starting with 57, the sequence repeats for the first time with 37:

      57, 74, 65, 61, 

and from then on the sequence is trapped in a "life cycle":

      37, 58, 89, 145, 42, 20, 4, 16, 37, . . .

If we cube the digits instead of squaring them the sequence has a similar
fate. Your job is to write a program that computes how long the sequence
lasts until it falls into a life cycle given a starting positive integer
and a power P (1 &lt;= P &lt;= 5).

PROBLEM NAME: life2

## INPUT FORMAT:

A single line with two space-separated integers: N and P.

### SAMPLE INPUT (file life2.in):

```text
57 2
```

## OUTPUT FORMAT:

Length of the sequence until it enters a life cycle, not including the
first number in the cycle.

### SAMPLE OUTPUT (file life2.out):

```text
4
```

[This corresponds to the sequence: 57, 74, 65, 61, 37, ...; 37 is the first
number that is repeated.]

**********************************************************************

# PROBLEM 8: Superwords [Dan Adkins, 2002]

The cows are playing dictionary games again; there's not much else to do
while chewing one's cud.  The new game is a simple one but they need to
verify their answers.

Given a list of N (1 &lt;= N &lt;= 100) words, what is the smallest "superword"
that contains all of them, in order, as subwords?  Consider an example
using three words: 'big', 'green', and 'engine'.  To make a "superword"
(which, regrettably, rarely appears in the dictionary), one combines them
carefully to yield: 'bigreengine'.

Words appear sequentially in a superword when the first letter of a
constituent word appears strictly later in the superword than the first
letter of the previous word and the last letter of that word appears
strictly later in the superword than the last letter of the previous word.
Here are some two word examples:
       sin in    -&gt; sinin
       sin sine  -&gt; sinsine
       sin int   -&gt; sint

Your task is to find superwords.

PROBLEM NAME: suword

## INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1:  Each line contains a single word that contains only lower
	  case letters ('a'..'z').  No word is longer than 75 characters.

### SAMPLE INPUT (file suword.in):

```text
3
big
green
engine
```

## OUTPUT FORMAT:

A single line that contains the "superword".

### SAMPLE OUTPUT (file suword.out):

```text
bigreengine
```

**********************************************************************

# PROBLEM 9: Cow Brainiacs [Hubert Chen, 2002]

One afternoon as the cows were chewing their cud, Bessie said, "Let's have
a contest to see who is the smartest cow.  Here's the contest:  we will
choose a positive number N (no larger than 2,000,000) and whoever computes
the rightmost non-zero digit of N factorial will be crowned the smartest
cow."

The other cows demurred, however, mooing, "We did that last year."

"Oh," said Bessie, "but there's a catch.  We're not necessarily going to
use base 10.  I know my hooves don't have that many digits!  We'll just
specify a positive number base B from 2 through 29."

Write a program to help the cows judge their intelligence contest.

PROBLEM NAME: brain

## INPUT FORMAT:

A single line with integers N and B

### SAMPLE INPUT (file brain.in):

```text
13 3
```

## OUTPUT FORMAT:

A single line with the decimal-representation of the "digit" that is the
rightmost non-zero digit for N! in base B.  If B &gt; 10, go ahead and output
a two-digit decimal number as a representation of the final "digit".

### SAMPLE OUTPUT (file brain.out):

```text
2
```

[13*12*11*10*9*8*7*6*5*4*3*2*1=6227020800 base 10, which in base 3 is
121001222020102200000, so the right-most non-zero digit is 2.]
