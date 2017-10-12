#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_compilefile.h"

PHP_MINIT_FUNCTION(compilefile)
{
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(compilefile)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(compilefile)
{
}

const zend_function_entry compilefile_functions[] = {
    PHP_FE(compile_file,	NULL)
    PHP_FE_END
};

zend_module_entry compilefile_module_entry = {
    STANDARD_MODULE_HEADER,
    "compilefile",
    compilefile_functions,
    PHP_MINIT(compilefile),
    PHP_MSHUTDOWN(compilefile),
    NULL,
    NULL,
    PHP_MINFO(compilefile),
    PHP_compilefile_VERSION,
    STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_compilefile
ZEND_GET_MODULE(compilefile)
#endif
