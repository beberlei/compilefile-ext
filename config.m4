PHP_ARG_ENABLE(compilefile, whether to enable compilefile support, [  --enable-compilefile           Enable compilefile support])

if test "$PHP_COMPILEFILE" != "no"; then
  PHP_NEW_EXTENSION(compilefile, compilefile.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
