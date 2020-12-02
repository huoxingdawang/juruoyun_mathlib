#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=jml_matrix_new(4,4);
	m1=jml_matrix_set(m1,0,0,3);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,-1);	m1=jml_matrix_set(m1,0,3,2);
	m1=jml_matrix_set(m1,1,0,-5);	m1=jml_matrix_set(m1,1,1,1);	m1=jml_matrix_set(m1,1,2,3);	m1=jml_matrix_set(m1,1,3,-4);
	m1=jml_matrix_set(m1,2,0,2);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,1);	m1=jml_matrix_set(m1,2,3,-1);
	m1=jml_matrix_set(m1,3,0,1);	m1=jml_matrix_set(m1,3,1,-5);	m1=jml_matrix_set(m1,3,2,3);	m1=jml_matrix_set(m1,3,3,-3);
    jml_matrix_view(m1);
    m1=jml_matrix_swap_row(m1,0,3);
	m1=jml_matrix_add_row(m1,1,0,5);
	m1=jml_matrix_add_row(m1,2,0,-2);
	m1=jml_matrix_add_row(m1,3,0,-3);
    jml_matrix_view(m1);
    m1=jml_matrix_swap_row(m1,1,2);
    m1=jml_matrix_multiply_row(m1,1,0.2);
    jml_matrix_view(m1);
	m1=jml_matrix_add_row(m1,2,1,12);
	m1=jml_matrix_add_row(m1,3,1,-8);
    jml_matrix_view(m1);
	m1=jml_matrix_add_row(m1,3,2,1/5);
    jml_matrix_view(m1);
    
	m1=jml_matrix_free(m1);

	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
