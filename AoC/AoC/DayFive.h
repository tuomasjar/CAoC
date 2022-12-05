#pragma once
typedef struct Stack{
	char list[100];
	int counter;
};

void SolveDay5Part1();
void SolveDay5Part2();
void Push(struct Stack *stack, char c);
char Pop(struct Stack *stack);
struct Stack InitStack(int index);

