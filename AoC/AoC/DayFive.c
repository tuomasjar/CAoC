#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "DayFive.h"


/*
[S]                 [T] [Q]
[L]             [B] [M] [P]     [T]
[F]     [S]     [Z] [N] [S]     [R]
[Z] [R] [N]     [R] [D] [F]     [V]
[D] [Z] [H] [J] [W] [G] [W]     [G]
[B] [M] [C] [F] [H] [Z] [N] [R] [L]
[R] [B] [L] [C] [G] [J] [L] [Z] [C]
[H] [T] [Z] [S] [P] [V] [G] [M] [M]
 1   2   3   4   5   6   7   8   9 */



void SolveDay5Part1() {
	struct Stack stack_arr[10];
	for (int i = 1; i < 10; i++) {
		stack_arr[i] = InitStack(i);
	}
	char result[10];
	char srt[50];
	FILE* fp;
	int err = fopen_s(&fp, "D5Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		char rep[5];
		int repeats = 0;
		int source = 0;
		int destination = 0;
		int counter = 5;
		int parseCounter = 0;
		while (srt[counter] != ' ') {
			rep[parseCounter] = srt[counter];
			counter++;
			parseCounter++;
		}
		rep[parseCounter] = '\n';
		repeats = atoi(rep);
		parseCounter = 0;
		counter += 6;
		char c = srt[counter];
		source = c-'0';
		counter += 5;
		char d = srt[counter];
		destination = d-'0';
		for (int i = 0; i < repeats; i++) {
			Push(&stack_arr[destination], Pop(&stack_arr[source]));
		}
	}
	fclose(fp);
	for (int i = 0; i < 9; i++) {
		result[i] = Pop(&stack_arr[i+1]);
	}
	result[9] = '\0';
	printf("Result is:");
	printf(result);
	printf("\n");
}

void SolveDay5Part2() {
	struct Stack stack_arr[10];
	struct Stack tempStack;
	for (int i = 1; i < 10; i++) {
		stack_arr[i] = InitStack(i);
	}
	char result[10];
	char srt[50];
	FILE* fp;
	int err = fopen_s(&fp, "D5Input.txt", "r");
	if (err != 0) {
		printf("Error opening file");
		return 0;
	}
	while (fgets(srt, 50, fp)) {
		char rep[5];
		int repeats = 0;
		int source = 0;
		int destination = 0;
		int counter = 5;
		int parseCounter = 0;
		while (srt[counter] != ' ') {
			rep[parseCounter] = srt[counter];
			counter++;
			parseCounter++;
		}
		rep[parseCounter] = '\n';
		repeats = atoi(rep);
		parseCounter = 0;
		counter += 6;
		char c = srt[counter];
		source = c - '0';
		counter += 5;
		char d = srt[counter];
		destination = d - '0';
		tempStack.counter = 0;
		for (int i = 0; i < repeats; i++) {
			Push(&tempStack, Pop(&stack_arr[source]));
		}
		for (int i = 0; i < repeats; i++) {
			Push(&stack_arr[destination], Pop(&tempStack));
		}
	}
	fclose(fp);
	for (int i = 0; i < 9; i++) {
		result[i] = Pop(&stack_arr[i + 1]);
	}
	result[9] = '\0';
	printf("Result is:");
	printf(result);
	printf("\n");
}


void Push(struct Stack* stack, char c) {
	stack->list[stack->counter] = c;
	stack->counter++;
}

char Pop(struct Stack* stack) {
	char retval = stack->list[stack->counter - 1];
	stack->counter--;
	return retval;
}

struct Stack InitStack(int index) {
	struct Stack retval;
	retval.counter = 0;
	switch (index) {
	case 1:
		Push(&retval, 'H');
		Push(&retval, 'R');
		Push(&retval, 'B');
		Push(&retval, 'D');
		Push(&retval, 'Z');
		Push(&retval, 'F');
		Push(&retval, 'L');
		Push(&retval, 'S');
		break;
	case 2:
		Push(&retval, 'T');
		Push(&retval, 'B');
		Push(&retval, 'M');
		Push(&retval, 'Z');
		Push(&retval, 'R');
		break;
	case 3:
		Push(&retval, 'Z');
		Push(&retval, 'L');
		Push(&retval, 'C');
		Push(&retval, 'H');
		Push(&retval, 'N');
		Push(&retval, 'S');
		break;
	case 4:
		Push(&retval, 'S');
		Push(&retval, 'C');
		Push(&retval, 'F');
		Push(&retval, 'J');
		break;
	case 5:
		Push(&retval, 'P');
		Push(&retval, 'G');
		Push(&retval, 'H');
		Push(&retval, 'W');
		Push(&retval, 'R');
		Push(&retval, 'Z');
		Push(&retval, 'B');
		break;
	case 6:
		Push(&retval, 'V');
		Push(&retval, 'J');
		Push(&retval, 'Z');
		Push(&retval, 'G');
		Push(&retval, 'D');
		Push(&retval, 'N');
		Push(&retval, 'M');
		Push(&retval, 'T');
		break;
	case 7:
		Push(&retval, 'G');
		Push(&retval, 'L');
		Push(&retval, 'N');
		Push(&retval, 'W');
		Push(&retval, 'F');
		Push(&retval, 'S');
		Push(&retval, 'P');
		Push(&retval, 'Q');
		break;
	case 8:
		Push(&retval, 'M');
		Push(&retval, 'Z');
		Push(&retval, 'R');
		break;
	case 9:
		Push(&retval, 'M');
		Push(&retval, 'C');
		Push(&retval, 'L');
		Push(&retval, 'G');
		Push(&retval, 'V');
		Push(&retval, 'R');
		Push(&retval, 'T');
		break;
	default:
		return retval;
	}
	return retval;
}