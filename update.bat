@echo off
xcopy %libs%\jbl jbl\ /E /Y /Q /R
attrib +r jbl\*
attrib -r jbl\jbl*config.h
copy examples\makefile + jbl\makefile + jml\makefile makefile
xcopy jml %libs%\jml\ /E /Y /Q