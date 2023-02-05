#include "data_process.h"

int normalization(double *data, int n, int* flag) {
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;
    if (fabs(size) < EPS) {
        for (int i = 0; i < n; i++) {
            if (size - min_value != 0 && size != 0) {
                data[i] = data[i] / size - min_value / size;
            } else {
                *flag = 0;
                break;
            }
        }
    } else {
        result = 0;
    }
    return result;
}
