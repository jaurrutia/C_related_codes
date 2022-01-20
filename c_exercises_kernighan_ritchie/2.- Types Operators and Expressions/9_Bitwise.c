/*Jonathan Urrutia 2022/01/20
*/

#include <stdio.h>


void dec2bi( int a, int aa[]);
void printbi (int aa[]);

int main(){
  int i;
  int a10, b10, a2[8], b2[8];
  int ab10, ab2[8];
  int abs10, abs2[16];

/*LEt us get tge numbers we sant to apply the operations to*/
  // printf("Enter an integer between 0 and 127: a = " );
  // scanf("%d\n", &a10 );  /*Ctl+D when finished*/
  // if( a10 > 127 || a10 < 0){
  //   printf("\n I said between 0 and 127: a = " );
  //   scanf("%d\n", &a10 );
  // }
  // dec2bi(a10, a2);
  // printf("\n In binary it equals to ");
  // printbi(a2);
  //
  // printf("\n Enter an integer between 0 and 127: b = " );
  // scanf("%d\n", &b10 );
  // if( b10 > 127 || b10 < 0){
  //   printf("\n I said between 0 and 127: b = " );
  //   scanf("%d\n", &b10 );
  // }
  // dec2bi(b10, b2);
  // printf("\n In binary it equals ");
  // printbi(b2);

  a10 = 10;
  b10 = 5;
  dec2bi(a10, a2);
  dec2bi(b10, b2);

  printf("\n\n %d & %d = %d \n\t\t", a10, b10, (ab10 = a10 & b10) );
  printbi(a2);
  printf("\n\t\t");
  printbi(b2);
  dec2bi(ab10, ab2);
  printf("\n\t\t--------\n\t\t");
  printbi(ab2);

  printf("\n\n %d | %d = %d \n\t\t", a10, b10, (ab10 = a10 | b10) );
  printbi(a2);
  printf("\n\t\t");
  printbi(b2);
  dec2bi(ab10, ab2);
  printf("\n\t\t--------\n\t\t");
  printbi(ab2);

  printf("\n\n %d ^ %d = %d \n\t\t", a10, b10, (ab10 = a10 ^ b10) );
  printbi(a2);
  printf("\n\t\t");
  printbi(b2);
  dec2bi(ab10, ab2);
  printf("\n\t\t--------\n\t\t");
  printbi(ab2);

  printf("\n\n ~ %d = %d \n\t\t", a10, (~a10)  );
  printbi(a2);
  dec2bi(127-a10, ab2);
  ab2[0] = 1;
  printf("\n\t\t--------\n\t\t");
  printbi(ab2);
  printf("\nThe first bit defines the sign of the integer 0-> +, 1-> -"
        "\n The negative numbers are actually ~ n + 1");


printf("\n");
return 0;
}

void dec2bi(int a, int aa[]) {
  int i ;
  for( i = 0; i<=7; ++i)
   aa[i] = 0;

  for( i = 7; a > 0 ; --i){
    aa[i] = a % 2;
    a = a / 2;
  }
}

void printbi( int aa[]){
  int i = 0;
  while( i <= 7) printf("%d", aa[i++]);
}
