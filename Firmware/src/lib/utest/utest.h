#ifndef UTEST_H_
#define UTEST_H_

#include "framework.h"

#include "utest/private/utest_asserts.h"
#include "utest/private/utest_template.h"

extern void utest_main(void (*utest_fixture)(void));

#endif /* UTEST_H_ */