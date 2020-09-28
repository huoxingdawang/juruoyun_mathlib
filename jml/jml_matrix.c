/* Copyright (c) [2020] juruoyun developer team
   Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#include "jml_matrix.h"
#if JBL_MATRIX_ENABLE==1
jbl_var_operators_new(jml_matrix_operators,jml_matrix_free,jml_matrix_copy,NULL,NULL,NULL,NULL);
#define _d(this,l,r)		(*(this->data+l*this->row+r))
#define _f(this,i,j)		for(jml_matrix_size_type i=0;i<this->line;++i)for(jml_matrix_size_type j=0;j<this->row;++j)
#define _ff(this,i,j,l,r)	for(jml_matrix_size_type i=0;i<l;++i)for(jml_matrix_size_type j=0;j<r;++j)
jml_matrix* jml_matrix_new(jml_matrix_size_type line,jml_matrix_size_type row)
{
	jml_matrix * this=jbl_malloc(sizeof(jml_matrix)+line*row*sizeof(jml_matrix_data_type));
	jbl_gc_init(this);
	jbl_gc_plus(this);
	jbl_var_set_operators(this,&jml_matrix_operators);
	this->line=line;
	this->row=row;
	for(jml_matrix_size_type i=0,n=line*row;i<n;this->data[i]=0,++i);
	return this;
}
jml_matrix *jml_matrix_copy(jml_matrix *that)
{
	if(!that)return NULL;
	jbl_gc_plus(that);
	return that;
}
jml_matrix* jml_matrix_free(jml_matrix* this)
{
	if(!this)return NULL;
	jbl_gc_minus(this);
	if(!jbl_gc_refcnt(this))
	{
		(jbl_gc_is_ref(this)?jml_matrix_free((jml_matrix*)(((jbl_reference*)this)->ptr)):0);
		jbl_free(this);
	}
	return NULL;
}
jml_matrix *jml_matrix_extend_to(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row,jbl_uint8 small,jml_matrix **pthi)
{
	if(!this)this=jml_matrix_new(line,row);		
	jbl_reference *ref=NULL;jml_matrix *thi=jbl_refer_pull_keep_father(this,&ref);
	jbl_uint8 flag=0;
	jml_matrix_size_type l=0,r=0;
	if(small)	flag=1,l=line,r=row;
	else if(line<=thi->line&&row<=thi->row&&jbl_gc_refcnt(thi)==1)flag=0;
	else		flag=1,l=jbl_max(line,thi->line),r=jbl_max(line,thi->row);
	if(flag)
	{
		jml_matrix *tmp=jml_matrix_new(l,r);
		_ff(thi,i,j,l,r)_d(tmp,i,j)=_d(thi,i,j);
		jml_matrix_free(thi);		
		thi=tmp;
	}
	if(ref)		ref->ptr=thi;
	else		this=thi;
	if(pthi)	*pthi=thi;
	return this;
}
jml_matrix_data_type jml_matrix_get(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row)
{
	if(!this)jbl_exception("NULL POINTER");
	jml_matrix *thi=jbl_refer_pull(this);
	if(line>=thi->line||row>=thi->row)jbl_exception("MATRIX OVREFLOW");
	return _d(thi,line,row);
}
jml_matrix *jml_matrix_set(jml_matrix *this,jml_matrix_size_type line,jml_matrix_size_type row,jml_matrix_data_type v)
{
	if(!this)this=jml_matrix_new(line,row);
	jml_matrix *thi;this=jml_matrix_extend_to(this,0,0,0,&thi);		
	_d(thi,line,row)=v;	
	return this;
}
jml_matrix* jml_matrix_add(jml_matrix* A,jml_matrix* B)
{
	if(!B)return A;
	if(!A)return jml_matrix_copy(B);
	B=jbl_refer_pull(B);
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(a->line!=B->line||a->row!=B->row)jbl_exception("MATRIX OVREFLOW");
	_f(a,i,j)_d(a,i,j)+=_d(B,i,j);
	return A;
}
jml_matrix* jml_matrix_minus(jml_matrix* A,jml_matrix* B)
{
	if(!B)return A;
	if(!A)return jml_matrix_copy(B);
	B=jbl_refer_pull(B);
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(a->line!=B->line||a->row!=B->row)jbl_exception("MATRIX OVREFLOW");
	_f(a,i,j)_d(a,i,j)-=_d(B,i,j);
	return A;
}
jml_matrix* jml_matrix_negative(jml_matrix* A)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	_f(a,i,j)_d(a,i,j)=-_d(a,i,j);
	return A;
}
jml_matrix* jml_matrix_number_multiply(jml_matrix* A,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	_f(a,i,j)_d(a,i,j)=_d(a,i,j)*v;
	return A;
}
jml_matrix* jml_matrix_multiply(jml_matrix* A,jml_matrix* B,jml_matrix* C)
{
	if(!A)return jml_matrix_add(B,C);
	if(!B)return jml_matrix_add(A,C);
	A=jbl_refer_pull(A);
	B=jbl_refer_pull(B);
	if(A->row!=B->line)jbl_exception("MATRIX OVREFLOW");
	jml_matrix *c;C=jml_matrix_extend_to(C,A->line,B->row,1,&c);
	for(jml_matrix_size_type i=0;i<A->line;++i)
		for(jml_matrix_size_type j=0;j<B->row;++j)
			for(jml_matrix_size_type k=0;k<B->line;++k)
				_d(c,i,j)+=_d(A,i,k)*_d(B,k,j);
	return C;
}
jml_matrix* jml_matrix_transpose(jml_matrix* A)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(a->row!=a->line)jbl_exception("MATRIX OVREFLOW");
	for(jml_matrix_size_type i=0;i<A->line;++i)
		for(jml_matrix_size_type j=0;j<i;++j)
		{
			jml_matrix_data_type c=_d(a,i,j);
			_d(a,i,j)=_d(a,j,i);
			_d(a,j,i)=c;
		}
	return A;
}



#if JBL_STREAM_ENABLE==1
jml_matrix* jml_matrix_view_put(jml_matrix* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 line,unsigned char * varname,unsigned char * func,unsigned char * file)
{
	jml_matrix *thi;if(jbl_stream_view_put_format(thi=jbl_refer_pull(this),out,format,tabs,UC"jml_matrix",line,varname,func,file)){jbl_stream_push_char(out,'\n');return this;}
	jbl_stream_push_chars(out,UC" line:");jbl_stream_push_uint(out,thi->line);
	jbl_stream_push_chars(out,UC" row:");jbl_stream_push_uint(out,thi->row);
	jbl_stream_push_char(out,'\n');
	++tabs;
#if JML_MATRIX_PRINT_LINENO ==1
	for(jbl_int32 j=0;j<tabs+1;jbl_stream_push_char(out,'\t'),++j);
	for(jml_matrix_size_type j=0;j<thi->row;++j)
		jbl_stream_push_uint(out,j),jbl_stream_push_char(out,'\t');		
	jbl_stream_push_char(out,'\n');
#endif		
	for(jml_matrix_size_type i=0;i<thi->line;++i)
	{
		for(jbl_int32 j=0;j<tabs;jbl_stream_push_char(out,'\t'),++j);
#if JML_MATRIX_PRINT_LINENO ==1
		jbl_stream_push_uint(out,i),jbl_stream_push_char(out,'\t');		
#endif		
		for(jml_matrix_size_type j=0;j<thi->row;++j)
			jbl_stream_push_double(out,_d(thi,i,j)),jbl_stream_push_char(out,'\t');
		jbl_stream_push_char(out,'\n');
	}
	return this;
}
#endif
#endif
