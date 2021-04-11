#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Assembly functions
int addition(int, int) __attribute__((cdecl));
int substraction(int, int) __attribute__((cdecl));
//C functions
int bin_to_dec(int num);

int base,n,op;

int main (int argc,char* argv[]){
    
    int i = 1;
    int temp;
    int initial_flag = 0;
    char* temp_char;
    int values[argc/2];
    char operators[argc/2 - 1];
    int values_counter = 0;
    int operators_counter = 0;
    int res = 0;

    printf("CALCULATOR\n");

    while(argv[i] != NULL){

        if(argv[i][1] == 'd'){
            temp_char = strtok(argv[i], "d");
            values[values_counter] = atoi(argv[i]);
            
            values_counter++;
        }
        else if(argv[i][0] == '+' || argv[i][0] == '-'){
            operators[operators_counter] = argv[i][0];

            operators_counter++;
        }
        else{

            temp_char = strtok(argv[i], "b");
            values[values_counter] = bin_to_dec(atoi(argv[i]));
         
            values_counter++;
        }
        i++;
    }

    int i_op = 0;

    for (int i=0; i<((argc/2)-1); i++){

        if (i == 0){
            if (operators[i_op] == '+'){
                res = addition(values[i], values[i+1]);
            }
            else if (operators[i_op] == '-'){
                res = substraction(values[i], values[i+1]);
            }
            i_op++;
        }
        else{
            if (operators[i_op] == '+'){
                res = addition(res, values[i+1]);
                i_op++;
            }
            else if (operators[i_op] == '-'){
                res = substraction(res, values[i+1]);
                i_op++;
            }
        }
    }
    
    printf("\nResult : %d",res);

    return res;
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

