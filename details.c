#include "details.h"
#define BUF_SIZE 256

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
    
    char mystr[BUF_SIZE];
    while (fgets(mystr, BUF_SIZE, stdin)) {
        for (int i = 0; i < BUF_SIZE; i++) {
            if (mystr[i] == '\0') { break; }
            dtls.bytes++;
        }
    }

    return dtls;
}
