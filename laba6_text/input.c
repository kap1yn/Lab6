#pragma once

int findN() {
    char ch[1000];
    int counter = 0;
    FILE *f_in = fopen("input.txt", "r");
    while(fgets(ch, sizeof(ch), f_in) != NULL){
        counter++;
    }
    fclose(f_in);
    return counter;
}

void create_data(sphere **arr, int *n) {
    (*n) = findN();
    *arr = (sphere *)malloc((*n) * sizeof(sphere));
}

void input_arr(sphere *arr, int n) {
    FILE *f_in = fopen("input.txt", "r");
    if(f_in){
        for (int i = 0; i < n; i++) {
            fscanf(f_in, "%f %f %f %f", &arr[i].x, &arr[i].y, &arr[i].z, &arr[i].R);
        }
        fclose(f_in);
    }
    else printf("Error in reading input.txt");
}