/* Copyright (c) [2020] juruoyun developer team
  Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#include "jml_vector.h"
#if JML_VECTOR_ENABLE==1
#include <math.h>
jbl_var_operators_new(jml_vector_operators,jml_vector_free,jml_vector_copy,jml_vector_space_ship,NULL,NULL,NULL);
#define _d(this,i)		((this)->data[i])
#define _f(this,i)	    for(jml_vector_size_type i=0;i<this->n;++i)
#define _ff(this,i,n)	for(jml_vector_size_type i=0;i<n;++i)

jml_vector* jml_vector_new(jml_vector_size_type n)
{
	jml_vector * this=jbl_malloc(sizeof(jml_vector)+n*sizeof(jml_vector_data_type));
	jbl_gc_init(this);
	jbl_gc_plus(this);
	jbl_var_set_operators(this,&jml_vector_operators);
	this->n=n;
	for(jml_vector_size_type i=0;i<n;this->data[i]=0,++i);
	return this;
}
jml_vector *jml_vector_copy(jml_vector *that)
{
	if(!that)return NULL;
	jbl_gc_plus(that);
	return that;
}
jml_vector* jml_vector_free(jml_vector* this)
{
	if(!this)return NULL;
	jbl_gc_minus(this);
	if(!jbl_gc_refcnt(this))
	{
		(jbl_gc_is_ref(this)?jml_vector_free((jml_vector*)(((jbl_reference*)this)->ptr)):0);
		jbl_free(this);
	}
	return NULL;
}
jml_vector *jml_vector_extend_to(jml_vector *this,jml_vector_size_type n,jbl_uint8 small,jml_vector **pthi)
{
	if(!this)this=jml_vector_new(n);		
	jbl_reference *ref=NULL;jml_vector *thi=jbl_refer_pull_keep_father(this,&ref);
	jbl_uint8 flag=0;
	jml_vector_size_type nn=0;
	if(small)	flag=1,nn=n;
	else if(n<=thi->n&&jbl_gc_refcnt(thi)==1)flag=0;
	else		flag=1,nn=jbl_max(n,thi->n);
	if(flag)
	{
		jml_vector *tmp=jml_vector_new(nn);
        nn=jbl_min(tmp->n,thi->n);
		_ff(thi,i,nn)_d(tmp,i)=_d(thi,i);
		jml_vector_free(thi);		
		thi=tmp;
	}
	if(ref)		ref->ptr=thi;
	else		this=thi;
	if(pthi)	*pthi=thi;
	return this;
}
char jml_vector_space_ship(jml_vector *this,jml_vector *that)
{
	jml_vector *thi=jbl_refer_pull(this);	
	jml_vector *tha=jbl_refer_pull(that);	
	if(thi==tha){return 0;}if(thi==NULL){return -1;}if(tha==NULL){return 1;}	
	if(thi->n!=tha->n)
		return (thi->n<tha->n)?-1:1;
	for(jbl_string_size_type i=0;i<thi->n;++i)
		if(thi->data[i]<tha->data[i])
			return -1;
		else if(thi->data[i]>tha->data[i])
			return 1;
	return 0;	
}
jml_vector_data_type jml_vector_get(jml_vector *this,jml_vector_size_type n)
{
	if(!this)jbl_exception("NULL POINTER");
	jml_vector *thi=jbl_refer_pull(this);
	if(n>=thi->n)jbl_exception("VECTOR OVREFLOW");
	return _d(thi,n);
}
jml_vector *jml_vector_set(jml_vector *this,jml_vector_size_type n,jml_vector_data_type v)
{
	jml_vector *thi;this=jml_vector_extend_to(this,n+1,0,&thi);		
	_d(thi,n)=v;	
	return this;
}
jml_vector* jml_vector_add(jml_vector* A,jml_vector* B)
{
	if(!B)return A;
	if(!A)return jml_vector_copy(B);
	B=jbl_refer_pull(B);
	jml_vector *a;A=jml_vector_extend_to(A,0,0,&a);
	if(a->n!=B->n)jbl_exception("VECTOR OVREFLOW");
	_f(a,i)_d(a,i)+=_d(B,i);
	return A;
}
jml_vector* jml_vector_minus(jml_vector* A,jml_vector* B)
{
	if(!B)return A;
	if(!A)return jml_vector_negative(jml_vector_copy(B));
	B=jbl_refer_pull(B);
	jml_vector *a;A=jml_vector_extend_to(A,0,0,&a);
	if(a->n!=B->n)jbl_exception("VECTOR OVREFLOW");
	_f(a,i)_d(a,i)-=_d(B,i);
	return A;
}
jml_vector* jml_vector_negative(jml_vector* A)
{
	if(!A)return NULL;
	jml_vector *a;A=jml_vector_extend_to(A,0,0,&a);
	_f(a,i)_d(a,i)=-_d(a,i);
	return A;
}
jml_vector* jml_vector_number_multiply(jml_vector* A,jml_vector_data_type v)
{
	if(!A)return NULL;
	jml_vector *a;A=jml_vector_extend_to(A,0,0,&a);
	_f(a,i)_d(a,i)=_d(a,i)*v;
	return A;
}
jml_vector_data_type jml_vector_multiply(jml_vector* A,jml_vector* B)
{
	if(!A||!B)return 0;
	A=jbl_refer_pull(A);
	B=jbl_refer_pull(B);
	if(A->n!=B->n)jbl_exception("VECTOR OVREFLOW");
	jml_vector_data_type ans=0;
	_f(A,i)ans+=_d(A,i)*_d(B,i);
	return ans;
}
jml_vector_data_type jml_vector_length(jml_vector* A)
{
	if(!A)return 0;
	A=jbl_refer_pull(A);
	jml_vector_data_type ans=0;
	_f(A,i)ans+=_d(A,i)*_d(A,i);
	return sqrt((double)ans);
}
jml_vector *jml_vector_get_E(jml_vector* A)
{
	if(!A)return NULL;
	jml_vector *a;A=jml_vector_extend_to(A,0,0,&a);
	jml_vector_data_type ans=0;
	_f(A,i)ans+=_d(A,i)*_d(A,i);
	ans=sqrt((double)ans);
    if(ans)_f(a,i)_d(a,i)=_d(a,i)/ans;
	return A;
}
double jml_vector_get_theta(jml_vector* A,jml_vector* B)
{
	if(!A||!B)return 0;
	A=jbl_refer_pull(A);
	B=jbl_refer_pull(B);
	if(A->n!=B->n)jbl_exception("VECTOR OVREFLOW");
	jml_vector_data_type ans=0,t1=0,t2=0;
	_f(A,i)ans+=_d(A,i)*_d(B,i),t1+=_d(A,i)*_d(A,i),t2+=_d(B,i)*_d(B,i);
	return acos((double)ans/sqrt((double)t1)/sqrt((double)t2));
}
#if JML_MATRIX_ENABLE==1
#define _md(this,r,c)		(*(this->data+r*this->column+c))
jml_matrix *jml_vector_lay_row(jml_matrix_size_type m,jml_vector * v[])
{
    if(!v)return NULL;
    jml_vector * vv;
    vv=jbl_refer_pull(v[0]);
    jml_matrix * m1=jml_matrix_new(m,vv->n);  
    for(jml_matrix_size_type i=0;i<m;++i)
    {
        vv=jbl_refer_pull(v[i]);
        if(m1->column!=vv->n)
        {
            m1=jml_matrix_free(m1);
            jbl_exception("VECTOR OVREFLOW");
        }
        _f(vv,j)_md(m1,i,j)=_d(vv,j);
    }
    return m1;
}
jml_matrix *jml_vector_lay_column(jml_matrix_size_type m,jml_vector * v[])
{
    if(!v)return NULL;
    jml_vector * vv;
    vv=jbl_refer_pull(v[0]);
    jml_matrix * m1=jml_matrix_new(vv->n,m);  
    for(jml_matrix_size_type i=0;i<m;++i)
    {
        vv=jbl_refer_pull(v[i]);
        if(m1->row!=vv->n)
        {
            m1=jml_matrix_free(m1);
            jbl_exception("VECTOR OVREFLOW");
        }
        _f(vv,j)_md(m1,j,i)=_d(vv,j);
    }
    return m1;
}
#endif

#if JBL_STREAM_ENABLE==1
jml_vector* jml_vector_view_put(jml_vector* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 row,unsigned char * varname,unsigned char * func,unsigned char * file)
{
	jml_vector *thi;if(jbl_stream_view_put_format(thi=jbl_refer_pull(this),out,format,tabs,UC"jml_vector",row,varname,func,file)){jbl_stream_push_char(out,'\n');return this;}
	jbl_stream_push_chars(out,UC" n:");jbl_stream_push_uint(out,thi->n);
	jbl_stream_push_char(out,'\n');
	++tabs;
	for(jml_vector_size_type i=0;i<thi->n;++i)
	{
		for(jbl_uint32 j=0;j<tabs;jbl_stream_push_char(out,'\t'),++j);
		jml_vector_data_push(out,_d(thi,i)),jbl_stream_push_char(out,'\t');
	}
    jbl_stream_push_char(out,'\n');
	return this;
}
#endif
#endif
