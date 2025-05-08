#include <stddef.h>

static const unsigned int arr_0_0[] = {1, 2, 4, 8, 16};
static const unsigned int arr_0_1[] = {3, 6, 12, 24};
static const unsigned int arr_0_2[] = {7, 14, 28};
static const unsigned int arr_0_3[] = {15, 30};
static const unsigned int arr_0_4[] = {31};
static const unsigned int arr_1_1[] = {5, 9, 10, 17, 18, 20};
static const unsigned int arr_1_2[] = {11, 13, 19, 22, 25, 26};

static const unsigned int *arr_0[] = {arr_0_0, arr_0_1, arr_0_2, arr_0_3, arr_0_4};
static const unsigned int *arr_1[] = {NULL, arr_1_1, arr_1_2};
static const unsigned int *arr_2[] = {};

static const size_t arr_0_len[] = {5, 4, 3, 2, 1};
static const size_t arr_1_len[] = {0, 6, 6};
static const size_t arr_2_len[] = {0};

static const unsigned int **LUT5[] = {arr_0, arr_1, arr_2};
static const size_t LUT5_len[] = {5, 3, 1};
static const size_t *LUT5arr_len[] = {arr_0_len, arr_1_len, arr_2_len};