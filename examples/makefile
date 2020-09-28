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
EXLIB = $(JBL_EXLIB) $(JWL_EXLIB)
complain_re2c = jwl
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
all:jbl jml
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
