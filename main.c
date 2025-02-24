#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "details.h"
#include "argparse.h"
#include "fstat.h"

int main(int argc, char **argv) {
	// dynamic array to keep  track of files
	darr_t darr = create_darr();
	// program state of what info to show
	int program_state = get_program_state(argc, argv, &darr);
	// user error
	if (program_state == -1) { 
		free(darr.darr);
		return 1;
	}
	// memory error
	if (program_state == 0) {
		if (darr.darr != NULL) { free(darr.darr); }
		printf("Something went wrong internally:(\n");
		return 2;
	}
	// no files provider
	if (darr.len == 0) {
		details_t details = stdin_details();
		free(darr.darr);
		report_header(program_state);
		report(details, program_state, "-");
		return 0;
	}
	// file provided
	report_header(program_state);

	for (int i = 0; i < darr.len; i++) {
		details_t details;
		// stdin
		if (!strcmp(argv[darr.darr[i]], "-")) {
			details = stdin_details();
			if (details.ok) {
			report(details, program_state, "-");
			}
			continue;
		}
		// check file state
		int path_state = is_file(argv[darr.darr[i]]);
		if (path_state == -1) {
			printf("%s: No such file or directory.\n", argv[darr.darr[i]]);
			continue;
		} else if (path_state == 0) {
			printf("%s: Is a directory.\n", argv[darr.darr[i]]);
			continue;
		}
		// report
		details = file_details(argv[darr.darr[i]]);
		if (!details.ok) {
			printf("%s: Something went wrong internally:(\n", argv[darr.darr[i]]);
		}else {
			report(details, program_state, argv[darr.darr[i]]);
		}
	}
	// free the dynamic array
	if (darr.darr != NULL) { free(darr.darr); }
    return 0;
}
