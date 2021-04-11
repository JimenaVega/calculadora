#include <stdio.h>
#include <stdlib.h>

int addition(int, int) __attribute__((cdecl));
int substraction(int, int) __attribute__((cdecl));


void inputs();
int bin_to_dec(int num);
void print_binary(int n);
int verify_input_range(int n);

int base,n,op;

int main (void){
    
    char answer;
    printf("CALCULATOR\n");

    while (1){

        int sum,res;
        inputs();

        int arr[n];

        for (int i=0; i<n; i++){
            printf("Enter the number ");
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

        /*if(base == 1){
            print_binary(res);
        }else{
            printf("\nSum is %d\n", res);
        }*/
        printf("\nSum is %d\n", res);
        
        
        printf("\nContinue with operations? [y/n]: ");
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

    //printf("The Binary number is = %d \n", binary_val);
    //printf("Its decimal equivalent is = %d \n", decimal_val);

    return decimal_val;

}

void print_binary(int n){

    printf("\nSum is: ");
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("\n");
}

int verify_input_range(int num){
    if (num < 0 || num > 2){
        printf("\nInvalid input. Re-enter option.\n");
        return 0;
    }else{
        return 1;
    }
}

void inputs(){
    do{
        printf("Ingrese base de numeración:\n[1] binario [2] decimal\n");
        scanf("%d", &base);
    }
    while(verify_input_range(base)==0);

    do{
        printf("Ingrese operacion:\n[1] suma [2] resta\n");
        scanf("%d", &op);
    }
    while(verify_input_range(op)==0);
    do{
        printf("Cantidad de numeros a ingresar: ");
        scanf("%d", &n);
    }
    while(n<0);

}