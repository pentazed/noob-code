//Program to print a mario pyramid
#include <stdio.h>

int main()
{
  int i, j, s, h;
  printf ("\tThis is mario's pyramid: \n");
  printf ("What should be the height of the pyramid: ");
  scanf (" %d", &h);

  //Generating a pyramid

  for (i = 0; i <= h; i++)
  {
    for (s = h; s > i; s--)
    {
      printf (" ");
    }
    for (j = 0; j < i-1; j++)
    {
      printf ("#");
    }
    printf ("\n");
  }
}
