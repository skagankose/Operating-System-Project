#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void copy_string(char[], char[]);
void insert_substring(char*, char*, int);
char* substring(char*, int, int);

int main()
{
    char text[8192], inputString[8192], fileName[8192], textVariable[8192];
    char ch;
    int position;
    int pos = 0;
    FILE *fp, *out;

    printf("Enter the file name to append: ");
    scanf("%s",fileName);

    if( access( fileName, F_OK ) == -1 ) {
        printf("Error: There is no such file.\n");
        return(-1);
    }

    fp = fopen(fileName,"r");

    if( fp == NULL ) {
       printf("Error:Permission Denied!\n");
       return(-1);
    }

    while (( ch = fgetc(fp)) != EOF) {
        textVariable[pos] = ch;
        pos++;
    }

    fclose(fp);

    copy_string(text, textVariable);

    printf("Enter the string to insert: ");
    scanf("%s",inputString);

    printf("Enter the position to insert: ");
    // scanf("%d", &position);

    char term;
    if(scanf("%d%c", &position, &term) != 2 || term != '\n') {
        printf("Error: Not a valid position!\n");
        return(-1);
    } else {
        if (position < 0) {
            printf("Error: Not a valid position!\n");
            return(-1);
        }
    }

    insert_substring(text, inputString, position);

    out = fopen(fileName, "w");
    fprintf(out, "%s", text);
    fclose(out);

    return(0);
}

// This function instert substring into positon on given text
void insert_substring(char *main, char *addition, int position) {
    char *tmpFirst, *tmpSecond;
    int length;

    length = strlen(main);

    if (position > length) {
      printf("%s\n", "Error: Position cxceeds the Length of the file.");
      exit(EXIT_FAILURE);
    }

    // Extract the substring until position
    tmpFirst = substring(main, 1, position - 1 );

    // Extract the substring from position to the end
    tmpSecond = substring(main, position, length-position+1);

    strcpy(main, "");
    strcat(main, tmpFirst);
    strcat(main, addition);
    strcat(main, tmpSecond);
    free(tmpFirst);
    free(tmpSecond);
}


// This function extract the given length substring from position
char *substring(char *string, int position, int length) {
    char *pointer;
    int n;

    pointer = malloc(length+1);

    if( pointer == NULL ) {
        printf("%s\n", "Malloc() function failed.");
        exit(EXIT_FAILURE);
    }

    for ( n = 0 ; n < length ; n++ ) {
      *(pointer+n) = *((string+position-1)+n);
     }

    *(pointer+n) = '\0';

    return pointer;
}

// This function copy one string to another
void copy_string(char d[], char s[]) {
    int m = 0;

    while (s[m] != '\0') {
      d[m] = s[m];
      m++;
    }

    d[m] = '\0';
}
