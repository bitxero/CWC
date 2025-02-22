#include <stdio.h>
#include <stdlib.h>
#include "details.h"
#include "argparse.h"


int main(int argc, char **argv) {
	darr_t darr = create_darr();
	int program_state = get_program_state(argc, argv, &darr);
	if (program_state == -1) { 
		free(darr.darr);
		return 1;
	}
	if (program_state == 0) {
		if (darr.darr != NULL) { free(darr.darr); }
		printf("Something went wrong internally:(");
		return 2;
	}
	// for (int i = 0; i < darr.len; i++) { printf("%s\n", argv[darr.darr[i]]); }
    // details_t f_dtls = stdin_details();
	if (darr.darr != NULL) { free(darr.darr); }
    return 0;
}
