/* Copyright (c) [2020] juruoyun developer team
  Juruoyun math lib is licensed under the Mulan PSL v1.
   You can use this software according to the terms and conditions of the Mulan PSL v1.
   You may obtain a copy of Mulan PSL v1 at:
      http://license.coscl.org.cn/MulanPSL
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
   PURPOSE.
   See the Mulan PSL v1 for more details.*/
#include "jml_pow.h"
#if JML_POW_ENABLE==1
jbl_uint64 jml_pow_mod(jbl_uint64 a,jbl_uint32 b,jbl_uint64 c)
{
	jbl_uint64 ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%c;
		a=a*a%c;
		b>>=1;
	}
	return ans;
}
#endif
