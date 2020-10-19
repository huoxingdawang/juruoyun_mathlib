/* Copyright (c) [2020] juruoyun developer team
   Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#include "jml_permutation.h"
#if JML_MATRIX_ENABLE==1
jbl_var_operators_new(jml_permutation_operators,jml_permutation_free,jml_permutation_copy,NULL,NULL,NULL,NULL);
jml_permutation* jml_permutation_new(jbl_uint64 size)
{
	jml_permutation * this=jbl_malloc(sizeof(jml_permutation)+size*sizeof(jbl_uint64));
	jbl_gc_init(this);
	jbl_gc_plus(this);
	jbl_var_set_operators(this,&jml_permutation_operators);
	this->size=size;
	this->ji=0;
	for(jbl_uint64 i=0;i<size;this->data[i]=i,++i);
	return this;
}
jml_permutation *jml_permutation_copy(jml_permutation *that)
{
	if(!that)return NULL;
	jbl_gc_plus(that);
	return that;
}
jml_permutation* jml_permutation_free(jml_permutation* this)
{
	if(!this)return NULL;
	jbl_gc_minus(this);
	if(!jbl_gc_refcnt(this))
	{
		(jbl_gc_is_ref(this)?jml_permutation_free((jml_permutation*)(((jbl_reference*)this)->ptr)):0);
		jbl_free(this);
	}
	return NULL;
}
jml_permutation *jml_permutation_extend_to(jml_permutation *this,jbl_uint64 size,jml_permutation **pthi)
{
	if(!this&&size)this=jml_permutation_new(size);
	jbl_reference *ref=NULL;jml_permutation *thi=jbl_refer_pull_keep_father(this,&ref);
	if(jbl_gc_refcnt(thi)!=1&&(thi->size==size||size==0))
	{
		jml_permutation *tmp=jml_permutation_new(thi->size);
		for(jbl_uint64 i=0;i<thi->size;tmp->data[i]=thi->data[i],++i);		
		jml_permutation_free(thi);		
		thi=tmp;
	}
	else if(thi->size!=size&&size!=0)
	{
		thi=jml_permutation_free(thi);
		thi=jml_permutation_new(size);
	}
	if(ref)		ref->ptr=thi;
	else		this=thi;
	if(pthi)	*pthi=thi;
	return this;
}
char jml_permutation_next(jml_permutation *this)
{
	jml_permutation *thi;this=jml_permutation_extend_to(this,0,&thi);
	jbl_uint64 first=0,last=thi->size,i=last-2,j=last-1,tmp;
	while(i!=-1ULL&&thi->data[i]>=thi->data[i+1])i--;
	if(i==-1ULL)return 0;
	while(thi->data[j]<=thi->data[i])--j;
	tmp=thi->data[i],thi->data[i]=thi->data[j],thi->data[j]=tmp,++thi->ji;
	first=i+1;last--;
	while(first<last)tmp=thi->data[first],thi->data[first]=thi->data[last],thi->data[last]=tmp,++first,--last,++thi->ji;
	thi->ji&=1;
	return 1;	
}
#if JBL_STREAM_ENABLE==1
jml_permutation* jml_permutation_view_put(jml_permutation* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 line,unsigned char * varname,unsigned char * func,unsigned char * file)
{
	jml_permutation *thi;if(jbl_stream_view_put_format(thi=jbl_refer_pull(this),out,format,tabs,UC"jml_permutation",line,varname,func,file)){jbl_stream_push_char(out,'\n');return this;}
	jbl_stream_push_char(out,':');
	for(jbl_uint64 i=0;i<thi->size;++i)jbl_stream_push_uint(out,thi->data[i]),jbl_stream_push_char(out,' ');
	jbl_stream_push_char(out,'\n');
	return this;
}
#endif
#endif
