#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lifes = 5;
char a[2];
int t = 0;
char letters[26];


void rightletter(char* rw, char* wb, int p){
    for(int i = p + 1; i < strlen(wb); i++){
        if(rw[i] == a[0]){
//it's prohibited to compute at this line.            
            wb[i] = a[0];
        }
    }
}

void verification(char* rw, char* wb, char man[]){

    if(lifes == 0){
        man[30] = '\\';
        printf("%s", man);
        printf("\nG A M E   O V E R\n");
        printf("the word was [%s]\n", rw);
        return;
    }
    /*making the fork man
    if(lifes == 4){
        printf("%s", man);
    }*/

    scanf(" %c", &a[0]);
    printf("\033[H\033[J");
    fflush(stdout);
    while(getchar() != '\n');

    if(a[0] > 122 || a[0] < 97){
        printf("apenas letras mínusculas!\n");
        return;
    }
    letters[t] = a[0];
    t++;
    letters[t] = ' ';
    letters[t + 1] = '\0';
    if(strcspn(rw, a) == strlen(rw)){
        lifes--;
        man[20] = lifes == 4 ? '/' : man[20];
        man[21] = lifes == 3 ? '|' : man[21];
        man[22] = lifes == 2 ? '\\' : man[22];
        man[29] = lifes == 1 ? '/' : man[29];

        printf("%s", man);
        printf("\nwrong letter, %d more lifes left                  ( %s)\n", lifes, letters);

    } else {
        int p = strcspn(rw, a); 
        wb[p] = a[0];
        rightletter(rw, wb, p);
        printf("%s", man);
        printf("\n%s                                     ( %s)\n", wb, letters);
        

        if(strcspn(wb, "-") == strlen(wb)){
            printf("\nCONGRATULATION, YOU WON!        %d wrong letters\n", 5 - lifes);
            return;
    }
    }
    
    t++;
    verification(rw, wb, man);
}

int main(int argc, char* argv[]){

    char man[33] = "______\n|     O\n|       \n|     "; // 20 21 22 29 30

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

    printf("Welcome to HANGMAN GAME\n Enter only lowercase letters to figure out the word:\n");
    printf("%s\n", wordbox);
    verification(rightword, wordbox, man);
    
    fclose(archive);
    
    return 0;
}