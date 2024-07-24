#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX_RANDOM 100

// Hàm tạo và xuất ma trận a chứa các phần tử ngẫu nhiên
void Matran(int **a, int m, int n) {
	srand(time_t(NULL));
	printf("Cau 1: Ma tran ngau nhien:\n");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = rand() % (MAX_RANDOM + 1);
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


// Hàm xuất các phần tử cực đại
void sortRows(int **a, int m, int n) {
	printf("\n Cau 9: Ma tran duoc sap xep (Moi hang duoc sap xep) :\n");
	for (int i = 0; i < m; ++i) {
		// Sắp xếp các phần tử của dòng thứ i
		for (int j = 0; j < n - 1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (a[i][j] > a[i][k]) {
					// Hoán đổi các phần tử để sắp xếp tăng dần
					int temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
			}
		}
		// Xuất dòng đã sắp xếp
		for (int j = 0; j < n; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int m, n;
	printf("Hay nhap so Hang (m): ");
	scanf_s("%d", &m);
	printf("Hay nhap so Cot (n): ");
	scanf_s("%d", &n);

	// Cấp phát bộ nhớ cho ma trận 2 chiều a
	int **a = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; ++i) {
		a[i] = (int *)malloc(n * sizeof(int));
	}

	// 1. Tạo và xuất ma trận a chứa các phần tử ngẫu nhiên
	Matran(a, m, n);


	// 7. Sắp xếp mảng a tăng theo từng dòng
	sortRows(a, m, n);

	_getch();
}