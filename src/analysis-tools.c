#include "analysis-tools.h"

char get_series_function_degree(const double *const data, const int data_size, double *const deviation) {
    char calculating = 1;

    char function_degree = 0;
    double previous_deviation = 0;

    double *deltas = NULL;
    int deltas_count = 0;

    while (calculating) {
        const double *series = data;
        int series_size = data_size;
        if (function_degree) {
            series = deltas;
            series_size = deltas_count;
        }
        int current_deltas_count = series_size - 1;
        double *current_deltas = NULL;
        if (current_deltas_count < 1) {
            calculating = 0;
        } else {
            current_deltas = malloc(sizeof(double) * current_deltas_count);
            calculate_series_deltas(series, series_size, current_deltas);
            double current_deviation = get_deltas_abs_sum(current_deltas, current_deltas_count);
            if (current_deviation < 0.001) {
                calculating = 0;
            } else if (function_degree && current_deviation > previous_deviation) {
                calculating = 0;
                --function_degree;
            }
            *deviation = previous_deviation;
            previous_deviation = current_deviation;
        }
        if (calculating) {
            ++function_degree;
            if (deltas) {
                free(deltas);
            }
            deltas = current_deltas;
            deltas_count = current_deltas_count;
        } else {
            if (current_deltas) {
                free(current_deltas);
            }
        }
    }
    if (deltas) {
        free(deltas);
    }
    return function_degree;
}

void calculate_series_deltas(const double *const series, const int series_size, double *const deltas) {
    for (int i = 0; i < series_size - 1; ++i) {
        deltas[i] = series[i + 1] - series[i];
    }
}

double get_deltas_abs_sum(const double *const deltas, const int deltas_count) {
    double deviation = 0;
    for (int i = 0; i < deltas_count; ++i) {
        deviation += get_abs_value(deltas[i]);
    }
    return deviation;
}

double get_abs_value(const double a) {
    double abs_value = a;
    if (a < 0) {
        abs_value = -a;
    }
    return abs_value;
}
