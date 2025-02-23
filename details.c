#include "details.h"
#define BUF_SIZE 1024

details_t file_details(char* fname) {
	details_t dtls;
	FILE *fp = fopen(fname, "r");
	
	if (fp == NULL) {
		dtls.ok = 0;
		return dtls;
	} 
    
    char mystr[BUF_SIZE];
    while (fgets(mystr, BUF_SIZE, fp));

    dtls.bytes = ftell(fp);

    return dtls;
}

details_t stdin_details() {

    details_t dtls = {
		.ok = 1,
        .bytes = 0,
    };
    
    while (getchar() != EOF) { dtls.bytes++; }

    return dtls;
}
