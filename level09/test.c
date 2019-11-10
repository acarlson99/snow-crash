#include <stdio.h>

int main(int argc, char **argv) {
	for (int i=0;argv[1][i] && argv[1][i] != '\n';i++) 
		argv[1][i] -= i;
	puts(argv[1]);
}
