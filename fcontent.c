#include <stdio.h>
#include <string.h>

int display_lines(int min, int max, char name[1024]) {

	FILE *file;
	file = fopen(name, "r");
	int lineNumber = 0;

	char str[1024];

	while (fscanf(file, "%s", str)!=EOF) {

		if(strncmp(str, "\n", 1024)) {
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
		// printf("%d", current);
		return -2;
	} else {
		return -1;
	}

}

int main() {

	FILE *file;
	int ret, lineNumber;
	char fileName[1024];
	char str[1024];
	int currentLine = 0;
	int lower, upper = 0;
	char ch;
	int stepSize, result;


	printf("Enter a file name to display: ");
	scanf("%s", fileName);
	//
	// print("Enter number of lines per page: ")
	// scanf("%s", lineNumber);

	printf("Specify number of lines to display per page: ");
	scanf("%d", &stepSize);

	// current = display_lines(currentLine, lower, upper, fileName);

	while (1) {

		upper = upper + stepSize;

		result = display_lines(lower, upper, fileName);

		lower = lower + stepSize;

		if (result == -1) {
			break;
		}

		if (upper == stepSize) {
			getchar();
		}
		printf("Press once or twice to smth to continue...");
		getchar();

	}

	// while (fscanf(file, "%s", str)!=EOF) {
	// 	printf("%s\n", str);
	// 	if(strncmp(str, "\n", 1024)) {
	// 		++currentLine;
	// 		// printf("yes\n");
	// 	}
	// 	if (currentLine == upper) {
	//
	// 		printf("Press enter to continue...\n");
	// 		mypause();
	// 	}
	// }


}
