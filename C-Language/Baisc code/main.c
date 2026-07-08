#include <stdio.h>
#include <stdlib.h>

int main()
{
  int number[6], i;
  number[0]= 100;
  number[1]= 200;
  number[2]= 300;
  number[3]= 400;
  number[4]= 1500;



  for( i = 0; i < 5 ; i++){
    printf("*%d", number[i]);

    if(i == 4 ){
        break;
    }
     printf(", ");
  }

// printf("*%d , #%d, %d#, %d*, *%d", number[0],number[1],number[2],number[3],number[4]);

}
