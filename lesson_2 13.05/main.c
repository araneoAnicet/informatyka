#include <stdio.h>
#include <stdlib.h>

int main(){
    int nameBuffer = 40;
    char userInput[nameBuffer];
    int rows, columns = nameBuffer;
    printf("Amount of students: ");
    scanf("%d", &rows);
    char names[rows][columns];
    float marks[rows];

    int i;
    for (i = 0; i < rows; i++){
        printf("Name: ");
        fflush(stdin);
        scanf("%s", names[i]);
        printf("Mark: ");
        scanf("%f", &marks[i]);
    }
    
    //Monitoring 
    for (i = 0; i < rows; i++){
        printf("%s: %f\n", names[i], marks[i]);
    }
    
    
    printf("Search name: ");
    fflush(stdin);
    scanf("%s", userInput);

    for (i = 0; i < rows; i++){
        if ( !strcmp(userInput, names[i]) ){
            printf("Student's mark: %f", marks[i]);
            break;
        }
    }
}
