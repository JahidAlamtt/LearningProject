#include <stdio.h>
#include <stdlib.h>

int main()
{
char text[50] = {'E','a','r','t','h',' ','W','i','t','h','o','t',' ','A','r','t',' ','i', 't', ' ','j','u','s','t',' ','E',' ','&',' ', 'H','.',};
int i;
for (i=0; i<32 ; i++){
    printf("%c", text[i] );
}

}
