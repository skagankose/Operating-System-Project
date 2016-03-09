#include <stdio.h>

int main () {

   int ret;
   // FILE *fp;
   char fName[1024];

	printf("Enter a file name: ");
	scanf("%s", fName);

   // fp = fopen(fName, "w");
	//
   // fprintf(fp, "%s", "This is tutorialspoint.com");
   // fclose(fp);

   ret = remove(fName);

   if(ret == 0) {
      printf("File deleted successfully.\n");
   } else {
      printf("Error: unable to delete the file.\n");
   }

   return(0);
}
