#include <stdio.h>

// int main(void)
// {
//   printf("0 x 0 = %3d \n", 0 * 0);
//   printf("1 x 1 = %3d \n", 1 * 1);
//   printf("2 x 2 = %3d \n", 2 * 2);
//   printf("3 x 3 = %3d \n", 3 * 3);
//   printf("4 x 4 = %3d \n", 4 * 4);
//   printf("5 x 5 = %3d \n", 5 * 5);
//   printf("6 x 6 = %3d \n", 6 * 6);
//   printf("7 x 7 = %3d \n", 7 * 7);
//   printf("8 x 8 = %3d \n", 8 * 8);
//   printf("9 x 9 = %3d \n", 9 * 9);
//   printf("10 x 10 = %3d \n", 10 * 10);

//   return 0;
// }

int main(void)
{
  for (int i = 0; i <= 10; i++)
  {
    printf("%2d x %2d = %3d \n", i, i, i * i);
  }

  return 0;
}