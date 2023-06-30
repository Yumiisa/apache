// write solution to this Implement the following piecewise recurrence relation in the 3 different ways.
// ▪ Explain the differences(advantages, disadvantages)
// between the 3.
// ▪ Must be written in C
//     The problem
//     F(n) = F(n - 3) + F(n - 2) where F(0) = 0,
//     F(1) = 1, and F(2) = 2. Assume that n will be less

// Iteration(Loop) :

#include <stdio.h>

int main()
{
    int n;
    int f0 = 0, f1 = 1, f2 = 2, fn;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n == 0)
        fn = f0;
    else if (n == 1)
        fn = f1;
    else if (n == 2)
        fn = f2;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            fn = f2 + f1;
            f0 = f1;
            f1 = f2;
            f2 = fn;
        }
    }

    printf("F(%d) = %d\n", n, fn);

    return 0;
}

// recursion
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return fibonacci(n - 3) + fibonacci(n - 2);
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0 || n > 30)
    {
        printf("Invalid input. Please enter a value between 0 and 30.\n");
        return 0;
    }

    printf("F(%d) = %d\n", n, fibonacci(n));

    return 0;
}

// Dynamic Programming(Memoization)

#include <stdio.h>

#define MAX_SIZE 100

int memo[MAX_SIZE];

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        if (memo[n] == 0)
            memo[n] = fibonacci(n - 3) + fibonacci(n - 2);
        return memo[n];
    }
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("F(%d) = %d\n", n, fibonacci(n));

    return 0;
}
