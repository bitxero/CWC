#include <sys/stat.h>
#include "fstat.h"

int is_file(char *fname) {
	struct stat buff;
	if (stat(fname, &buff) != 0) { return -1; }
	return !S_ISDIR(buff.st_mode);
}
