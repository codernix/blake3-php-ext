PHP_ARG_WITH([blake3],
  [for Blake3 support],
  [AS_HELP_STRING([--with-blake3=DIR], [Include Blake3 support, where DIR is the path to the blake3_wrapper library])])

if test "$PHP_BLAKE3" != "no"; then
  # If the user provided a path (--with-blake3=/some/path), use it.
  # Otherwise, check standard system paths.
  if test -r "$PHP_BLAKE3/include/blake3_wrapper.h"; then
    BLAKE3_DIR=$PHP_BLAKE3
    BLAKE3_INC_DIR=$BLAKE3_DIR/include
    BLAKE3_LIB_DIR=$BLAKE3_DIR/lib
  else
    AC_MSG_CHECKING([for blake3_wrapper in default locations])
    # Set default search paths here if you want
    BLAKE3_DIR=
    BLAKE3_INC_DIR=
    BLAKE3_LIB_DIR=
  fi

  # Add the include path for blake3_wrapper.h
  PHP_ADD_INCLUDE_DIR([$BLAKE3_INC_DIR])

  # Check for the library and the required function
  PHP_CHECK_LIBRARY([blake3_wrapper], [blake3_hash],
  [
    # Success! Add library to linker flags and define a preprocessor macro.
    PHP_ADD_LIBRARY_WITH_PATH([blake3_wrapper], [$BLAKE3_LIB_DIR], [BLAKE3_SHARED_LIBADD])
    AC_DEFINE(HAVE_BLAKE3, 1, [Define if Blake3 library is available])
    AC_MSG_RESULT([found])
  ],[
    # Failure!
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Cannot find blake3_wrapper library. Please specify the installation directory with --with-blake3=DIR])
  ],
  [
    # Extra search paths can be added here
    -L$BLAKE3_LIB_DIR
  ])

  PHP_NEW_EXTENSION(blake3, blake3.c, $ext_shared)
fi