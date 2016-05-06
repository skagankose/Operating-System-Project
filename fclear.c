#include <stdio.h>
#include <unistd.h>

int clearFile() {

	FILE *file;
	int ret;
	char fileName[1024];
	char textToAppend[4096];

	printf("Enter a file name: ");
	scanf("%s", fileName);

	if( access( fileName, F_OK ) == -1 ) {
		printf("Error: There is no such file.\n");
		return(-1);
	}

	file = fopen(fileName, "wb");

	if( file == NULL ) {
	   printf("Error:Permission Denied!\n");
	   return(-1);
	}

	fclose(file);
	return(0);
}
