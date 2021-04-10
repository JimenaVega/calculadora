#include <stdio.h>
#include <stdlib.h>

int addition(int, int) __attribute__((cdecl));
int substraction(int, int) __attribute__((cdecl));
int bin_to_dec(int num);
void print_binary(int n);

int main (void){
    int base,n,sum,op,res;
    char answer;
    printf("CALCULADORA\n");

    while (1){

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
            if(base == 1){
                arr[i] = bin_to_dec(arr[i]);
            }
        }
        
        for (int i=0; i<(n-1); i++){
            if (i==0){
                if (op == 1){
                    res = addition(arr[i], arr[i+1]);
                }
                else if (op == 2){
                    res = substraction(arr[i], arr[i+1]);
                }
            }
            else{
                if (op == 1){
                    res = addition(res, arr[i+1]);
                }
                else if (op == 2){
                    res = substraction(res, arr[i+1]);
                }
            }
        }

        printf("Sum is %d\n", res);
        
        printf("Continue with operations? [y/n]: ");
        scanf("%s", &answer);
        if(answer == 'n'){
            break;
        }
        else if(answer != 'y'){
            perror("Invalid input.");
            exit(1);
        }
    }

   
    return 0;

}

int bin_to_dec(int num){

    int binary_val, decimal_val = 0, base = 1, rem;
    binary_val = num;

    while (num > 0){

        rem = num % 10;
        decimal_val = decimal_val + rem * base;
        num = num / 10;
        base = base * 2;
    }

    printf("The Binary number is = %d \n", binary_val);
    printf("Its decimal equivalent is = %d \n", decimal_val);

    return decimal_val;

}

void print_binary(int n){

    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("\n");
}
