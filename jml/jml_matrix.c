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
#if JML_MATRIX_ENABLE==1
#include "jml_permutation.h"
jbl_var_operators_new(jml_matrix_operators,jml_matrix_free,jml_matrix_copy,jml_matrix_space_ship,NULL,NULL,NULL);
#define _d(this,r,c)		(*(this->data+r*this->column+c))
#define _f(this,i,j)		for(jml_matrix_size_type i=0;i<this->row;++i)for(jml_matrix_size_type j=0;j<this->column;++j)
#define _ff(this,i,j,r,c)	for(jml_matrix_size_type i=0;i<r;++i)for(jml_matrix_size_type j=0;j<c;++j)
jml_matrix* jml_matrix_new(jml_matrix_size_type row,jml_matrix_size_type column)
{
	jml_matrix * this=jbl_malloc(sizeof(jml_matrix)+row*column*sizeof(jml_matrix_data_type));
	jbl_gc_init(this);
	jbl_gc_plus(this);
	jbl_var_set_operators(this,&jml_matrix_operators);
	this->row=row;
	this->column=column;
	for(jml_matrix_size_type i=0,n=row*column;i<n;this->data[i]=0,++i);
	return this;
}
jml_matrix* jml_matrix_newE(jml_matrix_size_type n)
{
	jml_matrix * this=jml_matrix_new(n,n);
	for(jml_matrix_size_type i=0;i<n;_d(this,i,i)=1,++i);
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
jml_matrix *jml_matrix_extend_to(jml_matrix *this,jml_matrix_size_type row,jml_matrix_size_type column,jbl_uint8 small,jml_matrix **pthi)
{
	if(!this)this=jml_matrix_new(row,column);		
	jbl_reference *ref=NULL;jml_matrix *thi=jbl_refer_pull_keep_father(this,&ref);
	jbl_uint8 flag=0;
	jml_matrix_size_type r=0,c=0;
	if(small)	flag=1,r=row,c=column;
	else if(row<=thi->row&&column<=thi->column&&jbl_gc_refcnt(thi)==1)flag=0;
	else		flag=1,r=jbl_max(row,thi->row),c=jbl_max(column,thi->column);
	if(flag)
	{
		jml_matrix *tmp=jml_matrix_new(r,c);
        r=jbl_min(tmp->row,thi->row);
        c=jbl_min(tmp->column,thi->column);
		_ff(thi,i,j,r,c)_d(tmp,i,j)=_d(thi,i,j);
		jml_matrix_free(thi);		
		thi=tmp;
	}
	if(ref)		ref->ptr=thi;
	else		this=thi;
	if(pthi)	*pthi=thi;
	return this;
}
jml_matrix_data_type jml_matrix_get(jml_matrix *this,jml_matrix_size_type row,jml_matrix_size_type column)
{
	if(!this)jbl_exception("NULL POINTER");
	jml_matrix *thi=jbl_refer_pull(this);
	if(row>=thi->row||column>=thi->column)jbl_exception("MATRIX OVREFLOW");
	return _d(thi,row,column);
}
jml_matrix *jml_matrix_set(jml_matrix *this,jml_matrix_size_type row,jml_matrix_size_type column,jml_matrix_data_type v)
{
	jml_matrix *thi;this=jml_matrix_extend_to(this,row+1,column+1,0,&thi);		
	_d(thi,row,column)=v;	
	return this;
}
jml_matrix* jml_matrix_add(jml_matrix* A,jml_matrix* B)
{
	if(!B)return A;
	if(!A)return jml_matrix_copy(B);
	B=jbl_refer_pull(B);
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(a->row!=B->row||a->column!=B->column)jbl_exception("MATRIX OVREFLOW");
	_f(a,i,j)_d(a,i,j)+=_d(B,i,j);
	return A;
}
jml_matrix* jml_matrix_minus(jml_matrix* A,jml_matrix* B)
{
	if(!B)return A;
	if(!A)return jml_matrix_negative(jml_matrix_copy(B));
	B=jbl_refer_pull(B);
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(a->row!=B->row||a->column!=B->column)jbl_exception("MATRIX OVREFLOW");
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
jml_matrix* jml_matrix_multiply(jml_matrix* A,jml_matrix* B)
{
	if(!A||!B)return NULL;
	A=jbl_refer_pull(A);
	B=jbl_refer_pull(B);
	if(A->column!=B->row)jbl_exception("MATRIX OVREFLOW");
	jml_matrix *C=jml_matrix_new(A->row,B->column);
	for(jml_matrix_size_type i=0;i<A->row;++i)
		for(jml_matrix_size_type j=0;j<B->column;++j)
			for(jml_matrix_size_type k=0;k<B->row;++k)
				_d(C,i,j)+=_d(A,i,k)*_d(B,k,j);
	return C;
}
jml_matrix* jml_matrix_transpose(jml_matrix* A)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(a->column!=a->row)jbl_exception("MATRIX OVREFLOW");
	for(jml_matrix_size_type i=0;i<A->row;++i)
		for(jml_matrix_size_type j=0;j<i;++j)
		{
			jml_matrix_data_type c=_d(a,i,j);
			_d(a,i,j)=_d(a,j,i);
			_d(a,j,i)=c;
		}
	return A;
}
jml_matrix* jml_matrix_pow(jml_matrix* A,jbl_uint64 n)
{
	if(!A)return NULL;
	A=jbl_refer_pull(A);
	if(A->row!=A->column)jbl_exception("POW NOT SQUARE MATRIX");
	jml_matrix *B=jml_matrix_newE(A->row),*C=NULL;
	while(n--)
		C=jml_matrix_multiply(B,A),B=jml_matrix_free(B),B=C;
	return B;
}
char jml_matrix_space_ship(jml_matrix *this,jml_matrix *that)
{
	jml_matrix *thi=jbl_refer_pull(this);	
	jml_matrix *tha=jbl_refer_pull(that);	
	if(thi==tha){return 0;}if(thi==NULL){return -1;}if(tha==NULL){return 1;}	
	if(thi->row*thi->column!=tha->row*tha->column)
		return (thi->row*thi->column<tha->row*tha->column)?-1:1;
	for(jbl_string_size_type i=0,n=thi->row*thi->column;i<n;++i)
		if(thi->data[i]<tha->data[i])
			return -1;
		else if(thi->data[i]>tha->data[i])
			return 1;
	return 0;	
}
jml_matrix *jml_matrix_minor(jml_matrix *A,jml_matrix_size_type row,jml_matrix_size_type column)
{
	if(!A)return NULL;
	A=jbl_refer_pull(A);
	if(row>=A->row||column>=A->column)return NULL;
	jml_matrix *C=jml_matrix_new(A->row-1,A->column-1);
	for(jml_matrix_size_type i=0,ii=0;i<A->row;++i)
		if(i!=row)
		{
			for(jml_matrix_size_type j=0,jj=0;j<A->column;++j)
				if(j!=column)
					_d(C,ii,jj)=_d(A,i,j),++jj;
			++ii;
		}
	return C;
}
jml_matrix *jml_matrix_cofactor(jml_matrix *A,jml_matrix_size_type row,jml_matrix_size_type column)
{
	return ((row+column)&1)?jml_matrix_negative(jml_matrix_minor(A,row,column)):jml_matrix_minor(A,row,column);
}
jml_matrix_data_type jml_matrix_determinant(jml_matrix *A)
{
	if(!A)return 0;
	A=jbl_refer_pull(A);
	if(A->row!=A->column)jbl_exception("DETERMINANT NOT SQUARE MATRIX");
#if JML_MATRIX_DETERMINANT_USE_TOUP==0
	jml_matrix_data_type result=0;
	jml_permutation* p1=jml_permutation_new(A->column);
	do
	{
		jml_matrix_data_type temp=p1->ji?-1:1;
		for(jml_matrix_size_type i=0,j=0;j<A->column;temp*=_d(A,i,p1->data[j]),++i,++j);
		result+=temp;
	}while(jml_permutation_next(p1));
	p1=jml_permutation_free(p1);
#else
	jml_matrix_data_type result=1;
	jml_matrix * tmp=jml_matrix_toup(jml_matrix_copy(A),NULL);
//	jml_matrix_view(tmp);
	for(jml_matrix_size_type i=0;i<tmp->row;++i)result*=_d(tmp,i,i);
	jml_matrix_free(tmp);
#endif
	return result;
}
jml_matrix* jml_matrix_swap_row(jml_matrix* A,jml_matrix_size_type r1,jml_matrix_size_type r2)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(r1==r2||r1>=a->row||r2>=a->row)return A;
	for(jml_matrix_size_type i=0;i<a->column;++i)
	{
		jml_matrix_data_type c=_d(a,r1,i);
		_d(a,r1,i)=_d(a,r2,i);
		_d(a,r2,i)=c;
	}
	return A;
}
jml_matrix* jml_matrix_swap_column(jml_matrix* A,jml_matrix_size_type c1,jml_matrix_size_type c2)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(c1==c2||c1>=a->column||c2>=a->column)return A;
	for(jml_matrix_size_type i=0;i<a->row;++i)
	{
		jml_matrix_data_type c=_d(a,i,c1);
		_d(a,i,c1)=_d(a,i,c2);
		_d(a,i,c2)=c;
	}
	return A;
}
jml_matrix* jml_matrix_multiply_row(jml_matrix* A,jml_matrix_size_type r,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(r>=a->row)return A;
	for(jml_matrix_size_type i=0;i<a->column;++i)_d(a,r,i)*=v;
	return A;	
}
jml_matrix* jml_matrix_multiply_column(jml_matrix* A,jml_matrix_size_type c,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(c>=a->column)return A;
	for(jml_matrix_size_type i=0;i<a->row;++i)_d(a,i,c)*=v;
	return A;	
}
jml_matrix *jml_matrix_add_row(jml_matrix* A,jml_matrix_size_type r1,jml_matrix_size_type r2,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(r1==r2||r1>=a->row||r2>=a->row)return A;
	for(jml_matrix_size_type i=0;i<a->column;++i)_d(a,r1,i)+=_d(a,r2,i)*v;
	return A;		
}
jml_matrix *jml_matrix_add_column(jml_matrix* A,jml_matrix_size_type c1,jml_matrix_size_type c2,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(c1==c2||c1>=a->column||c2>=a->column)return A;
	for(jml_matrix_size_type i=0;i<a->row;++i)_d(a,i,c1)+=_d(a,i,c2)*v;
	return A;	
}
jml_matrix *jml_matrix_replace_row(jml_matrix* A,jml_matrix* B,jml_matrix_size_type r1,jml_matrix_size_type r2)
{
	if(!A)return NULL;
	if(!B)return A;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	jml_matrix *b=jbl_refer_pull(B);
	if(a->column!=b->column)	jbl_exception("REPLACE NOT EQUAL COLUMN  MATRIX");
	if(r1>=a->row)		jbl_exception("MATRIX OVREFLOW");
	if(r2>=b->row)		jbl_exception("MATRIX OVREFLOW");
	for(jml_matrix_size_type i=0;i<a->column;++i)_d(a,r1,i)=_d(b,r2,i);
	return A;
}
jml_matrix *jml_matrix_replace_column(jml_matrix* A,jml_matrix* B,jml_matrix_size_type c1,jml_matrix_size_type c2)
{
	if(!A)return NULL;
	if(!B)return A;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	jml_matrix *b=jbl_refer_pull(B);
	if(a->row!=b->row)jbl_exception("REPLACE NOT EQUAL ROW  MATRIX");
	if(c1>=a->column)		jbl_exception("MATRIX OVREFLOW");
	if(c2>=b->column)		jbl_exception("MATRIX OVREFLOW");
	for(jml_matrix_size_type i=0;i<a->row;++i)_d(a,i,c1)=_d(b,i,c2);
	return A;
}
jml_matrix *jml_matrix_toup(jml_matrix* A,jml_matrix* B)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(B&&a->row!=((jml_matrix*)jbl_refer_pull(B))->row)jbl_exception("TOUP NOT EQUAL COLUMN  MATRIX");
	if(B&&!(jbl_gc_is_ref(B)))jbl_exception("TOUP NOT REFER B MAY CAUSE MERERY OVERFLOW");
