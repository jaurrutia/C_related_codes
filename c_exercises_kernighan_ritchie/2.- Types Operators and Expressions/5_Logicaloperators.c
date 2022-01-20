/*Jonathan Urrutia 2020/10/21
Ninth example. Functions withs arrays: This are not called by value, so every effect on the function it it tracked y the array.
Excercises 1-16,17
*/


#include <stdio.h>
#define MAXLINE 1000                       /*Maximum input line size*/

int get_line( char line[], int maxline);    // I had to change getline (as in the book) to get_line due to declaration problemns related to the stdio.h library
int get_line_no_logical_op( char line[], int maxline);    // I had to change getline (as in the book) to get_line due to declaration problemns related to the stdio.h library

/*Print the longest input line*/
int main()
{
  int  len;                          /*Current line length, maximum length so far*/
  char line[MAXLINE], longest[MAXLINE];   /*Current input line and  longest line input*/

  printf("This are the lengths of the algorithm with operator:\n");
  while((len = get_line(line,MAXLINE)) > 0){
    printf("%d\n",len );
     };

  printf("\n This are the lengths of the algorithm without operator:\n");
  while((len = get_line_no_logical_op(line,MAXLINE)) > 0){
     printf("%d\n",len );
      };

return 0;
}


/*Functions we will use*/

/*get_line: read a line into s, returns its length*/
int get_line( char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) // i -> # in the array that is either EOF or \n
    s[i] = c;

  if( c == '\n'){                     // if  i is related to a \n wi will add one more
    s[i] = c;
    ++i;
  };
  s[i] = '\0';                        // We change its value to \0 -> This is a C convention indicating that \0 is not part of the text.
  return i;                           // Output = character number in the file that is the first line skip
}

/*get_line: read a line into s, returns its length*/
int get_line_no_logical_op( char s[], int lim)
{
  int c, i = 0, inside = 1;

  while( inside == 1){
    if (i >= lim -1 ) ++inside;
    else if ( (c = getchar()) == '\n') ++ inside;
    else if(c == EOF) ++inside;
    else {
      s[i] = c;
      ++i;
    }
  }

  if( c == '\n'){                     // if  i is related to a \n wi will add one more
    s[i] = c;
    ++i;
  };
  s[i] = '\0';                        // We change its value to \0 -> This is a C convention indicating that \0 is not part of the text.
  return i;                           // Output = character number in the file that is the first line skip

}

                     // Output = character number in the file that is the first line skip
