#include <stdio.h>

#define MAX_SZ 256

int main() {

	FILE *out;
	char textToAppend[4096];
	char fileName[1024];

	printf("Enter text to append: ");
	fgets (textToAppend, MAX_SZ, stdin);

	printf("Enter a existing file name: ");
	scanf("%s",fileName);

	out = fopen(fileName, "a");
	fprintf(out, "%s", textToAppend);
	fclose(out);
	return 0;

}
