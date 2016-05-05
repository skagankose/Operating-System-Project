#include <stdio.h>
#include <unistd.h>

int main() {

	FILE *file;
	int ret;
	char oldName[1024], newName[1024];

	printf("Enter a existing file name: ");
	scanf("%s",oldName);

	if (access( oldName, F_OK ) == -1) {
		printf("Error: There is no such file.\n");
		return(-1);
	}

	printf("Enter a new name: ");
	scanf("%s",newName);

	file = fopen(newName, "r");

	if (access( oldName, F_OK ) != -1) {
		printf("Error: File name already exist.\n");
	}

	ret = rename(oldName, newName);

	if (ret == 0) {
      printf("File renamed successfully.\n");
   } else {
      printf("Error: Permission Denied!\n");
   }

   return(0);
}
