#include "polynomial.h"

float horner(float modulus[], int factor, float x){

    float result = modulus[0];

    for(int i = 1; i < factor+1; i++) result = result * x + modulus[i];

return result;
}

void polynomial(char* readFilename, char* saveFilename){
    int factor = 0;
    float prec = 0.0;
    float from = 0.0, to = 0.0;

    FILE* file;

    fprintf(stdout, "Podaj stopien wielomianu(masz 20): ");
    fscanf(stdin, "%d", &factor);

    while(factor >= 20){
        fprintf(stdout, "Podales zly stopien wielomianu\nPodaj jeszcze raz stopien wielomianu(masz 20): ");
        fscanf(stdin, "%d", &factor);
    }

    fprintf(stdout, "Podaj dokladnosc do obliczenia miejsc zerowych: ");
    fscanf(stdin, "%f", &prec);

    fprintf(stdout, "Podaj przedzial(w formacie od do): ");
    fscanf(stdin, "%f %f", &from, &to);

    float tempNumber = 0.0f;
    int iterator = 0;
    float* array = 0;

    file = fopen(readFilename, "r");
    if(file == NULL){
        fprintf(stderr, "Nie udalo sie otworzyc pliku: %s", readFilename);
        exit(EXIT_FAILURE);
    }

    while(fscanf(file, "%f,", &tempNumber) != EOF){
        iterator++;
        array = (float*)realloc(array, iterator * sizeof(float));
        if(array == NULL){
            fprintf(stderr, "Nie udalo zalokowac pamieci na wspolczyniki wielomianu", readFilename);
            exit(EXIT_FAILURE);
        }
        if(array == NULL) exit(EXIT_FAILURE);
        array[iterator-1] = tempNumber;
    }
    fclose(file);

    float* result = 0;
    int count = 0;
    result = findZero(array, prec, from, to, factor, &count);

    file = fopen(saveFilename, "w");
    if(file == NULL){
        fprintf(stderr, "Nie udalo sie otworzyc pliku: %s", saveFilename);
        exit(EXIT_FAILURE);
    }

    if(count == 0){
         fprintf(file, "brak miejsc zerowych w przedziale\n");
    }
    else{
        for(int i = 0; i < count; i++){
            fprintf(file, "%f\n", result[i]);
        }
    }

    fclose(file);

    free(result);
    free(array);

    fflush(stdin);
}

float* findZero(float modulus[], float prec, float from, float to, int factor, int *count){

    int it = 0;

    float previous = 0.0f;

    float* result = 0;

    for(float i = from; i < to; i += prec){
        float temp = horner(modulus, factor, i);

        if((temp == 0) || ((previous > 0) && (temp < 0)) || ((previous < 0) && (temp > 0))){
            it++;
            result = (float*)realloc(result, it * sizeof(float));
            if(result == NULL) exit(EXIT_FAILURE);
            result[it-1] = i;
        }
        
        previous = temp;
    }

    *count = it;
    return result;
}