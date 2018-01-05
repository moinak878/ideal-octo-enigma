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

	 for(i=3;i<80;i++)
	{
		gotoxy(i,24);
		cprintf("%c",205);
	}

		for(i=5;i<27;i++)
	{
	  gotoxy(i-2,7);
	  cprintf("%c",196);
	}
 }

void display2()               //first screen
 {
	int i;
	gotoxy(31,2);
	  cprintf("D.A.V MODEL SCHOOL");
	gotoxy(36,3);
	  cprintf("  DURGAPUR");

	gotoxy(3,23);
	  cprintf("Created By:Tamali Kundu,Nunna Lakshmi Saranya,Titas Sarkar,Srijoni Choudhury ");

	gotoxy(60,24);
	  cprintf("Computer Science,XII");

	 textcolor(7);
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
		 cprintf(" %c",188);
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

	 for(i=3;i<80;i++)
	{
		gotoxy(i,24);
		cprintf("%c",205);
	}
 }


void menu()
{
	x:
	int i,choice=0;
	clrscr();
	  display();
	  gotoxy(6,9);
	  cout<<"NEW RECORD";
	  gotoxy(6,11);
	  cout<<"SEARCH RECORD";
	  gotoxy(6,13);
	  cout<<"DELETE RECORD";
	  gotoxy(6,15);
	  cout<<"MODIFY RECORD";
	  gotoxy(6,17);
	  cout<<"DISPLAY ALL";
	  gotoxy(6,19);
	  cout<<"EXIT";

	  textcolor(6);
	  gotoxy(4,9);
	  cprintf("1");
	  gotoxy(4,11);
	  cprintf("2");
	  gotoxy(4,13);
	  cprintf("3");
	  gotoxy(4,15);
	  cprintf("4");
	  gotoxy(4,17);
	  cprintf("5");
	  gotoxy(4,19);
	  cprintf("6");
	  textcolor(7);

	 gotoxy(35,13);
	 cout<<" ENTER YOUR CHOICE   ";
		cin>>choice;
	  if(choice==1)
		enterrecord();
	  else if(choice==2)
		searchrecord();
	  else if(choice==3)
		delrecord();
	  else if(choice==4)
			 modifyrecord();
	  else if(choice==5)
			 display1();
	  else if(choice==6)
			 exit(0);
	  else
		{
		 clrscr();
		 display();
		 gotoxy(5,12);
		 cout<<" WRONG CHOICE     ";
		 gotoxy(32,12);
		 cout<<"SORRY,WRONG CHOICE !! ENTER BETWEEN 1 AND 6 ";
		 gotoxy(54,20);
		  cout<<"Press ENTER to cont......";
		 getch();
		 goto x;
		}
}

void display1()
{
	clrscr();
	student s;
	fstream file1("mainfile.dat",ios::binary|ios::in);
	while(file1.read((char*)&s,sizeof(s)))
	  {
		 s.output();
	  }
	file1.close();

	menu();

}


void enterrecord()
{
	clrscr();

	student s;
	fstream file1("mainfile.dat",ios::app|ios::binary|ios::out);
	s.input();
	file1.write((char*)&s,sizeof(s));
	file1.close();
	s.output();

	menu();
}

void modifyrecord()
{
	fstream file1;
	clrscr();
	display();
	gotoxy(5,12);
	cout<<" MODIFY RECORD    ";

	gotoxy(33,12);
	cout<<" ENTER RECORD (Roll No) TO MODIFY  ";
	int r,pos=0;
	char found='f';
	cin>>r;
	file1.open("mainfile.dat",ios::binary|ios::in|ios::out);
	clrscr();
	student s,ss;
	while(!file1.eof())
	{
		pos=file1.tellg();
		file1.read((char*)&s,sizeof(s));
		if(s.rollno==r)
		{
		  s.output();
		  s.input1();
		  file1.seekg(pos);
		  file1.write((char*)&s,sizeof(s));
		  found='t';
		  break;
		}
		}
		if(found=='f')
		  {
			display();
			gotoxy(5,12);
			cout<<" MODIFY RECORD    ";

			gotoxy(33,12);
			cout<<"   RECORD NOT FOUND !!  ";
			gotoxy(54,20);
			cout<<"Press ENTER to cont......";
			getch();
			}
		file1.seekg(0);
		file1.close();
		menu();
	}

