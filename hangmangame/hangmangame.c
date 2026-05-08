#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lifes = 5;
char a[1];
void verification(char* rw, char* wb){

    if(lifes == 0){
        printf("GAME OVER\n");
        return;
    }
// it's prohibiten to compute at this line
    scanf(" %c", a);

    if(strcspn(rw, a) == strlen(rw)){
        lifes--;
        printf("%s\n", wb);
        printf("wrong letter, %d more lifes left\n", lifes);
    } else {
        wb[strcspn(rw, a)] = a[0];
        printf("%s\n", wb);

        if(strcspn(wb, "-") == strlen(wb)){
            printf("CONGRATULATION, YOU WON!\n");
            return;
    }
    }
    verification(rw, wb);
}

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("usage ./a.out [file]\n");
        return 1;
    }

    FILE *archive = fopen(argv[1], "r");
    if(archive == NULL){
        printf("Error, cannot open file\n");
        return 1;
    }
    
    fseek(archive, 0, SEEK_END);
    long size = ftell(archive);
    rewind(archive);
     
    char wordbox[(int)size];
    char rightword[(int)size];
    
    fscanf(archive, "%s", rightword);
    
    for(int i = 0; i < (int)size; i++){
        wordbox[i] = '-';
    }
    printf("Find out the word:\n");
    printf("%s\n", wordbox);
    verification(rightword, wordbox);
    fclose(archive);
    return 0;
}