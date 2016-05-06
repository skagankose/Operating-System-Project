
#include "fclear.c"
#include "fcontent.c"
#include "fcopy.c"
#include "fcreate.c"
#include "fdelete.c"
#include "fmove.c"
#include "rname.c"
#include "tappend.c"
#include "tinsert.c"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void help();

int main() {
	char command[1024];

	printf("------------------\n<<<  Commands >>>\nclf\ncontf\ncof\ncrf\ndef\nmof\nrname\ntappend\ntinsert\nexit()\n");
	printf("\n* Be careful, the program is case sensitive.\n** To get information about how command works, add \\h next to the command (command\\h). \nFor example: clf\\h\n------------------\n\nEnter a command:\n");
	scanf("%s", command);
	while(strcmp("exit()",command)!=0)
	{

		if (strcmp("clf",command)==0)
		{
			clearFile();
		}
		else if (strcmp("contf",command)==0)
		{
			contentFile();
		}
		else if (strcmp("cof",command)==0)
		{
			copyFile();
		}
		else if (strcmp("crf",command)==0)
		{
			createFile();
		}
		else if (strcmp("def",command)==0)
		{
			deleteFile();
		}
		else if (strcmp("mof",command)==0)
		{
			moveFile();
		}
		else if (strcmp("rname",command)==0)
		{
			rnameFile();
		}
		else if (strcmp("tappend",command)==0)
		{
			tappendFile();
		}
		else if (strcmp("tinsert",command)==0)
		{
			tinsertFile();
		}
		else if(strcmp(command,"clf\\h")==0){
			printf("\n> This function removes all text in a file.\nWhen function asks, You should just enter the file path. \n\n");
		}

		else if(strcmp(command,"contf\\h")==0){
			printf("\n> This function shows the content of a text file, with the ability to pause per page. The number of lines per page can be specified by the user.\nWhen function asks, You should enter the file path and enter a number to specify number of lines per page.\n\n");
		}

		else if(strcmp(command,"cof\\h")==0){
			printf("\n> This function copies the given file to specific path.\nWhen function asks, You should enter the file path and a path you want to copy file in.\n\n");
		}

		else if(strcmp(command,"crf\\h")==0){
			printf("\n> This function creates a file in given path.\nWhen function asks, You should just enter the file path and it will create the file if there is no\nfile with same filename.\n\n");
		}

		else if(strcmp(command,"def\\h")==0){
			printf("\n> This function deletes the given file.\nWhen function asks, You should just enter the file path and it will delete the file if file exists.\n\n");
		}

		else if(strcmp(command,"mof\\h")==0){
			printf("\n> This function moves the given file to specific pat.\nWhen function asks, You should enter the file path and a path you want to move file in.\n\n");
		}

		else if(strcmp(command,"rname\\h")==0){
			printf("\n> This function change name of the given file.\nWhen function asks, You should just enter the file path and it will change the file name if there is no file with same filename.\n\n");
		}

		else if(strcmp(command,"tappend\\h")==0){
			printf("\n> This function appends given text to the end of the given file.\nWhen function asks, You should enter a text and file path.\n\n");
		}

		else if(strcmp(command,"tinsert\\h")==0){
			printf("\n> This function inserts given text in a specific position (counted in characters) of the file.\nWhen function asks, You should enter file path, text and the position you want to insert text in.\n\n");
		}
		else{
			printf("\n!!! Command is not valid. Please enter a from the menu. !!!\n\n");
		}
		scanf("%s", command);

	}
}

