                           ORANGE PROBLEMS
                  Four problems numbered 5 through 8

# PROBLEM 5: Factorial Power [Piele, 1983]

The factorial power of a whole number N is defined like this:

     N! = 1 * 2 * 3 * ... * N-1 * N

For example, 12! = 1*2*3*4*5*6*7*8*9*10*11*12 = 479001600

The rightmost non-zero digit in 12! is 6; two zeroes follow it.  
Write a program that will compute the right-most non-zero digit 
in the decimal representation of N! and also find the number of 
zeroes after it.

PROBLEM NAME: fact

## INPUT FORMAT:

One line with a single integer: N, 1 &lt;= N &lt;= 1,000,000

### SAMPLE INPUT (file fact.in):

```text
12
```

## OUTPUT FORMAT:
A single line with two numbers:

* The right most non-zero digit of N!
* The number of zeroes that follow it

### SAMPLE OUTPUT (file fact.out):

```text
6 2
```

# PROBLEM 6: Friday the Thirteenth [Traditional; Andree, 1965]

Is Friday the 13th really an unusual event? 

That is, does the 13th of the month land on a Friday less often than on 
any other day of the week? To answer this question, write a program that 
will compute the frequency that the 13th of each month lands on Sunday, 
Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday over a given 
period of N years. The time period to test will be from January 1, 1900 
to December 31, 1900+N-1 for a given number of years, N. N is non-negative 
and will not exceed 400.

There are few facts you need to know before you can solve this
problem: 
* January 1, 1900 was on a Monday. 
* Thirty days has September, April, June, and November, all the rest have
  31 except for February which has 28 except in leap years
  when it has 29.
* Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992
  will be a leap year, but the year 1990 is not a leap year)
* The rule above does not hold for century years. Century years divisible
  by 400 are leap years, all other are not. Thus, the century years 1700,
  1800, 1900 and 2100 are not leap years, but 2000 is a leap year.

Do not use any built-in date functions in your computer language. 

Don't just precompute the answers, either. 

PROGRAM NAME: friday

## INPUT FORMAT:

One line with the integer N. 

### SAMPLE INPUT (file friday.in):

```text
20
```

## OUTPUT FORMAT:

Seven space separated integers on one line. These integers represent the 
number of times the 13th falls on Saturday, Sunday, Monday, Tuesday, ..., Friday.

### SAMPLE OUTPUT (file friday.out):

```text
36 33 34 33 35 35 34
```

# PROBLEM 7: Beef McNuggets [Hubert Chen, 1998]

Farmer Brown's cows are up in arms, having heard that McDonalds is considering 
the introduction of a new product: Beef McNuggets.  The cows are trying to find 
any possible way to put such a product in a negative light.

One strategy the cows are pursuing is that of `inferior packaging'. ``Look,'' say 
the cows, ``if you have Beef McNuggets in boxes of 3, 6, and 10, you can not satisfy 
a customer who wants 1, 2, 4, 5, 7, 8, 11, 14, or 17 McNuggets. Bad packaging: bad product.''

Help the cows. Given N (the number of packaging options, 1 &lt;= N &lt;= 10), and a set 
of N positive integers (1 &lt;= i &lt;= 256) that represent the number of nuggets in the 
various packages, output the largest number of nuggets that can not be purchased by 
buying nuggets in the given sizes. Print 0 if all possible purchases can be made or 
if there is no bound to the largest number.

The largest impossible number (if it exists) will be no larger than 2,000,000,000.

PROGRAM NAME: nuggets

## INPUT FORMAT:

* Line 1: N, the number of packaging options

* Line 2..N+1: The number of nuggets in one kind of box 

### SAMPLE INPUT (file nuggets.in) :

```text
3
3
6
10
```

## OUTPUT FORMAT:

The output file should contain a single line containing a single integer that 
represents the largest number of nuggets that can not be represented or 0 if all 
possible purchases can be made or if there is no bound to the largest number.

### SAMPLE OUTPUT (file nuggets.out):

```text
17
```

# PROBLEM 8: Calf Flac [Traditional; Brian Dean 2001]

PROBLEM NAME: calfflac

It is said that if you give an infinite number of cows an infinite number of 
heavy-duty laptops (with very large keys), that they will ultimately produce 
all the world's great palindromes. Your job will be to detect these bovine beauties.

Ignore punctuation, whitespace, and case when testing for palindromes, but 
keep these extra characters around so that you can print them out as the 
answer; just consider the letters `A-Z' and `a-z'.

Find any largest palindrome in a string no more than 20,000 characters long. 
The largest palindrome is guaranteed to be at most 2,000 characters long before 
whitespace and punctuation are removed.

## INPUT FORMAT:

A file with no more than 20,000 characters.

### SAMPLE INPUT (file calfflac.in):

```text
Confucius say: Madam, I'm Adam.
```

## OUTPUT FORMAT:

The first line of the output should be the length of the longest palindrome found. 
The next line or lines should be the actual text of the palindrome (without any 
surrounding white space or punctuation but with all other characters) printed on a line 
(or more than one line if newlines are included in the palindromic text). If there are 
multiple palindromes of longest length, outputthe one that appears first.

### SAMPLE OUTPUT (file calfflac.out):

```text
11
Madam, I'm Adam
```
