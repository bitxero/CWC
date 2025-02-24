#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int len;
	int cap;
	char **darr;
} sdarr_t;

sdarr_t create_sdarr() {
	char **v_darr = (char **)malloc(sizeof(char*));
	sdarr_t darr = {
		.len = 0,
		.cap = 1,
		.darr = v_darr
	};
	return darr;
}

int push_sdarr(sdarr_t *darr, char *val) {
	// push errors
	if (darr->darr == NULL) { return 0; }
	if (darr->len > darr->cap) { return 0; }
	// extend the array
	if (darr->len == darr->cap) {
		darr->cap *= 2;
		char **new_darr = (char **)malloc(sizeof(char*) * darr->cap);
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

sdarr_t frmfile(char* fname) {
	sdarr_t files = create_sdarr();
	// read file names from stdin
	if (!strcmp(fname, "-")) {
		do {
			char *myfile = (char *)calloc(sizeof(char) * 256, 0);
			int flen = 0;
			char c;

			while ((c = getchar()) != EOF && c != '\n') {	
				myfile[flen] = c;
				flen++;
				if (flen > 255) { flen = 0; }
			}
			if (strlen(myfile) > 0) {
				myfile[flen] = '\0';
				push_sdarr(&files, myfile);
			}else {
				free(myfile);
			}

			if (c == EOF) { break; }

		}while(1);
	}else {
		// read file names from file
	}

	return files;
}
// this is redundant
int main() {
	sdarr_t darr = frmfile("-");
	for (int i = 0; i < darr.len; i++) {
		printf("%s\n", darr.darr[i]);
		free(darr.darr[i]);
	}
	free(darr.darr);
	return 0;
}
