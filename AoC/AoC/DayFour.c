#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void SolveDay4Part1() {
	long sum = 0;
	char srt[50];
	FILE* fp;
	int err = fopen_s(&fp, "D4Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		char parse1[50];
		char parse2[50];
		char parse3[50];
		char parse4[50];
		int first = 0;
		int second = 0;
		int third = 0;
		int fourth = 0;
		int count = 0;
		int parseCount = 0;
		while (srt[count] != '-') {
			parse1[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse1[parseCount] = '\n';
		first = atoi(parse1);
		parseCount = 0;
		count++;
		while (srt[count] != ',') {
			parse2[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse2[parseCount] = '\n';
		second = atoi(parse2);
		parseCount = 0;
		count++;
		while (srt[count] != '-') {
			parse3[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse3[parseCount] = '\n';
		third = atoi(parse3);
		parseCount = 0;
		count++;
		while (srt[count] != '\n' && srt[count] != EOF) {
			parse4[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse4[parseCount] = '\n';
		fourth = atoi(parse4);
		if (first >= third && second <= fourth) {
			sum++;
		}
		else if (first <= third && second >= fourth) {
			sum++;
		}
		first = 0;
		second = 0;
		third = 0;
		fourth = 0;
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}

void SolveDay4Part2() {
	long sum = 0;
	char srt[50];
	FILE* fp;
	int err = fopen_s(&fp, "D4Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		char parse1[50];
		char parse2[50];
		char parse3[50];
		char parse4[50];
		int first = 0;
		int second = 0;
		int third = 0;
		int fourth = 0;
		int count = 0;
		int parseCount = 0;
		while (srt[count] != '-') {
			parse1[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse1[parseCount] = '\n';
		first = atoi(parse1);
		parseCount = 0;
		count++;
		while (srt[count] != ',') {
			parse2[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse2[parseCount] = '\n';
		second = atoi(parse2);
		parseCount = 0;
		count++;
		while (srt[count] != '-') {
			parse3[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse3[parseCount] = '\n';
		third = atoi(parse3);
		parseCount = 0;
		count++;
		while (srt[count] != '\n' && srt[count] != EOF) {
			parse4[parseCount] = srt[count];
			count++;
			parseCount++;
		}
		parse4[parseCount] = '\n';
		fourth = atoi(parse4);
		if (first >= third && first <= fourth) {
			sum++;
		}
		else if (third >= first && third <= second) {
			sum++;
		}
		else if (second >= third && second <= fourth) {
			sum++;
		}
		else if (fourth >= first && fourth <= second) {
			sum++;
		}
		first = 0;
		second = 0;
		third = 0;
		fourth = 0;
	}
	fclose(fp);
	printf("Result is:");
	printf("%ld\n", sum);
}