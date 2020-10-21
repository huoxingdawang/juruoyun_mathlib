#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	{
		jml_matrix* m1=jml_matrix_new(3,3);
		m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,1);
		m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,3);
		m1=jml_matrix_set(m1,2,0,1);	m1=jml_matrix_set(m1,2,1,3);	m1=jml_matrix_set(m1,2,2,6);
		jml_matrix_view(m1);
		pint(jml_matrix_determinant(m1));pn();
		m1=jml_matrix_free(m1);
	}
	{
		jml_matrix* m1=jml_matrix_new(4,4);
		m1=jml_matrix_set(m1,0,0,-1);	m1=jml_matrix_set(m1,0,1,0);	m1=jml_matrix_set(m1,0,2,3);	m1=jml_matrix_set(m1,0,3,1);
		m1=jml_matrix_set(m1,1,0,0);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,-4);	m1=jml_matrix_set(m1,1,3,-2);
		m1=jml_matrix_set(m1,2,0,0);	m1=jml_matrix_set(m1,2,1,-1);	m1=jml_matrix_set(m1,2,2,1);	m1=jml_matrix_set(m1,2,3,1);
		m1=jml_matrix_set(m1,3,0,0);	m1=jml_matrix_set(m1,3,1,2);	m1=jml_matrix_set(m1,3,2,-9);	m1=jml_matrix_set(m1,3,3,1);	
		jml_matrix_view(m1);
		pint(jml_matrix_determinant(m1));pn();
		m1=jml_matrix_free(m1);
	}
	{
		jml_matrix* m1=jml_matrix_new(1,1);
		m1=jml_matrix_set(m1,0,0,-1);
		jml_matrix_view(m1);
		pint(jml_matrix_determinant(m1));pn();
		m1=jml_matrix_free(m1);
	}
	{
		jml_matrix* m1=jml_matrix_new(2,2);
		m1=jml_matrix_set(m1,0,0,2);	m1=jml_matrix_set(m1,0,1,3);
		m1=jml_matrix_set(m1,1,0,3);	m1=jml_matrix_set(m1,1,1,6);
		jml_matrix_view(m1);
		pint(jml_matrix_determinant(m1));pn();
		m1=jml_matrix_free(m1);
	}		
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
