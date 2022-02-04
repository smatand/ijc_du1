#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"
#include "bitset.h"
#include "error.h"

struct ppm * ppm_read(const char * filename) {
	FILE *fp;
	fp = fopen(filename, "rb");
	// make sure the file opens
	if (!fp) {
		warning_msg("Chyba nacteni souboru '%s'\n", filename);
		goto error;
	}
	// buffer
	char buff[3];
	unsigned width = 0;
	unsigned height = 0;
	int rgb = 0;

	// read the header of file in a declared format
	// "P6" <ws>+ <xsizetxt> <ws>+ <ysizetxt> <ws+> "255" <ws> <binary data, MAX_IMAGE_SIZE>
	if(!fscanf(fp, "%s %u %u %d ", buff, &width, &height, &rgb)) {
		warning_msg("Problemy s nactenim hlavicky souboru %s.\n", filename);
		goto error;
	}
	// todo: edit it for more details about error
	if (strcmp(buff, "P6")) {
		warning_msg("Program podporuje jenom format P6 (ppm)!\n");
		goto error;
	}
	// initialize struct with read data
	unsigned imageSize = width*height*3;
    if (imageSize > MAX_IMAGE_SIZE) {
        warning_msg("Prilis velkej obrazek v souboru %s\n", filename);
        goto error;
    }
    if ((rgb < 0) || (rgb > MAX_RGB)) {
        warning_msg("Rozsah RGB hodnot muze byt jenom 0-255. Soubor %s ma %d", filename, rgb);
        goto error;
    }
	struct ppm * image = malloc(sizeof(struct ppm) + imageSize);
	if (image == NULL) {
		warning_msg("Alokace pomoci malloc()\n.");
		goto error;
	}
	image->xsize = width;
	image->ysize = height;

	// fread returns the number of items read which equals the number of bytes transferred only when size is 1
	if(fread(image->data, 1, imageSize, fp) != imageSize) {
		if (feof(fp) || ferror(fp)) {
			warning_msg("Problemy se ctenim binarnych dat souboru %s.\n", filename);
			free(image);
			goto error;
		}
	}
	return image;

	// GOTO
error:
	fclose(fp);
	return NULL;
}

void ppm_free(struct ppm *p) {
	free(p);
}
