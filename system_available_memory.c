#include <stdio.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/vmmeter.h>
#include "php.h"
PHP_FUNCTION(system_available_memory);

const zend_function_entry test_functions[] = {
	PHP_FE(system_available_memory, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry test_module_entry = {
	STANDARD_MODULE_HEADER,       // #if ZEND_MODULE_API_NO >= 20010901
	"system_available_memory",                       // название модуля
	test_functions,               // указываем экспортируемые функции
	NULL,                         // PHP_MINIT(test), Module Initialization
	NULL,                         // PHP_MSHUTDOWN(test), Module Shutdown
	NULL,                         // PHP_RINIT(test), Request Initialization
	NULL,                         // PHP_RSHUTDOWN(test), Request Shutdown
	NULL,                         // PHP_MINFO(test), Module Info (для phpinfo())
	"0.1",                        // версия нашего модуля
	STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(test)

PHP_FUNCTION(system_available_memory)
{
    int rc;
    u_int page_size;
    struct vmtotal vmt;
    size_t vmt_size, uint_size; 

    vmt_size = sizeof(vmt);
    uint_size = sizeof(page_size);

    rc = sysctlbyname("vm.vmtotal", &vmt, &vmt_size, NULL, 0);
    if (rc < 0){
	RETURN_FALSE;
       //perror("sysctlbyname");
      // return 1;
    }

    rc = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &uint_size, NULL, 0);
    if (rc < 0){
	RETURN_FALSE; 
      // perror("sysctlbyname");
       //return 1;
    }
	RETURN_LONG(vmt.t_free * (u_int64_t)page_size);
    //printf("Free memory       : %ld\n", vmt.t_free * (u_int64_t)page_size);
    //printf("Available memory  : %ld\n", vmt.t_avm * (u_int64_t)page_size);

    
    //RETURN_STRING("hello habr", 1); 
}