void delrecord()
{
	int r;
	char found='f',confirm='n';
	ifstream file1("mainfile.dat",ios::binary|ios::in);
	ofstream file2("temp.dat",ios::binary|ios::out);
	student s1,ss;

	clrscr();
	display();
	gotoxy(5,12);
	cout<<" DELETE RECORDS   ";

	gotoxy(33,12);
	cout<<"ENTER ROLL NUMBER TO  BE DELETED  ";
	cin>>r;
	while(file1.read((char*)&s1,sizeof(s1)))
	{

		if(s1.rollno==r)
		{
		  //s1.output();
		  found='t';

		  display();
		  gotoxy(5,12);
		  cout<<" DELETE RECORDS   ";
		  gotoxy(33,12);
		  cout<<"The Record is Successfully Deleted ....";
		  gotoxy(54,20);
		  cout<<"Press ENTER to cont......";
		  getch();
		}
		else
		 file2.write((char *)&s1,sizeof(s1));
	  }
	  if(found=='f')
		{
		display();
		gotoxy(5,12);
		cout<<" DELETE RECORDS   ";
		gotoxy(33,12);
		cout<<"SORRY,THE RECORD WAS NOT FOUND!              ";
		gotoxy(54,20);
		cout<<"Press ENTER to cont......";
			 getch();
		  }
		file1.close();
		file2.close();


		remove("mainfile.dat");
		rename("temp.dat","mainfile.dat");
		file1.open("mainfile.dat",ios::in);
			file1.close();
		menu();
		}

void searchrecord()
{
	clrscr();
	int b=0;
	student s;
	fstream file1("mainfile.dat",ios::binary|ios::in);
	display();
	gotoxy(5,12);
	cout<<" SEARCHED RECORDS ";

	gotoxy(30,12);
	cout<<"ENTER ROLL NO.OF THE RECORD TO BE SEARCHED ";
	int r;
	cin>>r;
	while(	file1.read((char*)&s,sizeof(s)))
	{

		if(s.rollno==r)
		{
			clrscr();
			s.output();
			b++;
			//break;
		}

	}
	if(b==0)
	{
		clrscr();
		display();
		gotoxy(5,12);
		cout<<" SEARCHED RECORDS ";
		gotoxy(33,12);
		cout<<"SORRY,THE RECORD WAS NOT FOUND!";
		gotoxy(54,20);
		cout<<"Press ENTER to cont......";
		getch();
			}
		clrscr();
		menu();
}
void passw()          // checks whether the person is authorized or not
{
 char un[30];
 gotoxy(30,11);
 printf("User Name : ");
 gotoxy(30,13);
 printf("Passward  : ");
 gotoxy(42,11);
 gets(un);
 gotoxy(42,13);
 int i=0;
 char c,ch[20];
 do
  {
	c=getch();
	ch[i++]=c;
	if(c==13)
	  printf(" ");
	else
	  printf("*");
  }while(c!=13);
  ch[i-1]=NULL;
	 if(strcmp(ch,"Class12e")==0 && strcmpi(un,"Project")==0)
	 {
		gotoxy(30,15);
		textcolor(3 + BLINK);
		cprintf("    MATCH FOUND");getch();
		textcolor(7);
		clrscr();
		display2();
		gotoxy(25,10);
		printf("      Please Wait.....");
		gotoxy(8,12);
		textcolor(6);
		cprintf("Û");
		gotoxy(10,12);
		gotoxy(67,12);
		textcolor(6);
		cprintf("Û");
		gotoxy(74,12);
		textcolor(6);
		cprintf("Û");
		gotoxy(10,12);
		for(int j=0;j<=55;j=j+1)
		 {
	 gotoxy(69,12);
	  if(j>=50)
		 cout<<j*2-10<<"%";
	  else
		 cout<<j*2<<"%";
	 delay(50);
	 gotoxy(10+j,12);
	 textcolor(6);
	 cprintf("Û");
		 }
		 delay(3500);
		 textcolor(7);
	 }
	else
	  {
		gotoxy(30,15);
		textcolor(RED + BLINK);
		cprintf("    MATCH NOT FOUND");getch();
		exit(0);
		textcolor(7);
	  }

}
void main()
{
		 clrscr();
		 display2();
		 passw();
		 menu();
}

