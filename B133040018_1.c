#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
typedef struct{
	char name[100];
	int **arr;
	int row_count;
	int col_count;
}Matrix;

void allocate_matrix(Matrix *input, int rowCount, int colCount){
	input->row_count = rowCount;
	input->col_count = colCount;
	input->arr = (int **)malloc(sizeof(int *) * rowCount);
	
	int i = 0;
	for (; i < rowCount; i++){
		input->arr[i] = (int *)malloc(sizeof(int) * colCount);
	}
	return;
}

void free_matrix(Matrix *input){
	int i = 0;
	for (; i < input->row_count; i++){
		free(input->arr[i]);
	}
	free(input->arr);
	return;
}

void fill_matrix(Matrix *input){
	int rowCount = input->row_count;
	int colCount = input->col_count;
	int i,j;
	for (i=0; i< rowCount;i++){
		for (j=0; j< colCount;j++){
			input->arr[i][j] = rand() % 2; 
		}
	}
	return;
}

void print_matrix(Matrix *input){
	printf("%s:\n", input->name);
	int rowCount = input->row_count;
	int colCount = input->col_count;
	int i,j;
	for (i=0; i< rowCount;i++){
		for (j=0; j< colCount;j++){
			printf("%d ", input->arr[i][j]);
		}
		printf("\n");
	}
	return;
}

void multiplication(Matrix *a, Matrix *b, Matrix *result){
	int i, j, k;
	for (i = 0; i< a->row_count; i++){ 
		for (j=0; j< b->col_count;j++){
			result->arr[i][j] = 0;
			for (k=0; k< a->col_count; k++){
				result->arr[i][j] += a->arr[i][k] * b->arr[k][j];
			}
		}
	}
}

int main(){

	srand(time(NULL));

	while (1){

		int a, b;
		printf("Enter the values of M and N (1 < N, M < 10): ");
		scanf("%d %d", &a, &b);
		
		if ((a ==0) && (b == 0)){
			printf("Finish!\n");
			return 0;
		}
		if ( !((1 < a) && (a < 10)) ){
			printf("Invalid Input: N and M must be between 2 and 9.\n");
			continue;
		} else if (!((1 < b) && (b < 10))){
			printf("Invalid Input: N and M must be between 2 and 9.\n");
			continue;
		}
		
		Matrix matrix1;
		sprintf(matrix1.name, "%s", "Matrix 1");
		allocate_matrix(&matrix1, a, b);
		fill_matrix(&matrix1);
		print_matrix(&matrix1);
		
		Matrix matrix2;
		sprintf(matrix2.name, "%s", "Matrix 2");
		allocate_matrix(&matrix2, b, a);
		fill_matrix(&matrix2);
		print_matrix(&matrix2);
		
		Matrix matrix3;
		sprintf(matrix3.name, "%s", "Resultig Matrix");
		allocate_matrix(&matrix3, a, a);
		multiplication(&matrix1, &matrix2, &matrix3);
		print_matrix(&matrix3);

		free_matrix(&matrix1);
		free_matrix(&matrix2);
		free_matrix(&matrix3);
	}
	return 0;

}
