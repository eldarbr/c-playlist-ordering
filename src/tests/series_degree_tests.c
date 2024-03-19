#include <stdio.h>

#include "../analysis-tools.h"

/*
 *  This test reads series from stdin
 *   and prints to stdout its degree
 */
int main(void) {
    char work_error = 0;

    int data_size = 0;
    if (!scanf("%d", &data_size) || getchar() != '\n') {
        work_error = 1;
    }

    double *data = NULL;
    if (!work_error) {
        data = malloc(sizeof(double) * data_size);
        if (!data) {
            work_error = 1;
        }
    }

    for (int i = 0; !work_error && i < data_size; ++i) {
        double tmp_num = 0;
        if (!scanf("%lf", &tmp_num) || getchar() != '\n') {
            work_error = 1;
        } else {
            data[i] = tmp_num;
        }
    }

    if (work_error) {
        printf("n/a\n");
    } else {
        double deviation = 0;
        char degree = get_series_function_degree(data, data_size, &deviation);
        printf("%d %lf\n", degree, deviation);
    }

    if (data) {
        free(data);
    }

    return work_error;
}
