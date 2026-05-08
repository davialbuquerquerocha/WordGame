#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lifes = 5;
char a[1];

void rightletter(char* rw, char* wb, int p){
    int index = strcspn(wb + p, a);
    index = index + p;
    if(index != strlen(wb)){
        wb[index] = a[0];
        printf("%s\n", wb);
        rightletter(rw, wb, index);
    }
}
void verification(char* rw, char* wb){

    if(lifes == 0){
        printf("GAME OVER\n");
        return;
    }

    scanf(" %c", a);

    if(strcspn(rw, a) == strlen(rw)){
        lifes--;
        printf("%s\n", wb);
        printf("wrong letter, %d more lifes left\n", lifes);
    } else {
        int p = strcspn(rw, a); 
        wb[p] = a[0];
        rightletter(rw, wb, p);
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