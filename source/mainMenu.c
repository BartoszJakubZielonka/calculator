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
            loadMatrix("matrix_1.txt");
            break;

            case 4:
            //TODO
            fprintf(stdout, "\n%d\n", tempChoice);
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

int** loadMatrix(char filename[MAX]){
    FILE* file;

    char* line = NULL;

    char tempChar[25];

    int** array;

    int countTemp = 0;
    int countRow = 0;
    int countColumn = 0;

    size_t length = 0;
    ssize_t read = 0;

    file = fopen(filename, "r");

    while ((read = getline(&line, &length, file)) != -1) {
        if(line[strlen(line)-1]=='\n')
            line[strlen(line)-1]='\0';
        if(countTemp == countRow){
            size_t newCount = (countRow + 1);
            int **newPtr = (int**)realloc(array, newCount * sizeof(*array));
            if(newPtr == NULL){
                freeMatrix(array, countRow);
                exit(EXIT_FAILURE);
            }
            countRow = newCount;
            array = newPtr;
        }
        for(int i = 0; i < strlen(line); i++){
            if(line[i] != ','){
                if(countColumn == 0){

                }
            }
        }
    
        countTemp++;
    }

    fclose(file);

    return "";
}

static void freeMatrix(int **array, size_t size);