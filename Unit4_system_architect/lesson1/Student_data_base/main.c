/*
 * main.c
 *
 *  Created on: 19/10/2021
 *      Author: BassantAhmed
 */

#include "Student_DB.h"
extern struct SStudent* gpFirstStudent;

int main ()
{
	int i , index=0 ;
	while(1)
	{

		DPRINTF("\n		choose one of the following options\r\n1: AddStudent \n2:Delete_student \n3: View_students \n4: DeleteAll ");
		DPRINTF("\n5: Get Nth order: \n6: list length: \n7:Get Nth order from the end \nEnter option number: ");
		scanf("%d",&i);
		switch (i)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			Delete_Record();
			break;
		case 3:
			ViewStudents();
			break;
		case 4:
			DeletAll();
			break;
		case 5:
			GetNth((struct SStudent*)gpFirstStudent , index);
			break;
		case 6:
			GetLenght((struct SStudent*)gpFirstStudent);
			break;
		case 7:
			GetNth_FromEnd((struct SStudent*)gpFirstStudent , index);
			break;
		default:
			DPRINTF("\nwrong choice number..");
			break;
		}
		DPRINTF("\n=========================");

	}







	return 0;
}
