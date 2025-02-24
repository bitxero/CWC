#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "argparse.h"

darr_t create_darr() {
	int *v_darr = (int *)malloc(sizeof(int));
	darr_t darr = {
		.len = 0,
		.cap = 1,
		.darr = v_darr
	};
	return darr;
}

int push_darr(darr_t *darr, int val) {
	// push errors
	if (darr->darr == NULL) { return 0; }
	if (darr->len > darr->cap) { return 0; }
	// extend the array
	if (darr->len == darr->cap) {
		darr->cap *= 2;
		int *new_darr = (int *)malloc(sizeof(int) * darr->cap);
		// extention error
		if (new_darr == NULL) {
			darr->cap /= 2;
			return 0;
		}
		for (int i = 0; i < darr->len; i++) {
			new_darr[i] = darr->darr[i];
		}
		free(darr->darr);
		darr->darr = new_darr;
	}
	darr->darr[darr->len] = val;
	darr->len++;		
	return 1;
}

int get_program_state(int argc, char **argv, darr_t *darr) {
	int state = 0;
	int scan_flgs = 1;
	for (int i = 1; i < argc; i++) {
		int len = strlen(argv[i]);
		if (argv[i][0] == '-' && scan_flgs) {
			if (len < 2) {
				if (!push_darr(darr, i)) { return 0; }
			}
			if (argv[i][1] == '-') {
				if (len < 3) { scan_flgs = 0; } // end of flags
				if (!strcmp(argv[i], "--bytes")) {
					state |= BYTES;
				}else if (!strcmp(argv[i], "--chars")) {
					state |= CHARS;
				}else if (!strcmp(argv[i], "--lines")) {
					state |= NLINES;
				}else {
					printf("Invalid argument: %s\n", argv[i]);
					return -1;
				}
			} else {
				for (int j = 1; j < len; j++) {
					switch(argv[i][j]) {
						case 'b':
							state |= BYTES;
							break;
						case 'c':
							state |= CHARS;
							break;
						case 'l':
							state |= NLINES;
							break;
						default:
							printf("Invalid argument: -%c\n", argv[i][j]);
							return -1;
					}
				}
			}
		} else {
			if (!push_darr(darr, i)) { return 0; }
		}
	}
	return state;
}
