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
#if JBL_MATRIX_ENABLE==1
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
jml_matrix *	jml_matrix_new					(jml_matrix_size_type line,jml_matrix_size_type row);	//新建一个矩阵
jml_matrix *	jml_matrix_newE					(jml_matrix_size_type n);								//新建一个n行n列单位阵
jml_matrix *	jml_matrix_copy					(jml_matrix *that);										//复制一个矩阵
jml_matrix *	jml_matrix_free					(jml_matrix *this);										//释放一个矩阵
#define			jml_matrix_extend(a,b,c)		jml_matrix_extend_to((a),(b),(c),1,NULL)				//将矩阵修改为b*c大小(多于部分直接丢弃，不足补零)
jml_matrix *	jml_matrix_extend_to			(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row,jbl_uint8 small,jml_matrix **pth);							//扩展字符串this到size字节
jml_matrix *	jml_matrix_set					(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row,jml_matrix_data_type v);
jml_matrix *	jml_matrix_add					(jml_matrix* A,jml_matrix* B);
jml_matrix *	jml_matrix_minus				(jml_matrix* A,jml_matrix* B);
jml_matrix *	jml_matrix_negative				(jml_matrix* A);
jml_matrix *	jml_matrix_number_multiply		(jml_matrix* A,jml_matrix_data_type v);
jml_matrix *	jml_matrix_multiply				(jml_matrix* A,jml_matrix* B,jml_matrix* C);
jml_matrix *	jml_matrix_transpose			(jml_matrix* A);
jml_matrix *	jml_matrix_pow					(jml_matrix* A,jml_matrix* D,jbl_uint64 n);
char			jml_matrix_space_ship			(jml_matrix *this,jml_matrix *that);					//比较两个矩阵
#define			jml_matrix_if_equal(x,y)		(jml_matrix_space_ship(x,y)==0)							//判断this是否=that
#define			jml_matrix_if_big(x,y)			(jml_matrix_space_ship(x,y)>0)							//判断this是否>that
#define			jml_matrix_if_small(x,y)		(jml_matrix_space_ship(x,y)<0)							//判断this是否<that
#define			jml_matrix_if_equal_small(x,y)	(jml_matrix_space_ship(x,y)<=0)							//判断this是否>=that
#define			jml_matrix_if_equal_big(x,y)	(jml_matrix_space_ship(x,y)>=0)							//判断this是否<=that


jml_matrix_data_type	jml_matrix_get			(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row);

#if JBL_STREAM_ENABLE==1
jml_matrix*				jml_matrix_view_put						(jml_matrix* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 line,unsigned char * varname,unsigned char * func,unsigned char * file);	//从out浏览一个字符串
#define					jml_matrix_view(x)						jml_matrix_view_put(x,jbl_stream_stdout,1,JBL_VIEW_DEFAULT_TABS,__LINE__,UC #x,UC __FUNCTION__,UC __FILE__)//浏览一个字符串
#endif



#endif
#endif
