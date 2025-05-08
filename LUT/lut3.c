#include <stddef.h>

static const unsigned int arr_0_0[] = {1, 2, 4};
static const unsigned int arr_0_1[] = {3, 6};
static const unsigned int arr_0_2[] = {7};

static const unsigned int *arr_0[] = {arr_0_0, arr_0_1, arr_0_2};
static const unsigned int *arr_1[] = {};
static const unsigned int *arr_2[] = {};

static const size_t arr_0_len[] = {3, 2, 1};
static const size_t arr_1_len[] = {0};

static const unsigned int **LUT3[] = {arr_0, arr_1, arr_2};
static const size_t LUT3_len[] = {3, 1, 0};
static const size_t *LUT3arr_len[] = {arr_0_len, arr_1_len, NULL};