#include <stdio.h>
#ifndef DETAILS_H_
#define DETAILS_H_

typedef struct {
    long bytes;
	char ok;
} details_t;

details_t file_details(char *fname);
details_t stdin_details();
#endif 
