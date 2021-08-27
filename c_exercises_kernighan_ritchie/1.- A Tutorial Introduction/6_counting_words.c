/*Jonathan Urrutia 2019/02/11
Sixth example. Word counting.
We'll define a word as any sequence without a \t, ' ' or \n. and will learn how
the if statement works, as well as the constants

Excercises 1-11,12
*/

#include <stdio.h>

#define IN 1 /* Inside a word*/
#define OUT 0 /*Outside a word*/

/*We will count characters, words and lines.*/
main()
{
  int c, nc, nw, nl, state;  /* charcater, number of charcaters, - words, -lines */

  nl = 1;
  nw = nc = 0;

  state = OUT;

  printf("We count characters, words and lines but before, we list all of your words separatelly. Write something:\n");
  while((c = getchar()) != EOF){
    ++nc;
    if(c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t'){
      state = OUT;
      printf("\n");
    }else if(state == OUT){
      state = IN;
      putchar(c);
      ++nw;
    }else if(state == IN){
      putchar(c);
    }
  }
  printf("\n There are %d characters, %d lines and %d words.\n", nc, nl, nw);





}
