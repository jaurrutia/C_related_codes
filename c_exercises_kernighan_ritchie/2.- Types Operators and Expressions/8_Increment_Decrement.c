/*Jonathan Urrutia 2022/01/20

*/

#include <stdio.h>
#define MAXSIZE 1000

void str_concat( char s1[], char s2[]);
void squeeze( char s[], char c); /*The book declares int c*/
void squeeze_all( char s1[], char s2[]);
int any( char s1[], char s2[]);

int main(){

  char c, s1[MAXSIZE], s2[MAXSIZE], s3[MAXSIZE];
  int i, j;
 /*++n and n++ (--n & n--) add (substract) one unit but they are done in different times
 ++ is only used for variables, not for expressions
  ++i     is allowed
  ++(i+j) is not allowed
  */

  int n = 5;
  /*++n performd the increment and then the operations*/
  printf("If n = 5: \n x = ++n ->  n = 5+1 = %d -> x = n = %d \n", n, ++n  );

  /*n++ performd the operations and then the increment*/
  n=5;
  printf("If n = 5: \n x = n++ ->  x = n = %d -> n = 5+1 = %d  \n", n++, n  );


  /*In either case n changes its value but it may be useful to do it before- or afterhand in some cases*/
  printf("Write a string: s1 = ");
  i = 0;
  while ((c = getchar()) != '\n'){  /*We store a copy of the characters and we make them a string*/
    s1[i] = c;
    ++i; /*++i = i++*/
  }
  ++i;
  s1[i] = '\0';

  printf("Write a string: s2 = ");
  i = 0;
  while ((c = getchar()) != '\n') s2[i++] = c; /*shorter*/
  s2[i] = '\0';

  printf("Write a string: s3 = ");
  i = 0;
  while ((c = getchar()) != '\n') s3[i++] = c; /*shorter*/
  s3[i] = '\0';

  str_concat(s1, s2);
  printf("We can concatenate s1 and s2 -> : %s \n", s1 );

  printf("Now, write a character you want to delete from this strings: ");
  squeeze( s1, (c = getchar()) );
  printf("The result is the following %s \n", s1 );


  squeeze_all( s1,s3 );
  printf("We can also delete all the characters of s3 found in this laste one : %s \n", s1 );






  return 0;
}


void str_concat( char s1[], char s2[]){
  int i,j;
  i = j = 0;

  while( s1[i] != '\0' )
    ++i;                       /*Find length of i,
                              whe do not write the increment in the condition to avoid the \0  in the string*/
  while ((s1[i++] = s2[j++]) != '\0' );
}

void squeeze(char s[], char c) {
  int i,j ;

  for (i = j = 0; s[i] != '\0'; i++)
    if( s[i] != c)
      s[j++] = s[i];   /*We copy the string in itself only for the characters different from c*/
  s[j] = '\0'; /*We declare once again the final element of the string */
}

void squeeze_all(char s1[], char s2[]) {
  int i,j,k ;

  for(k = 0; s2[k] != '\0'; k++){ /*We only need to add another loop for the characters c = s2[k];
                                    Probably it is innefficient since we repeat the algorithm several times*/
    for (i = j = 0; s1[i] != '\0'; i++){
      if( s1[i] != s2[k])
        s1[j++] = s1[i];
      }   /*We copy the string in itself only for the characters different from c*/
    s1[j] = '\0'; /*We declare once again the final element of the string */
    }
  }

  int any(char s1[], char s2[]){
    int i,j, lowest, new_lowest ;
    int found = 0;

    lower = new_lower = MAXSIZE-1;

    for(i = 0; s2[i] != '\0'; i++){
      for (j = 0; s1[j] != '\0' && s1[i] == s2[j]; i++){  /*If we have a match in the characters*/
        new_lowest = i;
        if( new_lowest < lowest){       /*Compare which is smaller*/
          lowest = new_lowest;
          found++;
        }
      }
    }
    if( found == 0) lowest = -1;
    return lowest;
  }
