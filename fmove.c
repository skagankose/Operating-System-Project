#include <stdio.h>

int main() {
   char ch, sourceName[1024], targetName[1024];
   FILE *source, *target;

   printf("Enter name of file to move: ");
	scanf("%s",sourceName);

   source = fopen(sourceName, "r");

   if( source == NULL ) {
      printf("Error: unable to move...\n");
      return(-1);
   }

   printf("Enter name of target: ");
   scanf("%s",targetName);

   target = fopen(targetName, "w");

   if( target == NULL )
   {
      fclose(source);
      printf("Error: unable to move...\n");
      return(-1);
   }

   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, target);

   printf("File moved successfully.\n");

   fclose(source);
   fclose(target);

	remove(sourceName);

   return 0;
}
