/*
 * fft.c
 *
 *  Created on: May 30, 2023
 *      Author: drewthomas
 */

#include "fft.h"

//float complex my_polar(float mag, float phase);

#define MAX 200
#define PI  3.1415926535897932384

int log_2(int N){    /*function to calculate the log2(.) of int numbers*/
    int k = N, i = 0;
    while(k) {
        k >>= 1;
        i++;
    }
    return i - 1;
}

int check(int n){    //checking if the number of element is a power of 2
    return n > 0 && (n & (n - 1)) == 0;
}

int reverse(int N, int n){    //calculating reverse number
    int j, p = 0;
    for(j = 1; j <= log_2(N); j++) {
        if(n & (1 << (log_2(N) - j))){
            p |= 1 << (j - 1);
        }
    }
    return p;
}

void ordina(float complex * f1, int N){ //using the reverse order in the array
    float complex f2[200];
    for(int i = 0; i < N; i++){
        f2[i] = f1[reverse(N, i)];
    }
    for(int j = 0; j < N; j++){
        f1[j] = f2[j];
    }
}

void transform(float complex * f, int N){ 
    ordina(f, N);   //first: reverse order
    float complex *W;
     W = (float complex *)malloc(N / 2 * sizeof(float complex));
     W[1] = my_polar(1.0, -1 * 2.0 * PI / N); 
     W[0] = 1;
     for(int i = 2; i < N / 2; i++){
        W[i] = cpowf(W[1], (float)i);
    } 
    int n = 1;
    int a = N / 2;
    for(int j = 0; j < log_2(N); j++){
        for(int i = 0; i < N; i++){
            if(!(i & n)){
                float complex temp = f[i];
                float complex Temp = W[(i * a) % (n * a)] * f[i + n];
                f[i] = temp + Temp;
                f[i + n] = temp - Temp;
            }
        }
    n *= 2;
    a = a / 2;
    }
    free(W);
}

void FFT(float complex * f, int N, float d){
    transform(f, N);
    for(int i = 0; i < N; i++){
        f[i] *= d; //multiplying by step
    }   
}

float complex my_polar(float mag, float phase){
    float complex num = mag*cosf(phase) + I*mag*sinf(phase);
    return num;
}