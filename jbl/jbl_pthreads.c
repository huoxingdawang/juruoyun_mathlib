/* Copyright (c) [2020] juruoyun developer team
   Juruoyun basic lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#include "jbl_pthreads.h"
#if JBL_PTHREAD_ENABLE==1
#include "jbl_ying.h"
#include "jbl_malloc.h"
#include "jbl_gc.h"
jbl_pthreads * jbl_pthreads_new(jbl_pthreads_size_type size)
{
    if(size==0)size=8;
    size=1U<<(jbl_highbit(size-1)+1);
	jbl_pthreads * this=jbl_malloc(sizeof(jbl_pthreads)+sizeof(jbl_pthread)*size);
	jbl_gc_init(this);
	jbl_gc_plus(this);//增加引用计数
	jbl_var_set_operators(this,&jbl_pthreads_operators);
	jbl_pthread_lock_init(this);
	this->len=0;
	this->size=size;
	return this;	
}
jbl_pthreads* jbl_pthreads_free(jbl_pthreads *this)
{
	if(!this)return NULL;
    jbl_pthread_lock_init(this);
	jbl_gc_minus(this);
	if(!jbl_gc_refcnt(this))
	{
		if(jbl_gc_is_ref(this))
			jbl_pthreads_free((jbl_pthreads*)(((jbl_reference*)this)->ptr));
		jbl_free(this);
	}
	return NULL;
}
JBL_INLINE jbl_pthreads *jbl_pthreads_copy(jbl_pthreads *that)
{
	if(!that)return NULL;
    jbl_pthread_lock_init(that);
	jbl_gc_plus(that);
    jbl_pthread_lock_unlock(that);    
	return that;
}
jbl_pthreads *jbl_pthreads_extend_to(jbl_pthreads *this,jbl_pthreads_size_type size,jbl_uint8 add,jbl_pthreads **pthi)
{
	if(!this)
    {
        this=jbl_pthreads_new(size);
        if(pthi)	*pthi=this;
        return this;
	}
    jbl_reference *ref=NULL;jbl_pthreads *thi=jbl_refer_pull_keep_father_rwlock(this,&ref);
	size+=thi->len*(add&1);
    if(size==0)size=8;
	size=1U<<(jbl_highbit(size-1)+1);
    if((size>thi->size)||(jbl_gc_refcnt(thi)!=1))
    {
        jbl_pthreads *tmp=jbl_pthreads_new(size);
        jbl_pthread_lock_wrlock(tmp);
        jbl_memory_copy(&tmp->threads,&thi->threads,sizeof(jbl_pthread)*thi->len);
        jbl_pthread_lock_unlock(thi);
        jbl_pthreads_free(thi);
        thi=tmp;
        if(ref)		ref->ptr=thi;
        else		this=thi;
	}
    if(pthi)	*pthi=thi;
    jbl_refer_pull_unlock(this);
    return this;
}
jbl_pthreads * jbl_pthreads_creat_thread(jbl_pthreads *this,void *func(void *),jbl_pthreads_size_type n,void * data)
{
    jbl_pthreads *thi;this=jbl_pthreads_extend_to(this,n,1,&thi);
    jbl_pthread_lock_wrlock(thi);
    for(jbl_pthreads_size_type i=0;i<n;++i)
    {
        if(data)
            pthread_create(&thi->threads[thi->len].thread,NULL,func,data);
        ++thi->len;
    }
    jbl_pthread_lock_unlock(thi);
    return this;
}
jbl_pthreads * jbl_pthreads_wait(jbl_pthreads *this)
{
    jbl_pthreads *thi;this=jbl_pthreads_extend_to(this,0,1,&thi);
    jbl_pthread_lock_wrlock(thi);
    for(jbl_pthreads_size_type i=0;i<thi->len;++i)
        pthread_join(thi->threads[i].thread,NULL);
    thi->len=0;
    jbl_pthread_lock_unlock(thi);
    return this;
}
#else

#endif
