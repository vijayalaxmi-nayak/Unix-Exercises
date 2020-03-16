#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>

int file_type(char dname[])
{
	//returns 1 if file, returns 2 if directory, returns 3 if not found
	
	DIR *dir;
	dir = opendir(dname);
	
	if(dir == NULL)
	{
		if(errno == ENOTDIR)
			return 1;
		else
			return 3;
	}
	closedir(dir);
	return 2;
}

int main()
{
	DIR *dir;
	char name[100];
	struct dirent *d;
	printf("Enter the file or directory name : ");
	gets(name);
	
	dir = opendir(name);
	
	int tmp = file_type(name);

	if(tmp == 1)
	{	
		printf("%s\n",name);
	}

	else if(tmp == 2)
	{
		while(d = readdir(dir))
		{
			if((strcmp(d->d_name,".") == 0) || (strcmp(d->d_name,"..") == 0))
				continue;
			
			printf("%s\n",d->d_name);
		}
	}
	else
		printf("Invalid file or directory name!\n");
	return 0;
}
