/*
 * main.c
 *
 *  Created on: May 30, 2023
 *      Author: drewthomas
 */

#include "main.h"
#include "fft.h"

int main(void){
	float d = 1; //just write 1 in order to have the same results of matlab fft(.)
	int n = 64; // array dimension
	float complex vec[64] = {1.34417,7.44338,-3.87277,0.40857,-2.03427,-3.24173,1.80218,2.65840,7.22662,4.11990,
	-3.31974,10.50095,3.64283,-1.84953,-0.98936,-0.42996,2.63075,5.58104,1.85816,0.79424,1.78866,-0.05014,3.67735,
	2.43862,-1.49905,2.72410,4.81324,1.15310,-0.87484,-4.66205,2.38580,0.15579,-0.73304,-3.60584,-10.02714,3.78817,
	3.86385,0.07922,1.87105,-6.91782,-0.03599,2.47464,2.79193,-0.74518,-4.77387,0.17185,2.69342,3.59053,1.23319,
	0.18886,-1.88483,3.32633,-0.98671,-4.25642,-2.57415,4.13318,1.23606,3.00431,-2.00936,0.26363,-2.39380,3.26887,
	3.48442,1.33336};

    FILE *f = fopen("fft.csv", "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

	FILE *fp = fopen("fft_pwr.csv", "w");
    if (fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

	FFT(vec, n, d);

	for(int i=0; i<n; i++){
		//printf("%.2f %+.2fi,\n", crealf(vec[i]), cimagf(vec[i]));
        fprintf(f, "%.2f %+.2fi,\n", crealf(vec[i]), cimagf(vec[i]));
		fprintf(fp, "%.2f,\n", sqrt(pow(crealf(vec[i]),2) + pow(cimagf(vec[i]),2))/n);
	}
    fclose(f);
	fclose(fp);
	exit(1);
}
