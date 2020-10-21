#include "main.h"

int main()
{
	jbl_start();
	jml_start();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_permutation* p1=jml_permutation_new(5);
	do
	{
		p1=jml_permutation_view(p1);
	}while(jml_permutation_next(p1));
	
	p1=jml_permutation_free(p1);
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
