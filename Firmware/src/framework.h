#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include "compiler.h"
#include "asf.h"
#include "statusc/statusc.h"
#include "config/conf_drivers.h"
#include "utest/utest.h"

#define UTEST_OUTPUT_CHAR(a) usart_putchar(CONF_USART_POINTER, a);

#endif /* FRAMEWORK_H_ */