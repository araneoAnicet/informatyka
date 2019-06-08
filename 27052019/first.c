#include <stdio.h>
#include <stdlib.h>

struct ulamek {
    int licznik;
    int mianownik;
};

int main() {
    struct ulamek myUlamek;
    printf("first num: ");
    scanf("%d", &myUlamek.licznik);
    printf("second num: ");
    scanf("%d", &myUlamek.mianownik);
    printf("Result: %f\n", (float) myUlamek.licznik / myUlamek.mianownik);
    return 0;
}

