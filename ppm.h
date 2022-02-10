#ifndef PPM_H
#define PPM_H

/* maximum size of ppm image */
#define MAX_IMAGE_SIZE (8000 * 8000 * 3) // 192m										
#define MAX_RGB 255


struct ppm {
	unsigned xsize;
	unsigned ysize;
	char data[]; // RGB bytes, in total (3 * xsize * ysize)
};

/**
 * reads from file filename and stores elements of created struct ppm
 * ppm->data is dynamically allocated, so it must have its free() fcn
 *
 * @param filename used to read the file from
 *
 * @return struct with defined sizes and dynamically alloc-ted char[]
 */
struct ppm * ppm_read(const char * filename);

/**
 * frees dynamically allocated struct ppm
 *
 * @param *p used to free from memory
 */
void ppm_free(struct ppm *p);

#endif // PPM_H
