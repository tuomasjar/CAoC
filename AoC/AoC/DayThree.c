#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SolveDay3Part1() {
	long sum = 0;
	char srt[50];

	FILE* fp;
	int err = fopen_s(&fp, "D3Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		char c='a';
		int count = 0;
		while (c != EOF && c != '\n') {
			count++;
			c = srt[count];
		}
		int found = 0;
		int midPoint = count / 2;
		for (int i = 0; i < midPoint; i++) {
			for (int j = midPoint; j < count; j++) {
				if (srt[i] == srt[j]) {
					if (srt[i] < 'a') {
						int temp = 27 + (srt[i] - 'A');
						sum += temp;
					}
					else {
						int temp = 1 + (srt[i] - 'a');
						sum += temp;
					}
					found = 1;
					break;
				}
			}
			if (found == 1) {
				found = 0;
				break;
			}
		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}

void SolveDay3Part2() {
	long sum = 0;
	char srt1[50];
	char srt2[50];
	char srt3[50];

	FILE* fp;
	int err = fopen_s(&fp, "D3Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt1, 50, fp)) {
		fgets(srt2, 50, fp);
		fgets(srt3, 50, fp);
		char c = 'a';
		int count = 0;
		int count2 = 0;
		int count3 = 0;
		while (c != EOF && c != '\n') {
			count++;
			c = srt1[count];
		}
		c = 'a';
		while (c != EOF && c != '\n') {
			count2++;
			c = srt2[count2];
		}
		c = 'a';
		while (c != EOF && c != '\n') {
			count3++;
			c = srt3[count3];
		}
		
		int found = 0;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count2; j++) {
				for (int k = 0; k < count3; k++) {
					if (srt1[i] == srt2[j] && srt1[i] == srt3[k]) {
						if (srt1[i] < 'a') {
							int temp = 27 + (srt1[i] - 'A');
							sum += temp;
						}
						else {
							int temp = 1 + (srt1[i] - 'a');
							sum += temp;
						}
						found = 1;
						break;
					}
				}
				if (found == 1)break;
			}
			if (found == 1) {
				found = 0;
				break;
			}
		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}