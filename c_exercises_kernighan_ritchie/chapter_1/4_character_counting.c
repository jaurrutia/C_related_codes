/*Jonathan Urrutia 2019/02/11
Fourth example. Charcater counting. To finish the loop, instead of usinf
enter to end, let's use Ctr+D, which is how we write the EOF value.
For more info in this matter: https://stackoverflow.com/questions/35789676/counting-characters-via-c-book
To run with a file, write in the terminal
  gcc file_name.c
  ./a.out < text_file.txt
*/

#include <stdio.h>

main()
{
long nc;  /* number of charactes*/

printf("Write a string and end it with Ctr+D or run it with a file\n");

for(nc = 0; getchar() != EOF; ++nc)  /*Similar to nc += 1, or nc++ yet different.*/
;              /*For a blanck loop, we only wirte ; instead of {...}*/
              /* The prefix versions (++n) alter the variable and then pass along its value.
               The postfix version (n++) pass along the current value and then alter the variable.*/
printf("\n Using a for-loop, we get that the character is %ld long. \n", nc );

}
