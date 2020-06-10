#ifndef __COMMON_H__
#define __COMMON_H__

#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "memory.h"
#include "errors.h"
#include "ptr_lists.h"
#include "configure.h"
#include "misc.h"

extern memory_system_t* memory_system;

#endif
