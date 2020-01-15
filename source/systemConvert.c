#include "systemConvert.h"

void systemConvert(){
    char system[MAX] = {0};
    char number[MAX] = {0};
    char prec[MAX] = {0};
    char integral[MAX] = {0};
    char fractional[MAX] = {0};

    char* endptr;

    int tempSystem = 0;
    int tempPrec = 0;

    double decimal = 0;

    fprintf(stdout, "W jakim formacie podajesz liczbe?(dostepne 2, 8, 10, 16): ");
    fgets(system, MAX, stdin);
    tempSystem = strtol(system, &endptr, DECIMAL);

    fprintf(stdout, "Podaj liczbe(w formacie calkowita.ulamkowa): ");
    fgets(number, MAX, stdin);
    int len=strlen(number);
    if(number[len-1]=='\n')
        number[len-1]='\0';

    fprintf(stdout, "Podaj precyzje: ");
    fgets(prec, MAX, stdin);
    tempPrec = strtol(prec, &endptr, DECIMAL);

    decimal = anyToDecimal(number, tempSystem);
    if(tempSystem != DECIMAL) fprintf(stdout, "Liczba w systemie %d to %f\n", DECIMAL, decimal);
    if(tempSystem != BINARY) decimalToAny(decimal, BINARY, tempPrec);
    if(tempSystem != OCTAL) decimalToAny(decimal, OCTAL, tempPrec);
    if(tempSystem != HEXADECIMAL) decimalToAny(decimal, HEXADECIMAL, tempPrec);
}

double anyToDecimal(char* number, int system){
    double decimal = 0.0;
    double fracDecimal = 0.0;
    double position = 1.0;

    int length = strlen(number);
    int dotPosition = 0;

    char* dotPositionPointer;
    

    dotPositionPointer = strchr(number, '.');

    if(dotPositionPointer == NULL)
        dotPosition = length;
    else
        dotPosition = dotPositionPointer-number+1;

    for(int i = dotPosition - 2; i >= 0; --i){
        decimal += getIntegralValue(number[i]) * position;
        position *= system;
    }

    position = system; 
    for (int i = dotPosition; i < length; i++){
        fracDecimal += getIntegralValue(number[i]) / position;
        position *= system;
    }

    return decimal + fracDecimal;
}

void decimalToAny(double number, int system, int prec){
    int i = 0;
    int length = 0;
    int integral = number;
    double frac = number - integral;

    double positon = 1.0;

    char* result, *reversResult;

    positon = 1.0;

    result = (char*)malloc(sizeof(char) * MAX);
    reversResult = (char*)malloc(sizeof(char) * MAX);

    while(integral){
        result[i] = getCharValue((integral % system));
        integral /= system;
        i++;
    }

    result[i] = '\0';

    length = strlen(result);

    int end = i - 1;

    for (int j = 0; j < i; j++) {
      reversResult[j] = result[end];
      end--;
   }

    reversResult[i] = '.';
    i++;
    reversResult[i] = '\0';

    while(prec--){
        frac *= system;
        int temp = frac;

        if(temp != 0){
            frac -= temp;
            reversResult[i] = getCharValue(temp);
        }else{
            reversResult[i] = getCharValue(0);
        }

        i++;
    }

    reversResult[i] = '\0';

    fprintf(stdout, "Liczba w systemie %d to %s\n", system, reversResult);
}

int getIntegralValue(char character){
    if(character >= 'A' && character <= 'F')
        return (10 + character - 'A');
    else if(character >= '0' && character <= '9')
        return (character - '0');

    return 0;
}

char getCharValue(int number){
    if( number >= 0 && number <= 9)
        return ('0' + number);
    else if(number >= 10 && number <= 15)
        return ('A' + number - 10);
    
    return ' ';
}