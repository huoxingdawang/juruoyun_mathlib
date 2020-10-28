#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=jml_matrix_new(3,3);
	m1=jml_matrix_set(m1,0,0,2);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,-1);
	m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,1);	m1=jml_matrix_set(m1,1,2,-2);
	m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,6);	m1=jml_matrix_set(m1,2,2,-9);
	
	jml_matrix* m2=jml_matrix_adjugate		(jml_matrix_copy(m1));
	jml_matrix* m3=jml_matrix_new(3,1);
	m3=jml_matrix_set(m3,0,0,2);
	m3=jml_matrix_set(m3,1,0,4);
	m3=jml_matrix_set(m3,2,0,9);
	
	jml_matrix* m4=jml_matrix_cramer(m1,m3);
	
	jml_matrix_view(m1);
	jml_matrix_view(m2);
	jml_matrix_view(m3);
	jml_matrix_view(m4);
	
	m1=jml_matrix_free(m1);
	m2=jml_matrix_free(m2);
	m3=jml_matrix_free(m3);
	m4=jml_matrix_free(m4);

	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
