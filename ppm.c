#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"

//////////////////////////////////////////////////////////////////////////////////////

ppmPic *readPic(char *fileName) {
	int tempr = 0;
	int tempg = 0;
	int tempb = 0;
	FILE* aPic = NULL;
	aPic = fopen(fileName, "r");
	char skip[3];
	fscanf(aPic, "%s", skip);
	ppmPic *myPic = malloc(sizeof(ppmPic));
	fscanf(aPic, "%d" "%d" "%d", &myPic->cols, &myPic->rows, &myPic->colors);
	myPic->pixels = malloc(sizeof(Pixel *) * myPic->rows);
	for(int x = 0; x < myPic->rows; x++){
		myPic->pixels[x] = malloc(sizeof(Pixel) * myPic->cols);
	}
	for(int r = 0; r < myPic->rows; r++){
		for(int c = 0; c < myPic->cols; c++){
			fscanf(aPic, "%d", &tempr);
			myPic->pixels[r][c].red = tempr;
			fscanf(aPic, "%d", &tempg);
			myPic->pixels[r][c].green = tempg;
			fscanf(aPic, "%d", &tempb);
			myPic->pixels[r][c].blue = tempb;
	}
}
	return myPic;
}

void writePic(ppmPic *myPic , char *fileName) {
	FILE* aPic = NULL;
	int x = strlen(fileName);
	char newName[x+4];
	strncpy(newName,fileName,x - 4);
	strcat(newName,"-NEW.ppm");
	aPic = fopen(newName, "w");
	fprintf(aPic, "%s", "P3\n");
	fprintf(aPic, "%d    %d    %d\n", myPic->cols, myPic->rows, myPic->colors);
	for(int r = 0; r < myPic->rows; r++){
		for(int c = 0; c < myPic->cols ; c++){
			fprintf(aPic, "%d %d %d			", myPic->pixels[r][c].red, myPic->pixels[r][c].green, myPic->pixels[r][c].blue);
		}
		fprintf(aPic, "\n");
	}
	fclose(aPic);
}

ppmPic *rotateLeft(ppmPic *thePic) {
	ppmPic *newPic = malloc(sizeof(ppmPic));
	newPic->cols = thePic->rows;
	newPic->rows = thePic->cols;
	newPic->colors = thePic->colors;
	newPic->pixels = malloc(sizeof(Pixel *) * newPic->rows);  // dot notation
	for(int x = 0; x < newPic->rows; x++){
		newPic->pixels[x] = malloc(sizeof(Pixel) * newPic->cols);  // arrow notation
	}
	for(int r = 0; r < thePic->rows; r++){
		for(int c = 0; c < thePic->cols; c++){
			newPic->pixels[thePic->cols - 1 - c][r] = thePic->pixels[r][c];
		}
	}
	return newPic;
}

ppmPic *rotateRight(ppmPic *thePic) {
	ppmPic *newPic = malloc(sizeof(ppmPic));
	newPic->cols = thePic->rows;
	newPic->rows = thePic->cols;
	newPic->colors = thePic->colors;
	newPic->pixels = malloc(sizeof(Pixel *) * newPic->rows);  // dot notation
	for(int x = 0; x < newPic->rows; x++){
		newPic->pixels[x] = malloc(sizeof(Pixel) * newPic->cols);  // arrow notation
	}
	for(int r = 0; r < thePic->rows; r++){
		for(int c = 0; c < thePic->cols; c++){
			newPic->pixels[c][thePic->rows - 1 - r] = thePic->pixels[r][c];
		}
	}
	return newPic;
}

ppmPic *flipHorizontal(ppmPic *thePic) {
	ppmPic *newPic = malloc(sizeof(ppmPic));
	newPic->cols = thePic->cols;
	newPic->rows = thePic->rows;
	newPic->colors = thePic->colors;
	newPic->pixels = malloc(sizeof(Pixel *) * newPic->rows);  // dot notation
	for(int x = 0; x < newPic->rows; x++){
		newPic->pixels[x] = malloc(sizeof(Pixel) * newPic->cols);  // arrow notation
	}
	for(int r = 0; r < newPic->rows; r++){
		for(int c = 0; c < newPic->cols; c++){
			newPic->pixels[r][c] = thePic->pixels[r][newPic->cols - 1 - c];
		}
	}

	return newPic;
}

ppmPic *flipVertical(ppmPic *thePic) {
	ppmPic *newPic = malloc(sizeof(ppmPic));
	newPic->cols = thePic->cols;
	newPic->rows = thePic->rows;
	newPic->colors = thePic->colors;
	newPic->pixels = malloc(sizeof(Pixel *) * newPic->rows);  // dot notation
	for(int x = 0; x < newPic->rows; x++){
		newPic->pixels[x] = malloc(sizeof(Pixel) * newPic->cols);  // arrow notation
	}
	for(int r = 0; r < newPic->rows; r++){
		for(int c = 0; c < newPic->cols; c++){
			newPic->pixels[r][c] = thePic->pixels[newPic->rows - 1 - r][c];
		}
	}
	return newPic;
}

ppmPic *invert(ppmPic *thePic) {
	ppmPic *newPic = malloc(sizeof(ppmPic));
	newPic->cols = thePic->cols;
	newPic->rows = thePic->rows;
	newPic->colors = thePic->colors;
	newPic->pixels = malloc(sizeof(Pixel *) * newPic->rows);  // dot notation
	for(int x = 0; x < newPic->rows; x++){
		newPic->pixels[x] = malloc(sizeof(Pixel) * newPic->cols);  // arrow notation
	}
	for(int r = 0; r < newPic->rows; r++){
		for(int c = 0; c < newPic->cols; c++){
			newPic->pixels[r][c].red = thePic->colors - thePic->pixels[r][c].red;
			newPic->pixels[r][c].green = thePic->colors - thePic->pixels[r][c].green;
			newPic->pixels[r][c].blue = thePic->colors - thePic->pixels[r][c].blue;
		}
	}
	return newPic;
}

ppmPic *duplicate(ppmPic *thePic) {
	ppmPic *newPic = malloc(sizeof(ppmPic));
	newPic->cols = thePic->cols;
	newPic->rows = thePic->rows;
	newPic->colors = thePic->colors;
	newPic->pixels = malloc(sizeof(Pixel *) * newPic->rows);  // dot notation
	for(int x = 0; x < newPic->rows; x++){
		newPic->pixels[x] = malloc(sizeof(Pixel) * newPic->cols);  // arrow notation
	}
	for(int r = 0; r < newPic->rows; r++){
		for(int c = 0; c < newPic->cols; c++){
			newPic->pixels[r][c] = thePic->pixels[r][c];
		}
	}
	return newPic;
}
