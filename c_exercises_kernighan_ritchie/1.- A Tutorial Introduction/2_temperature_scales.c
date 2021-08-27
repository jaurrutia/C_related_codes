/*Jonathan Urrutia 2019/02/07
Second example. The use of variables is studied but only int and float are used.
We print a table of temperature in several scales.

Excercises 1-3,4,5 and something more.
*/

#include <stdio.h>

#define PI 3.141592624      /*This is a symbolic constant. NO SEMICOLON and by convention in capital letters. It is useful to define them for quantities we will not change*/
#define LIGHTSPEED 1        /*Speed of light in natural units....*/
                            /*These are useful to provide information to a person reading the code.*/
main()
{
  int  i, celsius;              /*Here we must declare all used variables.*/
  float fahr, kelvin;        /*float -> floating point (fractional part)*/
  int lower, upper, step;    /* int -> integer; so no decimals are taken into account*/
  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("Output using a while loop and 2 decimals \n\n\n");
  printf("C\t F\t K\n -------------------\n");
  while(celsius <= upper){
    fahr = celsius*(9./5.)+32.;
    kelvin = 273.15 + celsius;
    printf("%d\t%.2f\t%.2f\n", celsius, fahr, kelvin );  /*%d for int, %.2f for floats using only 2 digits after the point.*/
    celsius = celsius + step;
  }

  printf("\n\n\n Output using a for loop, 2 decimals\n but a wide of 10 characters for printing \n\n\n");
  printf("\t C\t F\t K\n \t-------------------\n");
  for(celsius = lower; celsius <= upper; celsius += step){
    fahr = celsius*(9./5.)+32.;
    kelvin = 273.15 + celsius;
    printf("%10d %10.2f %10.2f\n", celsius, fahr, kelvin );  /*%10.2f for floats using only 2 digits after the point and printing them in a 10 characters space.*/
  }

  printf("\n\n\n Output in reverse \n\n\n");
  printf("\t C\t F\t K\n \t-------------------\n");
  for(celsius = upper; celsius >= lower; celsius -= step){
    fahr = celsius*(9./5.)+32.;
    kelvin = 273.15 + celsius;
    printf("%10d %10.2f %10.2f\n", celsius, fahr, kelvin );  /*%10.2f for floats using only 2 digits after the point and printing them in a 10 characters space.*/
  }

  printf("\n\n\n Just a short example for the symbolic constants:\n");
  for(i = LIGHTSPEED; i<= PI; i++){
    printf("i = %d\n",i);
  }
}
