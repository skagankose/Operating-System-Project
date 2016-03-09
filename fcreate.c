#include <stdio.h>

int main() {

	FILE *file;
	char fName[1024];
	char str[1024];

	printf("Enter a file name: ");
	scanf("%s", fName);

	file = fopen(fName, "r");

	if (file) {
		printf("Error: File already exist.\n");
	} else {
		file = fopen(fName, "wb");
		printf("File created successfully.\n");
	}

	fclose(file);
}
