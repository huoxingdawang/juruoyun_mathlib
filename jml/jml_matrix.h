/* Copyright (c) [2020] juruoyun developer team
   Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JBL_MATRIX_H
#define __JBL_MATRIX_H
#include "jml_matrix_config.h"
#if JML_MATRIX_ENABLE==1
#include "jml_ying.h"
typedef struct __jml_matrix
{
	jbl_gc						gc;
	jbl_var_ops_define			;
	jbl_pthread_lock_define		;
	jml_matrix_size_type		line;
	jml_matrix_size_type		row;
	jml_matrix_data_type		data[];
}jml_matrix;
jml_matrix *			jml_matrix_new					(jml_matrix_size_type line,jml_matrix_size_type row);	//新建一个矩阵
jml_matrix *			jml_matrix_newE					(jml_matrix_size_type n);								//新建一个n行n列单位阵
jml_matrix *			jml_matrix_copy					(jml_matrix *that);										//复制一个矩阵
jml_matrix *			jml_matrix_free					(jml_matrix *this);										//释放一个矩阵
#define					jml_matrix_extend(a,b,c)		jml_matrix_extend_to((a),(b),(c),1,NULL)				//将矩阵修改为b*c大小(多于部分直接丢弃，不足补零)
jml_matrix *			jml_matrix_extend_to			(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row,jbl_uint8 small,jml_matrix **pth);		//扩展矩阵this到size字节
jml_matrix_data_type	jml_matrix_get					(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row);							//矩阵取值
jml_matrix *			jml_matrix_set					(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row,jml_matrix_data_type v);	//矩阵赋值，A的原地运算
jml_matrix *			jml_matrix_add					(jml_matrix* A,jml_matrix* B);										//矩阵求和，A的原地运算
jml_matrix *			jml_matrix_minus				(jml_matrix* A,jml_matrix* B);										//矩阵求差，A的原地运算
jml_matrix *			jml_matrix_negative				(jml_matrix* A);													//矩阵求负，A的原地运算
jml_matrix *			jml_matrix_number_multiply		(jml_matrix* A,jml_matrix_data_type v);								//矩阵数乘，A的原地运算
jml_matrix *			jml_matrix_multiply				(jml_matrix* A,jml_matrix* B);										//矩阵乘法，注意会生成一个新矩阵
jml_matrix *			jml_matrix_transpose			(jml_matrix* A);													//矩阵转置，A的原地运算
jml_matrix *			jml_matrix_pow					(jml_matrix* A,jbl_uint64 n);										//矩阵求幂，注意会生成一个新矩阵
char					jml_matrix_space_ship			(jml_matrix *this,jml_matrix *that);								//矩阵比较
#define					jml_matrix_if_equal(x,y)		(jml_matrix_space_ship(x,y)==0)										//矩阵判等
jml_matrix *			jml_matrix_minor				(jml_matrix *A,jml_matrix_size_type line,jml_matrix_size_type row);	//矩阵求余子式    ，注意会生成一个新矩阵
jml_matrix *			jml_matrix_cofactor				(jml_matrix *A,jml_matrix_size_type line,jml_matrix_size_type row);	//矩阵求代数余子式，注意会生成一个新矩阵
jml_matrix_data_type	jml_matrix_determinant			(jml_matrix *A);													//矩阵求行列式
jml_matrix *			jml_matrix_swap_line			(jml_matrix* A,jml_matrix_size_type l1,jml_matrix_size_type l2);	//矩阵换行，A的原地运算
jml_matrix *			jml_matrix_swap_row				(jml_matrix* A,jml_matrix_size_type r1,jml_matrix_size_type r2);	//矩阵换列，A的原地运算
jml_matrix *			jml_matrix_multiply_line		(jml_matrix* A,jml_matrix_size_type l,jml_matrix_data_type v);		//把l行全部元素乘v，A的原地运算
jml_matrix *			jml_matrix_multiply_row			(jml_matrix* A,jml_matrix_size_type r,jml_matrix_data_type v);		//把r列全部元素乘v，A的原地运算
jml_matrix *			jml_matrix_add_line				(jml_matrix* A,jml_matrix_size_type l1,jml_matrix_size_type l2,jml_matrix_data_type v);		//把l1行全部元素加l2元素乘v，A的原地运算
jml_matrix *			jml_matrix_add_row				(jml_matrix* A,jml_matrix_size_type r1,jml_matrix_size_type r2,jml_matrix_data_type v);		//把r1列全部元素加r2元素乘v，A的原地运算
jml_matrix *			jml_matrix_replace_line			(jml_matrix* A,jml_matrix* B,jml_matrix_size_type l1,jml_matrix_size_type l2);		//把矩阵A 的第l1行全部替换为B的第l2行
jml_matrix *			jml_matrix_replace_row			(jml_matrix* A,jml_matrix* B,jml_matrix_size_type r1,jml_matrix_size_type r2);		//把矩阵A 的第r1列全部替换为B的第r2列
jml_matrix *			jml_matrix_toup					(jml_matrix* A);													//矩阵化成上三角阵，A的原地运算
jml_matrix *			jml_matrix_adjugate				(jml_matrix* A);													//矩阵转换为伴随矩阵，A的原地运算
jml_matrix *			jml_matrix_cramer				(jml_matrix* A,jml_matrix* B);										//以A为系数矩阵，B为常数矩阵解方程，注意会生成一个新矩阵

#if JBL_STREAM_ENABLE==1
jml_matrix*				jml_matrix_view_put						(jml_matrix* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 line,unsigned char * varname,unsigned char * func,unsigned char * file);	//从out浏览一个字符串
#define					jml_matrix_view(x)						jml_matrix_view_put(x,jbl_stream_stdout,1,JBL_VIEW_DEFAULT_TABS,__LINE__,UC #x,UC __FUNCTION__,UC __FILE__)//浏览一个字符串
#endif



#endif
#endif
