# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.

/*
Lucia corrected my problem 3,I needed to add const to the Triangle function so it would work correctly on autograder.
*/

# Overview
This classwork set is very similar to the previous one; you'll be writing functions which perform particular operations.

For the first problem, you'll write the entire program (we've provided a skeleton main() function, but that's all).

# Submission
You should submit your code on Gradescope.  Zip up your completed code, and upload it as classwork 4.

# Problems
## 1.
scanf() is sort of the reverse of printf(): it reads input and converts values according to a format string.  For example, to read two integers:

    scanf("%d %d", number1, number2);

The catch is that since scanf needs to modify the arguments, they must be pass-by-reference.  That is, number1 and number2 are not ints, but rather pointers to ints.

Write a command-line calculator program that reads what to do using scanf.  Your code should take both operands and the operation all on one line (e.g., "45 + 3") and then print the result.  You should re-use your calculator code from the previous assignment, and just add scanf to get the arguments.

## 2.
Write a function that prints the date and time represented by a `time_t`, using the format: `Weekday, Month Day, Year hours:minutes:seconds`

For example, `Wednesday, September 19, 2018 16:30:02`

You will probably want to use the time() and gmtime() functions.  You can access the help pages with `man 2 time` and `man gmtime`.

## 3.
We use pass-by-reference when the function needs to modify the parameters, but it can also be useful when the parameters take a large amount of memory and we want to avoid the overhead of copying them.

To simulate this case, write a new version of your which-triangle-is-larger function which operates with pass-by-reference.  If one triangle is NULL, then you should return the non-NULL one as "larger".

