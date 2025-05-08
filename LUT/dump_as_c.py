"""
the kind of shit i've been on as of late
"""

import json
import os

DIR = os.path.dirname(__file__)
fname = os.path.basename(__file__)

curly_int = lambda l: "{%s}" % str(l)[1:-1]
curly_len = lambda l: "{%s}" % str(list(map(len, l)))[1:-1]
curly_str = lambda l: "{%s}" % ", ".join(l)

SCUI = "static const unsigned int"
SCS = "static const size_t"
ECUI = "extern const unsigned int"
ECS = "extern const size_t"


def dump_c_files(folder: str, size: int,
                 groups_list: list[list[list[int]]]) -> None:

    layer0: list[str] = []
    layer1: list[str] = []

    arrs_l1 = []
    for a, things in enumerate(groups_list):
        arrs_l0 = []
        for b, l in enumerate(things):
            if l:
                arr_str = f"arr_{a}_{b}"
                layer0.append(f"{SCUI} {arr_str}[] = {curly_int(l)};")
                arrs_l0.append(arr_str)
            else:
                arrs_l0.append("NULL")
        while arrs_l0 and arrs_l0[-1] == "NULL":
            arrs_l0.pop()
        arr_str = f"arr_{a}"
        layer1.append(f"{SCUI} *{arr_str}[] = {curly_str(arrs_l0)};")
        arrs_l1.append(arr_str)

    sizes: list[str] = []
    arrs_l2: list[str] = []
    for a, things in enumerate(groups_list):
        if things:
            arr_str = f"arr_{a}_len"
            arrs_l2.append(arr_str)
            sizes.append(f"{SCS} {arr_str}[] = {curly_len(things)};")
        else:
            arrs_l2.append("NULL")

    extern_vars: list[tuple[str, str]] = []
    extern_vars.append((f"{SCUI} **LUT{size}[]", curly_str(arrs_l1)))
    extern_vars.append((f"{SCS} LUT{size}_len[]", curly_len(groups_list)))
    extern_vars.append((f"{SCS} *LUT{size}arr_len[]", curly_str(arrs_l2)))

    extern_str: list[str] = [f"{ls} = {rs};" for ls, rs in extern_vars]
    h_vars: list[str] = ["#include <stddef.h>"]
    h_vars.extend([f"{ls};" for ls, rs in extern_vars])

    parts = [["#include <stddef.h>"], layer0, layer1, sizes, extern_str]
    parts = map("\n".join, parts)

    with open(f"{folder}/lut{size}.c", "w") as f:
        f.write("\n\n".join(parts))
    with open(f"{folder}/lut{size}.h", "w") as f:
        f.write("\n".join(h_vars))


def final_c_file(folder: str, RANGE: range) -> None:
    includes: list[str] = ["#include <stddef.h>"]
    includes.extend([f'#include "lut{size}.h"' for size in RANGE])

    extern: list[str] = []
    imported: list[tuple[str, str]] = []

    ext_vals = [f"LUT{size}" for size in RANGE]
    extern.extend([f"{ECUI} **{v}[];"] for v in ext_vals)
    imported.append((f"{SCUI} ***LUT[{size}]", curly_str(ext_vals)))

    ext_vals = [f"LUT{size}_len" for size in RANGE]
    extern.extend([f"{ECS} {v}[];"] for v in ext_vals)
    imported.append((f"{SCS} *LUT_len[{size}]", curly_str(ext_vals)))

    ext_vals = [f"LUT{size}arr_len" for size in RANGE]
    extern.extend([f"{ECS} *{v}[];"] for v in ext_vals)
    imported.append((f"{SCS} **LUTarr_len[{size}]", curly_str(ext_vals)))

    extern = map("\n".join, extern)
    exported: list[str] = [f"{ls} = {rs};" for ls, rs in imported]
    h_vars: list[str] = ["#include <stddef.h>"]
    h_vars.extend([f"{ls};" for ls, rs in imported])

    parts = [includes, extern, exported]
    parts = map("\n".join, parts)
    with open(f"{folder}/lut.c", "w") as f:
        f.write("\n\n".join(parts))
    with open(f"{folder}/lut.h", "w") as f:
        f.write("\n".join(h_vars))


RANGE = range(1, 11)
for size in RANGE:
    with open(f"{DIR}/LUT_json/{size}.json", "r") as f:
        groups_list: list[list[list[int]]] = json.load(f)

    dump_c_files(f"{DIR}/p3d_c/LUT", size, groups_list)
final_c_file(f"{DIR}/p3d_c/LUT", RANGE)

with open(f"{DIR}/p3d_c/LUT/{fname}", "w", encoding="utf-8") as W:
    W.write('"""\nthe kind of shit i\'ve been on as of late\n"""\n\n')
    with open(__file__, "r", encoding="utf-8") as R:
        W.write(R.read())
