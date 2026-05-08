#include <stdio.h>
#include <stdlib>
#include <string.h>

int lifes = 5
char a[1];
void verification(char* rw, char* wb){
    printf("%s", wb)
    if(lifes = 0){
        printf("GAME OVER\n");
        return;
    }

    scanf("%c", &a[0]);

    if(strcspn(rw, a) == strlen(rw)){
        lifes--;
        printf("wrong letter, %d more lifes left\n\n")
    } else {
        wb[strcspn(rw, a)] = a[0];
        printf("%s", wb);
    }

    
    if(strcspn(wb, '_') == strlen(wb){
        printf("CONGRATULATION, YOU WON!\n");
        return:
    }
    verification(rw,wb);
}










int main(void){

    FILE *archive = fopen("argv[1]", "r");
    if(archive == NULL){
        printf("Error, cannot open file");
        return 1;
    }
    
    fseek(archive, 0, SEEK_END);
    long size = ftell(archive);
    rewind(archive);
     
    char wordbox[(int)size];
    char rightword[(int)size];
    fscanf(archive, "%s", rightword);
    
    for(int i = 0, i < (int)size, i++){
        wordbox[i] = '_';
    }

    verification(rightword, wordbox);
    fclose(archive);
    return 0;
}