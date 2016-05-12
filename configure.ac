#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.59])
AC_INIT([wcwidth-cjk], [0.99], [https://github.com/fumiyas/wcwidth-cjk])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([wcwidth.c])
AC_CONFIG_FILES([wcwidth-cjk], [chmod +x wcwidth-cjk])

# Checks for programs.
AC_PROG_CC

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([sys/param.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

#
# Platform specific setup
#
#############################
AC_CANONICAL_HOST
# Check for which host we are on and setup a few things
# specifically based on the host
case $host_os in
darwin*)
  AC_SUBST(LD_PRELOAD, DYLD_INSERT_LIBRARIES)
  AC_SUBST(DYLD_FORCE_FLAT_NAMESPACE, DYLD_FORCE_FLAT_NAMESPACE)
  AC_SUBST(SHARED_LIB_EXT, dylib)
  ;;
*)
  AC_SUBST(LD_PRELOAD, LD_PRELOAD)
  AC_SUBST(DYLD_FORCE_FLAT_NAMESPACE, '')
  AC_SUBST(SHARED_LIB_EXT, so)
  ;;
esac

AC_ARG_ENABLE(ja-legacy,
  AC_HELP_STRING([--enable-ja-legacy], [return width 2 for U+00A2 CENT SIGN, U+00A3 POUND SIGN, U+00A5 YEN SIGN, U+00A6 BROKEN BAR, U+00AC NOT SIGN, U+00AF MACRO, U+2212 MINUS SIGN]),
  [],
  [enable_ja_legacy=no]
)
if test x"$enable_ja_legacy" != x"no"; then
  AC_DEFINE([JA_LEGACY], [1], [No comment])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
