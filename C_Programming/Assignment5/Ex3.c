#include <stdio.h>

struct Scomplex {
	double m_R;
	double m_I;};

struct Scomplex Read_complex(void)
{
	struct Scomplex c;
	scanf("%lf %lf",&c.m_R,&c.m_I);
	return c;
}

struct Scomplex Add_complex (struct Scomplex A, struct Scomplex B)
{
	struct Scomplex sum;
	sum.m_R=A.m_R + B.m_R;
	sum.m_I= A.m_I + B.m_I;

	return sum;

}

void Print_complex( struct Scomplex C)
{
	printf("sum = %.1lf +%.1lfi \r\n",C.m_R,C.m_I);
}

void main(){
	struct Scomplex x,y;
	printf("for 1st complex number\n Enter real and imaginary respectively:");
	x=Read_complex();
	printf("\r\nfor 2st complex number\n Enter real and imaginary respectively:");
	y=Read_complex();
	Print_complex(Add_complex(x,y));
}
