# Scientific Programming in C for Physicists
## Self-Study Course: From Wolfram Language to Fredholm Integral Equations in Electromagnetic Scattering

This document consolidates the README content for all 20 weeks.

---

# Week 1 – Introduction to Scientific Programming

## Objectives
- Understand compiled vs interpreted languages.
- Install a C compiler.
- Compile and run a program.

## Wolfram Language
```wolfram
Print["Hello Physics!"]
```

## C
```c
#include <stdio.h>

int main() {
    printf("Hello Physics!\n");
    return 0;
}
```

## Assignment
Compile and execute the program.

---

# Week 2 – Variables and Numerical Precision

## Concepts
- int
- float
- double

## Wolfram Language
```wolfram
N[Pi,50]
```

## C
```c
#include <stdio.h>
#include <math.h>

int main() {
    double x = M_PI;
    printf("%.15f\n", x);
}
```

## Assignment
Compare precision with Wolfram Language.

---

# Week 3 – Loops

## Wolfram Language
```wolfram
Table[{x,Sin[x]},{x,0,1,0.1}]
```

## C
```c
#include <stdio.h>
#include <math.h>

int main() {
    for(double x=0;x<=1;x+=0.1)
        printf("%f %f\n",x,sin(x));
}
```

## Assignment
Generate a table and save it to a file.

---

# Week 4 – Functions

## Wolfram Language
```wolfram
f[x_] := Exp[-x^2]
```

## C
```c
#include <math.h>

double gaussian(double x){
    return exp(-x*x);
}
```

## Assignment
Evaluate the Gaussian function.

---

# Week 5 – Arrays

## Wolfram Language
```wolfram
Table[Sin[x],{x,0,10}]
```

## C
```c
#include <stdio.h>
#include <math.h>

int main(){
    double y[11];

    for(int i=0;i<11;i++)
        y[i]=sin(i);

    return 0;
}
```

---

# Week 6 – Numerical Differentiation

## Theory
Forward difference approximation.

## Wolfram Language
```wolfram
D[Sin[x],x]
```

## C
```c
double derivative(double x,double h){
    return (sin(x+h)-sin(x))/h;
}
```

## Assignment
Compare with cos(x).

---

# Week 7 – Numerical Integration

## Rectangle Rule

## Wolfram Language
```wolfram
NIntegrate[Sin[x],{x,0,Pi}]
```

## C
```c
double integrate(int N){
    double a=0,b=3.141592653589793;
    double h=(b-a)/N;
    double sum=0;

    for(int i=0;i<N;i++){
        double x=a+i*h;
        sum += sin(x)*h;
    }
    return sum;
}
```

---

# Week 8 – Simpson's Rule

## C
```c
double simpson(int N){
    double a=0,b=M_PI;
    double h=(b-a)/N;
    double s=0;

    for(int i=0;i<=N;i++){
        double x=a+i*h;

        if(i==0 || i==N)
            s += sin(x);
        else if(i%2==0)
            s += 2*sin(x);
        else
            s += 4*sin(x);
    }

    return h*s/3.0;
}
```

---

# Week 9 – Matrices

## C
```c
double A[3][3];
double B[3][3];
double C[3][3];
```

## Assignment
Implement matrix multiplication.

---

# Week 10 – Gaussian Elimination

## Theory
Solve Ax=b.

## C
Implement Gaussian elimination for a 3×3 system.

## Assignment
Compare against Mathematica's LinearSolve.

---

# Week 11 – Modular Programming

## File Structure
```text
main.c
integration.c
integration.h
```

## Header Example
```c
double trapezoidal(double a,double b,int N);
```

---

# Week 12 – Makefiles

## Example
```make
CC=gcc
CFLAGS=-O2

main: main.c
	$(CC) main.c -o main
```

## Assignment
Automate compilation.

---

# Week 13 – Git and GitHub

## Topics
- Commit
- Branch
- Pull request
- README

## Assignment
Create a repository and document one numerical method.

---

# Week 14 – Electromagnetic Scattering

## Theory
Rayleigh scattering.

## Wolfram Language
```wolfram
Plot[x^4,{x,0,1}]
```

## C
```c
double sigma(double k){
    return pow(k,4);
}
```

---

# Week 15 – Green Functions

## Theory
One-dimensional Green function.

## C
```c
#include <math.h>

double G(double x,double xp,double k){
    return exp(-k*fabs(x-xp));
}
```

---

# Week 16 – Fredholm Integral Equations

## Equation
u(x)=f(x)+λ∫K(x,t)u(t)dt

## Assignment
Study examples from Atkinson and Kress.

---

# Week 17 – Nyström Discretization

## Theory
Replace integral by weighted sums.

## C
```c
A[i][j] = w[j]*K(x[i],x[j]);
```

---

# Week 18 – Matrix Assembly

## Theory
Construct the linear system.

## C
```c
A[i][j] = delta - lambda*w[j]*K(x[i],x[j]);
```

## Assignment
Build matrix automatically.

---

# Week 19 – Linear Solvers

## LAPACK Example
```c
#include <lapacke.h>
```

## Assignment
Solve benchmark Fredholm equations.

---

# Week 20 – Electromagnetic Scattering Project

## Final Equation

E(r)=Einc(r)+k²∫G(r,r')χ(r')E(r')dr'

## Tasks
1. Discretize domain.
2. Build Green matrix.
3. Assemble Fredholm matrix.
4. Solve linear system.
5. Plot scattered field.

---

# Recommended Literature

1. The C Programming Language – Kernighan & Ritchie
2. C Programming: A Modern Approach – K. N. King
3. Numerical Recipes in C
4. Scientific Computing – Michael Heath
5. Linear Integral Equations – Rainer Kress
6. Numerical Solution of Integral Equations of the Second Kind – Kendall Atkinson
7. Absorption and Scattering of Light by Small Particles – Bohren & Huffman
8. Principles of Nano-Optics – Novotny & Hecht
9. Field Computation by Moment Methods – Harrington

---

# Open Source Libraries

## GSL
https://www.gnu.org/software/gsl/

## LAPACK
https://www.netlib.org/lapack/

## BLAS
https://www.netlib.org/blas/

## FFTW
https://www.fftw.org/

---

# Suggested Final Repository Structure

```text
scientific-programming-c/
│
├── README.md
├── syllabus/
├── week01/
├── week02/
...
├── week20/
│
├── examples/
├── exercises/
├── solutions/
│
└── project/
    └── fredholm-scattering/
```
