#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addition(int, int) __attribute__((cdecl));
int substraction(int, int) __attribute__((cdecl));


void inputs();
int bin_to_dec(int num);
void print_binary(int n);
int verify_input_range(int n);

int base,n,op;

int main (int argc,char* argv[]){
    
    // char answer;
    int i = 0;
    int temp;
    int initial_flag = 0;
    char* temp_char;
    int values[argc/2];
    char operators[argc/2 - 1];
    int values_counter = 0;
    int operators_counter = 0;

    printf("%d\n", argc);

    printf("CALCULATOR\n");

    while(argv[i] != NULL){
        printf("%s - %d\n", argv[i], argc);
        if(argv[i][1] == 'd'){
            temp_char = strtok(argv[i], "d");
            values[values_counter] = atoi(argv[i]);
            printf("[%d]\n", values[values_counter]);
            values_counter++;
        }
        else if(argv[i][1] == 'b'){
            temp_char = strtok(argv[i], "b");
            values[values_counter] = bin_to_dec(atoi(argv[i]));
            printf("[%d]\n", values[values_counter]);
            values_counter++;
        }
        //printf("%s\n", temp_char);
        i++;
    }
    
    // for(int i = 0; i < argc/2; i++){
    //     printf("%d-", values[i]);
    // }

    // while (1){

    //     int sum,res;

    //     inputs();

    //     int arr[n];

    //     for (int i=0; i<n; i++){
    //         printf("Enter a number ");
    //         scanf("%d", &arr[i]);

    //         if(base == 1){
    //             arr[i] = bin_to_dec(arr[i]);
    //         }
    //     }
        
    //     for (int i=0; i<(n-1); i++){
    //         if (i == 0){
    //             if (op == 1){
    //                 res = addition(arr[i], arr[i+1]);
    //             }
    //             else if (op == 2){
    //                 res = substraction(arr[i], arr[i+1]);
    //             }
    //         }
    //         else{
    //             if (op == 1){
    //                 res = addition(res, arr[i+1]);
    //             }
    //             else if (op == 2){
    //                 res = substraction(res, arr[i+1]);
    //             }
    //         }
    //     }

    //     /*if(base == 1){
    //         print_binary(res);
    //     }else{
    //         printf("\nSum is %d\n", res);
    //     }*/
    //     printf("\nSum is %d\n", res);
        
    //     printf("\nContinue with operations? [y/n]: ");
    //     scanf("%s", &answer);

    //     if (answer == 'n'){
    //         break;
    //     }
    //     else if (answer != 'y'){
    //         perror("Invalid input.");
    //         exit(1);
    //     }
    // }

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

    return decimal_val;
}

void print_binary(int n){

    printf("\nResult is: ");
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
        printf("Enter numeric base:\n[1] binary [2] decimal\n");
        scanf("%d", &base);
    }
    while (verify_input_range(base) == 0);

    do{
        printf("Enter operation:\n[1] addition [2] substraction\n");
        scanf("%d", &op);
    }
    while (verify_input_range(op) == 0);

    do{
        printf("Amount of numbers to enter: ");
        scanf("%d", &n);
    }
    while (n<0);
}