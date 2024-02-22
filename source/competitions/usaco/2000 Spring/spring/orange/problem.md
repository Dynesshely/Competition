                   1999-2000 USA Computing Olympiad
                  Spring Contest -- March 8-15, 2000
                           Orange Division

# PROBLEM 5: Double Smoothly Undulating Numbers [Ken Shirriff; JRM 26:2 p103 1994]

Smoothly undulating numbers alternate between a pair of digits (e.g., 1212121).  
Double smoothly undulating numbers alternate between a pair of digits in one number base and a pair (potentially different) of digits in some other number base.  
Consider the number 191919 in base 10.  
This number is 121212 when represented in base 11.  
So, 191919 (in base 10) is a double smoothly undulating number.

Similarly, there are triple undulating numbers (which are smoothly undulating in three bases) and even quadruple smoothly undulating numbers, like 300 (base 10), which is:

        * 606 (base 7)         * 363 (base 9)
        * 454 (base 8)         * 1A1 (base 13)

Your task will be to find double, triple, and quadruple smoothly undulating numbers.

## INPUT FORMAT:

A single line with five integers:
* The lowest base to examine (2..32)
* The highest base to examine (2..32)
* The lowest number in the range of numbers to search (1..10000000)
* The highest number in the range of numbers to search (1..10000000)
* The number 2, 3, or 4 for double, triple, or quadruple undulating numbers, respectively

### SAMPLE INPUT (file NUM.IN):

```text
10 11 190000 950000 2
```

## OUTPUT FORMAT:

A sort of list of numbers in base 10 that meet the input criteria.

### SAMPLE OUTPUT (file NUM.OUT):

```text
191919
383838
575757
767676
959595
```

----------------------------------------------------------------------

# PROBLEM 6: Trapped

Consider a maze marked with row and column numbers:

```text
            1 2 3 4 5 6 7
           +-+-+-+-+-+-+-+
         1 |           |
           + +-+-+-+-+-+ +
         2 |             |
           + +-+-+-+-+-+ +
         3 | |   |   | | |
           + +-+ + +-+ + +
         4 | |     |     |
           +-+-+-+-+-+-+-+
```

This maze has one exit (right hand side, first row).  It is possible to
reach the exit from many locations in the maze but not all of them (for
instance, row 4, column 2).

Your task is to decide how many cells are isolated from an exit.

## INPUT FORMAT:

* Line 1: two space-separated integers R,C (1 <= R,C <= 35) that tell the number of rows and columns for the maze

* Lines 2..2*R+2: An ASCII map of the matrix just as above.  
  Walls are marked by `_' and `|'.  
  Wall intersections (and potential wall intersections) are marked by `+'.

### SAMPLE INPUT (file MAZE.IN):

```text
4 7
+-+-+-+-+-+-+-+
|           |
+ +-+-+-+-+-+ +
|             |
+ +-+-+-+-+-+ +
| |   |   | | |
+ +-+ + +-+ + +
| |     |     |
+-+-+-+-+-+-+-+
```

## OUTPUT FORMAT:

On a single line, output one integer that tells the number of cells from
which one can not find a way to exit the maze.

### SAMPLE OUTPUT (file MAZE.OUT):

```text
7
```

----------------------------------------------------------------------

# PROBLEM 7: Stamps [1995 ACM Finals]

You are supplied a set of values for stamps (e.g., {1, 3, 5}) and the
maximum number of stamps that can be applied to an envelope (e.g., five
stamps). Your goal is to calculate the largest contiguous set of postage
that can be accommodated.  For the set of {1, 3, 5} with five maximum
stamps, one can build:

```text
  1: 1        6: 1+5       11: 5+5+1     16: 5+5+3+3      21: 5+5+5+3+3
  2: 1+1      7: 5+1+1     12: 5+5+1+1   17: 5+5+5+1+1    22: ????
  3: 3        8: 5+3       13: 5+5+3     18: 5+5+5+3
  4: 1+3      9: 5+3+1     14: 5+5+3+1   19: 5+5+5+3+1
  5: 5       10: 5+5       15: 5+5+5     20: 5+5+5+5
```

There appears to be no way to build 22 cents with no more than five
members of this set of stamps.  Thus, one can build values in the ragen
[1..21,] a total of 21 contiguous stamp values.  There is no reason to
believe that the largest contiguous set will start with the value `1'.

## INPUT FORMAT:

* Line 1: Two space separated integers, S (1 <= S <= 20), the
          number of stamp types, and E (1 <= E <= 10), the maximum
          number of stamps that can fit on an envelope.

* Line 2: S different space-separated positive integers representing
          the values of the stamps (1 <= stampval <= 1000)

### SAMPLE INPUT (file STAMP.IN):

```text
3 5
1 3 5
```

## OUTPUT FORMAT:

The maximum number of contiguous values that can be created by combining
the stamps.

### SAMPLE OUTPUT (file STAMP.OUT):

```text
21
```

----------------------------------------------------------------------

# PROBLEM 8: Metric Matrices [Hal Burch]

Given as input a square distance matrix, where a[i,j] is the distance
between point i and point j, determine if the distance matrix is "a
metric" or not.

A distance matrix a[x,y] is a metric if and only if
   1. f(x,x) = 0
   2, f(x,y) > 0 if x != y
   2. f(x,y) = f(y,x)
   3. f(x,y) + f(y,z) >= f(x,z)

## INPUT FORMAT:

* Line 1: One integer, N, the rows and number of columns, 2 <= N <= 30

* Line 2..N+1: N lines, each with N space-separated integers (-32000 <=
               each integer <= 32000).  The first of these lines
               represents the first row; the first number in each line
               is the first column.

### SAMPLE INPUT (file METRIC.IN):

```text
4
0 1 2 3
1 0 1 2
2 1 0 1
3 2 1 0
```

## OUTPUT FORMAT:

A single line with a single digit, which is the lowest digit of the
possible facts on this list:
    * 0: The matrix is a metric
    * 1: The matrix is not a metric, it violates rule 1 above
    * 2: The matrix is not a metric, it violates rule 2 above
    * 3: The matrix is not a metric, it violates rule 3 above
    * 4: The matrix is not a metric, it violates rule 4 above

### SAMPLE OUTPUT (file METRIC.OUT):

```text
0
```
