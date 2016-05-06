#include <stdio.h>
#include <unistd.h>

int copyFile() {

    FILE *source, *target;
    char ch, sourceName[1024], targetName[1024];

    printf("Enter name of file to copy: ");
    scanf("%s",sourceName);

    if( access( sourceName, F_OK ) == -1 ) {
        printf("Error: There is no such file.\n");
        return(-1);
    }

    source = fopen(sourceName, "r");

    if( source == NULL ) {
        printf("Error:Permission Denied!\n");
        return(-1);
    }

   printf("Enter name of target: ");
   scanf("%s",targetName);

    if (access( targetName, F_OK ) != -1) {
        printf("Error: File already exist.\n");
        return(-1);
    }

    target = fopen(targetName, "wb");

    if( target == NULL ) {
      fclose(source);
      printf("Error:Permission Denied!\n");
      return(-1);
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }

   printf("File copied successfully.\n");

   fclose(source);
   fclose(target);

   return(0);
}
