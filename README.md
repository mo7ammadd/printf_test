# printf test

A testing tool for the 42 ft_printf project. It compares the printed output and return values of your ft_printf function against the standard C printf function.

## Features

* Basic Cases: Tests %c, %s, %p, %d, %i, %u, %x, %X, and %%.
* Edge Cases: Tests NULL pointers, INT_MAX, INT_MIN, empty strings, and chained specifiers.
* Scoring: Displays the total number of passed tests and the exact match percentage.

## Usage

1. Place printftest.c inside your project directory.
2. Build your static library:
   make

3. Compile the tester:
   cc -Wall -Wextra -Werror main.c libftprintf.a -o tester

4. Run the tester:
   ./tester

## Cleanup

make fclean
rm -f tester
