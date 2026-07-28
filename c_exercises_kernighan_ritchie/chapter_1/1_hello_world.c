/*Jonathan Urrutia 2019/02/07
This is the first code writen in order to re-learn the basics of C.
The goal is to understand the concept of functions in C.

Excercises 1-1 & 1-2
*/


#include <stdio.h>  /* The library stdio.h is loaded.
                    stdio = standard input-output header
                    It's needed for basic functions.*/

 /*In C, we have -> function and variables.
The function 'main' is where the the program begins, so all C files must have a
'main' function somewhere. ALWAYS.

In the textbook no particular definition (as a variable/function) is needed for
the 'main' function, but in C17 it is required to define the return type of the function.
Usually it is an integer (int). The main function should return 0 if the program runs
successfully, and a non-zero value if there is an error.
 */

main()
{
printf("Hello, World!\n");  /*Prints what is written inside.*/
printf("Smth weird \t :)\n" );
}

/*To run the program from the terminal, use:
  gcc file_name.c
  ./a.out

  to run in in atom, F5
  */
