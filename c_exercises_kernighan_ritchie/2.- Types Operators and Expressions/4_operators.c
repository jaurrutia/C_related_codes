/*Jonathan Urrutia 2022/01/19
We study the binary arithmetic operators & logical operators.
We include the use of scanf for this example (not done in the book.)
*/

#include <stdio.h>

int main(){

  int i, year;

  printf("Please enter a year (integer value): ");
  scanf("%d\n", &year );

/*x % y = remainder of x/y, and can only be applied to integers*/
/*both arithmetic and logical operators assiciate from left to rigth
  ! is a negation of a sentence*/
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )  /*&& is the and operator and || the or*/
    printf("%d is a leap year\n", year );
  else
    printf("%d is not a leap year\n", year );

  return 0;
}
