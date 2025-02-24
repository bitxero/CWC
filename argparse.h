#ifndef ARGPARSE_H_
#define ARGPARSE_H_

typedef struct {
	int len;
	int cap;
	int *darr;
} darr_t;

enum states {
	BYTES = 1,
	CHARS = 2,
};

int get_program_state(int argc, char **argv, darr_t *darr);
darr_t create_darr();

#endif
