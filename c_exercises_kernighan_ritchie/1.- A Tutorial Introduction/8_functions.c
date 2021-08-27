/*Jonathan Urrutia 2020/10/20
Eigth example. Defining a functions.
We'll define an exponentiation operator since it is not in the stdio.h library of
C.
We will also rewrite the 2_temperature_scale file so we use functions
We explore the call by value behavior of C functions
*/

# include <stdio.h>


int power(int m, int n); /* Let's call the functions
                            The functions are located usually at the end
                            of the file. This is called a prototype and
                            should be consisten with it's definition
                            at the end */
int power_ver2( int m, int n);
float t_fahrenheit(int celsius);
float t_kelvin(int celsius);

/* Lets test it*/
int main ()
{
  int  i;
  int lower, upper, step, celsius;
  lower = 0;
  upper = 300;
  step = 20;

  printf("\n\n\n Example for the power function defined by us: \n\n\n");
  for (i = 0; i < 10; ++i)
    printf("i = %d -> 2^i = %d, (-3)^i = %d\n", i, power(2,i), power(-3,i));

  printf("\n\n\n Example for the power function with the called by value approach: \n\n\n");
  for (i = 0; i < 10; ++i)
    printf("i = %d -> 2^i = %d, (-3)^i = %d\n", i, power_ver2(2,i), power_ver2(-3,i));


  printf("\n\n\n Temperature values in different scales \n\n\n");
  printf("\t C\t F\t K\n \t-------------------\n");
  for(celsius = lower; celsius <= upper; celsius += step)
    printf("%10d %10.2f %10.2f\n", celsius, t_fahrenheit( celsius ),  t_kelvin( celsius ) );

  return 0;
}






// Here we will write all our functions. They should be coherent with the prototypes.

int power(int base, int n) //Declaration fo the function
{                           //we raise the base to the nth power.
  int i, p;                 //All this variable are local and independent from the main.
  p = 1;                    //It is stated tht the output is an integer
                           // parameters -> into the parethesis
  for (i = 1; i <= n; ++i)  // C functions are Called by Value and they operates with local copies
    p = p*base;
  return p;
}

int power_ver2(int base, int n) // With this we take advantage of the called by value behavior.
{                               // The n is a local copy so I can modify it without problems i nthe main
  int p;                        // So I can avoid usinf the i and work directly with n in a reveres loop
  for( p = 1; n > 0; --n)
    p = p * base;
  return p;
}


float t_fahrenheit(int T)
{
  return T * (9. / 5.) + 32.;
}

float t_kelvin(int T)
{
  return T + 273.15;
}
