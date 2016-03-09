#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copy_string(char [], char []);
void insert_substring(char*, char*, int);
char* substring(char*, int, int);

int main()
{
   char text[1024], substring[1024];
   int position;
	char ch, file_name[25];
	FILE *fp;
	int pos = 0;
	char textVariable[1024];
	FILE *out;

	printf("Enter the name of file you wish to append: ");
	scanf("%s",file_name);

	fp = fopen(file_name,"r");

	if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

	// printf("The contents of %s file are :\n", file_name);

   while( ( ch = fgetc(fp) ) != EOF ) {
      // printf("%c",ch);
		textVariable[pos] = ch;
		pos++;
	}
   fclose(fp);

	printf("textVar is %s", textVariable);

	copy_string(text, textVariable);

   printf("Enter the string to insert: ");
	scanf("%s",substring);

   printf("Enter the position to insert: ");
   scanf("%d", &position);

   insert_substring(text, substring, position);

   printf("%s\n",text);

	out = fopen(file_name, "w");
	fprintf(out, "%s", text);
	fclose(out);

   return 0;
}

void insert_substring(char *a, char *b, int position)
{
   char *f, *e;
   int length;

   length = strlen(a);

   f = substring(a, 1, position - 1 );
   e = substring(a, position, length-position+1);

   strcpy(a, "");
   strcat(a, f);
   free(f);
   strcat(a, b);
   strcat(a, e);
   free(e);
}

char *substring(char *string, int position, int length)
{
   char *pointer;
   int c;

   pointer = malloc(length+1);

   if( pointer == NULL )
       exit(EXIT_FAILURE);

   for( c = 0 ; c < length ; c++ )
      *(pointer+c) = *((string+position-1)+c);

   *(pointer+c) = '\0';

   return pointer;
}

void copy_string(char d[], char s[]) {
   int c = 0;

   while (s[c] != '\0') {
      d[c] = s[c];
      c++;
   }
   d[c] = '\0';
}
