#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
    {
        pchars("--------------------------------------------------------------------\n");
        jml_matrix* m1=NULL;
        m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,1);	m1=jml_matrix_set(m1,0,3,1);	m1=jml_matrix_set(m1,0,4,1);
        m1=jml_matrix_set(m1,1,0,3);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,1);	m1=jml_matrix_set(m1,1,3,1);	m1=jml_matrix_set(m1,1,4,-3);
        m1=jml_matrix_set(m1,2,0,0);	m1=jml_matrix_set(m1,2,1,1);	m1=jml_matrix_set(m1,2,2,2);	m1=jml_matrix_set(m1,2,3,2);	m1=jml_matrix_set(m1,2,4,6);
        m1=jml_matrix_set(m1,3,0,5);	m1=jml_matrix_set(m1,3,1,4);	m1=jml_matrix_set(m1,3,2,3);	m1=jml_matrix_set(m1,3,3,3);	m1=jml_matrix_set(m1,3,4,-1);
        jml_matrix_view(m1);
        m1=jml_matrix_to_row_minimal(m1,NULL);
        jml_matrix_view(m1);

        m1=jml_matrix_free(m1);
        pchars("--------------------------------------------------------------------\n");
    }
    {
        pchars("--------------------------------------------------------------------\n");
        jml_matrix* m1=NULL;
        m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,2);	m1=jml_matrix_set(m1,0,3,3);
        m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,3);	m1=jml_matrix_set(m1,1,2,6);	m1=jml_matrix_set(m1,1,3,1);
        m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,-1);	m1=jml_matrix_set(m1,2,2,-2);	m1=jml_matrix_set(m1,2,3,15);
        m1=jml_matrix_set(m1,3,0,1);	m1=jml_matrix_set(m1,3,1,-5);	m1=jml_matrix_set(m1,3,2,-10);	m1=jml_matrix_set(m1,3,3,12);
        jml_matrix_view(m1);
        m1=jml_matrix_to_row_minimal(m1,NULL);
        jml_matrix_view(m1);

        m1=jml_matrix_free(m1);
        pchars("--------------------------------------------------------------------\n");
    }
    {
        pchars("--------------------------------------------------------------------\n");
        jml_matrix* m1=NULL;
        m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,2);	m1=jml_matrix_set(m1,0,3,3);
        m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,3);	m1=jml_matrix_set(m1,1,2,6);	m1=jml_matrix_set(m1,1,3,1);
        m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,-1);	m1=jml_matrix_set(m1,2,2,-2);	m1=jml_matrix_set(m1,2,3,15);
        m1=jml_matrix_set(m1,3,0,1);	m1=jml_matrix_set(m1,3,1,-5);	m1=jml_matrix_set(m1,3,2,-10);	m1=jml_matrix_set(m1,3,3,12);
        jml_matrix_view(m1);
        jml_matrix* m2=NULL;
        m2=jml_matrix_set(m2,0,0,1);
        m2=jml_matrix_set(m2,1,0,3);
        m2=jml_matrix_set(m2,2,0,3);
        m2=jml_matrix_set(m2,3,0,1);
        jml_matrix_view(m2);
        jml_matrix_free(jbl_refer(&m2));
        m1=jml_matrix_to_row_minimal(m1,m2);
        jml_matrix_view(m1);
        jml_matrix_view(m2);

        m1=jml_matrix_free(m1);
        m2=jml_matrix_free(m2);
        pchars("--------------------------------------------------------------------\n");
    }
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
