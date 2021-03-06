#   Copyright (c) [2019] juruoyun developer team
#   Juruoyun math lib is licensed under the Mulan PSL v1.
#   You can use this software according to the terms and conditions of the Mulan PSL v1.
#   You may obtain a copy of Mulan PSL v1 at:
#      http://license.coscl.org.cn$(H)MulanPSL
#   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER BITSPRESS OR
#   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
#   PURPOSE.
#   See the Mulan PSL v1 for more details.
CC = gcc
BITS = -g
EXLIB = $(JBL_EXLIB) $(JML_EXLIB)
complain_re2c = jml
ifeq ($(shell uname),Linux)
	system = linux
else
ifeq ($(shell uname),Darwin)
	system = macos
else	
	system = windows
endif
endif

ifeq ($(system),linux)
	H = /
	rm = rm -f
	pre = linux_
endif
ifeq ($(system),windows)
	H = \\
	rm = del
	pre = win_
endif
ifeq ($(system),macos)
	H = /
	rm = rm -f
	pre = macos_
endif
all:jbl jml gcd matrix permutation pow vector
clean:
	$(rm) tmp$(H)* /s /Q
	$(rm) exes$(H)* /s /Q
	$(rm) testfiles$(H)*.out /s
	$(rm) testfiles$(H)*.ans /s
init:
	mkdir tmp
	mkdir exes
run:
	exes$(H)gcd         &&pause
	exes$(H)matrix0     &&pause
	exes$(H)matrix1     &&pause
	exes$(H)matrix2     &&pause
	exes$(H)matrix3     &&pause
	exes$(H)matrix4     &&pause
	exes$(H)matrix5     &&pause
	exes$(H)matrix6     &&pause
	exes$(H)matrix7     &&pause
	exes$(H)matrix8     &&pause
	exes$(H)matrix9     &&pause
	exes$(H)permutation &&pause
	exes$(H)pow         &&pause
	exes$(H)vector0     &&pause
	exes$(H)vector1     &&pause

#examples
gcd :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)gcd.o                examples$(H)gcd.c	
	$(CC) $(BITS) -o exes$(H)gcd               tmp$(H)$(pre)gcd.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
matrix :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix0.o            examples$(H)matrix0.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix1.o            examples$(H)matrix1.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix2.o            examples$(H)matrix2.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix3.o            examples$(H)matrix3.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix4.o            examples$(H)matrix4.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix5.o            examples$(H)matrix5.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix6.o            examples$(H)matrix6.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix7.o            examples$(H)matrix7.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix8.o            examples$(H)matrix8.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix9.o            examples$(H)matrix9.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix_benchmark0.o  examples$(H)matrix_benchmark0.c	
	$(CC) $(BITS) -o exes$(H)matrix0           tmp$(H)$(pre)matrix0.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix1           tmp$(H)$(pre)matrix1.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix2           tmp$(H)$(pre)matrix2.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix3           tmp$(H)$(pre)matrix3.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix4           tmp$(H)$(pre)matrix4.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix5           tmp$(H)$(pre)matrix5.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix6           tmp$(H)$(pre)matrix6.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix7           tmp$(H)$(pre)matrix7.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix8           tmp$(H)$(pre)matrix8.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix9           tmp$(H)$(pre)matrix9.o           tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix_benchmark0 tmp$(H)$(pre)matrix_benchmark0.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
permutation :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)permutation.o        examples$(H)permutation.c	
	$(CC) $(BITS) -o exes$(H)permutation       tmp$(H)$(pre)permutation.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
pow :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)pow.o                examples$(H)pow.c	
	$(CC) $(BITS) -o exes$(H)pow               tmp$(H)$(pre)pow.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
vector :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)vector0.o            examples$(H)vector0.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)vector1.o            examples$(H)vector1.c	
	$(CC) $(BITS) -o exes$(H)vector0           tmp$(H)$(pre)vector0.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)vector1           tmp$(H)$(pre)vector1.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
#   Copyright (c) [2020] juruoyun developer team
#   Juruoyun basic lib is licensed under the Mulan PSL v1.
#   You can use this software according to the terms and conditions of the Mulan PSL v1.
#   You may obtain a copy of Mulan PSL v1 at:
#      http://license.coscl.org.cn$(H)MulanPSL
#   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER BITSPRESS OR
#   IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
#   PURPOSE.
#   See the Mulan PSL v1 for more details.
#jbl
ifeq ($(system),linux)
JBL_EXLIB = -lpthread
endif
ifeq ($(system),windows)
JBL_EXLIB = 
endif
jbl                       :jbl/jbl_aes jbl/jbl_array jbl/jbl_base64 jbl/jbl_bitset jbl/jbl_cmd jbl/jbl_exception jbl/jbl_endian jbl/jbl_file jbl/jbl_gc jbl/jbl_ht jbl/jbl_json jbl/jbl_ll jbl/jbl_log jbl/jbl_malloc jbl/jbl_md5 jbl/jbl_pthread jbl/jbl_rand jbl/jbl_scanner jbl/jbl_sha1 jbl/jbl_stream jbl/jbl_string jbl/jbl_time jbl/jbl_var jbl/jbl_ying 
	ar  rc tmp$(H)$(pre)jbl.a tmp$(H)$(pre)jbl_*.o
jbl/jbl_aes            :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_aes.o         jbl$(H)jbl_aes.c         $(JBL_EXLIB)
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_aes_soft.o    jbl$(H)jbl_aes_soft.c    $(JBL_EXLIB)
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_aes_hard.o    jbl$(H)jbl_aes_hard.c    $(JBL_EXLIB) -maes
jbl/jbl_array          :
	$(CC) $(BITS) -c       -o tmp$(H)$(pre)jbl_array.o       jbl$(H)jbl_array.c       $(JBL_EXLIB)
