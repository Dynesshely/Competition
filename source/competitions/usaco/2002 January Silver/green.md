                           GREEN PROBLEMS
                  Four problems numbered 1 through 4

Problems - 2002 Winter Open, Green (Senior Division)

# PROBLEM 1: Pasture Fences [Dominic Battre, 2001]

Farmer John has a long fence made of fence poles and rails.  Each of the N (1 &lt;= N &lt;= 3000) 
fence poles carries a sign with a single number from -1000 through +1000.  Some poles might 
have the same number on their sign as other poles. While chewing their cud, the cows made up
 a game.  The cow who can find the "best fence sum" gets ice cream for dessert.

To win the game, the winning cow must find the longest contiguous set of poles whose sum has 
the smallest absolute value.  Help them determine the winning sum.

PROBLEM NAME: pasture

## INPUT FORMAT:

* Line 1: One line with a single integer: N

* Lines 2..N+1: Each line contains a pole's label.  Line 2 contains
  the value for pole with sequence number 1, etc.

### SAMPLE INPUT (file pasture.in):

```text
6
5
10
-5
-6
2
4
```

## OUTPUT FORMAT:

A single line with three numbers:
  * the sequence number of the pole that is first to be summed,
  * the sequence number of the pole that is last to be summed, and
  * the absolute value of the sum of the labels of those poles. If more than one 
sequence has the same "best fence sum" and same maximum length, report the sequence
 with the lowest first sequence number.

### SAMPLE OUTPUT (file pasture.out):

```text
4 6 0
```

# PROBLEM 2: New Years Party [Hal Burch, 2001]

A group of  N (3 &lt;= N &lt;= 200) cows is having a New Year's party.  Each cow is able 
to cook several different kinds of food (in units called a "dish"). There are a 
total of D (5 &lt;= D &lt;= 100) different kinds of food.  Each kind of food is denoted 
by an integer in the range 1..D.

The cowrdinator wants to maximize the total number of dishes brought to the party, 
but has specified a limit for the number of dishes of each type. Each cow can bring
 K (1 &lt;= K &lt;= 5) dishes, but they must be different from each other (she can't bring
 3 bovine pies, for example, but she could bring a pie, some bread, and some nice 
alfalfa in orange sauce).  What is the maximum amount of food that can be brought?

PROBLEM NAME: party

## INPUT FORMAT:

* Line 1: Three integers: N, K, and D

* Line 2: D non-negative integers: the limit on total number of each of
  the various dishes that can be brought to the party

* Lines 3..N+2: Each line contains an initial integer Z (1 &lt;= Z &lt;= D)
  denoting the number of different dishes a cow can prepare; the rest of
  the line contains Z integers that are the food identifiers, food type 1
  first, food type 2 second, etc..

### SAMPLE INPUT [FILE party.in]:

```text
4 3 5
2 2 2 2 3
4 1 2 3 4
4 2 3 4 5
3 1 2 4
3 1 2 3
```

EXPLANATION OF SAMPLE INPUT:

data......     explanation...................................................
4 3 5          4 cows, each cow brings up to 3 dishes, 5 different food types
2 2 2 2 3      max for party of 2 dishes food types 1..4; 3 dishes of food 5
4 1 2 3 4      This cow can cook 4 different foods (1, 2, 3, 4)
4 2 3 4 5      This cow can cook 4 different foods (2, 3, 4, 5)
3 1 2 4        This cow can cook 3 different foods (1, 2, 4)
3 1 2 3        This cow can cook 3 different foods (1, 2, 3)

## OUTPUT FORMAT:

A single line with a single integer that is the maximum number of dishes that can 
be brought to the party.

### SAMPLE OUTPUT [FILE party.out]:

```text
9
```

[Cow 1 brings foods 3 and 4; cow 2 brings foods 3, 4 and 5;
cow 3 brings foods 1 and 2; and cow 4 brings foods 1 and 2.]


# PROBLEM 3: Strolling Cows [Dan Adkins, 2001]

Before going to the barn for dinner, the cows like to stroll the N (1 &lt;= N &lt;= 30,000)
 pastures while watching the sun set.  Each pasture leads to precisely one pasture, though
 some pastures have more than one pasture emptying into them.  For a valid strolling experience,
 the cows can start in any pasture and must finish in that same pasture without visiting any 
other pasture twice.  Given a description of the pasture paths, deduce the longest possible 
valid stroll the cows can take.

PROBLEM NAME: stroll

## INPUT FORMAT:

* Line 1: One integer: N

* Lines 2..N+1: Line M tells the pasture number that pasture M-1 connects
  to (so line 2 tells which pasture is accessible from pasture 1, etc.)

### SAMPLE INPUT (FILE stroll.in):

```text
5
2
4
5
5
2
```

## OUTPUT FORMAT:

A single line with the integer that is the largest number of pastures that can be visited 
on a legal stroll.

### SAMPLE OUTPUT (FILE stroll.out):

```text
3
```

[by visiting pasture 2, then 4, then 5]


# PROBLEM 4: Grazing Sets [Brian Dean, 2001]

Farmer John's N (4 &lt;= N &lt;= 10,000) cows live at various points within a circular field.  
FJ wants to partition his cows by building K (3 &lt;= K &lt;= 1000) fences radially outward 
from the center of the field at evenly-spaced angles (each measuring 360/K degrees).  
Depending on how he rotates this system of fences, he can partition the cows into K 
subsets, each containing a different subset of cows (potentially an empty subset). 
Define the RANGE of this partition as the number of cows in the largest set minus 
the number of cows in the smallest set.  Determine the minimum attainable RANGE value 
for a given set of cows.

Of course, no cow can straddle a fence.  Cows must be in one partition or the other.

To avoid problems with rounding, the input data will not contain cows that are very 
close to an integer multiple of 360/K degrees apart.

PROBLEM NAME: grazeset

## INPUT FORMAT:

* Line 1: Two integers: N and K

* Lines 2..N+1: Each line contains a single double that tells the angle at
  which a cow is grazing.  Angles are expressed in degrees, 0 &lt;= angle &lt;
  360.

### SAMPLE INPUT (FILE grazeset.in):

```text
4 3
30
60
150.003
240
```

## OUTPUT FORMAT:

A single line with the integer that is the minimum attainable RANGE value 
for the set of cows.

### SAMPLE OUTPUT (FILE grazeset.out):

```text
1
```
