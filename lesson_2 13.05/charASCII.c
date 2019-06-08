#include <stdio.h>

int main(){
    char userInput;
    int codeDelatation;
    printf("Your character: ");
    scanf("%c", &userInput);
    //getc(userInput);
    printf("Result: %c\n", userInput);
    printf("ASCII code: %d\n", userInput);
    printf("Your ASCII encoding delatation: ");
    scanf("%d", &codeDelatation);
    printf("With ASCII delatation: %d\n", userInput + codeDelatation);
    printf("Character after delatation: %c\n", userInput + codeDelatation);
    return 0;
}