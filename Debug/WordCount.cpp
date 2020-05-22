#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc,char *argv[])
{
	char ch;
	int count1=1,count2=0,i=0;
	FILE *fp;
	char str1[3]="-c",str2[3]="-w";
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("not open");
		exit(0);
	}	
	while((ch=fgetc(fp))==','||(ch=fgetc(fp))==' ')
	{
		count2++;
	}
	while ((ch=fgetc(fp))!=EOF) 
	{
		if(ch==' '||ch==',')
			i=1;
		if(ch!=' '||ch!=',')
		{
			if(i==1)
			{
				count1++;
			}
			i=0;
		}
		count2++;
	} 
	if(strcmp(argv[1],str2)==0)
		printf("µ¥´ÊÊý:%d\n",count1);
	else if(strcmp(argv[1],str1)==0)
		printf("×Ö·ûÊý:%d\n",count2+2);
	fclose(fp);
} 