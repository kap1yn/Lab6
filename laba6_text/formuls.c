#pragma once
#include <math.h>

typedef struct parameters {
    float x, y, z, R;
}sphere;

float getS(sphere *arr, int n){
    return 4 * M_PI * arr[n].R * arr[n].R;
}

float getV(sphere *arr, int n){
    return 4 * (M_PI * arr[n].R * arr[n].R * arr[n].R) / 3;
}