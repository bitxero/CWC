#include <stdio.h>
#include "details.h"
#include "argparse.h"


int main(int argc, char **argv) {
	int file_count;
	int *files;
	int program_state = get_program_state(argc, argv, &file_count, files);
	if (program_state == -1) { return 1; }
    FILE *fp = fopen("test.txt", "r"); // temprary value
    details_t f_dtls = stdin_details();
    printf("%ld\n", f_dtls.bytes);
    return 0;
}
