/*
 * Student_DB.h
 *
 *  Created on: 19/10/2021
 *      Author: BassantAhmed
 */

#ifndef STUDENT_DB_H_
#define STUDENT_DB_H_
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "stdint.h"
#include "string.h"

#define DPRINTF(...)	{fflush(stdout); \
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout); \
						fflush(stdin);}

struct SData {
	int m_ID;
	char m_name [256];
	float m_height;
};

struct SStudent {
	struct SData Student;
	struct SStudent* pNextStudent;
};

void AddStudent ();
void fill_the_record (struct SStudent *pNewStudent);
void Delete_Record ();
void ViewStudents ();
void DeletAll ();
void GetNth(struct SStudent *pLinkedList , int index);
int GetLenght(struct SStudent *pLinkedList);
void GetNth_FromEnd(struct SStudent *pLinkedList , int index);


#endif /* STUDENT_DB_H_ */
