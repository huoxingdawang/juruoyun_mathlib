/* Copyright (c) [2020] juruoyun developer team
   Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JBL_PERMUTATION_H
#define __JBL_PERMUTATION_H
#include "jml_permutation_config.h"
#if JBL_PERMUTATION_ENABLE==1
#include "jml_ying.h"
typedef struct __jml_permutation
{
	jbl_gc						gc;
	jbl_var_ops_define			;
	jbl_pthread_lock_define		;
	jbl_uint64					size;
	jbl_uint64					ji;
	jbl_uint64					data[];
}jml_permutation;
jml_permutation *	jml_permutation_new					(jbl_uint64 size);												//新建一个矩阵
jml_permutation *	jml_permutation_copy				(jml_permutation *that);										//复制一个矩阵
jml_permutation *	jml_permutation_free				(jml_permutation *this);										//释放一个矩阵
#define				jml_permutation_extend(a,b)			jml_permutation_extend_to((a),b,NULL)							//将矩阵修改为b*c大小(多于部分直接丢弃，不足补零)
jml_permutation *	jml_permutation_extend_to			(jml_permutation *this,jbl_uint64 size,jml_permutation **pth);	//扩展字符串this到size字节
char				jml_permutation_next				(jml_permutation *this);
#if JBL_STREAM_ENABLE==1
jml_permutation*	jml_permutation_view_put			(jml_permutation* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 line,unsigned char * varname,unsigned char * func,unsigned char * file);	//从out浏览一个字符串
#define				jml_permutation_view(x)				jml_permutation_view_put(x,jbl_stream_stdout,1,JBL_VIEW_DEFAULT_TABS,__LINE__,UC #x,UC __FUNCTION__,UC __FILE__)//浏览一个字符串
#endif



#endif
#endif
