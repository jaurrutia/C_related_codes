/*Jonathan Urrutia 2020/10/26
Eleventh example. External variables
Until the last file, all our variables where local to each function: we needed to tell the function
under which element to operate. If we had 'scalars' we used the call by value schema and we operated
with a copy of the variable. For arrays this was not the case, yet, we nedded to tell the Functions
which strings we were working on.

Now, we will defie external variables so our functions will know where to operate w/o us telling them.
*/

#include <stdio.h>
#define MAXLINE 1000

/*External variables are defined ONCE outside the functions (and main) so the system stores them
They mus be declared in each function (and main) so the system access to them*/

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

/*Print longest line; specialized version*/
int main(){
  int len;
  extern int max;             // We declar them explicitli with the extern + type
  extern char longest[];

  max = 0;
  while ((len = get_line()) > 0)
      if (len > max){
        max = len;
        copy();
      }
  if( max > 0 ) /*If There is a line*/
    printf("%s", longest );

  return 0;
}

/*get_line specialized version*/
int get_line(void){
  int c, i;
  extern char line[];

  for( i = 0; i< MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
      line[i] = c;
  if( c == '\n'){
    line[i] = c;
    ++i;
  }
line[i] = '\0';
return i;
}

void copy(void){
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
  ++i;
}
