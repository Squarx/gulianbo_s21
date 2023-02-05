#include "data_stat.h"

double max(double *data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (max < data[i]) max = data[i];
    }
    return max;
}
double min(double *data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (min > data[i]) min = data[i];
    }
    return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    double average = (1.0 * sum)/(1.0 * n);
    return average;
}

double variance(double *data, int n) {
    double sigma = 0, average = mean(data, n);
    for (int i = 0; i < n; i++) {
        sigma += 1.0*(average - data[i]) * (average - data[i]) / n;
    }
    return sigma;
}
