#include <stdio.h>
void Find(int (*)[5]);
int min(int a, int b, int c);
int main() {
	int arr[4][5] = { {1, 0, 1, 0, 0},
					  {1 ,0 ,1 ,1 ,1},
					  {1 ,1 ,1 ,1 ,1},
					  {1 ,0 ,0 ,1 ,0} };

	Find(arr);

	system("pause");


}
void Find(int (*arr)[5]) {
	int total[4][5];
	int i, j = 0;
	int max_i, max_j, max_to = 0;
	for (i = 0; i < 4; i++) {
		total[i][0] = arr[i][0];
	}
	for (i = 0; i < 5; i++) {
		total[0][i] = arr[0][i];
	}
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 5; j++) {
			if (arr[i][j] == 1) {
				total[i][j] = min(total[i][j - 1], total[i - 1][j], total[i - 1][j - 1]) + 1;

			}
			else
				total[i][j] = 0;
		}

	}


	max_to = total[0][0];
	//total배엳 최대수가 있는 인덱스 max_i, max_j 추출
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			if (max_to < total[i][j]) {
				max_to = total[i][j];
				max_i = i;
				max_j = j;
			}



		}
	}


	//해당 arr 출력,max_i부터 max_to만큼 뺀 수 까지 인덱스 설정
	//이유:정사각형 배열의 한변의 길이가 max_to여서
	printf("최대 정사각형 배열:\n");
	for (i = max_i; i > max_i - max_to; i--) {
		for (j = max_j; j > max_j - max_to; j--) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}


}
int min(int a, int b, int c)
{
	int m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return m;
}
