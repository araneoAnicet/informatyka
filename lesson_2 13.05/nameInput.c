#include <stdio.h>

int main(){
    char userName[30];
    char userSurname[30];

    printf("Name: ");
    scanf("%s", userName);
    printf("Surname: ");
    scanf("%s", userSurname);
    printf("%s ", userName);
    printf("%s\n", userSurname);

    return 0;
}
