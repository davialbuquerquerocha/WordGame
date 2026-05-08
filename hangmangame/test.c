#include <stdio.h>
#include <string.h>

int main(void){
    char a[1];
    char d = 'y';
    a[0] = d;
    char b[10] = "way so";

    int c = strcspn(b, a);
    printf("%d\n", c);
return 0;
}