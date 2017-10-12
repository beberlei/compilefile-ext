#ifndef PHP_compilefile_H
#define PHP_compilefile_H

extern zend_module_entry compilefile_module_entry;
#define phpext_compilefile_ptr &compilefile_module_entry

#define PHP_COMPILEFILE_VERSION "0.1.0"

ZEND_BEGIN_MODULE_GLOBALS(compilefile)
ZEND_END_MODULE_GLOBALS(compilefile)

#if defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_COMPILEFILE_API __attribute__ ((visibility("default")))
#else
#	define PHP_COMPILEFILE_API
#endif

#endif	/* PHP_compilefile_H */
