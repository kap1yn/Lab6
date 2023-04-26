#pragma once

void arrToBinary(sphere *arr, int n){
    FILE *f_bin = fopen("arr_bin.bin", "wb");
    if(f_bin){
        fwrite(&arr, sizeof(sphere), n, f_bin);
        fclose(f_bin);
    }
    else printf("Error in writing .bin file");
}

void readBinary(sphere *arr, int n){
    FILE *f_bin = fopen("arr_bin.bin", "rb");
    if(f_bin){
        fread(&arr, sizeof(sphere), n, f_bin);
    }
    else printf("Error in reading .bin file");
}