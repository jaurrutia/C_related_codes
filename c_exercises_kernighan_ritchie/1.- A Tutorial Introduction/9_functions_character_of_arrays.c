/*Jonathan Urrutia 2020/10/21
Ninth example. Functions withs arrays: This are not called by value, so every effect on the function it it tracked y the array.
Excercises 1-16,17
*/


#include <stdio.h>
#define MAXLINE 1000                       /*Maximum input line size*/

int get_line( char line[], int maxline);    // I had to change getline (as in the book) to get_line due to declaration problemns related to the stdio.h library
int get_line_arbitrary( char line[], int maxline);
void copy(char to[], char from[]);

/*Print the longest input line*/
int main()
{
  int  len, max;                          /*Current line length, maximum length so far*/
  char line[MAXLINE], longest[MAXLINE];   /*Current input line and  longest line input*/

  max = 0;
  while((len = get_line(line,MAXLINE)) > 0){
    if(len >= 80){
      printf("This line has more than 80 characters:\n %s\n", line );
    }
    if (len > max){
      max = len;
      copy( longest, line);
    }
  }
  if (max > 0 )                            /*lines have at least one char so max > 0 is equivalent to 'There is a line'*/
    printf("\n\n\n The longest line has %d characters and it is:\n %s\n", max, longest );

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

/* copy: a array into another array*/
void copy( char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
