#include "mainMenu.h"

void mainMenu(char* readFilename, char* saveFilename){
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
            polynomial(readFilename, saveFilename);
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

void polynomial(char* readFilename, char* saveFilename){
    double factor = 0.0;
    double prec = 0.0;
    double from = 0.0, to = 0.0;

    FILE* file;

    fprintf(stdout, "Podaj stopien wielomianu(masz 20): ");
    fscanf(stdin, "%f", &factor);

    while(factor >= 20.0){
        fprintf(stdout, "Podales zly stopien wielomianu\nPodaj jeszcze raz stopien wielomianu(masz 20): ");
        fscanf(stdin, "%f", &factor);
    }

    fprintf(stdout, "Podaj dokladnosc do obliczenia miejsc zerowych: ");
    fscanf(stdin, "%f", &prec);

    fprintf(stdout, "Podaj przedzial(w formacie od,do): ");
    fscanf(stdin, "%f,%f", &from, &to);

    int tempNumber = 0, iterator = 0;
    int* array = 0;

    file = fopen(readFilename, "r");
    while(fscanf(file, "%d,", &tempNumber) != EOF){
        iterator++;
        array = (int*)realloc(array, iterator * sizeof(int));
        if(array == NULL) exit(EXIT_FAILURE);
        array[iterator-1] = tempNumber;
    }
    fclose(file);

    for(int i = 0; i < iterator; i++){
        fprintf(stdout, "%d ", array[i]);
    }

    file = fopen(saveFilename, "w");
    fclose(file);
}