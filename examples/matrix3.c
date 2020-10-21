#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=jml_matrix_new(4,4);
	m1=jml_matrix_set(m1,0,0,-1);	m1=jml_matrix_set(m1,0,1,0);	m1=jml_matrix_set(m1,0,2,3);	m1=jml_matrix_set(m1,0,3,1);
	m1=jml_matrix_set(m1,1,0,0);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,-4);	m1=jml_matrix_set(m1,1,3,-2);
	m1=jml_matrix_set(m1,2,0,0);	m1=jml_matrix_set(m1,2,1,-1);	m1=jml_matrix_set(m1,2,2,1);	m1=jml_matrix_set(m1,2,3,1);
	m1=jml_matrix_set(m1,3,0,0);	m1=jml_matrix_set(m1,3,1,2);	m1=jml_matrix_set(m1,3,2,-9);	m1=jml_matrix_set(m1,3,3,1);
	jml_matrix_view(m1);
	jml_matrix* m2=jml_matrix_minor(m1,1,1);
	jml_matrix_view(m2);
	jml_matrix* m3=jml_matrix_cofactor(m1,1,1);
	jml_matrix_view(m3);
	jml_matrix* m4=jml_matrix_cofactor(m1,1,0);
	jml_matrix_view(m4);
	
	m1=jml_matrix_free(m1);
	m2=jml_matrix_free(m2);
	m3=jml_matrix_free(m3);
	m4=jml_matrix_free(m4);
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
