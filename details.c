#include "details.h"
#define BUF_SIZE 1024

details_t file_details(FILE *fp) {
    details_t dtls;
    
    char mystr[BUF_SIZE];
    while (fgets(mystr, BUF_SIZE, fp));

    dtls.bytes = ftell(fp);

    return dtls;
}

details_t stdin_details() {

    details_t dtls = {
        .bytes = 0,
    };
    
    while (getchar() != EOF) { dtls.bytes++; }

    return dtls;
}
