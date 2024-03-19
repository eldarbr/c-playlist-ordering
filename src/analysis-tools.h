#ifndef ANALYSIS_TOOLS_01
#define ANALYSIS_TOOLS_01

#include <stdlib.h>

char get_series_function_degree(const double *const data, const int data_size, double *const deviation);
double get_deltas_abs_sum(const double *const deltas, const int deltas_count);
double get_abs_value(const double a);
void calculate_series_deltas(const double *const series, const int series_size, double *const deltas);

#endif
