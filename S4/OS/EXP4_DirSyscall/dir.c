#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

void main(){
	DIR *dir;
	struct dirent *ptr;
	char dirname[100];
	printf("\nEnter the directory:");
	scanf("%s",dirname);
	dir=opendir(dirname);
	printf("Inod\tDirectory name\n");
	while((ptr=readdir(dir))!=NULL){
		printf("%ld\t%s\n",ptr->d_ino,ptr->d_name);
	}
	closedir(dir);
	return;
}
	
