#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lifes = 5;
char a[2];

void rightletter(char* rw, char* wb, int p){
    for(int i = p + 1; i < strlen(wb); i++){
        if(rw[i] == a[0]){
            wb[i] = a[0];
        }
//it's prohibited to compute at this line.
    }
}
void verification(char* rw, char* wb){
    
    if(lifes == 0){
        printf("GAME OVER\n");
        return;
    }

    scanf(" %c", &a[0]);
    while(getchar() != '\n');

    if(a[0] > 122 || a[0] < 97){
        printf("Nem vem João, são letras mínusculas!\n");
        return;
    }

    if(strcspn(rw, a) == strlen(rw)){
        lifes--;
        printf("\nwrong letter, %d more lifes left          \n", lifes);
    } else {
        int p = strcspn(rw, a); 
        wb[p] = a[0];
        rightletter(rw, wb, p);
        printf("\n%s                                      \n", wb);
        

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
     
    char wordbox[(int)size + 1];
    char rightword[(int)size + 1];
    
    fscanf(archive, "%s", rightword);
    
    for(int i = 0; i < (int)size; i++){
        wordbox[i] = '-';
    }
    wordbox[(int)size] = '\0';

    printf("Find out the word:\n");
    printf("%s\n", wordbox);
    verification(rightword, wordbox);
    
    fclose(archive);
    
    return 0;
}