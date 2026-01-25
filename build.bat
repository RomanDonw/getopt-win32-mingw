@echo off

if exist ".\build\" goto skip_creating_build_folder
	echo Creating build directory...
	mkdir build
:skip_creating_build_folder

echo Building sources...
gcc -DEXPORTS_GETOPT -c ./getopt.c -o ./getopt.o
if not exist ".\getopt.o" goto end

echo Creating static library...
ar rcs ./build/libgetopt.a ./getopt.o

echo Linking dynamic library...
gcc -fPIC -shared ./getopt.o -o ./build/getopt.dll

del .\getopt.o

:end