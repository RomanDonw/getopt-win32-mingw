/*
	getopt-win32-mingw - getopt implementation library for Windows (Win32) with MinGW.

	Copyright (C) 2026 Roman Kravchenko
	Based on getopt-win32 by nanoporetech (https://github.com/nanoporetech/getopt-win32).
	Original getopt from GNU C Library.

	SPDX-License-Identifier: LGPL-3.0
*/

#pragma once

#include <string.h>
#include <wchar.h>

// Standard GNU options
#define	null_argument 0 // Argument Null
#define	no_argument 0 // Argument Switch Only
#define required_argument 1 // Argument Required
#define optional_argument 2 // Argument Optional

// Shorter Options
#define ARG_NULL 0 // Argument Null
#define ARG_NONE 0 // Argument Switch Only
#define ARG_REQ	 1 // Argument Required
#define ARG_OPT	2 // Argument Optional

extern int optind;
extern int opterr;
extern int optopt;

/* ===== ANSI function versions. ===== */

struct option_a
{
	const char* name;
	int has_arg;
	int *flag;
	int val;
};

extern char *optarg_a;
extern int getopt_a(int argc, char *const *argv, const char *optstring);
extern int getopt_long_a(int argc, char *const *argv, const char *options, const struct option_a *long_options, int *opt_index);
extern int getopt_long_only_a(int argc, char *const *argv, const char *options, const struct option_a *long_options, int *opt_index);

/* ===== UNICODE function versions. ===== */

struct option_w
{
	const wchar_t *name;
	int has_arg;
	int *flag;
	int val;
};

extern wchar_t *optarg_w;
extern int getopt_w(int argc, wchar_t *const *argv, const wchar_t *optstring);
extern int getopt_long_w(int argc, wchar_t *const *argv, const wchar_t *options, const struct option_w *long_options, int *opt_index);
extern int getopt_long_only_w(int argc, wchar_t *const *argv, const wchar_t *options, const struct option_w *long_options, int *opt_index);

/* ===== Select a definition of standard names based on present UNICODE or _UNICODE flag. ===== */

#if defined(UNICODE) || defined(_UNICODE)
	#define getopt getopt_w
	#define getopt_long getopt_long_w
	#define getopt_long_only getopt_long_only_w
	#define option option_w
	#define optarg optarg_w
#else
	#define getopt getopt_a
	#define getopt_long getopt_long_a
	#define getopt_long_only getopt_long_only_a
	#define option option_a
	#define optarg optarg_a
#endif