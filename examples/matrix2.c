#include "main.h"

int main()
{
	printf("--------------------------------" __FILE__ "--------------------------------\n");
	jbl_start();
	jml_start();
	jml_matrix* m1=jml_matrix_new(3,2);
	m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,2);
	m1=jml_matrix_set(m1,1,0,4);	m1=jml_matrix_set(m1,1,1,5);
	m1=jml_matrix_set(m1,2,0,7);	m1=jml_matrix_set(m1,2,1,8);
	jml_matrix* m2=jml_matrix_new(2,3);
	m2=jml_matrix_set(m2,0,0,1);	m2=jml_matrix_set(m2,0,1,2);	m2=jml_matrix_set(m2,0,2,3);
	m2=jml_matrix_set(m2,1,0,4);	m2=jml_matrix_set(m2,1,1,5);	m2=jml_matrix_set(m2,1,2,6);
	jml_matrix_view(m1);
	jml_matrix_view(m2);

	jml_matrix* m5=jml_matrix_negative			(jml_matrix_copy(m1));
	jml_matrix* m6=jml_matrix_number_multiply	(jml_matrix_copy(m1),3);
	jml_matrix* m7=jml_matrix_multiply			(m1,m2);
	
	jml_matrix_view(m5);
	jml_matrix_view(m6);
	jml_matrix_view(m7);
	
	m1=jml_matrix_free(m1);
	m2=jml_matrix_free(m2);
	m5=jml_matrix_free(m5);
	m6=jml_matrix_free(m6);
	m7=jml_matrix_free(m7);
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
