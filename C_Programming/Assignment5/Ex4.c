#include <stdio.h>

struct SStudent {
	char m_name [50];
	int m_roll;
	int m_mark;
};



void main(){
	struct SStudent students [10];
	int i;
	printf("Enter information of students\r\n");
	for (i=0;i<10;i++)
	{
		printf("for roll number %d\n",i+1);
		printf("Enter name:");
		scanf("%s",&students[i].m_name);
		printf("Enter mark:");
		scanf("%d",&students[i].m_mark);
	}
	printf("\r\nDisplaying information of students\r\n");
	for(i=0;i<10;i++)
	{
		printf("information for roll number %d\n",i+1);
		printf("Name: %s\n",students[i].m_name);
		printf("Mark: %d\n",students[i].m_mark); 
	}

}
