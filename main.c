#include <stdio.h>
#include <stdlib.h>

void save_pbm_image(long int width, long int height, char* pFilename, char* pData) {
	printf("%s\t->\t%s\n", pFilename, pData);

	// Create PBM image file
	FILE* pFile = fopen(pFilename, "w");

	// PBM file extension header (Portable BitMap magic identifier)
	fprintf(pFile, "P1\n");

	// Write image width & height to file
	fprintf(pFile, "%lu %lu\n", width, height);

	long int length = strlen(pData);

	// Write image data to file
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			// Ca
			long int index = j * width + i;

			fprintf(pFile, "%c ", pData[length - index - 1]);
		}

		fprintf(pFile, "\n");
	}

	// Close PBM image file
	fclose(pFile);
}

char *int_to_bin(int n) {
    // determine the number of bits needed ("sizeof" returns bytes)
    int nbits = sizeof(n) * 8;
    char *s = malloc(nbits+1);  // +1 for '\0' terminator
    s[nbits] = '\0';
    // forcing evaluation as an unsigned value prevents complications
    // with negative numbers at the left-most bit
    unsigned int u = *(unsigned int*)&n;
    int i;
    unsigned int mask = 1 << (nbits-1); // fill in values right-to-left
    for (i = 0; i < nbits; i++, mask >>= 1)
        s[i] = ((u & mask) != 0) + '0';
    return s;
}

void f(long int width, long int height) {

	// char* str;
	// str = (char*) malloc(100 * sizeof(char));

	// sprintf(str, "%d", 42);
	// fprintf(stdout, "%s\n", str);


	for (int i = 0; i < 16; i++) {

		char* pFilename;
		pFilename = (char*) malloc(100 * sizeof(char));
		sprintf(pFilename, "output/%d.pbm", i);

        char *pData = int_to_bin(i);
        // save image
        save_pbm_image(width, height, pFilename, pData);
        //printf("%d -> %s\n", i, pData);
        free(pData);
    }
}

// new
void r(long int size, char* pData) {
	long int dataLength = strlen(pData);

	//fprintf(stdout, "DEBUG %ld/%ld\n", dataLength, size);

	if (dataLength == size) {
		fprintf(stdout, "%s\n", pData);
	} else {
		long int dataCopyLength = dataLength + 2;

		char* pDataCopy0 = (char*) malloc(dataCopyLength * sizeof(char));
		strcpy(pDataCopy0, pData);
		pDataCopy0[dataLength] = '0';
		pDataCopy0[dataLength + 1] = '\0';
		r(size, pDataCopy0);

		char* pDataCopy1 = (char*) malloc(dataCopyLength * sizeof(char));
		strcpy(pDataCopy1, pData);
		pDataCopy1[dataLength] = '1';
		pDataCopy1[dataLength + 1] = '\0';
		r(size, pDataCopy1);
	}
}

int main(int argc, char** argv) {
	long int height, width;

    if (argc == 3) {
        width = strtol(argv[1], NULL, 10);
        height = strtol(argv[2], NULL, 10);

        // TODO: call function to generate images
        // f(width, height);
        //char* pData = "";//(char*) malloc(sizeof(char));
        // pData[0] = '\0';
        r(height * width, "");
    } else {
        fprintf(stderr, "Invalid number of arguments.");
    }

	return 0;
}