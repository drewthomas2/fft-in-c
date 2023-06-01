/*
 * fft.h
 *
 *  Created on: May 30, 2023
 *      Author: drewthomas
 */

#ifndef INC_FFT_H_
#define INC_FFT_H_

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 200
#define PI  3.1415926535897932384

int log_2(int N);
int check(int n);
void ordina(float complex * f1, int N);
void transform(float complex * f, int N);
void FFT(float complex * f, int N, float d);
float complex my_polar(float mag, float phase);

#endif /* INC_FFT_H_ */