#include "hashcmap.h"
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct entry {
    void * key;
    void * value;
    struct entry * next;
}*Entry
