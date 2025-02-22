#ifndef ARGPARSE_H_
#define ARGPARSE_H_

typedef struct {
	int len;
	int cap;
	int *darr;
} darr_t;

enum states {
	BYTES = 1,
};

int get_program_state(int argc, char **argv, int *file_count, int *files);

#endif
