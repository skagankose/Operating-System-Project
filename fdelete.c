#include <stdio.h>
#include <unistd.h>

int deleteFile() {

    FILE *file;
    int ret;
    char fName[1024];

    printf("Enter a file name: ");
    scanf("%s", fName);

    if (access(fName, F_OK ) == -1) {
        printf("Error: There is no such file.\n");
        return(-1);
   	}

    ret = remove(fName);

    if (ret == 0) {
        printf("Success.\n");
    } else {
        printf("Error: Permission Denied!\n");
    }

    return(0);


}
