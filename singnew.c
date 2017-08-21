#include<stdio.h>
#include<string.h>
struct{
char dname[20],fname[20][20];
int count;
}direc;
void main(){
int i,ch;
char f[20];
printf("Enter name of directory\n");
scanf("%s",direc.dname);
direc.count=0;
while(1){
printf("Enter your choice\n1-Create file\t2-Delete file\t3-Search file\t4-Display files\t5-Exit\n");
scanf("%d",&ch);
switch(ch){
	case 1:printf("Enter name of file\n");
	scanf("%s",f);
	for(i=0;i<direc.count;i++){
	if(strcmp(f,direc.fname[i])==0)
	printf("Filename already exists\t give another name\n");
	scanf("%s",f);break;}
	strcpy(direc.fname[direc.count],f);
	direc.count++;break;
	case 2:printf("Enter name of file to be deleted\n");\
	scanf("%s",f);
	for(i=0;i<direc.count;i++){
	if(strcmp(f,direc.fname[i])==0){
	printf("File %s is deleted\n",f);
	strcpy(direc.fname[i],direc.fname[direc.count-1]);break;}}
	if(i==direc.count)
	printf("File %s not found\n",f);
	else
	direc.count--;
	break;
	case 3:printf("Enter name of file to be searched\n");
	scanf("%s",f);
	for(i=0;i<direc.count;i++){
	if(strcmp(f,direc.fname[i])==0){
	printf("File is found in position %d\n",i+1);break;}}
	if(i==direc.count)
	printf("File not found\n");break;
	case 4:if(i==direc.count)
	printf("No files are found\n");
	{printf("\n\t\tDirectory : %s\nFiles are :\n",direc.dname);
	for(i=0;i<direc.count;i++)
	printf("File %d : %s\n",i+1,direc.fname[i]);}
	break;
	case 5:exit(0);
}
}
}

