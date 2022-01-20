/*Jonathan Urrutia 2022/01/20
We how does the different kind of data behaves when combined
Automatic changes -> when more storage is needed (changing a integer to a float if (5. + int i) signed data
Loosfing information is not fobidden (but it gives a warning if done)

For unsigned data it is more complicated since the max.min values change
*/

#include <stdio.h>
#include <math.h> /*To use the function: sqrt( double f ) - To compule it we write in the terminal
                   gcc file.c -lm
                   the -lm option id to link the math.h header*/
#include <ctype.h> /*has better functions for our char2int and lower_case functions
                    It does not depends if it is ASCII or other character set*/


/*changes a character to its numerical value // isdigit(c) */
int char2int( char s[]); /*default (un)signed status depends on the equipment. It is better to
                          specify it explicitely*/

/*Rewrites charecter in  ASCII into its lower cases. // tolower(c)  */
int lower_case(int c);

int main(){

  int i = 5, ii;
  float x = 6.1, xx;

/*Gain and loss of information */
  printf("i = %d \n", i );
  printf("x = %f \n", x );

  printf("i = x -> %d \n", (ii = x) );
  printf("x = i -> %f \n", (xx = i) ); /*truncation or rounding of data is implementation dependent*/

 /*Another way we can change the kind of data of a varibly is by the operator 'cast' which forces
 the variable to have another type.
 If a function is called and it specifies the kinf of data in the preamble, the cast operation is made by default*/
 printf("(float) i -> %f \n", (float) i);
 printf("sqrt( i ) = sqrt ( (double) i) -> %f \n", sqrt( i ) );


  return 0;
}




int char2int( char s[]){
  int i, n = 0;
  for( i = 0; s[i] >= '0' && s[i] <= '9'; ++i) /*False = 0, True != 0*/
    n = 10 * n + (s[i] - '0');

  return n;
}

int lower_case( int c){
  if ( c >= 'A' && c <= 'Z') return c + 'a' - 'A';
  else return c;
}
