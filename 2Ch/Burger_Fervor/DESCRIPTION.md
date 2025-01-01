## Burger Fervor

## The problem
A man named Homer Simpson likes to eat and drink. He has t minutes that
he’ll spend eating burgers and drinking beer. There are two kinds of bur-
gers. One of them takes m minutes to eat, and the other takes n minutes
to eat.
Homer likes burgers more than beer, so he’d like to spend the entire t
minutes eating burgers. However, doing so isn’t always possible. For exam-
ple, if m = 4, n = 9, and t = 15, then no combination of the 4-minute and
9-minute burgers can take him exactly 15 minutes to eat. If that’s the case,
he’ll spend as much time as possible eating burgers and then fill the rest of
the time drinking beer. Our task is to determine the number of burgers that
Homer can eat.

### Input
We read test cases until there is no more input. Each test case is represented
by a line of three integers: m, the number of minutes it takes to eat the first
kind of burger; n, the number of minutes it takes to eat the second kind of
burger; and t, the number of minutes that Homer will spend eating burgers
and drinking beer. Each m, n, and t value is less than 10,000.

### Output
For each test case:
- If Homer can spend exactly t minutes eating burgers, then output
  the maximum number of burgers that he can eat.
- Otherwise, output the maximum number of burgers that Homer
  can eat when maximizing his time eating burgers, a space, and the
  number of remaining minutes (during which he’ll drink beer).
  The time limit for solving the test cases is three seconds.
