#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
    {
        pchars("--------------------------------------------------------------------\n");
        jml_matrix* m1=jml_matrix_new(3,3);
        m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,-1);	m1=jml_matrix_set(m1,0,2,-1);
        m1=jml_matrix_set(m1,1,0,-3);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,1);
        m1=jml_matrix_set(m1,2,0,2);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,1);
        jml_matrix* m2=jml_matrix_inverse(NULL,m1);
        jml_matrix* m3=jml_matrix_inverse_by_column(NULL,m1);
        
        jml_matrix* m4=jml_matrix_multiply(m1,m2);
        jml_matrix* m5=jml_matrix_multiply(m1,m3);
        
        jml_matrix_view(m1);
        jml_matrix_view(m2);
        jml_matrix_view(m3);
        jml_matrix_view(m4);
        jml_matrix_view(m5);
        
        m1=jml_matrix_free(m1);
        m2=jml_matrix_free(m2);
        m3=jml_matrix_free(m3);
        m4=jml_matrix_free(m4);
        m5=jml_matrix_free(m5);
        pchars("--------------------------------------------------------------------\n");
    }
    {
        pchars("--------------------------------------------------------------------\n");
        jml_matrix* m1=jml_matrix_new(3,3);
        m1=jml_matrix_set(m1,0,0,-8);	m1=jml_matrix_set(m1,0,1,3);	m1=jml_matrix_set(m1,0,2,0);
        m1=jml_matrix_set(m1,1,0,-5);	m1=jml_matrix_set(m1,1,1,9);	m1=jml_matrix_set(m1,1,2,0);
        m1=jml_matrix_set(m1,2,0,-2);	m1=jml_matrix_set(m1,2,1,15);	m1=jml_matrix_set(m1,2,2,0);
        jml_matrix* m2=jml_matrix_inverse(NULL,m1);
        
        jml_matrix* m4=jml_matrix_multiply(m1,m2);
        
//      jml_matrix_view(m1);
        jml_matrix_view(m2);
        jml_matrix_view(m4);
        
        m1=jml_matrix_free(m1);
        m2=jml_matrix_free(m2);
        m4=jml_matrix_free(m4);
        pchars("--------------------------------------------------------------------\n");
    }
    {
        pchars("--------------------------------------------------------------------\n");
        jml_matrix* m1=jml_matrix_new(3,3);
        m1=jml_matrix_set(m1,0,0,5);	m1=jml_matrix_set(m1,0,1,3);	m1=jml_matrix_set(m1,0,2,1);
        m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,-3);	m1=jml_matrix_set(m1,1,2,-2);
        m1=jml_matrix_set(m1,2,0,-5);	m1=jml_matrix_set(m1,2,1,2);	m1=jml_matrix_set(m1,2,2,1);
        jml_matrix* m2=jml_matrix_inverse(NULL,m1);
        
        jml_matrix* m4=jml_matrix_multiply(m1,m2);
        
//      jml_matrix_view(m1);
        jml_matrix_view(m2);
        jml_matrix_view(m4);
        
        m1=jml_matrix_free(m1);
        m2=jml_matrix_free(m2);
        m4=jml_matrix_free(m4);
        pchars("--------------------------------------------------------------------\n");
    }
