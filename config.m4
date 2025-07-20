PHP_ARG_WITH([blake3],
  [for Blake3 support],
  [AS_HELP_STRING([--with-blake3], [Include Blake3 support])])

if test "$PHP_BLAKE3" != "no"; then
  AC_MSG_CHECKING([for blake3_hash in -lblake3_wrapper])

  # Check for the library and the required function.
  # We pass an empty fourth argument because the search paths are provided
  # by the LDFLAGS and CPPFLAGS environment variables set in the build script.
  PHP_CHECK_LIBRARY([blake3_wrapper], [blake3_hash],
  [
    # Success! Add the library to the linker flags and define a preprocessor macro.
    PHP_ADD_LIBRARY(blake3_wrapper, 1, BLAKE3_SHARED_LIBADD)
    AC_DEFINE(HAVE_BLAKE3, 1, [Define if Blake3 library is available])
    AC_MSG_RESULT([found])
  ],[
    # Failure!
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Cannot find blake3_wrapper library. Check that it is installed and that CPPFLAGS and LDFLAGS are set correctly.])
  ])

  PHP_NEW_EXTENSION(blake3, blake3.c, $ext_shared)
fi
