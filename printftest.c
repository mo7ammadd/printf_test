#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"

void print_and_check(int r_orig, int r_mine, int *passed, int *total)
{
    printf("Return -> Orig: %d | Mine: %d\n\n", r_orig, r_mine);
    (*total)++;
    if (r_orig == r_mine)
        (*passed)++;
}

int main(void)
{
    int o, m;
    int passed = 0, total = 0;
    int a = 42;
    char *str = "Hello 42 Irbid!";

    printf("\n========================================================\n");
    printf("                 PART 1: BASIC CASES                    \n");
    printf("========================================================\n\n");

    printf("--------------------[ %%c ]--------------------\n");
    o = printf("Orig : %c\n", 'Z');
    m = ft_printf("Mine : %c\n", 'Z');
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ %%s ]--------------------\n");
    o = printf("Orig : %s\n", str);
    m = ft_printf("Mine : %s\n", str);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ %%p ]--------------------\n");
    o = printf("Orig : %p\n", &a);
    m = ft_printf("Mine : %p\n", &a);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ %%d & %%i ]--------------------\n");
    o = printf("Orig : %d | %i\n", 100, -200);
    m = ft_printf("Mine : %d | %i\n", 100, -200);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ %%u ]--------------------\n");
    o = printf("Orig : %u\n", 4294967295U);
    m = ft_printf("Mine : %u\n", 4294967295U);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ %%x & %%X ]--------------------\n");
    o = printf("Orig : %x | %X\n", 255, 255);
    m = ft_printf("Mine : %x | %X\n", 255, 255);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ %%%% ]--------------------\n");
    o = printf("Orig : %%\n");
    m = ft_printf("Mine : %%\n");
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ MIXED ]--------------------\n");
    o = printf("Orig : %c %s %p %d %u %x %%\n", 'A', "Mix", &a, -42, 42, 42);
    m = ft_printf("Mine : %c %s %p %d %u %x %%\n", 'A', "Mix", &a, -42, 42, 42);
    print_and_check(o, m, &passed, &total);

    printf("\n========================================================\n");
    printf("                 PART 2: EDGE CASES                     \n");
    printf("========================================================\n\n");

    printf("--------------------[ 1. EMPTY FORMAT & NULL STRINGS ]--------------------\n");
    o = printf("");
    m = ft_printf("");
    printf("\n");
    print_and_check(o, m, &passed, &total);

    o = printf("Orig: [%s]\n", (char *)NULL);
    m = ft_printf("Mine: [%s]\n", (char *)NULL);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ 2. MULTIPLE PERCENTAGES ]--------------------\n");
    o = printf("Orig: %%%%%%%%%%\n"); 
    m = ft_printf("Mine: %%%%%%%%%%\n");
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ 3. EXTREME POINTERS ]--------------------\n");
    o = printf("Orig: %p | %p | %p\n", (void *)-1, (void *)ULONG_MAX, (void *)NULL);
    m = ft_printf("Mine: %p | %p | %p\n", (void *)-1, (void *)ULONG_MAX, (void *)NULL);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ 4. ZERO EVERYWHERE ]--------------------\n");
    o = printf("Orig: %d, %i, %u, %x, %X, %p\n", 0, 0, 0, 0, 0, (void *)0);
    m = ft_printf("Mine: %d, %i, %u, %x, %X, %p\n", 0, 0, 0, 0, 0, (void *)0);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ 5. EXTREME HEX, INT & UNSIGNED ]--------------------\n");
    o = printf("Orig: %d | %d | %u | %x | %X\n", INT_MAX, INT_MIN, UINT_MAX, UINT_MAX, UINT_MAX);
    m = ft_printf("Mine: %d | %d | %u | %x | %X\n", INT_MAX, INT_MIN, UINT_MAX, UINT_MAX, UINT_MAX);
    print_and_check(o, m, &passed, &total);

    printf("--------------------[ 6. CHAINED SPECIFIERS ]--------------------\n");
    o = printf("Orig: %d%d%d%d%d\n", 1, -2, 3, -4, 5);
    m = ft_printf("Mine: %d%d%d%d%d\n", 1, -2, 3, -4, 5);
    print_and_check(o, m, &passed, &total);

    // RESULT
    printf("\n========================================================\n");
    float percentage = ((float)passed / total) * 100;
    printf(" Passed Tests: %d / %d\n", passed, total);
    printf(" Match Percentage: %.2f%%\n", percentage);
    printf("========================================================\n\n");

    return (0);
}
