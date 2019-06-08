#include <stdio.h>

struct worker {
    char * name[40];
    char * surname[40];
    float workingHours;
    float extra;
    float salary;
};

struct worker structWrite(char * name[], char * surname, float workHours, float salary, float extra){
    struct worker inputWorker; 
    strcpy(inputWorker.name, name);
    strcpy(inputWorker.surname, surname);
    inputWorker.workingHours = workHours;
    inputWorker.extra = extra;
    inputWorker.salary = salary;
    return inputWorker;
}

int main(){
    int amoutOfWorkers = 3;
    float salarySum = 0;
    float maxSalary;
    char * maxSalaryName;
    char * maxSalarySurname;
    int wantToFind;
    char * searchedSurname[40];
    struct worker workers[amoutOfWorkers];
    char name[40], surname[40];
    float workHours, salary, extra;

    int i;
    for (i = 0; i < amoutOfWorkers; i++){
        printf("Worker name: ");
        scanf("%s", name);
        printf("Worker surname: ");
        scanf("%s", surname);
        printf("Work hours: ");
        scanf("%f", &workHours);
        printf("extra hours: ");
        scanf("%f", &extra);
        printf("salary: ");
        scanf("%f", &salary);

        workers[i] = structWrite(name, surname, workHours, salary, extra);
        salarySum += workers[i].salary;
    }
    printf("\n\n\n");

    maxSalary = workers[0].salary;
    maxSalaryName = workers[0].name;
    maxSalarySurname = workers[0].surname;

    for (i = 0; i < amoutOfWorkers; i++){
        if (workers[i].salary > maxSalary){
            maxSalary = workers[i].salary;
            maxSalaryName = workers[i].name;
            maxSalarySurname = workers[i].surname;
        }

        printf("Index: %d\n", i);
        printf("Name: %s\n", workers[i].name);
        printf("Surname: %s\n", workers[i].surname);
        printf("Working hours: %f\n", workers[i].workingHours);
        printf("Extra hours salary: %f\n", workers[i].extra);
        printf("Basic salary: %f\n\n\n", workers[i].salary);

    }
    printf("\n\n\n");
    printf("Max salary: %f\n", maxSalary);
    printf("Best worker name: %s\n", maxSalaryName);
    printf("Best worker surname: %s\n", maxSalarySurname);

    printf("Wnat to find a person?(1 - yes; 0 - no)\n");
    scanf("%d", &wantToFind);
    printf("Enter searched surname: ");
    scanf("%s", searchedSurname);

    printf("\n\n\n");
    if (wantToFind){
        for (i = 0; i < amoutOfWorkers; i++){
            if (!strcmp(workers[i].surname, searchedSurname)){
                printf("Name: %s\n", workers[i].name);
                printf("Surname: %s\n", workers[i].surname);
                printf("Salary: %f\n", workers[i].salary);
                return 0;
            }
        }
    }
    return 0;
}