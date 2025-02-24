#include "details.h"
#include "argparse.h"

#define BUF_SIZE 1024

details_t file_details(char* fname) {
	details_t dtls;
	FILE *fp = fopen(fname, "r");
	// file open error
	if (fp == NULL) {
		dtls.ok = 0;
		return dtls;
	}

	dtls.chars = 0;
	dtls.nlines = 0;
	int c;
	// char count
	while ((c = fgetc(fp)) != EOF) { 
		if ((c & 255) < 128 || ((c & 255) >= 128 && (c & 255) < 192)) { 
			dtls.chars++;
			if (c == 10) { dtls.nlines++; }
		} 
	}
	// byte count
	dtls.bytes = ftell(fp);
	// set ok
	dtls.ok = 1;
	return dtls;
    
}

details_t stdin_details() {
	// set ok
    details_t dtls = {
		.ok = 1,
        .bytes = 0,
		.nlines = 0,
    };
    // read a char at a time
    while (1) {
		int c = getchar();
		if(c == EOF) { break; }
		dtls.bytes++;
		if ((c & 255) < 128 || ((c & 255) >= 128 && (c & 255) < 192)) { 
			dtls.chars++;
			if (c == 10) { dtls.nlines++; }
		}
	}

    return dtls;
}

void report(details_t details, int state, char *fname) {
	if (state & BYTES) { printf(" %-10ld", details.bytes); }
	if (state & CHARS) { printf(" %-10ld", details.chars); }
	if (state & NLINES) { printf(" %-10ld", details.nlines); }
	printf("\t%s\n", fname);
}

void report_header(int state) {
	if (state & BYTES) { printf(" %-10s", "bytes"); }
	if (state & CHARS) { printf(" %-10s", "chars"); }
	if (state & NLINES) { printf(" %-10s", "new lines"); }
	printf("\tfile name\n");
}