//A*B=C
//B=A^-1*C
    {
        pchars("------------------------------3==4----------------------------------\n");
        jml_matrix* A=jml_matrix_new(3,3);
        A=jml_matrix_set(A,0,0,5);	A=jml_matrix_set(A,0,1,3);	A=jml_matrix_set(A,0,2,1);
        A=jml_matrix_set(A,1,0,1);	A=jml_matrix_set(A,1,1,-3);	A=jml_matrix_set(A,1,2,-2);
        A=jml_matrix_set(A,2,0,-5);	A=jml_matrix_set(A,2,1,2);	A=jml_matrix_set(A,2,2,1);
        jml_matrix* C=jml_matrix_new(3,3);
        C=jml_matrix_set(C,0,0,1);	C=jml_matrix_set(C,0,1,-1);	C=jml_matrix_set(C,0,2,-1);
        C=jml_matrix_set(C,1,0,-3);	C=jml_matrix_set(C,1,1,2);	C=jml_matrix_set(C,1,2,1);
        C=jml_matrix_set(C,2,0,2);	C=jml_matrix_set(C,2,1,0);	C=jml_matrix_set(C,2,2,1);
 

        jml_matrix* B=jml_matrix_inverse(jml_matrix_copy(C),A);
        
        jml_matrix* AB=jml_matrix_multiply(A,B);
        
        jml_matrix_view(A);
        jml_matrix_view(B);
        jml_matrix_view(C);
        jml_matrix_view(AB);
        
        A=jml_matrix_free(A);
        B=jml_matrix_free(B);
        C=jml_matrix_free(C);
        AB=jml_matrix_free(AB);
        pchars("--------------------------------------------------------------------\n");
    }
//A*X=B
//X=A^-1*B
    {
        pchars("------------------------------3==4----------------------------------\n");
        jml_matrix* A=jml_matrix_new(3,3);
        A=jml_matrix_set(A,0,0,2);	A=jml_matrix_set(A,0,1,1);	A=jml_matrix_set(A,0,2,-1);
        A=jml_matrix_set(A,1,0,1);	A=jml_matrix_set(A,1,1,1);	A=jml_matrix_set(A,1,2,0);
        A=jml_matrix_set(A,2,0,1);	A=jml_matrix_set(A,2,1,-1);	A=jml_matrix_set(A,2,2,1);
        jml_matrix* B=jml_matrix_new(3,2);
        B=jml_matrix_set(B,0,0,1);	B=jml_matrix_set(B,0,1,4);
        B=jml_matrix_set(B,1,0,-2);	B=jml_matrix_set(B,1,1,3);
        B=jml_matrix_set(B,2,0,3);	B=jml_matrix_set(B,2,1,2);
 

        jml_matrix* X=jml_matrix_inverse(jml_matrix_copy(B),A);
        
        jml_matrix* AX=jml_matrix_multiply(A,X);
        
        jml_matrix_view(A);
        jml_matrix_view(X);
        jml_matrix_view(B);
        jml_matrix_view(AX);
        
        A=jml_matrix_free(A);
        X=jml_matrix_free(X);
        B=jml_matrix_free(B);
        AX=jml_matrix_free(AX);
        pchars("--------------------------------------------------------------------\n");
    }
//X*B=F
//X=F*B^-1
    {
        pchars("------------------------------1==4----------------------------------\n");
        jml_matrix* F=jml_matrix_new(2,3);
        F=jml_matrix_set(F,0,0,2);	F=jml_matrix_set(F,0,1,9);	F=jml_matrix_set(F,0,2,-4);
        F=jml_matrix_set(F,1,0,-1);	F=jml_matrix_set(F,1,1,-7);	F=jml_matrix_set(F,1,2,3);
        jml_matrix* B=jml_matrix_new(3,3);
        B=jml_matrix_set(B,0,0,0);	B=jml_matrix_set(B,0,1,3);	B=jml_matrix_set(B,0,2,8);
        B=jml_matrix_set(B,1,0,2);	B=jml_matrix_set(B,1,1,5);	B=jml_matrix_set(B,1,2,1);
        B=jml_matrix_set(B,2,0,1);	B=jml_matrix_set(B,2,1,3);	B=jml_matrix_set(B,2,2,2);

        jml_matrix* X=jml_matrix_inverse_by_column(jml_matrix_copy(F),B);
        
        jml_matrix* XB=jml_matrix_multiply(X,B);
        
        jml_matrix_view(F);
        jml_matrix_view(B);
        jml_matrix_view(X);
        jml_matrix_view(XB);
        
        F=jml_matrix_free(F);
        B=jml_matrix_free(B);
        X=jml_matrix_free(X);
        XB=jml_matrix_free(XB);
        pchars("----------------------------------------------------------------\n");
    }
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
