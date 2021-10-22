/*
 * Student_DB.c
 *
 *  Created on: 19/10/2021
 *      Author: BassantAhmed
 */
#include "Student_DB.h"
struct SStudent *gpFirstStudent = NULL;

void AddStudent (){
	struct SStudent *pLastStudent = NULL;
	struct SStudent *pNewStudent = NULL;
	//if the list contains records
	if(gpFirstStudent)
	{
		pLastStudent=gpFirstStudent;
		while (pLastStudent->pNextStudent)
			pLastStudent=pLastStudent->pNextStudent;

		pNewStudent = (struct SStudent *) malloc(sizeof(struct SStudent ));
		pLastStudent->pNextStudent=pNewStudent;

	}
	//if the list is empty
	else
	{
		//create new record
		gpFirstStudent = (struct SStudent *) malloc(sizeof(struct SStudent));
		pNewStudent=gpFirstStudent;
	}

	//fill the record data
	fill_the_record (pNewStudent);


	//set the next record to null
	pNewStudent->pNextStudent=NULL;

}


void fill_the_record (struct SStudent *pNewStudent){
	char temp[50];
	DPRINTF("\n Enter the ID: ");
	gets(temp);
	pNewStudent->Student.m_ID = atoi(temp);

	DPRINTF("\n Enter Student's full name : ");
	gets(pNewStudent->Student.m_name);

	DPRINTF("\n Enter height: ");
	gets(temp);
	pNewStudent->Student.m_height = atof(temp);

}


void Delete_Record (){
	char temp[50];
	int selected_ID;
	struct SStudent* pSelectedRecord=gpFirstStudent;
	struct SStudent* pPreviousRecord = NULL;
	//get selected ID
	DPRINTF("\n Enter the ID: ");
	gets(temp);
	selected_ID=atoi(temp);
	//loop on all records to find the ID
	if (gpFirstStudent){
		while (pSelectedRecord){
			if(pSelectedRecord->Student.m_ID == selected_ID){
				//if it is the selected record
				//1) if previous record exist
				if (pPreviousRecord){
					pPreviousRecord->pNextStudent=pSelectedRecord->pNextStudent;
				}
				//2)if previous record not exist
				else
				{
					gpFirstStudent=pSelectedRecord->pNextStudent;
				}
				//delete the record
				free (pSelectedRecord);
				break;
			}

			pPreviousRecord=pSelectedRecord;
			pSelectedRecord=pSelectedRecord->pNextStudent;
		}
		if (!pSelectedRecord)
			printf("\ncannot find student ID");

	}
}


void ViewStudents (){
	struct SStudent* pViewStudent=gpFirstStudent;
	int i;
	//if there is a list
	if(gpFirstStudent){
		for(i=1 ; pViewStudent ; i++){
			DPRINTF("\r\nRecord number %d",i);
			DPRINTF("\n ID: %d \nName: %s \n height: %0.2f", pViewStudent->Student.m_ID,
					pViewStudent->Student.m_name,
					pViewStudent->Student.m_height);
			pViewStudent=pViewStudent->pNextStudent;
		}
	}
	else
		printf("\nthere is no list ");


}

void DeletAll (){
	struct SStudent* pNextRecord=gpFirstStudent->pNextStudent;
	if(gpFirstStudent)
	{
		free (gpFirstStudent);
		gpFirstStudent=NULL;
		while (pNextRecord)
		{
			free (pNextRecord);
			pNextRecord=pNextRecord->pNextStudent;
		}
	}
	else
		printf("\nthere is no list to delete .. ");

}

void GetNth(struct SStudent *pLinkedList , int index){
	DPRINTF("\nEnter index:");
	scanf("%d",&index);
	int count =0;
	while (index != count)
	{
		pLinkedList=pLinkedList->pNextStudent;
		count++;
	}
	printf("\noutput ID : %d \nName : %s \nHeight : %0.2f",pLinkedList->Student.m_ID,pLinkedList->Student.m_name,pLinkedList->Student.m_height);

}

int GetLenght(struct SStudent *pLinkedList){
	int count=1;
	pLinkedList=gpFirstStudent;
	while(pLinkedList){
		count++;
		pLinkedList=pLinkedList->pNextStudent;
	}
	printf("the linked list length is %d",count-1);

	return count-1;
}

void GetNth_FromEnd(struct SStudent *pLinkedList , int index){
	int count =0 ,flag=1;
	DPRINTF("\nEnter index: ");
	scanf("%d ",&index);
	//initialize tow pointers (reference & main)
	//initialize pointers to head
	struct SStudent *pMain = pLinkedList;
	struct SStudent *pReference = pLinkedList;

	//move reference to n node from head
	if(pLinkedList){
		while (count != index)
		{
			pReference = pLinkedList->pNextStudent;
			if(!pReference)
			{
				printf("length of the list is less than the index %d",index);
				break;
				flag=0;
			}
			count++;
		}

		//move both pointers one by one till ref to null
		while(pReference)
		{
			pReference=pReference->pNextStudent;
			pMain=pMain->pNextStudent;
		}
		if(flag)
			printf("\nID: %d \nName : %s \nheight : %0.2f ",pMain->Student.m_ID ,pMain->Student.m_name , pMain->Student.m_height);
	}
}






