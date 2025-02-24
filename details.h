#include <stdio.h>
#ifndef DETAILS_H_
#define DETAILS_H_

typedef struct {
    long bytes;
	long chars;
	long nlines;
	char ok;
} details_t;

details_t file_details(char *fname);
details_t stdin_details();
void report(details_t details, int state, char *fname);
void report_header(int state);

#endif 
