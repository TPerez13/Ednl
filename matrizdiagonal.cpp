#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned diagonal(int m[5][5]);

int main(){

    FILE *matriz;
    int m[5][5];
    unsigned mdiag;

    while(!feof(matriz)){
        if(mdiag==0){
            printf("La matriz no es diagonal\n");
            exit(1);
        }else{
            fscanf(matriz,"%u", &mdiag);
            printf("La matriz es diagonal\n");
            //printf("%u ", mdiag);
            }
       //printf("\n");
    }
    fclose(matriz);

    mdiag = diagonal(m);

    matriz=fopen("matriz.txt","r");

    if(matriz==NULL){
        puts("El fichero no se puede abrir.\n");
    }
    //printf("\n");

    

system("pause");
return 0;
}

unsigned diagonal(int m[5][5]){

    int i, j;

    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(m[i][j]!=0 && m[j][i]!=0)
                return 0;
        }
    }
    return 1;
}