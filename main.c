#include <stdio.h>

int main()
{
  char operator;
  double first, second;
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Enter the two numbers independently");
  scanf("%lf %lf", &first, &second);

  switch (operator) {
    case '+':
      printf("%lf + %lf = %lf", first, second, (first + second));
      break;

    case '-':
      printf("%lf + %lf = %lf", first, second, (first - second));
      break;

    case '*':
      printf("%lf + %lf = %lf", first, second, (first * second));
      break;

    case '/':
      if (second != 0.0)
        printf("%lf + %lf = %lf", first, second, (first / second));
      else
        printf("ERROR");
      break;

    default:
      printf("Invalid operator");
  }

  return 0;
}
