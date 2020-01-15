#include "mainMenu.h"

void mainMenu(){
    char choice[MAX] = {0};
    char *endptr;

    fprintf(stdout, "Witaj! w nietypowym kalkulatorze\n");

    while(1){
        fprintf(stdout, "Wybierz jedna z podanych funkcji:\n1.Przelicz na systemy liczobwe\n2.Znajdz miejsca zerowe wielomianu\n3.Przemnoz Macierze\n4.Dodaj dwie macierze\nK lub k aby wyjsc\n");
        fgets(choice, MAX, stdin);
        int len=strlen(choice);
        if(choice[len-1]=='\n')
            choice[len-1]='\0';
        
        if((strcmp(choice, "k") == 0) || (strcmp(choice, "K") == 0)) break;

        int tempChoice = strtol(choice, &endptr, DECIMAL);

        switch(tempChoice){
            case 1:
            systemConvert();
            break;

            case 2:
            //TODO
            fprintf(stdout, "\n%d\n", tempChoice);
            break;

            case 3:
            multiplicationMatrix();
            break;

            case 4:
            addMatrixs();
            break;

            case 'k':
            case 'K':
            break;

            default:
            fprintf(stderr, "Nie znam opcji: %d\n", tempChoice);
            break;
        }
    }
}