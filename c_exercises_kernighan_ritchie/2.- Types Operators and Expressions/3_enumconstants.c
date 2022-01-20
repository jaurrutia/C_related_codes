/*Jonathan Urrutia 2022/01/19
We study the enum definition, an alternative to #define
https://www.geeksforgeeks.org/enumeration-enum-c/
*/

#include <stdio.h>

/*enum   flong{constant1, constant2,...}, by default they start in 0 an increase by 1*/
enum days {MON, TUE, WED, THU, FRI, SAT, SUN};
/*We can choose the data values*/
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
enum escapes {BELL = '\a', BACKSPACE = '\b', TAB = '\t'};

int main(){

int i;  /*This is evaluated by deafault with a 'garbage' value*/
const int year = 2022;  /*This kind of definition avoids any change in the varuable's value. It becomes a read-only */
enum days day_of_week = TUE;  /*We can declare bareables for each category or not, depending on how we use them*/

while( day_of_week <= FRI){
  printf("The day corresponds to the number %d %c of the month %d of the year %d\n", day_of_week, TAB, JAN, year);
  ++ day_of_week;
}
 return 0;
}
