#include <stddef.h>

static const unsigned int arr_0_0[] = {1, 2, 4, 8};
static const unsigned int arr_0_1[] = {3, 6, 12};
static const unsigned int arr_0_2[] = {7, 14};
static const unsigned int arr_0_3[] = {15};
static const unsigned int arr_1_1[] = {5, 9, 10};

static const unsigned int *arr_0[] = {arr_0_0, arr_0_1, arr_0_2, arr_0_3};
static const unsigned int *arr_1[] = {NULL, arr_1_1};
static const unsigned int *arr_2[] = {};

static const size_t arr_0_len[] = {4, 3, 2, 1};
static const size_t arr_1_len[] = {0, 3};

static const unsigned int **LUT4[] = {arr_0, arr_1, arr_2};
static const size_t LUT4_len[] = {4, 2, 0};
static const size_t *LUT4arr_len[] = {arr_0_len, arr_1_len, NULL};