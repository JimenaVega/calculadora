#include <stdio.h>

#include "cdecl.h"

//int PRE_CDECL addition( int, int ) POST_CDECL;
//int PRE_CDECL substraction( int, int ) POST_CDECL;
int addition(int, int) __attribute__((cdecl));


int main(void){
    int base,n,sum,op,res;

    printf("CALCULADORA\n");
    printf("Ingrese base de numeración:\n[1] binario [2] decimal\n");
    scanf("%d", &base);

    printf("Ingrese operacion:\n[1] suma [2] resta\n");
    scanf("%d", &op);

    printf("Cantidad de numeros a ingresar: ");
    scanf("%d", &n);

    int arr[n];

    for (int i=0; i<n; i++){
        printf("Ingrese el numero: ");
        scanf("%d", &arr[i]);
    }
    
    res = addition(2,2);
    /*for (int i=0; i<(n-1); i++){
        if (i==0){
            res = addition(arr[i], arr[i+1]);
        }
        else{
            res = addition(res, arr[i+1]);
        }
    }*/
 
    printf("Sum is %d\n", res);
    return 0;
}
