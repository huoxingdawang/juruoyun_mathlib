#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
    {
        jml_vector *v1=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,1),1,1),2,2),3,2);
        jml_vector *v2=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,0),1,2),2,0),3,2);
        jml_vector *v3=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,1),1,0),2,2),3,1);
        jml_vector *v4=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,1),1,3),2,2),3,5);
        jml_vector_view(v1);
        jml_vector_view(v2);
        jml_vector_view(v3);
        jml_vector_view(v4);
        
        
        jml_matrix *m1=jml_vector_lay_row(4,(jml_vector*[4]){v1,v2,v3,v4});
        jml_matrix_view(m1);
        puint(jml_matrix_rank(m1));pn();
        puint(jml_matrix_determinant(m1));pn();

        v1=jml_vector_free(v1);
        v2=jml_vector_free(v2);
        v3=jml_vector_free(v3);
        v4=jml_vector_free(v4);


        jml_matrix_free(m1);
    }
    {
        jml_vector *v1=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 1),1,-1),2, 0),3, 1);
        jml_vector *v2=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 2),1, 3),2, 0),3, 2);
        jml_vector *v3=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 0),1, 1),2, 2),3, 1);
        jml_vector *v4=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,-3),1, 3),2, 0),3,-3);
        jml_vector *v5=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 2),1, 1),2, 3),3, 4);
        
        
        jml_matrix *m1=jml_vector_lay_row(5,(jml_vector*[5]){v1,v2,v3,v4,v5});
        jml_matrix_view(m1);
        puint(jml_matrix_rank(m1));pn();

        v1=jml_vector_free(v1);
        v2=jml_vector_free(v2);
        v3=jml_vector_free(v3);
        v4=jml_vector_free(v4);
        v5=jml_vector_free(v5);


        jml_matrix_free(m1);
    }
    {
        jml_vector *v1=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 1),1, 3),2,-2),3, 1);
        jml_vector *v2=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,-1),1,-4),2, 2),3,-1);
        jml_vector *v3=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 1),1, 2),2,-2),3, 1);
        jml_vector *v4=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0, 0),1, 1),2, 3),3, 1);
        
        
        jml_matrix *m1=jml_vector_lay_column(4,(jml_vector*[4]){v1,v2,v3,v4});
        jml_matrix_view(m1);
        m1=jml_matrix_toup(m1,NULL);
        jml_matrix_view(m1);
        puint(jml_matrix_rank(m1));pn();
        
        v1=jml_vector_free(v1);
        v2=jml_vector_free(v2);
        v3=jml_vector_free(v3);
        v4=jml_vector_free(v4);


        jml_matrix_free(m1);
    }	
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
