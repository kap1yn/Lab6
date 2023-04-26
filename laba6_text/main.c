#include <stdlib.h>
#include <stdio.h>
#include "formuls.c"
#include "input.c"
#include "binary.c"
#include "output.c"

static int count = 0;

void checkEquality(sphere *, int);

int main() {
    remove("output.txt"); //Щоб доповнення працювали корректно

    int n;
    sphere *arr;

    create_data(&arr, &n);
    if (arr) {
        input_arr(arr, n);
        arrToBinary(arr, n);
        readBinary(arr, n);
        checkEquality(arr, n);
        outputInCmd();
        free(arr);
    }
    else printf("Memory allocation failed");
}

void checkEquality(sphere *arr, int n){
    float V, S;

    for(int i = n-1; i >= 0; i--){
        if(arr[i].R == 3) {
            flag = 1;
            V = getV(arr, i);
            S = getS(arr, i);
            resToTxt(i+1, arr, V, S);
            count++;
        }
    }
    if(count == 0) {
        for (int i = n - 1; i >= 0; i--) {
            V = getV(arr, i);
            S = getS(arr, i);
            flag = 0;
            if (V > S) resToTxt(i + 1, arr, V, S);
        }
    }
}