//	if(a->row!=a->column)jbl_exception("TOUP NOT SQUARE MATRIX");
	jbl_uint8 f=0;
	for(jml_matrix_size_type i=0,j=0;i<a->row;++i)//O(n*(n+n+n*n)+n*n)=O(n^3)
	{		
		for(j=i;j<a->row&&i<a->column&&!_d(a,j,i);++j);
		if(j>=a->row)continue;
		if(i!=j)a=jml_matrix_swap_row(a,i,j),B=jml_matrix_swap_row(B,i,j),f=!f;
		for(jml_matrix_size_type k=i+1;k<a->row;++k)
            B=jml_matrix_add_row(B,k,i,-_d(a,k,i)/_d(a,i,i)),
			a=jml_matrix_add_row(a,k,i,-_d(a,k,i)/_d(a,i,i));
	}
	if(f)a=jml_matrix_negative(a),B=jml_matrix_negative(B);
	return A;	
}
jml_matrix *jml_matrix_adjugate(jml_matrix* A)
{
	if(!A)return NULL;
	jml_matrix *b=jml_matrix_copy(jbl_refer_pull(A));
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	_f(b,i,j)
	{
		jml_matrix *c=jml_matrix_cofactor(b,i,j);
		_d(a,i,j)=jml_matrix_determinant(c);
		jml_matrix_free(c);
	}
	jml_matrix_free(b);
	return A;	
}
jml_matrix *jml_matrix_cramer(jml_matrix* A,jml_matrix* B)
{
	if(!A)return NULL;
	if(!B)return NULL;
	jml_matrix *a=jbl_refer_pull(A);
	jml_matrix *b=jbl_refer_pull(B);
	if(a->row!=b->row)jbl_exception("CRAMER NOT EQUAL ROW  MATRIX");
	if(a->row!=a->column)	jbl_exception("CRAMER NOT SQUARE MATRIX");
	if(b->column != 1)		jbl_exception("CRAMER NOT COLUMN EQUAL 1 MATRIX");
	jml_matrix_data_type D=jml_matrix_determinant(a);
	if(!D)return NULL;
	jml_matrix * ans=jml_matrix_new(1,a->column);
	for(jml_matrix_size_type c=0;c<a->column;++c)
	{
		jml_matrix *e=jml_matrix_replace_column(jml_matrix_copy(a),b,c,0);
		_d(ans,0,c)=jml_matrix_determinant(e)/D;	
		jml_matrix_free(e);
	}
	return ans;	
}
jml_matrix_size_type jml_matrix_rank(jml_matrix *A)
{
	if(!A)return 0;
    jml_matrix * a=jml_matrix_toup(jml_matrix_copy(jbl_refer_pull(A)),NULL);
    jml_matrix_size_type i=0,j=0;    
    for(;j<a->column&&i<a->row;++j)
        if(_d(a,i,j))
            ++i;
    a=jml_matrix_free(a);
    return i;
}
jml_matrix *jml_matrix_inverse(jml_matrix* E,jml_matrix* A)
{
	if(!A)return NULL;
    jml_matrix * a=jml_matrix_copy(jbl_refer_pull(A));
	if(a->row!=a->column)	jbl_exception("INVERSE NOT SQUARE MATRIX");
    jml_matrix * e;
    if(E) E=jml_matrix_extend_to(E,0,0,0,&e);
    else  E=e=jml_matrix_newE(a->row);
	if(a->row!=e->row)jbl_exception("INVERSE NOT EQUAL ROW  MATRIX");
	for(jml_matrix_size_type i=0,j=0;i<a->row;++i)//O(n*(n+n+n*n)+n*n)=O(n^3)
	{		
		for(j=i;j<a->row&&!_d(a,j,i);++j);
		if(j>=a->row)continue;
		if(i!=j)a=jml_matrix_swap_row(a,i,j),e=jml_matrix_swap_row(e,i,j);
		for(jml_matrix_size_type k=i+1;k<a->row;++k)
			e=jml_matrix_add_row(e,k,i,-_d(a,k,i)/_d(a,i,i)),
			a=jml_matrix_add_row(a,k,i,-_d(a,k,i)/_d(a,i,i));
	}
    for(jml_matrix_size_type i=0;i<a->row;++i)
    {
        if(!_d(a,i,i))return a=jml_matrix_free(a),E=jml_matrix_free(E);
        e=jml_matrix_multiply_row(e,i,1/_d(a,i,i)),
        a=jml_matrix_multiply_row(a,i,1/_d(a,i,i));
	}
    for(jml_matrix_size_type i=a->row-1;i!=(-1ULL);--i)
    {
		for(jml_matrix_size_type k=i-1;k!=(-1ULL);--k)
			e=jml_matrix_add_row(e,k,i,-_d(a,k,i)/_d(a,i,i)),
			a=jml_matrix_add_row(a,k,i,-_d(a,k,i)/_d(a,i,i));        
    }
    a=jml_matrix_free(a);
	return E;	
}
jml_matrix *jml_matrix_inverse_by_column(jml_matrix* E,jml_matrix* A)
{
	if(!A)return NULL;
    jml_matrix * a=jml_matrix_copy(jbl_refer_pull(A));
	if(a->row!=a->column)	jbl_exception("INVERSE NOT SQUARE MATRIX");
    jml_matrix * e;
    if(E) E=jml_matrix_extend_to(E,0,0,0,&e);
    else  E=e=jml_matrix_newE(a->row);
	if(a->column!=e->column)jbl_exception("INVERSE NOT EQUAL COLUMN  MATRIX");
	for(jml_matrix_size_type i=0,j=0;i<a->column;++i)//O(n*(n+n+n*n)+n*n)=O(n^3)
	{		
		for(j=i;j<a->column&&!_d(a,i,j);++j);
		if(j>=a->column)continue;
		if(i!=j)a=jml_matrix_swap_column(a,i,j),e=jml_matrix_swap_column(e,i,j);
		for(jml_matrix_size_type k=i+1;k<a->column;++k)
			e=jml_matrix_add_column(e,k,i,-_d(a,i,k)/_d(a,i,i)),
			a=jml_matrix_add_column(a,k,i,-_d(a,i,k)/_d(a,i,i));
	}
    for(jml_matrix_size_type i=0;i<a->column;++i)
    {
        if(!_d(a,i,i))return a=jml_matrix_free(a),E=jml_matrix_free(E);
        e=jml_matrix_multiply_column(e,i,1/_d(a,i,i)),
        a=jml_matrix_multiply_column(a,i,1/_d(a,i,i));
	}
    for(jml_matrix_size_type i=a->column-1;i!=(-1ULL);--i)
    {
		for(jml_matrix_size_type k=i-1;k!=(-1ULL);--k)
			e=jml_matrix_add_column(e,k,i,-_d(a,i,k)/_d(a,i,i)),
			a=jml_matrix_add_column(a,k,i,-_d(a,i,k)/_d(a,i,i));        
    }
    a=jml_matrix_free(a);
	return E;	
}
jml_matrix *jml_matrix_to_row_minimal(jml_matrix* A,jml_matrix* B)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
    a=jml_matrix_toup(a,B);
    for(jml_matrix_size_type i=0,j=0;i<a->row;++i)
        for(;j<a->column;++j)
            if(_d(a,i,j))//第一个非零元
            {
                B=jml_matrix_multiply_row(B,i,1/_d(a,i,j));
                a=jml_matrix_multiply_row(a,i,1/_d(a,i,j));
                for(jml_matrix_size_type k=0;k<i;++k)       if(_d(a,k,j))B=jml_matrix_add_row(B,k,i,-_d(a,k,j)/_d(a,i,j)),a=jml_matrix_add_row(a,k,i,-_d(a,k,j)/_d(a,i,j));
                for(jml_matrix_size_type k=i+1;k<a->row;++k)if(_d(a,k,j))B=jml_matrix_add_row(B,k,i,-_d(a,k,j)/_d(a,i,j)),a=jml_matrix_add_row(a,k,i,-_d(a,k,j)/_d(a,i,j));
                break;
            }
    return A;
}
#if JBL_STREAM_ENABLE==1
jml_matrix* jml_matrix_view_put(jml_matrix* this,jbl_stream *out,jbl_uint8 format,jbl_uint32 tabs,jbl_uint32 row,unsigned char * varname,unsigned char * func,unsigned char * file)
{
	jml_matrix *thi;if(jbl_stream_view_put_format(thi=jbl_refer_pull(this),out,format,tabs,UC"jml_matrix",row,varname,func,file)){jbl_stream_push_char(out,'\n');return this;}
	jbl_stream_push_chars(out,UC" row:");jbl_stream_push_uint(out,thi->row);
	jbl_stream_push_chars(out,UC" column:");jbl_stream_push_uint(out,thi->column);
	jbl_stream_push_char(out,'\n');
	++tabs;
#if JML_MATRIX_PRINT_LINENO ==1
	for(jbl_uint32 j=0;j<tabs+1;jbl_stream_push_char(out,'\t'),++j);
	for(jml_matrix_size_type j=0;j<thi->column;++j)
		jbl_stream_push_uint(out,j),jbl_stream_push_char(out,'\t');		
	jbl_stream_push_char(out,'\n');
#endif		
	for(jml_matrix_size_type i=0;i<thi->row;++i)
	{
		for(jbl_uint32 j=0;j<tabs;jbl_stream_push_char(out,'\t'),++j);
#if JML_MATRIX_PRINT_LINENO ==1
		jbl_stream_push_uint(out,i),jbl_stream_push_char(out,'\t');		
#endif		
		for(jml_matrix_size_type j=0;j<thi->column;++j)
			jml_matrix_data_push(out,_d(thi,i,j)),jbl_stream_push_char(out,'\t');
		jbl_stream_push_char(out,'\n');
	}
	return this;
}
#endif
#endif
