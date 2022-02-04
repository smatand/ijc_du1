#ifndef PPM_H
#define PPM_H

#define MAX_IMAGE_SIZE (8000 * 8000 * 3) // 192m
#define MAX_RGB 255


struct ppm {
	unsigned xsize;
	unsigned ysize;
	char data[]; // RGB bytes, in total (3 * xsize * ysize)
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif // PPM_H
