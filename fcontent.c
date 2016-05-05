#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int display_lines(int, int, char[]);

int main() {

	FILE *file;
	int ret, lineNumber, stepSize, result;
	char fileName[8192], str[8192];
	int currentLine = 0;
	int lower, upper = 0;
	char ch;


	printf("Enter a file name to display: ");
	scanf("%s", fileName);

	if( access( fileName, F_OK ) == -1 ) {
		printf("Error: There is no such file.\n");
		return(-1);
	}

	printf("Specify number of lines to display per page: ");
	scanf("%d", &stepSize);

	if (stepSize < 1) {

		printf("%s", "Erro: Not a valid line number!\n" );
		return(-1);
	}

	printf("\n");


	while (1) {


		upper = upper + stepSize;
		result = display_lines(lower, upper, fileName);
		lower = lower + stepSize;

		if (result == -1) {
			break;
		}

		if (upper == stepSize) {getchar();}

		printf("\nPress enter to continue...\n");
		getchar();


	}

}

// This function display the lines from min to max for a given array
int display_lines(int min, int max, char name[8192]) {

	FILE *file;
	int lineNumber = 0;

	file = fopen(name, "r");

	if (file == NULL) {
	   printf("Error:Permission Denied!\n");
	   exit(EXIT_FAILURE);
	}

	char str[8192];

	while (fscanf(file, "%s", str)!=EOF) {

		if(strncmp(str, "\n", 8192)) {
			lineNumber++;
		}

		if (lineNumber>min && lineNumber<=max) {

			printf("%s\n", str);

		}

		if (lineNumber>max) {
			break;
		}

	}

	fclose(file);

	if (lineNumber == max+1) {
		return -2;
	} else {
		return -1;
	}

}
