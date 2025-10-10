#ifndef TYPES_H
#define TYPES_H

#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ unsigned long
#endif
#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ signed long
#endif

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ssize_t;

#endif
