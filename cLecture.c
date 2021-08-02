#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hello() {
	printf("hello");
}

void bonjour() {
	printf("bonjour");
}

int main() {

	void (*fp)();
	fp = hello;

	fp();

	fp = bonjour;

	fp();

  return 0;
}