jbl/jbl_base64         :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_base64.o      jbl$(H)jbl_base64.c      $(JBL_EXLIB)
jbl/jbl_bitset         :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_bitset.o      jbl$(H)jbl_bitset.c      $(JBL_EXLIB)
jbl/jbl_cmd            :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_cmd.o         jbl$(H)jbl_cmd.c         $(JBL_EXLIB)
jbl/jbl_endian         :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_endian.o      jbl$(H)jbl_endian.c      $(JBL_EXLIB)
jbl/jbl_exception      :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_exception.o   jbl$(H)jbl_exception.c   $(JBL_EXLIB)
jbl/jbl_file           :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_file.o        jbl$(H)jbl_file.c        $(JBL_EXLIB)
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_file_ct.o     jbl$(H)jbl_file_ct.c     $(JBL_EXLIB)
jbl/jbl_gc             :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_gc.o          jbl$(H)jbl_gc.c          $(JBL_EXLIB)
jbl/jbl_ht             :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_ht.o          jbl$(H)jbl_ht.c          $(JBL_EXLIB)
jbl/jbl_json           :
ifeq ($(system),linux)
ifeq ($(findstring jbl,$(complain_re2c)),jbl)
	re2c -f -c jbl$(H)jbl_json.l -o jbl$(H)jbl_json.c
endif
endif
ifeq ($(system),macos)
ifeq ($(findstring jbl,$(complain_re2c)),jbl)
	re2c -f -c jbl$(H)jbl_json.l -o jbl$(H)jbl_json.c
endif
endif
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_json.o        jbl$(H)jbl_json.c        $(JBL_EXLIB)
jbl/jbl_ll             :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_ll.o          jbl$(H)jbl_ll.c          $(JBL_EXLIB)
jbl/jbl_log             :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_log.o         jbl$(H)jbl_log.c         $(JBL_EXLIB)
jbl/jbl_malloc         :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_malloc.o      jbl$(H)jbl_malloc.c      $(JBL_EXLIB)
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_malloc_fast.o jbl$(H)jbl_malloc_fast.c $(JBL_EXLIB)
jbl/jbl_md5            :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_md5.o         jbl$(H)jbl_md5.c         $(JBL_EXLIB)
jbl/jbl_pthread        :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_pthread.o     jbl$(H)jbl_pthread.c     $(JBL_EXLIB)
jbl/jbl_rand           :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_rand.o        jbl$(H)jbl_rand.c        $(JBL_EXLIB)
jbl/jbl_scanner           :
ifeq ($(system),linux)
ifeq ($(findstring jbl,$(complain_re2c)),jbl)
	re2c -o jbl$(H)jbl_scanner.c jbl$(H)jbl_scanner.l
endif
endif
ifeq ($(system),macos)
ifeq ($(findstring jbl,$(complain_re2c)),jbl)
	re2c -o jbl$(H)jbl_scanner.c jbl$(H)jbl_scanner.l
endif
endif
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_scanner.o     jbl$(H)jbl_scanner.c     $(JBL_EXLIB)  
jbl/jbl_sha1           :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_sha1.o        jbl$(H)jbl_sha1.c        $(JBL_EXLIB)    
jbl/jbl_stream         :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_stream.o      jbl$(H)jbl_stream.c      $(JBL_EXLIB)
jbl/jbl_string         :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_string.o      jbl$(H)jbl_string.c      $(JBL_EXLIB)
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_string_cc.o   jbl$(H)jbl_string_cc.c   $(JBL_EXLIB)
jbl/jbl_time           :
ifeq ($(system),linux)
ifeq ($(findstring jbl,$(complain_re2c)),jbl)
	re2c -o jbl$(H)jbl_time.c jbl$(H)jbl_time.l
endif
endif
ifeq ($(system),macos)
ifeq ($(findstring jbl,$(complain_re2c)),jbl)
	re2c -o jbl$(H)jbl_time.c jbl$(H)jbl_time.l
endif
endif
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_time.o       jbl$(H)jbl_time.c        $(JBL_EXLIB)
jbl/jbl_var            :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_var.o        jbl$(H)jbl_var.c         $(JBL_EXLIB)
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_var_data.o   jbl$(H)jbl_var_data.c    $(JBL_EXLIB)
jbl/jbl_ying           :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)jbl_ying.o       jbl$(H)jbl_ying.c        $(JBL_EXLIB)
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
JML_EXLIB =  -lm
endif
ifeq ($(system),windows)
JML_EXLIB = 
endif
jml                       :jml/jml_gcd jml/jml_matrix jml/jml_permutation jml/jml_pow jml/jml_vector jml/jml_ying
	ar  rc tmp$(H)$(pre)jml.a tmp$(H)$(pre)jml_*.o
jml/jml_gcd               :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_gcd.o         jml$(H)jml_gcd.c          $(JML_EXLIB)
jml/jml_matrix            :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_matrix.o      jml$(H)jml_matrix.c       $(JML_EXLIB)
jml/jml_permutation       :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_permutation.o jml$(H)jml_permutation.c  $(JML_EXLIB)
jml/jml_pow               :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_pow.o         jml$(H)jml_pow.c          $(JML_EXLIB)
jml/jml_vector            :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_vector.o      jml$(H)jml_vector.c       $(JML_EXLIB)
jml/jml_ying              :
	$(CC) $(BITS) -c -Wall -Wextra -Wconversion -o tmp$(H)$(pre)jml_ying.o        jml$(H)jml_ying.c         $(JML_EXLIB)
