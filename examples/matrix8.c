#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=jml_matrix_new(3,3);
	m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,-1);	m1=jml_matrix_set(m1,0,2,-1);
	m1=jml_matrix_set(m1,1,0,-3);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,1);
	m1=jml_matrix_set(m1,2,0,2);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,1);
	jml_matrix* m2=jml_matrix_inverse(m1);
    
	
	jml_matrix_view(m1);
	jml_matrix_view(m2);
	
	m1=jml_matrix_free(m1);
	m2=jml_matrix_free(m2);

	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
