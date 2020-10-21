/* Copyright (c) [2020] juruoyun developer team
   Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JBL_MATRIX_CONFIG_H
#define __JBL_MATRIX_CONFIG_H
#include "jml_config.h"
#if JML_MATRIX_ENABLE==1
#include "jml_ying.h"
typedef jbl_uint64 jml_matrix_size_type;
typedef double jml_matrix_data_type;
#define jml_matrix_data_push			jbl_stream_push_double
#define JML_MATRIX_PRINT_LINENO			0
#define JML_MATRIX_DETERMINANT_USE_TOUP	1						//打开可以获得明显性能提升，矩阵越大越明显


#endif
#endif
