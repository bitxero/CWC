#include <stdio.h>
#ifndef DETAILS_H_
#define DETAILS_H_

typedef struct {
    long bytes;
} details_t;

details_t file_details(FILE *fp);
details_t stdin_details();
#endif 
