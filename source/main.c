#include <stdlib.h>
#include <stdio.h>

#include "mainMenu.h"

int main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "Nie podales plikow do obliczania wielomianow!!!");
        exit(EXIT_FAILURE);
    }

    mainMenu(argv[1], argv[2]);

    exit(EXIT_SUCCESS);
}