#include "main.h"

int main()
{
	printf("--------------------------------" __FILE__ "--------------------------------\n");
	jbl_start();
	jml_start();
	puint(jml_pow(3,10));pn();
	puint(jml_pow_mod(3,10,8));pn();
	pchars("--------------------------------" __FILE__ "--------------------------------\n");
	jml_start();
	jbl_stop(); 	
}
