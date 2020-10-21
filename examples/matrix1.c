#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=jml_matrix_new(3,3);
	m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,0);
	m1=jml_matrix_set(m1,1,0,0);	m1=jml_matrix_set(m1,1,1,1);	m1=jml_matrix_set(m1,1,2,1);
	m1=jml_matrix_set(m1,2,0,0);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,1);
	jml_matrix_view(m1);
	jml_matrix* mE=jml_matrix_newE(3);
	jml_matrix_view(mE);
	jml_matrix* m2=jml_matrix_pow(m1,0);
	jml_matrix* m3=jml_matrix_pow(m1,1);
	jml_matrix* m4=jml_matrix_pow(m1,2);
	jml_matrix* m5=jml_matrix_pow(m1,3);
	jml_matrix* m6=jml_matrix_pow(m1,4);
	jml_matrix_view(m2);
	jml_matrix_view(m3);
	jml_matrix_view(m4);
	jml_matrix_view(m5);
	jml_matrix_view(m6);
	
	puint(jml_matrix_if_equal(m2,mE));pn();
	puint(jml_matrix_if_equal(m3,mE));pn();



	
	m1=jml_matrix_free(m1);
	m2=jml_matrix_free(m2);
	m3=jml_matrix_free(m3);
	m4=jml_matrix_free(m4);
	m5=jml_matrix_free(m5);
	m6=jml_matrix_free(m6);
	mE=jml_matrix_free(mE);
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
