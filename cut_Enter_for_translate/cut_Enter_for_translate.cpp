#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCE_LENGTH 256

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stdout, "Usage: %s input.txt\n", argv[0]);
		exit(1);
	}

	FILE* fpi, * fpo;
	char tmp[SENTENCE_LENGTH];
	char filename[256];

	if ((fopen_s(&fpi, argv[1], "r")) != 0) {
		fprintf(stderr, "error: can't open input file %s\n", argv[1]);
		exit(1);
	}

	strncpy_s(filename, sizeof(filename), argv[1], (strlen(argv[1]) - 4));
	strcat_s(filename, "_NoEtr.txt");

	if ((fopen_s(&fpo, filename, "w")) != 0) {
		fprintf(stderr, "error: can't open output file %s\n", argv[1]);
		exit(1);
	}

	while (fscanf_s(fpi, "%s", tmp) != EOF) {
		fprintf(fpo, "%s ", tmp);
	}

	fclose(fpi);
	fclose(fpo);
	return 0;
}