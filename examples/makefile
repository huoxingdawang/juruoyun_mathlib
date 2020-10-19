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
all:jbl jml matrix
clean:
	$(rm) tmp$(H)* /s /Q
	$(rm) exes$(H)* /s /Q
	$(rm) testfiles$(H)*.out /s
	$(rm) testfiles$(H)*.ans /s
init:
	mkdir tmp
	mkdir exes
run:
	exes$(H)test    &&pause

#examples
matrix :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix0.o            examples$(H)matrix0.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix1.o            examples$(H)matrix1.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix2.o            examples$(H)matrix2.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix3.o            examples$(H)matrix3.c	
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)matrix4.o            examples$(H)matrix4.c	
	$(CC) $(BITS) -o exes$(H)matrix0           tmp$(H)$(pre)matrix0.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix1           tmp$(H)$(pre)matrix1.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix2           tmp$(H)$(pre)matrix2.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix3           tmp$(H)$(pre)matrix3.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
	$(CC) $(BITS) -o exes$(H)matrix4           tmp$(H)$(pre)matrix4.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
permutation :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)permutation.o            examples$(H)permutation.c	
	$(CC) $(BITS) -o exes$(H)permutation           tmp$(H)$(pre)permutation.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
pow :
	$(CC) $(BITS) -c -Wall -o tmp$(H)$(pre)pow.o            examples$(H)pow.c	
	$(CC) $(BITS) -o exes$(H)pow           tmp$(H)$(pre)pow.o tmp$(H)$(pre)jml.a tmp$(H)$(pre)jbl.a $(EXLIB)
