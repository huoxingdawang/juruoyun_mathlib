/* Copyright (c) [2020] juruoyun developer team
   Juruoyun basic lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#ifndef __JBL_PTHREADS_H
#define __JBL_PTHREADS_H
#include "jbl_pthread_config.h"
#if JBL_PTHREAD_ENABLE==1
#include "jbl_pthread.h"
#include "jbl_gc.h"
#include "jbl_var.h"

typedef struct __jbl_pthread
{
	pthread_t thread;
}jbl_pthread;
typedef struct __jbl_pthreads
{
	jbl_gc 					gc;
	jbl_var_ops_define		;
	jbl_pthread_lock_define	;
	jbl_pthreads_size_type	len;
	jbl_pthreads_size_type	size;
	jbl_pthread             threads[];
}jbl_pthreads;
jbl_pthreads *   jbl_pthreads_new           (jbl_pthreads_size_type size);
jbl_pthreads *   jbl_pthreads_free          (jbl_pthreads *this);
jbl_pthreads *   jbl_pthreads_copy          (jbl_pthreads *that);
jbl_pthreads *   jbl_pthreads_creat_thread  (jbl_pthreads *this,void *func(void *),jbl_pthreads_size_type n,void * data);
jbl_pthreads *   jbl_pthreads_wait          (jbl_pthreads *this);


#endif
#endif
