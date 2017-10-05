#include <stdio.h>
int add (int num1, int num2) {
	return num1 + num2;
}

int add (int num1) {
	return num1 + 2;
}

void main () {
	printf("%d\n", add(10, 2));
	printf("%d\n", add(10));
}