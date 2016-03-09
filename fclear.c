#include <stdio.h>

int main() {

	FILE *file;
	int ret;
	char fileName[1024];

	printf("Enter a file name: ");
	scanf("%s", fileName);

	ret = remove(fileName);

	file = fopen(fileName, "wb");

	fclose(file);
}
