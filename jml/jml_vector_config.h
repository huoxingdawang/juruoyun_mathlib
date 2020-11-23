/* Copyright (c) [2020] juruoyun developer team
   Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JML_VECTOR_CONFIG_H
#define __JML_VECTOR_CONFIG_H
#include "jml_config.h"
#if JML_VECTOR_ENABLE==1
#include "jml_ying.h"
typedef jbl_uint64      jml_vector_size_type;
typedef long double     jml_vector_data_type;
#define jml_vector_data_push(x,y)	    jbl_stream_push_double(x,(double)(y))


#endif
#endif
