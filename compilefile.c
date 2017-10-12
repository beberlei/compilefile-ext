#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_compilefile.h"

ZEND_DECLARE_MODULE_GLOBALS(compilefile)

PHP_FUNCTION(compile_file)
{
    zend_file_handle file_handle;
    zend_string *resolved_path;
    zval *path;
    int failure_retval;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &path) == FAILURE) {
        return;
    }

    resolved_path = zend_resolve_path(Z_STRVAL_P(path), (int)Z_STRLEN_P(path));

    if (resolved_path) {
        failure_retval = zend_hash_exists(&EG(included_files), resolved_path);
    } else {
        resolved_path = zend_string_copy(Z_STR_P(path));
    }

    if (failure_retval) {
        /* do nothing, file already included */
    } else if (SUCCESS == zend_stream_open(ZSTR_VAL(resolved_path), &file_handle)) {

        if (!file_handle.opened_path) {
            file_handle.opened_path = zend_string_copy(resolved_path);
        }

        if (zend_hash_add_empty_element(&EG(included_files), file_handle.opened_path)) {
            zend_compile_file(&file_handle, ZEND_REQUIRE);
            zend_destroy_file_handle(&file_handle);
        } else {
            zend_file_handle_dtor(&file_handle);
            failure_retval=1;
        }
    }
}

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
    PHP_COMPILEFILE_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_COMPILEFILE
ZEND_GET_MODULE(compilefile)
#endif
