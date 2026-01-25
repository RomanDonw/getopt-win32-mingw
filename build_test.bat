@echo off

echo Building test program with static linking...
gcc -static -I. -L./build ./test/main.c -o ./test/main_static.exe -lgetopt

echo Building test program with dynamic linking...
gcc -I. -L./build ./test/main.c -o ./test/main_dynamic.exe -lgetopt

echo Finished successfully.