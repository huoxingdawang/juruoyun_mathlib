/* Copyright (c) [2020] juruoyun developer team
  Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JML_VECTOR_H
#define __JML_VECTOR_H
#include "jml_vector_config.h"
#if JML_VECTOR_ENABLE==1
#include "jml_ying.h"
#include "jml_matrix.h"
typedef struct __jml_vector
{
	jbl_gc						gc;
	jbl_var_ops_define			;
	jbl_pthread_lock_define		;
	jml_vector_size_type		n;
	jml_vector_data_type		data[];
}jml_vector;
jml_vector *            jml_vector_new                  (jml_vector_size_type n);
jml_vector *            jml_vector_copy                 (jml_vector *that);
jml_vector *            jml_vector_free                 (jml_vector* this);
#define					jml_vector_extend(a,b,c)		jml_vector_extend_to((a),(b),(c),1,NULL)				//将向量修改为n大小(多于部分直接丢弃，不足补零)
jml_vector *			jml_vector_extend_to			(jml_vector *this,jml_vector_size_type n,jbl_uint8 small,jml_vector **pth);		//扩展向量this到size字节
char                    jml_vector_space_ship           (jml_vector *this,jml_vector *that);
jml_vector_data_type	jml_vector_get					(jml_vector *this,jml_vector_size_type n);							//向量取值
jml_vector *			jml_vector_set					(jml_vector *this,jml_vector_size_type n,jml_vector_data_type v);	//向量赋值，A的原地运算
jml_vector *			jml_vector_add					(jml_vector* A,jml_vector* B);										//向量求和，A的原地运算
jml_vector *			jml_vector_minus				(jml_vector* A,jml_vector* B);										//向量求差，A的原地运算
jml_vector *			jml_vector_negative				(jml_vector* A);													//向量求负，A的原地运算
jml_vector *			jml_vector_number_multiply		(jml_vector* A,jml_vector_data_type v);								//向量数乘，A的原地运算
jml_vector_data_type    jml_vector_multiply				(jml_vector* A,jml_vector* B);										//向量内积
jml_vector_data_type    jml_vector_length               (jml_vector* A);                                                    //向量求长
jml_vector *		    jml_vector_get_E                (jml_vector* A);                                                    //向量求单位向量，A的原地运算
double      		    jml_vector_get_theta            (jml_vector* A,jml_vector* B);                                      //向量求角

#if JML_MATRIX_ENABLE==1
jml_matrix *			jml_vector_lay_row				(jml_matrix_size_type m,jml_vector * v[]);			                //m个向量行摆成矩阵
jml_matrix *			jml_vector_lay_column			(jml_matrix_size_type m,jml_vector * v[]);			                //m个向量列摆成矩阵
#endif

#if JBL_STREAM_ENABLE==1
jml_vector*				jml_vector_view_put						(jml_vector* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 line,unsigned char * varname,unsigned char * func,unsigned char * file);	//从out浏览一个字符串
#define					jml_vector_view(x)						jml_vector_view_put(x,jbl_stream_stdout,1,JBL_VIEW_DEFAULT_TABS,__LINE__,UC #x,UC __FUNCTION__,UC __FILE__)//浏览一个向量
#endif


#endif
#endif