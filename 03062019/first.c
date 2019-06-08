#include <stdio.h>
#include <stdlib.h>


struct pracownik {
    char imie[40];
    char nazwisko[40];
    int placa;
    float godziny;
    float extra;
};

void zapisB();
int odczytB();
float suma();

int main(int argc, char *argv[]) {
    int opcja;
    
    do {
        printf("wybierz: 1-zapis, 2-odczyt calej bazy, 3-suma wyplat, 0-koniec programu ? ");
        scanf("%d", &opcja);
        
        switch(opcja) { 
            case 1: zapisB(); break;
            case 2: odczytB(1); break;
            case 3: printf("Suma wyplat: %f\n", suma()); break;
            case 4: /* do smth */ break;
            case 0: printf("KONIEC PROGRAMU\n"); break;
            default: printf("nie ma takiej opcji!!!");
        }
    } while(opcja != 0);
    
    return 0;
}

void zapisB() {
    struct pracownik p;
    FILE *fplik;
    int i, k;
    int rozmiar = sizeof(struct pracownik);

    if ((fplik = fopen("baza", "ab")) == NULL) {
        printf("blad");
        exit(1);
    }
    printf("Podaj liczbe pracownikow ");
    scanf("%d", &k);
    for(i = 1; i <= k; i++) {
        fflush(stdin);
        printf("Podaj nazwisko ");
        scanf("%s", p.nazwisko);
        printf("Podaj imie ");
        scanf("%s", p.imie);
        printf("Podaj place ");
        scanf("%d", &p.placa);
        printf("Podaj godziny pracy ");
        scanf("%f", &p.godziny);
        printf("Podaj extra ");
        scanf("%f", &p.extra);
        fwrite(&p, rozmiar, 1, fplik);
    }
    if (fclose(fplik) != 0) {
        printf("Blad ");
    }
    else printf("\nkoniec zapisu\n");
}

int odczytB(int doShow){
    int iloscPracownikow = 0;
    struct pracownik p;
    FILE *fplik;
    int rozmiar = sizeof(struct pracownik);
    if ((fplik = fopen("baza", "rb")) == NULL) {
        printf ("blad");
        exit(1);
    }
    if (doShow){
        while(fread(&p, rozmiar, 1, fplik) == 1) {
            iloscPracownikow++;
            printf("%s %s %d, godziny: %f, extra: %f\n\n", p.imie, p.nazwisko, p.placa, p.godziny, p.extra);
        }
    } else {
        while(fread(&p, rozmiar, 1, fplik) == 1) {
            iloscPracownikow++;
        }
    }
    if (fclose(fplik) != 0) {
        printf("Blad przy zamykaniu pliku");
        }
    return iloscPracownikow;
}

void showMax(){
    FILE *fplik;
    struct pracownik p;
    int maxSalary;
    int amountOfWorkers = odczytB(0);
    int i;
    fread(&p, amountOfWorkers, 1, fplik);
    maxSalary = p.placa;
    while (fread(&p, amountOfWorkers, 1, fplik) == 1){
        if (p.placa >= maxSalary) {
            maxSalary = p.placa;
        }
    }
    
    printf("Max place: %d", maxSalary);
}

float suma() {
    struct pracownik p;
    int rozmiar = sizeof(struct pracownik);
    float s = 0;
    FILE *fplik;
    if ((fplik = fopen("baza", "rb")) == NULL) {
        printf("blad");
        exit(1);
    }
    while(fread(&p, rozmiar, 1, fplik) == 1) {
        s += p.placa;
    }
    if (fclose(fplik) != 0){
        printf("Blad przy zamykaniu pliku");
    }
    return s;
}