/*
Jonathan Urrutia 2020/10/26
Firs steps in C++

To run it on terminal we use

g++ "fileName"
then we will open it with
./a.out

Another way to do it is as follow

g++ -o outputname filename.cpp
./outputname


*/

#include <iostream> //Input Output STRAMing
#include <cmath>
#include <string>

int main( int argc, char* argv[]){
  // print to the screen smthing
  double x = 1.0, y = 2.0; //Declaration of float's with double precission
  double z, u = -3.4;
  int i, j;

  // The arrays ar declares as in C, but we may inizialize them with a matematica-like syntax:
  int array[2][3] = {{1,6,4},{2,2,2}}; //Only works at this time. Otherwirse we need to assign the values ony by one.

  // We have boolean variables
  bool flag1, flag2;
  flag1 = true;
  flag2 = false;

  std::cout << "Some examples with the cmath library\n"; //cout = Console OUTput

  z = x/y; // division
  z = x*y; // multiplication
  z = sqrt(x); // square root
  z = exp(y); // exponential function
  z = pow(x, y); // x to the power of y
  z = M_PI; // z stores the value of pi

  x = 7.8;
  y = 1.65;

  z = fmod(x, y); // remainder when x is divided by y
                  // z is 1.2 since 7.8 = 4*1.65 + 1.2
  z = atan2(y, x); // inverse tangent (in radians) of
                  // angle between the vector
                  // (x, y) and the positive x-axis
                  // note the ordering of y and x in
                  // calling the function atan2
                  // z is 0.208465
  z = fabs(u);    // Absolute value of u
                  // z is 3.4
                  // note fabs should not be confused
                  // with abs (the integer equivalent)

// As in C we also have +=, -=, %= (for integers), *=, /= , a++, ++a, --a,a--.

  std::cout <<"One common mistake is the deivision by int i,j\n";
  i = 5;
  j = 2;
  z = i/j;
  std:: cout << "with i = " << i <<", j = "<< j << ", i/j = " << z <<"\n"; // printf also works here

  std::cout << "So, to make it work properly we have to transfor i and j as follows:\n";
  z = ((double) (i))/((double) (j));
  std::cout << " ((double) (i))/((double) (j)) = " << z <<"\n";


// For stringgs
  std::string city; // note the std::
  city = "Oxford"; // note the double quotation marks
  std::cout << "String length = " << city.length() << "\n";
  std::cout << "Third character = " << city.at(2) << "\n";
  std::cout << "Third character = " << city[2] << "\n";
  std::cout << city << "\n"; // Prints the string in city
  std::cout << city.c_str() << "\n"; // Also prints city

// Keyboard Input
  int account_number, pin;
  std::cout << "Enter your account number\n";
  std::cout << "and then your PIN followed by RETURN\n";
  std::cin >> account_number >> pin;

/*
  std::string name;
  std::cout << "Enter your name and then hit RETURN\n";
  std::getline(std::cin, name);
  std::cout << "Your name is " << name << "\n";
*/
  return 0;
}
