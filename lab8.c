#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int, int);
void initMatrix(int **, int, int);
int findRange(int **, int, int);
double findAverage(int **, int, int);
void printCorners(int **, int, int);

int main(int argc, char *argv[]) {
	int **data;
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);

	data = allocateMatrix(row, col);
	initMatrix(data, row, col);
	printf("The range of values is %d\n", findRange(data, row, col) );
	printf("The average of all values is %lf\n", findAverage(data, row, col) );
	printCorners(data, row, col);

	return 0;
}

int **allocateMatrix(int r, int c) {
	int** matrix = NULL;
	matrix = (int**)malloc(r*sizeof(int*));
	for (int j = 0; j < r; j++){
		matrix[j] = (int*)malloc(c*sizeof(int));
	}
	return matrix;
}

void initMatrix(int **array, int r, int c) {
	srand(0);
	for (int j = 0; j < r; j++){
    for (int q = 0; q < c; q++){
			array[j][q] = rand() % 1000;
		}
	}
}

int findRange(int **array, int r, int c) {
	int high = 0;
	int low = 0;
	int range;
	for (int j = 0; j < r; j++){
    for (int q = 0; q < c; q++){
			if (array[j][q] > high){
				high = array[j][q];
			}
			if (array[j][q] < low){
				low = array[j][q];
			}
		}
	}
	range = high - low;
	return range;
}


double findAverage(int **array, int r, int c) {
	double compval = 0;
	int elements = 0;
	double average = 0;
	for (int j = 0; j < r; j++){
    for (int q = 0; q < c; q++){
			compval = compval + array[j][q];
			elements++;
		}
	}
	average = compval / (double)elements;
	return average;
}

void printCorners(int **array, int r, int c) {
	if ( r == 0 && c == 0 ){
		printf("%d", array[0][0]);
	}
	printf("%d %d\n%d %d",array[0][0], array[0][c-1], array[r-1][0], array[r-1][c-1]);
}
