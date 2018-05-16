#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ELLIPSE_TYPE 0
#define BRICK_TYPE 1

typedef struct Light_ {
    Point lightSource;
} Light;

typedef struct Element_ {
    char type;
    double * object;
    struct Element_ * next;
} Element;

typedef struct List_ {
    Element * tete;
    double nbElement;
} List;

typedef struct Ray_ {
    Line rayLine;
} Ray;

