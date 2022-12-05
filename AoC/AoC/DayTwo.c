#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SolveDay2Part1() {
	long sum = 0;
	char srt[50];

	FILE* fp;
	int err = fopen_s(&fp, "D2Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		if (srt[2] == 'X') {
			sum++;
			if (srt[0] == 'A') {
				sum += 3;
			}
			else if (srt[0] == 'B') {
			
			}
			else {
				sum += 6;
			}
		}
		else if (srt[2] == 'Y') {
			sum += 2;
			if (srt[0] == 'A') {
				sum += 6;
			}
			else if (srt[0] == 'B') {
				sum += 3;
			}
			else {
				
			}
		}
		else if (srt[2] == 'Z') {
			sum += 3;
			if (srt[0] == 'A') {
				
			}
			else if (srt[0] == 'B') {
				sum += 6;
			}
			else {
				sum += 3;
			}
		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}

void SolveDay2Part2() {
	long sum = 0;
	char srt[50];

	FILE* fp;
	int err = fopen_s(&fp, "D2Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		if (srt[2] == 'X') {
			if (srt[0] == 'A') {
				sum += 3;
			}
			else if (srt[0] == 'B') {
				sum += 1;
			}
			else {
				sum += 2;
			}
		}
		else if (srt[2] == 'Y') {
			sum += 3;
			if (srt[0] == 'A') {
				sum += 1;
			}
			else if (srt[0] == 'B') {
				sum += 2;
			}
			else {
				sum += 3;
			}
		}
		else if (srt[2] == 'Z') {
			sum += 6;
			if (srt[0] == 'A') {
				sum += 2;
			}
			else if (srt[0] == 'B') {
				sum += 3;
			}
			else {
				sum += 1;
			}
		}
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}