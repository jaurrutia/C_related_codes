/*Jonathan Urrutia 2019/02/11
Fifth  example. Charcater counting. To finish the loop, instead of usinf
enter to end, let's use Ctr+D, which is how we write the EOF value.
For more info in this matter: https://stackoverflow.com/questions/35789676/counting-characters-via-c-book
To run with a file, write in the terminal
  gcc file_name.c
  ./a.out < text_file.txt
  Excercises 1. 8 - 10
*/

#include <stdio.h>


main()
{
long nc;  /* number of charactes*/
int c, nl, nt, nb, nbs, dummy;  /* charcater, number of lines, - tabs, - blanks, -back slashes */

nl = 1;  /*we set one because the firs line is not counted in the while loop*/
nt = 0;
nb = 0;
nbs = 0;

printf("We count all of the special characters using a while-loop. Write a string:\n");
while((c = getchar()) != EOF){
  if (c == '\n'){ ++nl;}
  if (c == '\t'){ ++nt;}
  if (c == ' '){ ++nb;}  /*Unlike in the book, blank is not written as \b. */
  if (c == '\\'){ ++nbs;}
  ++nc;
}
printf("\n There are %ld characters, %d lines, %d tabs, %d blanks and %d back-slashes.\n", nc, nl, nt, nb, nbs );

printf("We replace all special characters to ist symbols:\n");
while((c = getchar()) != EOF){
  if(c == '\n'){ c = 'n'; printf("\\");}
  if(c == '\t'){ c = 't';} printf("\\");
  if(c == '\\'){ c = '\\'; printf("\\");}
  if(c == ' ' ){ c = 'b'; printf("\\");}
  putchar(c);
}

nb = 0;
printf("\n We collaps all blanks to one:\n");
while((c = getchar()) != EOF){
  if(c ==  ' '){++nb;}
  if( nb == 0 ){ putchar(c);}
  if(c != ' ' && nb != 0){ printf(" "); putchar(c); nb = 0;}


}



}
