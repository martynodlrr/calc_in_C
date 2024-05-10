#include <stdio.h>
#include <stdlib.h>

void res(double first, double second, char operator)
{
    switch (operator) {
        case '+':
            printf("%lf\n", (first + second));
            break;
        case '-':
            printf("%lf\n", (first - second));
            break;
        case '*':
            printf("%lf\n", (first * second));
            break;
        case '/':
            if (second != 0.0)
                printf("%lf\n", (first / second));
            else {
                system("./matrix");
            }
            break;
        default:
            printf("Invalid operator");
    }
}

int main()
{
    char operator;
    double first, second;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two numbers separated by a space: ");
    scanf("%lf %lf", &first, &second);

    res(first, second, operator);

    return 0;
}
