#pragma once

static int flag  = 0;

void resToTxt(int k, sphere *arr, float V, float S) {
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