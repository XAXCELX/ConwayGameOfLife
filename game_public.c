#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dibujarMatriz(int m[][10],int filas,int columnas){
    printf("-------------------------------\n");
    int i,j;
    int contadorVivos=0;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(m[i][j]==2){
                printf("[2]");
                continue;
            }
            if(m[i][j]==0){
                printf("[ ]");
                continue;
            }
            printf("[x]");
            contadorVivos++;
        }
        printf("\n");
    }
    printf("Total vivos : %d\n",contadorVivos);
}


void aplicarJuego(int m[][10],int filas,int columnas){
    int i,j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            if(i==0||j==0||i==(filas-1)||j==(columnas-1)){
                m[i][j]=0;
            }
            if(m[i][j+1]==1&&m[i][j-1]==0){
                m[i][j]=0;
                m[i][j-1]=1;
            }
            if(m[i-1][j]||m[i+1][j]){
                m[i][j]=0;
            }
            if(m[i-1][j]==0&&m[i+1][j]==0&&m[i][j-1]==0&&m[i][j+1]==0){
                m[i][j]=0;
                m[i][rand()%7]=1;                
                m[rand()%7][j]=1;
            }
            m[rand()%filas][rand()%columnas]=0;
            m[rand()%filas][rand()%columnas]=0;
            
        }
    }
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            if(i==0||j==0||i==(filas-1)||j==(columnas-1))
            {
                m[i][j]=0;
            }
        }
    }
}

int main()
{
    int filas=10;
    int columnas=10;
    int matriz[filas][columnas];
    int i,j;
    srand(time(NULL));
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            int alea=rand()%2;
            matriz[i][j]=alea;
        }
    }
    int aa;
    for(aa=0;aa<10;aa++){
        dibujarMatriz(matriz,filas,columnas);
        aplicarJuego(matriz,filas,columnas);
        dibujarMatriz(matriz,filas,columnas);
    }
    return 0;
}