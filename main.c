#include <stdio.h>
#include <stdlib.h>

void make_images(long int width, long int height) {
	/*
	float** w;
	w = (float**) malloc(nNeurons * sizeof(float*));

	for (i = 0; i < nNeurons; i++) {
		w[i] = (float*) calloc(nNeurons, sizeof(float));
		check_memory_allocation(w[i], "w[i]", "calculate_weights()");
	}

	for (k = 0; k < trainingSetSize; k++) {
		for (i = 0; i < nNeurons; i++) {
			for (j = 0; j < nNeurons; j++) {
				if (i != j)
					w[i][j] += pTrainingSet[k][i] * pTrainingSet[k][j];
			}
		}
	}
	*/

	int *pPattern = (int*) malloc( (width * height) * sizeof(int));
}

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