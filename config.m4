PHP_ARG_ENABLE(test, Enable test support)

if test "$PHP_TEST" = "yes"; then
   AC_DEFINE(HAVE_TEST, 1, [You have test extension])
   PHP_NEW_EXTENSION(system_available_memory, system_available_memory.c, $ext_shared)
fi
