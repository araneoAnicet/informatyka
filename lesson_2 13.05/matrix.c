#include <stdio.h>
#include <stdlib.h>


    float F1(int w, int T[][w], int R) {
        int j;
        float s;
        s=0;
        for(j=0;j<w;j++){
            s=s+T[R][j];
        }
            return s;
    }

    float F2(int w, int T[w][w], int R)
    {
        int i;
        float s;
        s=0;
        for(i=0;i<w;i++)
            s=s+T[i][R];
            return s;
    }

    
    int main()
    {
    int i, j, w=3, R, userInput, changesAmount = 0;
    float s;
        int T[w][w];
        for ( i=0; i<w; i++)
        for ( j=0; j<w; j++)
    {
    printf( "wpisz liczbe: ");
    scanf("%d", &userInput);
    if (userInput < 0){
        changesAmount ++;
        T[i][j] = 0;
    } else {
        T[i][j] = userInput;
    }

    }
    for ( i=0; i<w; i++)
    {
    for ( j=0; j<w; j++) // wyświetlenie i-tego wiersza tablicy
    printf( "%d\t" ,T[i][j] );
    printf( "\n");
    }
    printf("Ilosc zmian: %d\n", changesAmount);
    printf("Podaj numer kolumny R\n");
    scanf("%d", &R);
    if(R>=0 && R<w)
    {
    s=F2(w,T,R);
        printf("Suma z kolumny to: %f ", s);
    }
    else printf("Zly numer kolumny, ");
    
    printf("Podaj numer wiersza R\n");
    scanf("%d", &R);
    if(R>=0 && R<w)
    {
    s=F1(w,T,R);
        printf("Suma z wiersza to: %f \n", s);
    }
    else printf("Zly numer wiersza\n");
        return 0;
    }