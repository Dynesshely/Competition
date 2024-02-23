                    1999-2000 USA Computing Olympiad
                  Spring Contest -- March 8-15, 2000
                             Green Division

# PROBLEM 1: Ski Cows [Brian Dean]

Since his cows have been well-behaved, Farmer John sends them on
vacation during the winter to visit with USACO head coach Rob K.  Since
Rob lives in Colorado, he loves to take the cows out snow skiing and
needs your help to determine the best ski location to visit.
Specifically, since he doesn't want the cows to get bored, he wants to
visit a mountain on which there are many routes to ski from top to
bottom.

You will be given a file which contains a description of a mountain and
its interesting landmarks.  The file describes landmarks, their
elevation, and which paths exist between various landmarks.

The landmarks with the largest and smallest elevations represent
respectively the top and bottom of the mountain.  All ski routes must
start at the top of the mountain and follow some sequence of ski paths,
moving from landmark to landmark downhill, until they reach the bottom
of the mountain.

Your task is to compute the number of different possible ski routes.

## INPUT FORMAT:

* The first line contains two integers: N, 2 <= N <= 200, which gives
  the number of "landmarks" on the mountain; and M, which gives the
  number of "ski paths" on the mountain, where 1 <= M <= 5000.  A ski
  path connects two landmarks (see below).

* Subsequently, N space-separated positive integers smaller than
  1,000,000 specify in turn the elevation of each landmark (e.g.,
  landmark 1, landmark 2, ..., landmark N).  All elevations are unique.
  The integers are given 10 per line, except possibly the last line of
  these integers.

* Finally, M space-separated pairs of integers (each in the range
  [1..N]) specify the ski connections of the previously-specified
  landmarks by listing the pair of indices of each connected pair of
  landmarks.  Each pair connects two different landmarks (i.e., not from
  5 to 5) Each pair of integers is unordered.  There might be multiple
  ski paths connecting the same pair of landmarks.  The pairs are given
  ten pairs per line, except possibly the last line of these pairs.


### SAMPLE INPUT (file SKI.IN):

```text
4 5
500 400 300 200
1 2 2 3 3 4 1 4 2 4
```

## OUTPUT FORMAT:

A single integer on the output line that specifies the total possible
number of paths down the mountain.

### SAMPLE OUTPUT (file SKI.OUT):

```text
3
```

----------------------------------------------------------------------

# PROBLEM 2: Cowtography [Brian Dean]

Farmer John wants to draw a map of his land, which is divided into
rectangular fields. Each field is colored with a number (an integer in
[1..1,000,000]).  His goal is to design a map in which every adjacent
pair of fields is colored differently.

Unfortunately, Farmer John's land is described in a rather unusual
manner.  His entire farm is a square, 1 kilometer on a side.  The
description of the layout of his farm is given by a sequence of lines,
each of which contains one word or number per line.

The 1-by-1 kilometer square comprising the entire farm is described in
the file as a series of one or more regions.  A region can be specified
by either:

*  A number giving the color of the region under consideration

*  The number "-1", indicating that the region under consideration
   is to be split evenly in half with a vertical line.  Following the
   "-1" command will be descriptions of the left and then right halves,
   each described as a region.

*  The number "-2", indicating that the region under consideration is
   to be split evenly in half with a horizontal line.  Following the
   "-2" command will be a description of the upper and then lower
   halves, each described as a region.

There are no more than 100 regions on Farmer John's property.

For example, if FARM.IN contained the following text:
```text
-1
5
-2
-1
37
6
5
```

The farm would resemble something like this:

+----------+------+-----+
|          |      |     |
|          |      |     |
|          |      |     |
|          |  37  |  6  |
|          |      |     |
|          |      |     |
|    5     +------+-----+
|          |            |
|          |            |
|          |      5     |
|          |            |
|          |            |
|          |            |
+----------+------------+

Your task is to determine the greatest number of adjacent regions
colored with the same color.

