#pragma once
#include <math.h>

struct sphere {
    float x, y, z, R;
};

float getS(struct sphere *arr, int n){
    return 4 * M_PI * arr[n].R * arr[n].R;
}

float getV(struct sphere *arr, int n){
    return 4 * (M_PI * arr[n].R * arr[n].R * arr[n].R) / 3;
}