/*Jonathan Urrutia 2020/10/21
Ninth example. Functions withs arrays: This are not called by value, so every effect on the function it it tracked y the array.
Excercises 1-17, 18, 19
*/

#include <stdio.h>
#define MAXLINE 1000
#define CHARTOP 80

int get_line_arbitrary( char line[], int maxline);
int remove_blanks(char s[]);
void copy(char to[], char from[]);
void reverse_copy(char to[], char from[], int len);

int main(){
  int len, new_len;
  char line[MAXLINE], rev_line[MAXLINE];

  printf("This is the text without trim blanks and lines over 80 characters. we also write its revered version:\n" );
  while ((len = get_line_arbitrary(line,MAXLINE)) > 0) {  /*While there's a line*/
    new_len = remove_blanks(line);
    printf("\n\n The original line had %d charaters and the new one has %d.\n", len, new_len );
    if (new_len  > CHARTOP){
      printf("%s", line );
      reverse_copy(rev_line , line, new_len);
      printf("%s", rev_line);
    }
  }

return 0;
}


/*Functions we will use*/
int get_line_arbitrary( char s[], int lim)
{
  int c, i, j;

  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) // i -> # in the array that is either EOF or \n
    if (  i < lim - 2){
      s[j] = c;
      ++j;
    }
  if( c == '\n'){                     // if  i is related to a \n wi will add one more
    s[j] = c;
    ++j;
    ++i;
  };
  s[j] = '\0';                        // We change its value to \0 -> This is a C convention indicating that \0 is not part of the text.
  return i;                           // Output = character number in the file that is the first line skip
}

int remove_blanks( char s[])
{
  int i;

  i = 0;
  while (s[i] != '\n')   /*Find new line*/
    ++i;
  --i;                    /*Character just before the new line*/

  while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) /*If blank space*/
    --i;
  if( i >= 0){ /*We set the new line and finish it w/o the rests of the blanks*/
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';
  }
  return i; /*We return the new length*/
}


/* reverse the string under the asumption of knowing it's length*/
void reverse_copy( char to[], char from[], int len){
  int i;
  i = 0;
  while((to[len-2-i] = from[i]) != '\n')
    ++i;
  to[len-1] = '\n';
  to[len] = '\0';
}
