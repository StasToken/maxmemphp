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
	STANDARD_MODULE_HEADER,       
	"system_available_memory",    
	test_functions,               
	NULL,                         
	NULL,                         
	NULL,                         
	NULL,                         
	NULL,                         
	"0.1",                      
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
    }

    rc = sysctlbyname("vm.stats.vm.v_page_size", &page_size, &uint_size, NULL, 0);
    if (rc < 0){
	RETURN_FALSE; 
    }
	RETURN_LONG(vmt.t_free * (u_int64_t)page_size);
}
