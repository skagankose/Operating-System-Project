#include <stdio.h>

int main() {

	FILE *file;
	int ret;
	char oldName[1024];
	char newName[1024];

	printf("Enter a existing file name: ");
	scanf("%s",oldName);
	printf("Enter a new name: ");
	scanf("%s",newName);

	ret = rename(oldName, newName);

	if(ret == 0) {
      printf("File renamed successfully.\n");
   } else {
      printf("Error: unable to rename the file.\n");
   }

   return(0);
}
