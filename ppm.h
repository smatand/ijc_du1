#ifndef PPM_H
#define PPM_H

/* maximum size of ppm image */
#define MAX_IMAGE_SIZE (8000 * 8000 * 3) // 192m										
#define MAX_RGB 255


/**
 * @brief	Data about the size and data of ppm image
 */
struct ppm {
	unsigned xsize;
	unsigned ysize;
	char data[]; // RGB bytes, in total (3 * xsize * ysize)
};

/**
 * @brief	Read data from file filename and store them
 *
 * @param	filename used to read the file from
 * @return	struct with stored data 
 */
struct ppm * ppm_read(const char * filename);

/**
 * @brief		Free dynamically allocated memory
 *
 * @param *p	used to free from memory
 */
void ppm_free(struct ppm *p);

#endif // PPM_H
