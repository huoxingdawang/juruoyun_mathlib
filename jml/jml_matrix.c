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
	if(!A)return jml_matrix_negative(jml_matrix_copy(B));
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
jml_matrix* jml_matrix_multiply(jml_matrix* A,jml_matrix* B)
{
	if(!A||!B)return NULL;
	A=jbl_refer_pull(A);
	B=jbl_refer_pull(B);
	if(A->row!=B->line)jbl_exception("MATRIX OVREFLOW");
	jml_matrix *C=jml_matrix_new(A->line,B->row);
	for(jml_matrix_size_type i=0;i<A->line;++i)
		for(jml_matrix_size_type j=0;j<B->row;++j)
			for(jml_matrix_size_type k=0;k<B->line;++k)
				_d(C,i,j)+=_d(A,i,k)*_d(B,k,j);
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
jml_matrix* jml_matrix_pow(jml_matrix* A,jbl_uint64 n)
{
	if(!A)return NULL;
	A=jbl_refer_pull(A);
	if(A->line!=A->row)jbl_exception("POW NOT SQUARE MATRIX");
	jml_matrix *B=jml_matrix_newE(A->line),*C=NULL;
	while(n--)
		C=jml_matrix_multiply(B,A),B=jml_matrix_free(B),B=C;
	return B;
}
char jml_matrix_space_ship(jml_matrix *this,jml_matrix *that)
{
	jml_matrix *thi=jbl_refer_pull(this);	
	jml_matrix *tha=jbl_refer_pull(that);	
	if(thi==tha){return 0;}if(thi==NULL){return -1;}if(tha==NULL){return 1;}	
	if(thi->line*thi->row!=tha->line*tha->row)
		return (thi->line*thi->row<tha->line*tha->row)?-1:1;
	for(jbl_string_size_type i=0,n=thi->line*thi->row;i<n;++i)
		if(thi->data[i]<tha->data[i])
			return -1;
		else if(thi->data[i]>tha->data[i])
			return 1;
	return 0;	
}
jml_matrix *jml_matrix_minor(jml_matrix *A,jml_matrix_size_type line,jml_matrix_size_type row)
{
	if(!A)return NULL;
	A=jbl_refer_pull(A);
	if(line>=A->line||row>=A->row)return NULL;
	jml_matrix *C=jml_matrix_new(A->line-1,A->row-1);
	for(jml_matrix_size_type i=0,ii=0;i<A->line;++i)
		if(i!=line)
		{
			for(jml_matrix_size_type j=0,jj=0;j<A->row;++j)
				if(j!=row)
					_d(C,ii,jj)=_d(A,i,j),++jj;
			++ii;
		}
	return C;
}
jml_matrix *jml_matrix_cofactor(jml_matrix *A,jml_matrix_size_type line,jml_matrix_size_type row)
{
	return ((line+row)&1)?jml_matrix_negative(jml_matrix_minor(A,line,row)):jml_matrix_minor(A,line,row);
}
jml_matrix_data_type jml_matrix_determinant(jml_matrix *A)
{
	if(!A)return 0;
	A=jbl_refer_pull(A);
	if(A->line!=A->row)jbl_exception("DETERMINANT NOT SQUARE MATRIX");
#if JML_MATRIX_DETERMINANT_USE_TOUP==0
	jml_matrix_data_type result=0;
	jml_permutation* p1=jml_permutation_new(A->row);
	do
	{
		jml_matrix_data_type temp=p1->ji?-1:1;
		for(jml_matrix_size_type i=0,j=0;j<A->row;temp*=_d(A,i,p1->data[j]),++i,++j);
		result+=temp;
	}while(jml_permutation_next(p1));
	p1=jml_permutation_free(p1);
#else
	jml_matrix_data_type result=1;
	jml_matrix * tmp=jml_matrix_toup(jml_matrix_copy(A));
//	jml_matrix_view(tmp);
	for(jml_matrix_size_type i=0;i<tmp->line;++i)result*=_d(tmp,i,i);
	jml_matrix_free(tmp);
#endif
	return result;
}
jml_matrix* jml_matrix_swap_line(jml_matrix* A,jml_matrix_size_type l1,jml_matrix_size_type l2)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(l1==l2||l1>=a->line||l2>=a->line)return A;
	for(jml_matrix_size_type i=0;i<a->row;++i)
	{
		jml_matrix_data_type c=_d(a,l1,i);
		_d(a,l1,i)=_d(a,l2,i);
		_d(a,l2,i)=c;
	}
	return A;
}
jml_matrix* jml_matrix_swap_row(jml_matrix* A,jml_matrix_size_type r1,jml_matrix_size_type r2)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(r1==r2||r1>=a->row||r2>=a->row)return A;
	for(jml_matrix_size_type i=0;i<a->line;++i)
	{
		jml_matrix_data_type c=_d(a,i,r1);
		_d(a,i,r1)=_d(a,i,r2);
		_d(a,i,r2)=c;
	}
	return A;
}
jml_matrix* jml_matrix_multiply_line(jml_matrix* A,jml_matrix_size_type l,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(l>=a->line)return A;
	for(jml_matrix_size_type i=0;i<a->row;++i)_d(a,l,i)*=v;
	return A;	
}
jml_matrix* jml_matrix_multiply_row(jml_matrix* A,jml_matrix_size_type r,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(r>=a->row)return A;
	for(jml_matrix_size_type i=0;i<a->line;++i)_d(a,i,r)*=v;
	return A;	
}
jml_matrix *jml_matrix_add_line(jml_matrix* A,jml_matrix_size_type l1,jml_matrix_size_type l2,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(l1==l2||l1>=a->line||l2>=a->line)return A;
	for(jml_matrix_size_type i=0;i<a->row;++i)_d(a,l1,i)+=_d(a,l2,i)*v;
	return A;		
}
jml_matrix *jml_matrix_add_row(jml_matrix* A,jml_matrix_size_type r1,jml_matrix_size_type r2,jml_matrix_data_type v)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	if(r1==r2||r1>=a->row||r2>=a->row)return A;
	for(jml_matrix_size_type i=0;i<a->line;++i)_d(a,i,r1)+=_d(a,i,r2)*v;
	return A;	
}
jml_matrix *jml_matrix_replace_line(jml_matrix* A,jml_matrix* B,jml_matrix_size_type l1,jml_matrix_size_type l2)
{
	if(!A)return NULL;
	if(!B)return A;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	jml_matrix *b=jbl_refer_pull(B);
	if(a->row!=b->row)	jbl_exception("REPLACE NOT EQUAL ROW  MATRIX");
	if(l1>=a->line)		jbl_exception("MATRIX OVREFLOW");
	if(l2>=b->line)		jbl_exception("MATRIX OVREFLOW");
	for(jml_matrix_size_type i=0;i<a->row;++i)_d(a,l1,i)=_d(b,l2,i);
	return A;
}
jml_matrix *jml_matrix_replace_row(jml_matrix* A,jml_matrix* B,jml_matrix_size_type r1,jml_matrix_size_type r2)
{
	if(!A)return NULL;
	if(!B)return A;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
	jml_matrix *b=jbl_refer_pull(B);
	if(a->line!=b->line)jbl_exception("REPLACE NOT EQUAL LINE  MATRIX");
	if(r1>=a->row)		jbl_exception("MATRIX OVREFLOW");
	if(r2>=b->row)		jbl_exception("MATRIX OVREFLOW");
	for(jml_matrix_size_type i=0;i<a->line;++i)_d(a,i,r1)=_d(b,i,r2);
	return A;
}
jml_matrix *jml_matrix_toup(jml_matrix* A)
{
	if(!A)return NULL;
	jml_matrix *a;A=jml_matrix_extend_to(A,0,0,0,&a);
//	if(a->line!=a->row)jbl_exception("TOUP NOT SQUARE MATRIX");
	jbl_uint8 f=0;
	for(jml_matrix_size_type i=0,j=0;i<a->line;++i)//O(n*(n+n+n*n)+n*n)=O(n^3)
	{		
		for(j=i;j<a->line&&i<a->row&&!_d(a,j,i);++j);
		if(j>=a->line)continue;
		if(i!=j)a=jml_matrix_swap_line(a,i,j),f=!f;
		for(jml_matrix_size_type k=i+1;k<a->line;++k)
			a=jml_matrix_add_line(a,k,i,-_d(a,k,i)/_d(a,i,i));
	}
	if(f)a=jml_matrix_negative(a);
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
	if(a->line!=b->line)jbl_exception("CRAMER NOT EQUAL LINE  MATRIX");
	if(a->line!=a->row)	jbl_exception("CRAMER NOT SQUARE MATRIX");
	if(b->row != 1)		jbl_exception("CRAMER NOT ROW EQUAL 1 MATRIX");
	jml_matrix_data_type D=jml_matrix_determinant(a);
	if(!D)return NULL;
	jml_matrix * ans=jml_matrix_new(1,a->row);
	for(jml_matrix_size_type r=0;r<a->row;++r)
	{
		jml_matrix *c=jml_matrix_replace_row(jml_matrix_copy(a),b,r,0);
		_d(ans,0,r)=jml_matrix_determinant(c)/D;	
		jml_matrix_free(c);
	}
	return ans;	
}
jml_matrix_size_type jml_matrix_rank(jml_matrix *A)
{
    jml_matrix * a=jml_matrix_toup(jml_matrix_copy(jbl_refer_pull(A)));
//  jml_matrix_view(a);pf();
    jml_matrix_size_type i=0,j=0;    
    for(;j<a->row&&i<a->line;++j)
        if(_d(a,i,j))
            ++i;
    a=jml_matrix_free(a);
    return i;
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
	for(jbl_uint32 j=0;j<tabs+1;jbl_stream_push_char(out,'\t'),++j);
	for(jml_matrix_size_type j=0;j<thi->row;++j)
		jbl_stream_push_uint(out,j),jbl_stream_push_char(out,'\t');		
	jbl_stream_push_char(out,'\n');
#endif		
	for(jml_matrix_size_type i=0;i<thi->line;++i)
	{
		for(jbl_uint32 j=0;j<tabs;jbl_stream_push_char(out,'\t'),++j);
#if JML_MATRIX_PRINT_LINENO ==1
		jbl_stream_push_uint(out,i),jbl_stream_push_char(out,'\t');		
#endif		
		for(jml_matrix_size_type j=0;j<thi->row;++j)
			jml_matrix_data_push(out,_d(thi,i,j)),jbl_stream_push_char(out,'\t');
		jbl_stream_push_char(out,'\n');
	}
	return this;
}
#endif
#endif
