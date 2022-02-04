#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"
#include "error.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		error_exit("Program musi prijat jenom jeden argument s nazvem souboru ke cteni!");	
	}
	// get ppm data
	struct ppm *image = ppm_read(argv[1]); 	


	ppm_free(image);
	return 0;
}
