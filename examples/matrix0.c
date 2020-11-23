#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=NULL;
	m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,2);	m1=jml_matrix_set(m1,0,2,3);
	m1=jml_matrix_set(m1,1,0,4);	m1=jml_matrix_set(m1,1,1,5);	m1=jml_matrix_set(m1,1,2,6);
	m1=jml_matrix_set(m1,2,0,7);	m1=jml_matrix_set(m1,2,1,8);	m1=jml_matrix_set(m1,2,2,9);
	jml_matrix* m2=jml_matrix_new(3,3);
	m2=jml_matrix_set(m2,0,0,1);	m2=jml_matrix_set(m2,0,1,2);	m2=jml_matrix_set(m2,0,2,3);
	m2=jml_matrix_set(m2,1,0,4);	m2=jml_matrix_set(m2,1,1,5);	m2=jml_matrix_set(m2,1,2,6);
	m2=jml_matrix_set(m2,2,0,7);	m2=jml_matrix_set(m2,2,1,8);	m2=jml_matrix_set(m2,2,2,9);
	jml_matrix_view(m1);
	jml_matrix_view(m2);

	jml_matrix* m3=jml_matrix_add				(jml_matrix_copy(m1),m2);
	jml_matrix* m4=jml_matrix_minus				(jml_matrix_copy(m1),m2);
	jml_matrix* m5=jml_matrix_negative			(jml_matrix_copy(m1));
	jml_matrix* m6=jml_matrix_number_multiply	(jml_matrix_copy(m1),3);
	jml_matrix* m7=jml_matrix_multiply			(m1,m2);
	jml_matrix* m8=jml_matrix_transpose			(jml_matrix_copy(m1));
	
	jml_matrix_view(m3);
	jml_matrix_view(m4);
	jml_matrix_view(m5);
	jml_matrix_view(m6);
	jml_matrix_view(m7);
	jml_matrix_view(m8);
	
	m1=jml_matrix_free(m1);
	m2=jml_matrix_free(m2);
	m3=jml_matrix_free(m3);
	m4=jml_matrix_free(m4);
	m5=jml_matrix_free(m5);
	m6=jml_matrix_free(m6);
	m7=jml_matrix_free(m7);
	m8=jml_matrix_free(m8);
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
