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
