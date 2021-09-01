#include <stdio.h>

struct SStudent {
	char m_name[50];
	int m_roll;
	float m_marks;

};


void main ()
{
	struct SStudent s;
	printf("Enter information of students:\r\n");
	printf("Enter name: ");
	gets(s.m_name);
	printf("Enter roll number: ");
	scanf("%d",&s.m_roll);
	printf("Enter marks: ");
	scanf("%f",&s.m_marks);

	printf("\r\nDisplaying information: \r\n");
	printf("Name: %s\nRoll: %d\nMarks: %.2f",s.m_name,s.m_roll,s.m_marks);
}
