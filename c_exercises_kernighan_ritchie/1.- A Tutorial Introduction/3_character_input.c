/*Jonathan Urrutia 2019/02/07
Third example. The use of characters is studied
Excercises 1 - 6,7
The loop works twice... it should be redo.
*/

#include <stdio.h>

main()
{
/*First we will use getchar() and putchar().
the idea is:
    read a character
    while(character != end of file indicator){
    output the read chraracter
    read a character}

    The EOF keyboard es Ctr+D
*/
int c, test;

printf("EOF = %f\n", EOF );  /*EOF is the indicator 'end of file'; it is defined in stdio.h and is a large int. */
printf("Write a charcater:\n");

while((c = getchar())!= EOF){  /*The parenthesis operation is made before the != in the test parameters*/
  test = (c != EOF);
  printf("Your character was: ");
  putchar(c);

  printf("\n getchar() != EOF ->  %d\n", test );


}


}
