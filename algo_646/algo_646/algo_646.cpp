#include <stdio.h>
#include <stdlib.h>
struct pair
{
	int a;
	int b;

};

int findLongestChain(struct pair arr[], int n) {
	int i, j, max = 0;
	int*mcl = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {//초기화
		mcl[i] = 1;
	}
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1) {
				mcl[i] = mcl[j] + 1;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (max < mcl[i]) {
			max = mcl[i];
		}
	}
	free(mcl);
	//printf("%d", &mcl);
	return max;
}
int main() {
	int i = 0;
	
	struct pair arr[] = { {1,2},{15,25},{27,40},{50,60} };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	
	
	printf("chain의 최대 길이는 %d\n입니다.", findLongestChain(arr, n));
	system("pause");
	return 0;
}