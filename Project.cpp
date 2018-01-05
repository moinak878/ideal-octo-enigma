#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<string.h>
void enterrecord();
void searchrecord();
void delrecord();
void modifyrecord();
int display();
void display1();

class student //to record temporarily
 {
    public:
	int rollno;
	char name[20];
	int marks[5], total;
	float percentage;
	float tot_marks;
	float pass_marks;
	student()
	{
		tot_marks=100;
		pass_marks=40;
	}
	void input();
	void input1();
	void output();
};
void student::input()                // first time input
{
	total=0;
	display();
	gotoxy(5,12);
	cout<<" ENTER NEW RECORD";

	gotoxy(30,7);
	cout<<"Enter Roll No         : ";
	cin>>rollno;
	gotoxy(30,9);
	cout<<"Enter Name of Student : ";
	gets(name);
	gotoxy(30,13);
	cout<<"Enter marks in 5 subjects out of 100";
	gotoxy(30,14);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(54,20);
	cout<<"Press ENTER to cont......";
	gotoxy(30,15);
	cout<<"Enter marks in English   : ";
	cin>>marks[0];
	gotoxy(30,15);
	cout<<"                             ";
	gotoxy(30,15);
	cout<<"Enter marks in Physics   : ";
	cin>>marks[1];
	gotoxy(30,15);
	cout<<"                             ";
	gotoxy(30,15);
	cout<<"Enter marks in Chemistry : ";
	cin>>marks[2];
	gotoxy(30,15);
	cout<<"                             ";
	gotoxy(30,15);
	cout<<"Enter marks in Maths     : ";
	cin>>marks[3];
	gotoxy(30,15);
	cout<<"                             ";
	gotoxy(30,15);
	cout<<"Enter marks in Computer  : ";
	cin>>marks[4];
	for(int i=0;i<5;i++)
		total=total+marks[i];
	percentage = total/5.0;
}
void student::input1()                    // while modifying contents
{
	int marks1,marks2,marks3,marks4,marks5,roll;
	char nam[30];
	total=0;
	display();
	gotoxy(5,12);
	cout<<" ENTER NEW RECORD";

	gotoxy(30,7);
	cout<<"Enter Roll No(Press -1 ,if Unchanged)    : ";
	cin>>roll;
	if(roll!=-1)
	  rollno=roll;
	gotoxy(30,9);
	cout<<"Enter Name of Student  :";
	gotoxy(30,10);
	cout<<"(Press .,if Unchanged) ";
	gotoxy(55,9);
	gets(nam);
	if(strcmp(nam,".")!=0)
	  strcpy(name,nam);
	gotoxy(30,13);
	cout<<"Enter marks in 5 subjects(Press -1 ,if Unchanged)";
	gotoxy(30,14);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(54,20);
	cout<<"Press ENTER to cont......";
	gotoxy(30,15);
	cout<<"Enter marks in English : ";
	cin>>marks1;
	if(marks1!=-1)
	marks[0]=marks1;
	gotoxy(30,15);
	cout<<"                                                 ";
	gotoxy(30,15);
	cout<<"Enter marks in Physics : ";
	cin>>marks2;
	if(marks2!=-1)
	marks[1]=marks2;
	gotoxy(30,15);
	cout<<"                                                 ";
	gotoxy(30,15);
	cout<<"Enter marks in Chemistry : ";
	cin>>marks3;
	if(marks3!=-1)
	marks[2]=marks3;
	gotoxy(30,15);
	cout<<"                                                 ";
	gotoxy(30,15);
	cout<<"Enter marks in Maths    : ";
	cin>>marks4;
	if(marks4!=-1)
	marks[3]=marks4;
	gotoxy(30,15);
	cout<<"                                                 ";
	gotoxy(30,15);
	cout<<"Enter marks in Computer  : ";
	cin>>marks5;
	if(marks5!=-1)
	marks[4]=marks5;
	for(int i=0;i<5;i++)
		total=total+marks[i];
	percentage = total/5.0;
}

