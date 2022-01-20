/*Jonathan Urrutia 2022/01/19
We study the different definitions for a constant (including string constants).
*/

#include <stdio.h>
#include <string.h>  /*For the strlen function*/

#define INTCONST 1234             /*int*/
#define LONGCONST 123456789L      /*long int L<->l  */
#define UNSIGNEDCONST 12345U      /*unsigned int U<->u  */
#define UNSIGNEDLONGCONST 12345UL /*unsigned long int UL<->ul  */
#define DOUBLECONST 1.5           /*double */
#define DOUBLECONSTTWO 1.5e-3     /*double*/
#define FLOATCONST 1.5F           /*float*/
#define LONGFLOATCONST 1.5L           /*long double*/

#define INTOCTACONST 0123         /*int but in octa (base 8), 0 at the beginning*/
#define INTOHEXCONST 0X123        /*int but in octa (base 16), 0X<->0x at the beginning*/

#define ZEROCHAR '0'              /*char   numerical valuo of char '0'*/
#define ZEROVALUE '\0'            /*char  numerical zero in character */
#define CHARACTER 'x'             /*char   numerical valuo of char '0'*/
#define CHARACTEROCTA '\013'      /*char   in ASCII vectical tab  DEC 11 = OCT 13 = HEX B*/
#define CHARACTERHEX '\xb'        /*char  */

/*Constant expression: Evaluation made in the compilation*/

#define MAXLINE 1000
char line[MAXLINE + 1];  /*Global variable*/


int my_strlen( char s[] );


int main(){
  int i;

  /*String constant or literal =  This is an array of char  */
  char s1[] = "Hello, world!";
  char s2[] = "Hello, " "world!";
  char s3[] = "x";
  char c = 'x';

  /* They concatenate   Hello," " world!" = "Hello, world!" */
  printf("Let us see how long are our strings with strlen :\n");
  printf("\"%s\" has %ld characters\n",s1, strlen(s1)  );  /*I had an arror if %d, so I used %ld (long int)*/
  printf("\"%s\" has %ld characters\n",s2, strlen(s2) );

  printf("Let us see how long are the array of the strings with my_strlen :\n");
  printf("\"%s\" is a %d long array\n",s1, my_strlen(s1) );  /*I had an arror if %d, so I used %ld (long int)*/
  printf("\"%s\" ia a %d long array\n",s2, my_strlen(s2) );


  /* "x" != 'x' ; "x" = [ 'x', '\0 ]; the las is added always to strings */
  printf("The char 'x' equals %d\n", c );
  printf("The string  \"x\" equals [");

  for(i = 0; i <= my_strlen(s3); ++i){
    printf(" %d ", s3[i] );
  }
  printf("]\n");
  return 0;
}

int my_strlen( char s[]){
 int i = 0;
 while (s[i] != '\0') {
   ++ i;}
 return i;
}
