#include <stdio.h>

struct SDistance {
	int m_feet;
	float m_inch;

};


void main ()
{
	struct SDistance D1,D2,sum;
	printf("Enter information for 1st distance\r\n");
	printf("Enter feet: ");
	scanf("%d",&D1.m_feet);
	printf("Enter inch: ");
	scanf("%f",&D1.m_inch);

	printf("\r\nEnter information for 2st distance\r\n");
	printf("Enter feet: ");
	scanf("%d",&D2.m_feet);
	printf("Enter inch: ");
	scanf("%f",&D2.m_inch);

	sum.m_feet=D1.m_feet + D2.m_feet;
	sum.m_inch=D1.m_inch + D2.m_inch;
	if (sum.m_inch >12)
	{
		sum.m_feet+=1;
		sum.m_inch-=12;
	}
	printf("\r\nsumf of distances=%d\' %.1f\"",sum.m_feet,sum.m_inch);
}
