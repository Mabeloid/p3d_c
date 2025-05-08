#include <stddef.h>
#include "lut1.h"
#include "lut2.h"
#include "lut3.h"
#include "lut4.h"
#include "lut5.h"
#include "lut6.h"
#include "lut7.h"
#include "lut8.h"
#include "lut9.h"
#include "lut10.h"

extern const unsigned int **LUT1[];
extern const unsigned int **LUT2[];
extern const unsigned int **LUT3[];
extern const unsigned int **LUT4[];
extern const unsigned int **LUT5[];
extern const unsigned int **LUT6[];
extern const unsigned int **LUT7[];
extern const unsigned int **LUT8[];
extern const unsigned int **LUT9[];
extern const unsigned int **LUT10[];
extern const size_t LUT1_len[];
extern const size_t LUT2_len[];
extern const size_t LUT3_len[];
extern const size_t LUT4_len[];
extern const size_t LUT5_len[];
extern const size_t LUT6_len[];
extern const size_t LUT7_len[];
extern const size_t LUT8_len[];
extern const size_t LUT9_len[];
extern const size_t LUT10_len[];
extern const size_t *LUT1arr_len[];
extern const size_t *LUT2arr_len[];
extern const size_t *LUT3arr_len[];
extern const size_t *LUT4arr_len[];
extern const size_t *LUT5arr_len[];
extern const size_t *LUT6arr_len[];
extern const size_t *LUT7arr_len[];
extern const size_t *LUT8arr_len[];
extern const size_t *LUT9arr_len[];
extern const size_t *LUT10arr_len[];

static const unsigned int ***LUT[10] = {LUT1, LUT2, LUT3, LUT4, LUT5, LUT6, LUT7, LUT8, LUT9, LUT10};
static const size_t *LUT_len[10] = {LUT1_len, LUT2_len, LUT3_len, LUT4_len, LUT5_len, LUT6_len, LUT7_len, LUT8_len, LUT9_len, LUT10_len};
static const size_t **LUTarr_len[10] = {LUT1arr_len, LUT2arr_len, LUT3arr_len, LUT4arr_len, LUT5arr_len, LUT6arr_len, LUT7arr_len, LUT8arr_len, LUT9arr_len, LUT10arr_len};