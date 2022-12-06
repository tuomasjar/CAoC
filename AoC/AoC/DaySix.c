#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SolveDay6Part1() {
	long sum = 0;
	long max = 0;
	int inputNum = 0;
	char srt[4096];
	char map[4];
	FILE* fp;
	int found = 1;
	int err = fopen_s(&fp, "D6Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 4096, fp)) {
		for (int i = 3; i < 4096; i++) {
			found = 1;
			for (int j = 3; j >= 0; j--) {
				for (int k = 3; k >= 0; k--) {
					if (k == j) continue;
					if (srt[i - j] == srt[i - k]) {
						found = 0;
						break;
					}
				}
				if (found == 0) {
					break;
				}
			}
			if (found == 1) {
				sum = i + 1;
				break;
			}
			
		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}

void SolveDay6Part2() {
	long sum = 0;
	long max = 0;
	int inputNum = 0;
	char srt[4096];
	char map[4];
	FILE* fp;
	int found = 1;
	int err = fopen_s(&fp, "D6Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 4096, fp)) {
		for (int i = 13; i < 4096; i++) {
			found = 1;
			for (int j = 13; j >= 0; j--) {
				for (int k = 13; k >= 0; k--) {
					if (k == j) continue;
					if (srt[i - j] == srt[i - k]) {
						found = 0;
						break;
					}
				}
				if (found == 0) {
					break;
				}
			}
			if (found == 1) {
				sum = i + 1;
				break;
			}

		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}