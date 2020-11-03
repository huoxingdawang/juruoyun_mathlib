#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	{
        jml_matrix* m1=jml_matrix_new(4,5);
        m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,0);	m1=jml_matrix_set(m1,0,2,2);	m1=jml_matrix_set(m1,0,3,-1);	m1=jml_matrix_set(m1,0,4,0);
        m1=jml_matrix_set(m1,1,0,0);	m1=jml_matrix_set(m1,1,1,-2);	m1=jml_matrix_set(m1,1,2,4);	m1=jml_matrix_set(m1,1,3,0);	m1=jml_matrix_set(m1,1,4,0);
        m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,1);	m1=jml_matrix_set(m1,2,2,7);	m1=jml_matrix_set(m1,2,3,-1);	m1=jml_matrix_set(m1,2,4,1);
        m1=jml_matrix_set(m1,3,0,-3);	m1=jml_matrix_set(m1,3,1,-1);	m1=jml_matrix_set(m1,3,2,-7);	m1=jml_matrix_set(m1,3,3,1);	m1=jml_matrix_set(m1,3,4,-1);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
	{
        jml_matrix* m1=jml_matrix_new(3,4);
        m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,2);	m1=jml_matrix_set(m1,0,2,-2);	m1=jml_matrix_set(m1,0,3,3);
        m1=jml_matrix_set(m1,1,0,4);	m1=jml_matrix_set(m1,1,1,-3);	m1=jml_matrix_set(m1,1,2,3);	m1=jml_matrix_set(m1,1,3,12);
        m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,-1);	m1=jml_matrix_set(m1,2,2,1);	m1=jml_matrix_set(m1,2,3,9);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(2);pn();
		m1=jml_matrix_free(m1);
	}
	{
		jml_matrix* m1=jml_matrix_new(3,3);
		m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,1);
		m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,2);	m1=jml_matrix_set(m1,1,2,3);
		m1=jml_matrix_set(m1,2,0,1);	m1=jml_matrix_set(m1,2,1,3);	m1=jml_matrix_set(m1,2,2,6);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
    pchars("以下矩阵参考线代课本习题一 11\n");
	{   //(1)
		jml_matrix* m1=jml_matrix_new(3,2);
		m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);
		m1=jml_matrix_set(m1,1,0,2);	m1=jml_matrix_set(m1,1,1,0);
		m1=jml_matrix_set(m1,2,0,1);	m1=jml_matrix_set(m1,2,1,2);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(2);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(2)
        jml_matrix* m1=jml_matrix_new(2,3);
        m1=jml_matrix_set(m1,0,0,0);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,2);
        m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,0);	m1=jml_matrix_set(m1,1,2,1);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(2);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(3)
        jml_matrix* m1=jml_matrix_new(2,3);
        m1=jml_matrix_set(m1,0,0,0);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,2);
        m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,0);	m1=jml_matrix_set(m1,1,2,1);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(2);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(3)
		jml_matrix* m1=jml_matrix_new(3,3);
		m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,2);
		m1=jml_matrix_set(m1,1,0,3);	m1=jml_matrix_set(m1,1,1,1);	m1=jml_matrix_set(m1,1,2,4);
		m1=jml_matrix_set(m1,2,0,2);	m1=jml_matrix_set(m1,2,1,-1);	m1=jml_matrix_set(m1,2,2,0);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(4)
		jml_matrix* m1=jml_matrix_new(3,4);
		m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,-1);	m1=jml_matrix_set(m1,0,2,2);	m1=jml_matrix_set(m1,0,3,1);
		m1=jml_matrix_set(m1,1,0,2);	m1=jml_matrix_set(m1,1,1,-2);	m1=jml_matrix_set(m1,1,2,4);	m1=jml_matrix_set(m1,1,3,-2);
		m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,4);	m1=jml_matrix_set(m1,2,3,-1);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(5)
		jml_matrix* m1=jml_matrix_new(4,4);
		m1=jml_matrix_set(m1,0,0,2);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,3);	m1=jml_matrix_set(m1,0,3,4);
		m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,1);	m1=jml_matrix_set(m1,1,2,0);	m1=jml_matrix_set(m1,1,3,2);
		m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,1);	m1=jml_matrix_set(m1,2,2,4);	m1=jml_matrix_set(m1,2,3,2);
		m1=jml_matrix_set(m1,3,0,4);	m1=jml_matrix_set(m1,3,1,5);	m1=jml_matrix_set(m1,3,2,2);	m1=jml_matrix_set(m1,3,3,5);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(4);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(6)
		jml_matrix* m1=jml_matrix_new(3,4);
		m1=jml_matrix_set(m1,0,0,2);	m1=jml_matrix_set(m1,0,1,1);	m1=jml_matrix_set(m1,0,2,3);	m1=jml_matrix_set(m1,0,3,4);
		m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,1);	m1=jml_matrix_set(m1,1,2,0);	m1=jml_matrix_set(m1,1,3,2);
		m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,1);	m1=jml_matrix_set(m1,2,2,4);	m1=jml_matrix_set(m1,2,3,2);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(7)
		jml_matrix* m1=jml_matrix_new(5,4);
		m1=jml_matrix_set(m1,0,0,2);	m1=jml_matrix_set(m1,0,1,2);	m1=jml_matrix_set(m1,0,2,3);	m1=jml_matrix_set(m1,0,3,1);
		m1=jml_matrix_set(m1,1,0,1);	m1=jml_matrix_set(m1,1,1,-3);	m1=jml_matrix_set(m1,1,2,-2);	m1=jml_matrix_set(m1,1,3,0);
		m1=jml_matrix_set(m1,2,0,8);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,5);	m1=jml_matrix_set(m1,2,3,3);
		m1=jml_matrix_set(m1,3,0,3);	m1=jml_matrix_set(m1,3,1,7);	m1=jml_matrix_set(m1,3,2,8);	m1=jml_matrix_set(m1,3,3,2);
		m1=jml_matrix_set(m1,4,0,7);	m1=jml_matrix_set(m1,4,1,5);	m1=jml_matrix_set(m1,4,2,0);	m1=jml_matrix_set(m1,4,3,0);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
	{   //(8)
		jml_matrix* m1=jml_matrix_new(5,5);
		m1=jml_matrix_set(m1,0,0,1);	m1=jml_matrix_set(m1,0,1,-1);	m1=jml_matrix_set(m1,0,2,2);	m1=jml_matrix_set(m1,0,3,1);	m1=jml_matrix_set(m1,0,4,0);
		m1=jml_matrix_set(m1,1,0,2);	m1=jml_matrix_set(m1,1,1,-2);	m1=jml_matrix_set(m1,1,2,4);	m1=jml_matrix_set(m1,1,3,-2);	m1=jml_matrix_set(m1,1,4,0);
		m1=jml_matrix_set(m1,2,0,3);	m1=jml_matrix_set(m1,2,1,0);	m1=jml_matrix_set(m1,2,2,6);	m1=jml_matrix_set(m1,2,3,-1);	m1=jml_matrix_set(m1,2,4,1);
		m1=jml_matrix_set(m1,3,0,0);	m1=jml_matrix_set(m1,3,1,3);	m1=jml_matrix_set(m1,3,2,0);	m1=jml_matrix_set(m1,3,3,0);	m1=jml_matrix_set(m1,3,4,1);
		jml_matrix_view(m1);
		pint(jml_matrix_rank(m1));pt();pint(3);pn();
		m1=jml_matrix_free(m1);
	}
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}

