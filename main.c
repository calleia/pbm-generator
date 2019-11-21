#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	long int height, width;

    if (argc == 3) {
        width = strtol(argv[1], NULL, 10);
        height = strtol(argv[2], NULL, 10);

        // TODO: call function to generate images
    } else {
        fprintf(stderr, "Invalid number of arguments.");
    }

	return 0;
}