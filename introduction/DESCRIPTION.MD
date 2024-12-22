## Food Line

There are n lines of people waiting for food, and the number of people wait-
ing in each line is known. Then, each of m new people will arrive, and they
will join the shortest line (the line with the fewest number of people). Our
task is to determine the number of people in each line that each of the m
people joins.

## Example:
Suppose that there are three lines, with three people in line 1, two peo-
ple in line 2, and five people in line 3. Then, four new people arrive. (Try
to work out what happens for this case before reading the rest of this para-graph.)
The first person joins a line with two people, line 2; now line 2 has
three people. The second person joins a line with three people, line 1 or line
2—let’s say line 1; line 1 now has four people. The third person joins a line
with three people, line 2; line 2 now has four people. The fourth and final
person joins a line with four people, line 1 or line 2—let’s say line 1; line 1
now has five people.
