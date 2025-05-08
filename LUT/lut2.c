#include <stddef.h>

static const unsigned int arr_0_0[] = {1, 2};
static const unsigned int arr_0_1[] = {3};

static const unsigned int *arr_0[] = {arr_0_0, arr_0_1};
static const unsigned int *arr_1[] = {};
static const unsigned int *arr_2[] = {};

static const size_t arr_0_len[] = {2, 1};

static const unsigned int **LUT2[] = {arr_0, arr_1, arr_2};
static const size_t LUT2_len[] = {2, 0, 0};
static const size_t *LUT2arr_len[] = {arr_0_len, NULL, NULL};