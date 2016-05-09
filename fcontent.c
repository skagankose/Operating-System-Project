#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int displayLines(FILE *file, int minLine, int maxLine);
int getLineNumber(FILE *file);

int contentFile() {

	FILE *file;
	FILE *test;
	int ret, lineNumber, stepSize, result;
	char fileName[8192], str[8192];
	int currentLine = 0;
	char ch;

	printf("Enter a file name to display: ");
	scanf("%s", fileName);

	if( access( fileName, F_OK ) == -1 ) {
		printf("Error: There is no such file.\n");
		return(-1);
	}

	test = fopen(fileName, "r");

	if (test == NULL) {
	   printf("Error:Permission Denied!\n");
	   return(-1);
	}

	fclose(test);

	printf("Specify number of lines to display per page: ");


	char term;
	if(scanf("%d%c", &stepSize, &term) != 2 || term != '\n') {
		printf("Error: Not a valid line number!\n");
		return(-1);
	} else {
		if (stepSize < 1) {
			printf("Error: Not a valid line number!\n");
			return(-1);
		}
	}

	// int l = getLineNumber(test);
	int lower = 0;
	int upper = 0;

	char line[256];
	int totalLines;

	test = fopen(fileName, "r");

	while (fgets(line, sizeof(line), test)) {
		/* note that fgets don't strip the terminating \n, checking its
		   presence would allow to handle lines longer that sizeof(line) */

		totalLines++;

	}

	fclose(test);

	while (1) {

		if (upper < totalLines-1) {


			upper = upper + stepSize;

			char line[256];
			int lineNumber = 1;

			test = fopen(fileName, "r");

			while (fgets(line, sizeof(line), test)) {
				/* note that fgets don't strip the terminating \n, checking its
				   presence would allow to handle lines longer that sizeof(line) */

				if (lineNumber >= lower && lineNumber <= upper) {
					printf("%s", line);
				}

				lineNumber++;


			}

			fclose(test);

			lower = upper + 1;

		} else {
			break;
		}

		int c;
		do {
		    c = getchar();
		}while(c != '\n' && c != EOF);
		if (c == EOF) {
		    // input stream ended, do something about it, exit perhaps
		} else {
		    printf("Type Enter to continue\n");
		    getchar();
		}


	}

	printf("\nSuccess.\n");

	return(0);


}
