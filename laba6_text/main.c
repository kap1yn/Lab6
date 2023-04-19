#include <stdlib.h>
#include <stdio.h>
#include "formuls.c"

static int flag  = 0;
static int count = 0;

void create_data(struct sphere **, int *);
void input_arr(struct sphere *, int);
void arrToBinary(struct sphere *, int);
void readBinary(struct sphere *, int);
void checkEquality(struct sphere *, int);
void resToTxt(int, struct sphere *, float, float);
void outputInCmd();

int main() {
    remove("output.txt"); //Щоб доповнення працювали корректно

    int n;
    struct sphere *arr;

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

void create_data(struct sphere **arr, int *n) {
    printf("Input n = ");
    scanf("%d", n);

    *arr = (struct sphere *)malloc((*n) * sizeof(struct sphere));
}

void input_arr(struct sphere *arr, int n) {
    FILE *f_in = fopen("input.txt", "r");
    if(f_in){
        for (int i = 0; i < n; i++) {
            fscanf(f_in, "%f %f %f %f", &arr[i].x, &arr[i].y, &arr[i].z, &arr[i].R);
        }
        fclose(f_in);
    }
    else printf("Error in reading input.txt");
}

void arrToBinary(struct sphere *arr, int n){
    FILE *f_bin = fopen("arr_bin.bin", "wb");
    if(f_bin){
        fwrite(&arr, sizeof(struct sphere), n, f_bin);
        fclose(f_bin);
    }
    else printf("Error in writing .bin file");
}

void readBinary(struct sphere *arr, int n){
    FILE *f_bin = fopen("arr_bin.bin", "rb");
    if(f_bin){
        fread(&arr, sizeof(struct sphere), n, f_bin);
    }
    else printf("Error in reading .bin file");
}

void checkEquality(struct sphere *arr, int n){
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

void resToTxt(int k, struct sphere *arr, float V, float S) {
    FILE *f_out = fopen("output.txt", "a");
    if(f_out){
        if (flag == 1)
            fprintf(f_out, "V = S : [%d] (x-%g)^2 + (y-%g)^2 + (z-%g)^2 = %g; V = %f; S = %g \n", k, arr[k - 1].x, arr[k - 1].y,
                   arr[k - 1].z, arr[k - 1].R, V, S);
        else
            fprintf(f_out, "V > S : (x = %g, y = %g z = %g), R = %g\n", arr[k - 1].x, arr[k - 1].y, arr[k - 1].z, arr[k - 1].R);
        fclose(f_out);
    }
    else printf("Error in writing result .txt file");
}

void outputInCmd(){
    char str[10000];
    FILE *f_out = fopen("output.txt", "r");
    if(f_out){
        while(fgets(str, 10000, f_out) != NULL) {
            printf("%s", str);
        }
        fclose(f_out);
    }
    else printf("Error in reading result .txt file");
}