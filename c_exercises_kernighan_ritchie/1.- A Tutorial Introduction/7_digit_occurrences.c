/*Jonathan Urrutia 2019/02/11
Seventh example. Digit occurrences
We'll define a word as any sequence without a \t, ' ' or \n. and will learn how
the if statement works, as well as the constants

Excercises 1-13,14
*/

#include <stdio.h>

/*We will count digits, white spaces and others. Also  count the number of characters in a word and make the histogram*/
main()
{
  int c, i, j, nwhite, nother, nc_word,  max, max_nc;  /* charcater, indices, number of - spaces, -others, -char in a word and the max values  */
  int ndigit[10], length_words[100]; /*Array for the number of digits (0.1,...,9)*/

  nwhite = nother = nc_word = max =0;
  for (i=0;i<= 9; ++i)
    ndigit[i] = 0;
  for (i=0;i<=99; ++i)
      length_words[i] = 0;

  printf("We count digit of numbers and white spaces:\n");
  while((c = getchar()) != EOF){
    if(c >= '0' && c <= '9'){
      ++ndigit[c-'0'];
      ++nc_word;
    }else if (c == ' ' || c == '\n' || c == '\t'){
      ++nwhite;
      ++length_words[nc_word];
      nc_word = 0;
    }else{
      ++nother;
      ++nc_word;
    }
  }
  ++length_words[nc_word];  /*Ohterwise, the laste string w/o spaces is not counted*/

  printf("\n Number of digits white spaces (w) and others (o) is:");
  for(i=0; i<= 9; ++i){
    printf("\n %d -> %d ",i,ndigit[i] );
    for (j = 0; j< ndigit[i]; ++j)
      printf("-");
  }

  printf("\n w -> %d ",nwhite);
  for (j = 0; j< nwhite; ++j)
    printf("-");
  printf("\n o -> %d ",nother);
  for (j = 0; j< nother; ++j)
    printf("-");

    printf("\n Now we print frequency of the length of the words (strings separated by w):");

  for(i = 0; i <= 99; ++i){     /*we find the maximum number of chracters (max_nc) and its frequency (max)*/
      if(max < length_words[i]){
        max = length_words[i];
        max_nc = i;
      }
    }
      printf("%d %d \n", max, max_nc);

    for(i=0; i<= max_nc; ++i){
      printf("\n %d -> %d ",i,length_words[i] );
      for (j = 0; j< length_words[i]; ++j)
        printf("-");
    }
}
