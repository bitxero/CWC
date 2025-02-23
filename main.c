#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "details.h"
#include "argparse.h"
#include "fstat.h"

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
	
	report_header(program_state);

	if (darr.len == 0) {
		details_t details = stdin_details();
		free(darr.darr);
		report(details, program_state, "");
		return 0;
	}

	for (int i = 0; i < darr.len; i++) {
		details_t details;
		if (!strcmp(argv[darr.darr[i]], "-")) {
			details = stdin_details();
			report(details, program_state, "-");
			continue;
		}
		int path_state = is_file(argv[darr.darr[i]]);
		if (path_state == -1) {
			printf("%s: No such file or directory.\n", argv[darr.darr[i]]);
			continue;
		} else if (path_state == 0) {
			printf("%s: Is a directory.\n", argv[darr.darr[i]]);
			continue;
		}
		details = file_details(argv[darr.darr[i]]);
		report(details, program_state, argv[darr.darr[i]]);

	}

	if (darr.darr != NULL) { free(darr.darr); }
    return 0;
}