void student::output()                //to display the records
{
	clrscr();
	display();
	gotoxy(5,12);
	cout<<"DETAILS OF STUDENT ";

	gotoxy(40,6);
	cout<<"THE DETAILS OF THE STUDENT ";
	for(int i=0;i<53;i++)
	 {
	  gotoxy(26+i,8);
	  cprintf("%c",196);
	  gotoxy(26+i,10);
	  cprintf("%c",196);
	  gotoxy(26+i,18);
	  cprintf("%c",196);
	}
	gotoxy(27,9);
	cout<<"Student's Name : "<<name;
	gotoxy(65,9);
	cout<<"Roll No : "<<rollno;
	gotoxy(27,11);
	cout<<"SUBJECT     | "<<"ob. marks" <<"full marks"<<"pass marks";
	gotoxy(27,12);
	cout<<"ENGLISH     | "<<marks[0];
	gotoxy(27,13);
	cout<<"PHYSICS     | "<<marks[1];
	gotoxy(27,14);
	cout<<"CHEMISTRY   | "<<marks[2];
	gotoxy(27,15);
	cout<<"MATHEMATICS | "<<marks[3];
	gotoxy(27,16);
	cout<<"COMPUTER    | "<<marks[4];
	gotoxy(27,20);
	cout<<"TOTAL MARKS   º";
	gotoxy(32,20);
	cout<<total;
	gotoxy(45,19);
	cout<<"PERCENTAGE    º";
	gotoxy(49,20);
	cout<<percentage<<" %";
	gotoxy(60,19);
	cout<<"      STATUS";
	gotoxy(52,17);
	  cout<<"Press Enter to continue.... ";

	if(percentage<40)
	{
		gotoxy(66,20);
		cout<<"FAILED";
	}
	if(percentage>=40 && percentage<60)
	{
		gotoxy(63,20);
		cout<<"PASSED, GRADE C";
	}
	if(percentage>=60 && percentage<80)
	{
		gotoxy(63,20);
		cout<<"PASSED, GRADE B";
	}
	if(percentage>=80 && percentage<=100)
	{
		gotoxy(63,20);
		cout<<"PASSED, GRADE A";
	}
	getch();
}

int display()          // prints the main frame
 {
  clrscr();
	int i;
	gotoxy(31,2);
	  cprintf("D.A.V MODEL SCHOOL");
	gotoxy(36,3);
	  cprintf("DURGAPUR");

	gotoxy(3,23);
	  cprintf("Created By: Tamali Kundu,Nunna Lakshmi Saranya,Titas Sarkar,Srijoni Choudhury");

	gotoxy(60,24);
	  cprintf("Computer Science,XII");

	textcolor(7);
	for(i=1;i<18;i++)
	  {
		 gotoxy(25,5+i);
		 cprintf("%c",179);
	  }
	 for(i=1;i<24;i++)
	  {
		 if(i==1)
		 {
	  gotoxy(2,3+i);
	  cprintf("%c",201);
		 }
		 else
	if(i==22)
	  {
		 gotoxy(2,3+i);
		 cprintf("%c",200);
	  }

		 else
	 {
	 gotoxy(2,3+i);
	 cprintf("º");
	 }
	  }

		for(i=1;i<23;i++)
	  {
		 if(i==1)
		 {
	  gotoxy(80,3+i);
	  cprintf("%c",187);
		 }
		 else
	if(i==22)
	  {
		 gotoxy(79,3+i);
		 cprintf("e%c",188);
	  }

		 else
	 {
	 gotoxy(80,3+i);
	 cprintf("º");
	 }
	  }


	for(i=0;i<77;i++)
		{
	gotoxy(3+i,21);
	cprintf("%c",196);
		}
		_setcursortype(_NOCURSOR);
		textcolor(4);
		gotoxy(22,4);
		cprintf("COMPUTERIZED REPORT CARD GENERATION");
		textcolor(10);

		gotoxy(5,6);
		cprintf("Enter Your choice ");
		gotoxy(4,23);
		cprintf("%s",__DATE__);
		gotoxy(6,23);
		textcolor(7);
		 for(i=3;i<80;i++)
	{
	  gotoxy(i,3);
	  cprintf("%c",205);
	}

		for(i=3;i<80;i++)
	{
	  gotoxy(i,5);
	  cprintf("%c",205);
	}
