#include "matrix.h"

int** loadMatrix(char filename[MAX], int *row, int *column){
    FILE* file;

    char* line = NULL;
    char* endptr;

    char tempChar[25];

    int** array = 0;

    int countRow = 0;
    int countColumn = 0;

    int j = 0;

    size_t length = 0;
    ssize_t read = 0;

    file = fopen(filename, "r");

    while ((read = getline(&line, &length, file)) != -1) {
        for(int i = 0; i < strlen(line); i++){
            if(line[i] != ','){
                if(countRow == 0) countColumn++;
            }
        }
        countRow++;
    }

    rewind(file);

    array = (int**)malloc( countRow * sizeof(*array));
    if(array == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < countRow; i++){
        array[i] = (int*)malloc( (countColumn - 1) * sizeof(int));
        if(array[i] == NULL){
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < (countColumn - 1); j++){
            fscanf(file, "%d,", &array[i][j]);
        }
    }

    fclose(file);

    *row = countRow;
    *column = countColumn;

    return array;
}

static void freeMatrix(int **array, size_t size){
    for(int i = 0; i < size; i++){
        free(array[i]);
    }
    free(array);
}

void addMatrixs(){
    char matrix1[MAX] = {0};
    char matrix2[MAX] = {0};

    int row1 = 0, column1 = 0;
    int row2 = 0, column2 = 0;

    int** array1;
    int** array2;
    int** array3;

    fprintf(stdout, "Podaj plik z pierwsza macierza: ");
    fgets(matrix1, MAX, stdin);
        int len=strlen(matrix1);
        if(matrix1[len-1]=='\n')
            matrix1[len-1]='\0';

    fprintf(stdout, "Podaj plik z druga macierza: ");
    fgets(matrix2, MAX, stdin);
        len=strlen(matrix2);
        if(matrix2[len-1]=='\n')
            matrix2[len-1]='\0';

    array1 = loadMatrix(matrix1, &row1, &column1);
    array2 = loadMatrix(matrix2, &row2, &column2);

    if((row1 != row2) && (column1 != column2)){
        fprintf(stderr, "Wrong matrix sizes!");
        return;
    }

    array3 = (int**)malloc( row1 * sizeof(*array3));
    if(array3 == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < row1; i++){
        array3[i] = (int*)malloc( (column1 - 1) * sizeof(int));
        if(array3[i] == NULL){
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < column1 - 1; j++){
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }

    fprintf(stdout, "Suma macierzy to: \n");

    for(int i = 0; i < row2; i++){
        for(int j = 0; j < column2 - 1; j++){
            fprintf(stdout, "%d ", array3[i][j]);
        }
        fprintf(stdout,"\n");
    }

    freeMatrix(array1, row1);
    freeMatrix(array2, row1);
    freeMatrix(array3, row1);
}

void multiplicationMatrix(){
    char matrix1[MAX] = {0};
    char matrix2[MAX] = {0};

    int row1 = 0, column1 = 0;
    int row2 = 0, column2 = 0;

    int** array1;
    int** array2;
    int** array3;

    fprintf(stdout, "Podaj plik z pierwsza macierza: ");
    fgets(matrix1, MAX, stdin);
        int len=strlen(matrix1);
        if(matrix1[len-1]=='\n')
            matrix1[len-1]='\0';

    fprintf(stdout, "Podaj plik z druga macierza: ");
    fgets(matrix2, MAX, stdin);
        len=strlen(matrix2);
        if(matrix2[len-1]=='\n')
            matrix2[len-1]='\0';

    array1 = loadMatrix(matrix1, &row1, &column1);
    array2 = loadMatrix(matrix2, &row2, &column2);

    if((column1-1) != row2){
        fprintf(stderr, "Wrong matrix sizes!");
        return;
    }

    array3 = (int**)malloc( row1 * sizeof(*array3));
    if(array3 == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < row1; i++){
        array3[i] = (int*)calloc((column2 - 1),sizeof(int));
        if(array3[i] == NULL){
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < column2 - 1; j++){
            array3[i][j] = 0;
        }
    }

    for(int i = 0; i < row1; i++){
        for(int j = 0; j < column2 - 1; j++){
            for(int k = 0; k < column1 - 1; k++){
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }

    fprintf(stdout, "Iloczyn macierzy to: \n");

    for(int i = 0; i < row2; i++){
        for(int j = 0; j < column2 - 1; j++){
            fprintf(stdout, "%d ", array3[i][j]);
        }
        fprintf(stdout,"\n");
    }

    freeMatrix(array1, row1);
    freeMatrix(array2, row1);
    freeMatrix(array3, row1);
}