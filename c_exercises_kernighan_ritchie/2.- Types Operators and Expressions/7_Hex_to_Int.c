/*Jonathan Urrutia 2022/01/20
We how does the different kind of data behaves when combined
Automatic changes -> when more storage is needed (changing a integer to a float if (5. + int i) signed data
Loosfing information is not fobidden (but it gives a warning if done)

For unsigned data it is more complicated since the max.min values change
*/

#include <stdio.h>

/*changes a character to its numerical value // isdigit(c) */
#define MAXSIZE 100

int main(){

  char c, s[MAXSIZE];
  int len, i, n, lowest;
  printf("Write a number in hexadecimal base: \n" );

  len = 0;
  while( (c = getchar()) != '\n' ){  /*make a copy of the input and calculate its length*/
    s[len] = c;
    ++ len;
  }

  lowest = 0;  /*See if se need to skip the 0x or 0X*/
  if( s[lowest] == '0' ){
    ++lowest;
    if( s[lowest] == 'x' || s[lowest] == 'x') ++lowest;
  }

  n = 0;
  for(i = lowest ; i <= len -1; ++i){
    if ( s[i] >= 'A' && s[i] <= 'F') s[i] = s[i] - 'A' + 10 ;
    else if ( s[i] >= 'a' && s[i] <= 'f') s[i] = s[i] - 'a' + 10;
    else if ( s[i] >= '0' && s[i] <= '9') s[i] = s[i] - '0';
    else {
      printf("No valid input. \n");
      return 0;
    }
    n = n * 16 + s[i];
  }


  printf("Its integer value is %d \n", n );


  return 0;
}
