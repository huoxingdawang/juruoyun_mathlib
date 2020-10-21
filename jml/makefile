#   Copyright (c) [2020] juruoyun developer team
#  Juruoyun math lib is licensed under the Mulan PSL v1.
#   You can use this software according to the terms and conditions of the Mulan PSL v1.
#   You may obtain a copy of Mulan PSL v1 at:
#      http://license.coscl.org.cn$(H)MulanPSL
#   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER BITSPRESS OR
#   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
#   PURPOSE.
#   See the Mulan PSL v1 for more details.
#jml
ifeq ($(system),linux)
JML_EXLIB = 
endif
ifeq ($(system),windows)
JML_EXLIB = 
endif
jml                       :jml/jml_gcd jml/jml_matrix jml/jml_ying jml/jml_permutation jml/jml_pow
	ar  rc tmp$(H)$(pre)jml.a tmp$(H)$(pre)jml_*.o
jml/jml_gcd               :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_gcd.o         jml$(H)jml_gcd.c          $(JML_EXLIB)
jml/jml_matrix            :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_matrix.o      jml$(H)jml_matrix.c       $(JML_EXLIB)
jml/jml_ying              :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_ying.o        jml$(H)jml_ying.c         $(JML_EXLIB)
jml/jml_permutation       :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_permutation.o jml$(H)jml_permutation.c  $(JML_EXLIB)
jml/jml_pow               :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_pow.o         jml$(H)jml_pow.c          $(JML_EXLIB)
