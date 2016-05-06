#include <stdio.h>
#include <unistd.h>

int rnameFile() {

	FILE *file;
	int ret;
	char oldName[1024], newName[1024], mixName[8192];

	printf("Enter a existing file name: ");
	scanf("%s",oldName);

	if (access( oldName, F_OK ) == -1) {
		printf("Error: There is no such file.\n");
		return(-1);
	}

	printf("Enter a new name along with the path: ");
	scanf("%s",newName);

	if (access( newName, F_OK ) != -1) {
		printf("Error: File name already exist.\n");
		return(-1);
	}

	ret = rename(oldName, newName);

	if (ret == 0) {
		printf("Success.\n");
   } else {
      printf("Error: Permission Denied!\n");
	  return(-1);
   }

   return(0);
}
