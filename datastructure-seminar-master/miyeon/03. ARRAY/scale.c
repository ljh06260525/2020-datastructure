#include <stdio.h>
#include <string.h>

int numC_major[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };
int inputC_major[8] = { 0 };
char comparison(int arr[]);

int main(void) {
	scanf("%d %d %d %d %d %d %d %d", &inputC_major[0], &inputC_major[1], &inputC_major[2], &inputC_major[3], &inputC_major[4], &inputC_major[5], &inputC_major[6], &inputC_major[7]);	
	comparison(inputC_major);
}

void comparison(int arr[]) {
	for (int j = 0; j < 8; j++) {
		if (strcmp(&arr[j], &arr[j + 1]) != 0)
			continue;
		else
			return 0;
	}

	for (int i = 0; i < 7; i++) {
		if (arr[0] == 1) {
			if (arr[i] < arr[i + 1]) {
				if (i + 1 == 7)
					printf("ascending\n");
				else
					continue;
			}
			else {
				printf("mixed\n");
				break;
			}
		}

		else if (arr[0] == 8) {
			if (arr[i] > arr[i + 1]) {
				if (i + 1 == 7)
					printf("descending\n");
				else
					continue;
			}
			else {
				printf("mixed\n");
				break;
			}
		}

		else {
			printf("mixed\n");
			return 0;
		}
	}
}