#include "main.h"
#define MAXN 10
//173716916184296448.0
int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_matrix* m1=jml_matrix_new(MAXN,MAXN);
	for(int i=0;i<MAXN;++i)for(int j=0;j<MAXN;++j)m1=jml_matrix_set(m1,i,j,jbl_rand()%100);
	jml_matrix_view(m1);
	pdouble(jml_matrix_determinant(m1));pn();pf();
	jbl_time * t1=jbl_time_now(NULL);
	for(int i=0;i<1;++i)jml_matrix_determinant(m1);
	jbl_time * t2=jbl_time_now(NULL);
	puint(jbl_time_minus(t2,t1));pchars("ms\n");
	t1=jbl_time_free(t1);
	t2=jbl_time_free(t2);
	m1=jml_matrix_free(m1);
	
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
