#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dirent.h"
#include <direct.h>


int main(void) {
	char filedir[200];
	char filename[200];
	char allFile[20][200];
	int filecount = 0; //记录文件数目

	int i;
	for (i = 0; i < 20; i++)
		strcpy(allFile[i], "0");

	DIR* dp;
	struct dirent* dirp;
	_getcwd(filedir, 100);
	strcat(filedir, "\\Test");

	printf("Local File Path: %s\n", filedir);

	if ((dp = opendir(filedir)) == NULL) {
		printf("Cannot open %s", filedir);
		//不返回的话，程序会执行出错
		return -1;
	}
	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
		strcpy(filename, filedir);
		strcat(filename, "\\");
		strcat(filename, dirp->d_name);
		strcpy(allFile[filecount], filename);
		filecount++;
	}
	printf("%d", filecount);
	closedir(dp);


	return 0;
}