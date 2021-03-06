/* Copyright (c) [2020] juruoyun developer team
  Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JML_GCD_H
#define __JML_GCD_H
#include "jml_gcd_config.h"
#if JML_GCD_ENABLE==1
#include "jml_ying.h"
jbl_uint64 jml_gcd(jbl_uint64 a,jbl_uint64 b);
jbl_uint64 jml_lcm(jbl_uint64 a,jbl_uint64 b);
#endif
#endif