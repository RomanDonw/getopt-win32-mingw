# POSIX getopt library implementation for Windows (Win32) with MinGW.

Used sources from [getopt-win32](https://github.com/nanoporetech/getopt-win32) repo and setupped it to compile with MinGW to static (`lib[...].a`) & dynamic (`[...].dll`) libraries.

## Building
Just run `build.bat` and wait for comiling and linking libraries. Out libraries files contain in `build/` folder.

## Usage
Copy `getopt.h` to your compiler include path (folder).

### For static linking:
You need only to copy `libgetopt.a` to MinGW libraries path (folder).

### For dynamic linking:
It has the same steps like static linking, but also has some additions.
It's recommended to **copy `getopt.dll` to both compiler libraries path (folder) and your application folder (where contains you `.exe` program)**, overwise you can get *\"library not found\"*-like Windows error when you run your program.
