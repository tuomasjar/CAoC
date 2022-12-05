#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SolveDay1part1() {
	long sum = 0;
	long max = 0;
	int inputNum = 0;
	char srt[50];

	FILE* fp;
	int err = fopen_s(&fp, "D1Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		inputNum = atoi(srt);
		if (inputNum!= 0) {
			sum += inputNum;
		}
		else {
			if (max < sum)max = sum;
			sum = 0;
		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n",max);
}

void SolveDay1part2() {
	long sum = 0;
	long result = 0;
	long max1 = 0;
	long max2 = 0;
	long max3 = 0;
	int inputNum = 0;
	char srt[50];

	FILE* fp;
	int err = fopen_s(&fp, "D1Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		inputNum = atoi(srt);
		if (inputNum != 0) {
			sum += inputNum;
		}
		else {
			if (max1 < sum) {
				max2 = max3;
				max2 = max1;
				max1 = sum;
			}
			else if (max2 < sum) {
				max3 = max2;
				max2 = sum;
			}
			else if (max3 < sum) {
				max3 = sum;
			}
			sum = 0;
		}
	}
	if (max1 < sum) {
		max2 = max3;
		max2 = max1;
		max1 = sum;
	}
	else if (max2 < sum) {
		max3 = max2;
		max2 = sum;
	}
	else if (max3 < sum) {
		max3 = sum;
	}
	sum = 0;
	result = max1 + max2 + max3;
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", result);
}