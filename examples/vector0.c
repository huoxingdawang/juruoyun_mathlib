#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
    jml_vector *v1=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,1),1,2),2,3),3,4);
    jml_vector *v2=jml_vector_set(jml_vector_set(jml_vector_set(jml_vector_set(NULL,0,4),1,3),2,1),3,6);    

    
	jml_vector_view(v1);
	jml_vector_view(v2);




	jml_vector* m3=jml_vector_add				(jml_vector_copy(v1),v2);
	jml_vector* m4=jml_vector_minus				(jml_vector_copy(v1),v2);
	jml_vector* m5=jml_vector_negative			(jml_vector_copy(v1));
	jml_vector* m6=jml_vector_number_multiply	(jml_vector_copy(v1),3);
	jml_vector* m7=jml_vector_get_E	            (jml_vector_copy(v1));
	
	pdouble(jml_vector_multiply(v1,v2));pn();
	pdouble(jml_vector_get_theta(v1,v2));pn();
	pdouble(jml_vector_length(v1));pn();
	jml_vector_view(m3);
	jml_vector_view(m4);
	jml_vector_view(m5);
	jml_vector_view(m6);
	jml_vector_view(m7);
    
    
	v1=jml_vector_free(v1);
	v2=jml_vector_free(v2);
	m3=jml_vector_free(m3);
	m4=jml_vector_free(m4);
	m5=jml_vector_free(m5);
	m6=jml_vector_free(m6);
	m7=jml_vector_free(m7);

	
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
