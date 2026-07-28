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
  
 s1[] = "4";
 s2[] = "2";

printf("%d", any(s1,s2));




  return 0;
}



  int any(char s1[], char s2[]){
    int i,j, lowest, new_lowest ;
    int found = 0;

    lowest = new_lowest = MAXSIZE-1;

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
