#include <stdio.h>
//Shrirang Bodkhe - 25070521090


int main() {
	int r1, c1;
	

	if (scanf("%d %d", &r1, &c1) != 2) return 0;
	

	int matrix_a[r1][c1];
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			scanf("%d", &matrix_a[i][j]);
		}
	}
	
	int r2, c2;

	if (scanf("%d %d", &r2, &c2) != 2) return 0;
	

	if (c1 != r2) {
		printf("Invalid input\n");
		return 0; 
	}
	

	int matrix_b[r2][c2];
	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
		scanf("%d", &matrix_b[i][j]);
		}
	}
	

	int result[r1][c2];
	 for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
		result[i][j] = 0;
		}
	}

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
for (int k = 0; k < c1; k++) {
				result[i][j] += matrix_a[i][k] * matrix_b[k][j];
			}
		}
}
	

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
