#include <stdio.h>

int
main ()
{
  int max, ostatok, number;
  scanf ("%d", &number);
  ostatok = number % 10;
  max = ostatok;
  number /= 10;
  ostatok = number % 10;
  if (ostatok > max)
    max = ostatok;
  number /= 10;
  if (number > max)
    max = number;
  printf ("%d", max);
  return 0;

}
