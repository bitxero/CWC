#include <stdio.h>
#include "details.h"

int main() {
    FILE *fp = fopen("test.txt", "r"); // temprary value
    details_t f_dtls = stdin_details();
    printf("%ld\n", f_dtls.bytes);
    return 0;
}
