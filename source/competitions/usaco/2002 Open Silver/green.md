                        GREEN PROBLEMS
                   Four problems numbered 1 through 4

# PROBLEM 1: Mountain Majesties [Brian Dean, 2001]

The cows are summering near the Front Range of the Rocky Mountains, not so
far from Coach Rob's house.  Visible on the horizon are N mountains (N &lt;=
100,000), for example (here, N=5):

                   /\
      /\          /  \  /\
     /  \/\    /\/    \/  \
    /    \ \  /  \    /    \
  -----------------------------

Each mountain is an isosceles triangle whose height is exactly twice the
length of its base.  A mountain is described by specifying the x-coordinate
of each of the two endpoints of its base; these coordinates will be
positive integers that fit nicely in a 16-bit signed entity.  Your task is
to compute the total area of the union of these mountains.

PROBLEM NAME: majesty

## INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Each line describes a single mountain with two
          sorted space-separated integers.

### SAMPLE INPUT (file majesty.in):

```text
5
2 7
6 9
12 15
14 21
20 25
```

## OUTPUT FORMAT:

A single integer, giving the area of the union of the mountains.  This area
will always be an integer and will always fit into 32 signed bits.

### SAMPLE OUTPUT

```text
114
```

**********************************************************************

# PROBLEM 2: Secret Milk Pipes [Barton, 2002]

Farmer John wants to connect his water distribution system cheaply, but he
doesn't want his rival, Farmer Snidely, to be able to predict the actual
routes he chooses.  FJ knows that this kind of problem usually asks for
the cheapest way to connect water pipes, so he decides to avoid that and
use the second cheapest way instead.

Given a list of all the bidirectional pipes that might connect a set of W
(3 &lt;= W &lt;= 2000) water stations (any one of which can be made into a well)
along with the costs for no more than P (P &lt;= 20,000) pipes, find the second
cheapest way to distribute water.  No pipe connects a station to itself;
no two pipes connect the same pair of stations.

It is guaranteed that there is only one cheapest way to distribute the
water and that there are at least two ways to distribute the water.  All
costs are positive integers that fit into a signed 16-bit entity.  A water
station is identified by its ID number, which is an integer in the range
1..W.

PROBLEM NAME: secret

## INPUT FORMAT:

* Line 1: Two space-separated integers, W and P

* Lines 2..P+1: Each line describes a single pipe and contains three
	  space-separated integers: a water station that is one endpoint
	  of a pipe, a water station that is the other endpoint of a pipe,
	  and the cost of that pipe.

### SAMPLE INPUT (file secret.in):

```text
5 7
1 2 3
2 3 4
1 4 7
2 4 11
2 5 9
5 4 5
3 5 8
```

## OUTPUT FORMAT:

A single line with a single integer that is the second lowest cost to
construct a water distribution system.

### SAMPLE OUTPUT (file secret.out):

```text
20
```

**********************************************************************


# PROBLEM 3: Circus Tickets [Gadnell &amp; Backman/Kolstad, 1997]

Farmer John is taking 16 cows to see the three ring circus.  Being cows,
they are seated in the cow section, a 4x4 set of seats near the front of
the audience.  The seats, rows, and columns are numbered thusly:

     col 1    col 3
        | col 2 | col 4
        |   |   |   |
        1   2   3   4  &lt;-- row 1
        5   6   7   8  &lt;-- row 2
        9  10  11  12  &lt;-- row 3
       13  14  15  16  &lt;-- row 4

The cows are herded helter-skelter into the seats.  It is only after they
are seated that they check their tickets.  In a revelation that will
surprise no one, they are not necessarily in the proper seats.  The layout
of the cow seating is such that they can rearrange themselves only by
rotating a row right or left or rotating a column up or down.  The examples
below show all four operations applied to the first row or column of the
proper seating shown above:

  4   1   2   3     2   3   4   1     5   2   3   4    13   2   3   4
  5   6   7   8     5   6   7   8     9   6   7   8     1   6   7   8
  9  10  11  12     9  10  11  12    13  10  11  12     5  10  11  12
 13  14  15  16    13  14  15  16     1  14  15  16     9  14  15  16
Rot row 1 right    Rot row 1 left     Rot col 1 up      Rot col 1 down

Given the initial seating arrangement of the cows, determine a very good
set of rotations to rearrange cows so that their tickets and seat numbers
match.  At least one solution always exists.

Your score for each test case will depend on how close you get to the best
number of rotations submitted by other contestants for that case.  Your
output sequence must be shorter than 500 operations in order to receive
credit for this problem.

HINT: The sequence 1l 1l 1l 4u 1r 4d 1l 1l 4u 1r 4u 4u 4u swaps the upper
left cow with the cow to her right.

PROBLEM NAME: tix

## INPUT FORMAT:

Four lines, each with four space separated integers.  Line 1 is the first
row; line 2 is the second row; and so on.

### SAMPLE INPUT (file tix.in):

```text
4 1 2 3
6 7 8 5
10 11 12 9
14 15 16 13
```

## OUTPUT FORMAT:

A series of output lines that contain the ordered sequence of rotations
that will arrange the cows.  Each line contains a row or column number
(1..4) followed by a space followed by a lower-case letter that indicates
the operation to be performed: 'r' for rotate a row right, 'l' for rotate
a row left, 'u' for rotate a column up, and 'd' for rotate a column down.

### SAMPLE OUTPUT (file tix.out):

```text
1 l
2 r
3 r
4 r
```

[Other correct sequences are equally valid though might not garner as many
points.]

**********************************************************************

# PROBLEM 4: Life Cycle [Piele, 2002]

The cows are calculating the "life cycle" for each of their identification
tag numbers.

Take any positive integer N (1 &lt;= N &lt;= 9999), say 57, square all the digits
and add them up:  5^2 + 7^2 to get 25 + 49 = 74. Now do the same procedure
with the result 74 to get the next number in the sequence 65. Continuing
to apply this procedure to a sequence of terms eventually repeats one
number of the sequence.

When starting with 57, the sequence repeats for the first time with 37,
which is the next number in this part of the sequence:

      57, 74, 65, 61, 

From then on the sequence is trapped in a "life cycle":

      37, 58, 89, 145, 42, 20, 4, 16, 37, . . .

If we cube the digits instead of squaring them the sequence has a similar
fate. Your job is to write a program that computes how long the sequence
lasts until it falls into a life cycle given a starting positive integer
and a power P (1 &lt;= P &lt;= 5).

PROBLEM NAME: life

## INPUT FORMAT:

A single line with two space-separated integers: N and P.

### SAMPLE INPUT (file life.in):

```text
57 2
```

## OUTPUT FORMAT:

Length of the sequence until it enters a life cycle, not including the
first number in the cycle.

### SAMPLE OUTPUT (file life.out):

```text
4
```

[This corresponds to the sequence: 57, 74, 65, 61, 37, ...; 37 is the first
number that is repeated.]