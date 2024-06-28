#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char admin[10],admin1[10]="lib",pass[10],pass1[10]="1234",newname[20],newrn[5],newbranch[5],newmob[10];
char books[30][50],name[20][20],rollno[5][20],branch[5][20],mob[10][20],rn[5],rn1[5],rn2[5],ibook[30][50];
int c,c1,i,b,s,j,b1[10],b2;
void login();
void add_books();
void add_student();
void update_student();
void delete_student();
void issue_book();
void show_ibook();
void show_student();
int main()
{
	top:
	login();
	if(strcmp(admin,admin1)==0 && strcmp(pass,pass1)==0)
	{
		top1:
		printf("\n--------------------------------------------");
		printf("\n1.Add Books      2.Add Student");
		printf("\n3.Update Student 4.Delete Student");
		printf("\n5.Issue Book     6.Show Issued Book");
		printf("\n7.Show Student   8.Log Out");
		printf("\n--------------------------------------------\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				add_books();
				goto top1;
				break;
			case 2:
				add_student();
				goto top1;
				break;
			case 3:
				update_student();
				goto top1;
				break;
			case 4:
				delete_student();
				goto top1;
				break;
			case 5:
				issue_book();
				goto top1;
				break;
			case 6:
				show_ibook();
				goto top1;
				break;
			case 7:
				show_student();
				goto top1;
				break;
			case 8:
				exit(0);
			default:
					printf("\nWrong Choice\n");
					goto top1;
		}
	}
	else
	{
		printf("\nWrong Username Or Password\n");
		goto top;
	}
}
void login()
{
	printf("\n           Library Management Portal        ");
	printf("\n--------------------------------------------");
	fflush(stdin);
	printf("\nUsername :");
	gets(admin);
	printf("\nPassword :");
	gets(pass);
	printf("\n--------------------------------------------");
}
void add_books()
{
	printf("\nEnter Number Of Books You Want To Add :");
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{
		fflush(stdin);
		printf("\nEnter Book's Name :");
		gets(books[i]);
	}
}
void add_student()
{
	printf("\nEnter Number of Student You Want to Add :");
	scanf("%d",&s);
	for(i=0;i<s;i++)
	{
		fflush(stdin);
		printf("\nName :");
		gets(name[i]);
		printf("\nRoll No :");
		gets(rollno[i]);
		printf("\nBranch :");
		gets(branch[i]);
		printf("\nMobile Number :");
		gets(mob[i]);
	}
}
void update_student()
{
	fflush(stdin);
	printf("\nEnter Roll Number of Student :");
	gets(rn);
	for(i=0;i<s;i++)
	{
		if(strcmp(rn,rollno[i])==0)
		{
			t0:
			printf("\n       Student Details      ");
			printf("\n----------------------------");
			printf("\n1.Name      :%s",name[i]);
			printf("\n2.Roll No   :%s",rollno[i]);
			printf("\n3.Branch    :%s",branch[i]);
			printf("\n4.Mobile No.:%s",mob[i]);
			printf("\n----------------------------");
			printf("\nEnter Your Choice :");
			scanf("%d",&c1);
			switch(c1)
			{
				case 1:
				fflush(stdin);
				printf("\nName :");
				gets(newname);
				strcpy(name[i],newname);
				break;
				case 2:
				fflush(stdin);
				printf("\nRoll No :");
				gets(newrn);
				strcpy(rollno[i],newrn);
				break;
				case 3:
				fflush(stdin);
				printf("\nBranch :");
				gets(newbranch);
				strcpy(branch[i],newbranch);
				break;
				case 4:
				fflush(stdin);
				printf("\nMobile No.:");
				gets(newmob);
				strcpy(mob[i],newmob);
				break;
				default:
				printf("\nWrong Choice\n");
				goto t0;
			}
		}
	}
}
void show_student()
{
	fflush(stdin);
	printf("\nEnter Roll Number :");
	gets(rn1);
	for(i=0;i<s;i++)
	{
		if(strcmp(rn1,rollno[i])==0)
		{
			printf("\n       Student Details      ");
			printf("\n----------------------------");
			printf("\n1.Name      :%s",name[i]);
			printf("\n2.Roll No   :%s",rollno[i]);
			printf("\n3.Branch    :%s",branch[i]);
			printf("\n4.Mobile No.:%s",mob[i]);
			printf("\n----------------------------");
		}
	}
}
void delete_student()
{
	fflush(stdin);
	printf("\nEnter Roll Number :");
	gets(rn2);
	for(i=0;i<s;i++)
	{
		if(strcmp(rn2,rollno[i])==0)
		{
			strcpy(name[i],name[i+1]);
			strcpy(rollno[i],rollno[i+1]);
			strcpy(branch[i],branch[i+1]);
			strcpy(mob[i],mob[i+1]);
		}
	}
}
void issue_book()
{
	for(i=0;i<b;i++)
	{
		printf("\nBook :%s",books[i]);
	}
	printf("\nEnter Number of Books You Want To Issue :");
	scanf("%d",&b2);
	for(j=0;j<b2;j++)
	{
		fflush(stdin);
		printf("\nEnter Book Name You Want to Issue :");
		gets(ibook[j]);
	}
}
void show_ibook()
{
	printf("\nIssued Books Are :");
	for(j=0;j<b2;j++)
	{
		printf("\n%s",ibook[j]);
	}
}