## INPUT FORMAT:

As above, a series of lines containing a number, the string `hsplit',
or the string `vsplit'.

### SAMPLE INPUT (file FARM.IN):

```text
vsplit
5
hsplit
vsplit
37
6
5
```

## OUTPUT FORMAT:

A single line with an integer that tells the greatest number of adjacent
fields have the same color.

### SAMPLE OUTPUT (file FARM.OUT):

```text
2
```

----------------------------------------------------------------------

# PROBLEM 3: Cow Routes [Brian Dean]

A postal truck passing Farmer John's barn hit a rock and accidentally
spilled a load of postcards, each of which contains directions between
two cities.  Each postcard contains a simple description of some route
between two cities and looks like this:

"To get from A to E, start at A, go 3 north to B, then go 2 east to C,
then go 1 north to D, and finally go 2 west to E."

All of the directions conform to this format -- they give a route by
specifying the first city and the list of distances and cities visited
along the route with the direction (north, south, east, or west)
followed between consecutive cities.

Write a program that determines if there is any inconsistency among the
set of routes.  They describe a planar map, of course.

## EXAMPLE

Consider two routes:
* Start at A, go 3 north to B, go 2 west to C, go 1 south to D
* Start at D, go 3 west to A
These are inconsistent, since they cannot both be valid routes on a
plane (i.e., you can't go west from A to D and also go west from D to
A).

## INPUT FORMAT:

The input format consists first of a line containing the number of
routes, R (2 <= R <= 200) followed by the routes themselves.

Cities are named by numbers (whose range is [1..200]) instead of
letters; directions are named by upper-case `N', `S', `E', and `W'.
Each route has a starting city followed by a series of one or more
space-separated distance/direction/city triples.  Distances are integers
in the range [1..200]. A distance of 0 marks the end of a route. A route
contains no more than 200 distance,direction,city triples.  No route
will contain any given city more than once on that route.

Long routes might stretch over more than one input line.  Each route
begins on a new input line.

### SAMPLE INPUT (file ROUTE.TXT):

```text
2
1 3 N 2 2 W 3 1 S 4 0
4 3 W 1 0
```

## OUTPUT FORMAT:

A single line with largest integer N such that the first N routes of
the input file are consistent with each other.

### SAMPLE OUTPUT (file ROUTE.TXT):

```text
1
```

----------------------------------------------------------------------

# PROBLEM 4: Largest Matrix Subsequences [Adapted from 1995 UMD Competition]

Define an `increasing sequence' as a matrix of numbers which grows when
read from left to right and from top to bottom along every row and every
column.  An example:

```text
             1 2 3 6
             3 5 7 9
```

Find the largest increasing sequence sub-matrix (or sub-matrices) in a
matrix of integers (whose range is [0..32,000]).  The largest sub-matrix
is that sub-matrix with the largest product of nrows*ncolumns.  If more
than one largest sub-matrix exists, print each of them, with the list
in `numerical order'.

In the example above, row 1 is "1 2 3 6" and column 1 is "1 3".

## INPUT FORMAT:

Line 1: Two space separated integers: R, C (1 <= R,C <= 150).  These
        are the number of rows and columns, respectively.

Line 2..end: R*C space-separated integers that represent the matrix.
        These integers are presented 20 per line, except possibly the
        last line.  The first integer belongs in row 1 column 1; the
        second integer belongs in row 1 column 2; and so on for a total
        of R*C integers.

### SAMPLE INPUT (file MAT.IN):

```text
3 4
8 2 3 9
3 5 7 8
7 2 1 9
```

## OUTPUT FORMAT:

A series of one or more lines, each with four space-separated integers.
The first two integers are the row and column of the upper left element;
the second two integers are the extent of the submatrix (number of rows,
number of columns).

### SAMPLE OUTPUT (file MAT.OUT):

```text
1 2 2 2
2 1 1 4
```
