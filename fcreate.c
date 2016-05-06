#include <stdio.h>
#include <unistd.h>

int main() {

	FILE *file;
	char fName[1024], str[1024];

	printf("Enter a file name: ");
	scanf("%s", fName);

	if (access(fName, F_OK ) != -1) {
		printf("Error: File already exist.\n");
		return(-1);
	}

	file = fopen(fName, "wb");

	if (file) {
		printf("File created successfully.\n");
	} else {
		printf("Error: Permission Denied!\n");
	}
	fclose(file);

	return(0);
}
