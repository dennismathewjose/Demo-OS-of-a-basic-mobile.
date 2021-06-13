                 /*******************************************
		  *        SNEHAL<<RAJ<<MANI<<DENNIS         *
		  *		C++ PROJECT XII B            *
		  *		    PHONE.CPP     alpha 2.3.3*
                  ********************************************/
#include<fstream.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<process.h>
#include<iomanip.h>
#include<stdlib.h>

//global variables
char menuans='1';
int u_flag=0;
int s_flag=0;
char ans1='*';
char ans2='*';
char ans3='*';
char cH='0';
char CS,EC,SCh,CH;
int w=1;
char tmsg[300];
//prototypes
void contacts();
void sms_send();
void inbox();
void docs();
void calendar();
void calculator();
void odd();
void tic();
void fortune();

struct user
{
 char user_name[30];
 char user_num[15];
 int pass,password;
}u,U,test;

struct msg
{
 char from[30];
 char to[30];
 char txt[200];
}m,mtest;

//menu()

void menu()
{
 do
{
 clrscr();
 gotoxy(29,7);    textcolor(1);
 cprintf("Phone Menu");
 gotoxy(29,8);
 cout<<"----------";
 gotoxy(26,10);  textcolor(GREEN);
 cprintf("Contacts(c)    SMS(s)");
 gotoxy(26,13);
 cprintf("Documents(d)   Calculator(r)");
 gotoxy(26,16);
 cprintf("Calendar(l)    Extras(e)");
 gotoxy(26,19);
 cprintf("Settings(t)    Shut(S)");

 cout<<endl;
 menuans=getch();
 clrscr();
}while(!(menuans=='c'|| menuans=='s'||  menuans=='d'|| menuans=='r'||  menuans=='l'||   menuans=='e'||  menuans=='t'|| menuans=='S' ));


 switch(menuans)
 {
  case 'c':
  contacts();
  break;
  case 's':
  do{
  clrscr();
  cout<<"1. Send a message\n2. View Inbox\n3. Exit to Menu";

  CS=getch();
  if(CS=='1')
   sms_send();
  else if(CS=='2')
   inbox();
  else if(CS=='3')
    menu();

}while(!(CS=='1'||CS=='2'||CS=='3'));
  break;
  case 'd':
  docs();
  break;
  case 'r':
  calculator();
  break;
  case 'l':
  calendar();
  break;
  case 'e':
 do{
  clrscr();
  cout<<"1. Odd or Even\n2. Tic-Tac-Toe\n3. Fortune\n4. Exit to Menu";

   EC=getch();
   if(EC=='1')
   odd();
  else if(EC=='2')
   tic();
  else if(EC=='3')
    fortune();
  else if(EC=='4')
   menu();
 }while (!(  EC=='1'||EC=='2'||EC=='3'||EC=='4'));
  break;
  case 't':
  do{
  clrscr();
   textcolor(4);
   cout<<"\tAbout(a)\n\n\tExit(e)\n";

  SCh=getch();
  if(SCh=='e')
  menu();
  else if(SCh=='a')
   {
     char bout[400];int IGI=0;
    strcpy(bout,"\n\nPhone.cpp was created as a C++ project for Class XII  \n\nDevelopers: \nArun Mani:Any year Calendar,Odd or Even game code  \nDennis Mathew Jose :Contacts app,Documents app  \nRaj Narayanan:Scientific Calculator,Tic-Tac-Toe game code  \nSnehal Sha:SMS app,Kernel  \n\n1600 lines , Compiled \nStatus:Working \nBugs:None \nCreated:17/NOV/2018 \nLast Modified:03/DEC/2018  \nVersion 2.3.2 ");
    do
     {
      cout<<bout[IGI++];
      if(bout[IGI]==' ')
      delay(300);
     }while(bout[IGI]!='\0');
    delay(4000);
    menu();
  }//if
}while(!(SCh=='e'||SCh=='a'));
  break;
  case 'S':
  clrscr();
  for(int gig=5;gig>-1;gig--)
 {  delay(1000);
     clrscr();
  cout<<"Shutting down in "<<gig<<" seconds\n\n";

  cout<<"Press any to go back";
  if(kbhit())
   menu();
}exit(0);
  break;
}
}

//dennis:documents,contacts


class documents
 {
  char title[25];
  char list[100];
  char date[12];
   public:
    void view(int);
    void getdata();
    friend int check(char[]);
   }doc;


 int check(char nm[40])
    {
     if(strcmpi(doc.title,nm)==0)
       return 1;
     else
     return -1;
 }


 void documents::getdata()
    {
      clrscr();
     cout<<setw(5)<<"Enter the date: ";
     gets(date);
     cout<<'\n'<<setw(5)<<"Enter the title of the document: ";

     gets(title);
     cout<<'\n'<<setw(5)<<"Enter the content\n\n";
     gets(list);

      ofstream fo(u.user_name,ios::binary|ios::ate);
       fo.write((char*)&doc,sizeof(doc));
       fo.close();
     char ans;
     cout<<"\nDo you wish to make more Documents? (y/n)\n";
     cin>>ans;
     if(ans=='y'||ans=='Y')
     getdata();
     }

 void kandupidi()
     {
     clrscr();
     int ret,flag=0;
     char nm[35];
     gotoxy(1,4);
     cout<<"Enter the title of the document\n";
     gets(nm);
     ifstream fin(u.user_name);

     while(fin.read((char*)&doc,sizeof(doc)))
       {
       ret=check(nm);
	if(ret==1)
	 {
	 doc.view(1);
	 flag=1;

	 }
	}
	fin.close();
       if(flag!=1)
       cout<<"sorry!!!no name matched your search\n";
     }
void documents::view(int a)
      {

      if(a==2)
    {
       cout<<"\n\ntitle :"<<title;
       cout<<"\ndate of creation: "<<date;
       cout<<"\nlist: "<<list<<endl;
       }
      else
      {
      cout<<"\n";
      gotoxy(20,3);
      cout<<"DOCUMENTS\n";
       gotoxy(20,5);
       cout<<"TITLE: "<<title;
       gotoxy(20,6);
       cout<<"CONTENT :"<<list;
       gotoxy(20,7);
       cout<<"DATE OF CREATION "<<date;
       }
      }
 void docs()
    {
     clrscr();
     int ch;
     char ans;
     do
     {

     clrscr();
     gotoxy(30,5);
     cout<<"1.CREATE";
     gotoxy(30,6);
     cout<<"2.VIEW";
     gotoxy(30,7);
     cout<<"3.SEARCH\n";
     gotoxy(30,8);
     cout<<"4.EXIT\n";
     gotoxy(25,10);
     cout<<"Please enter your choice(1-4)\n";
     cin>>ch;
     switch(ch)
      {
       case 1:
       doc.getdata();
       break;
       case 2:
      ifstream fd(u.user_name);
      if(!fd)
    cout<<"\nSorry no documents exist\n";
    else
     {
      while(fd)
      {
      fd.read((char*)&doc,sizeof(doc));
       if(!fd.eof())
	doc.view(ch); }
	}
	fd.close();

     break;

   case 4:
   cout<<"Press any key to exit\n";
   getch();
   menu();

   case 3:
    kandupidi();
    break;
  default:
   cout<<"Invalid Choice";
   delay(2000);
   clrscr();
   ans='y';
   continue;

   }
   cout<<"Do you wish to continue(y/n)\n";
   cin>>ans;
 }
   while(ans=='y'||ans=='Y');
  menu();
 }




//dennis contacts



class contacts
 {
 char mob_no[11];
 char name[40];
 char emailid[50];
 public:

    void input();
    void display(int);

   void edit();
   friend int verify(char[]);
   }cs;

  int verify(char nm[40])
    {
     if(strcmpi(cs.name,nm)==0)
       return 1;
     else
     return -1;

   }


     void contacts::input()
    {
      clrscr();
     cout<<setw(5)<<"Enter the mobile number: ";
     gets(mob_no);
     cout<<'\n'<<setw(5)<<"Enter the name: ";

     gets(name);
     cout<<'\n'<<setw(5)<<"Enter the email_id\n";
     gets(emailid);
      ofstream fo(u.user_num,ios::binary|ios::app);
       fo.write((char*)&cs,sizeof(cs));
       fo.close();
     char ans;
     cout<<"do you wish to add more contacts(y/n)";
     cin>>ans;
     if(ans=='y'||ans=='Y')
     input();
     }
     void contacts::display(int a)
      {
      if(a==5)
    {  cout<<name;
      for(int z=strlen(name);z<=44;z++) cout<<' ';
      cout<<mob_no<<'\n';}
      else
      {
       gotoxy(22,5);
       cout<<"name: "<<name;
       gotoxy(22,6);
       cout<<"mobile number :"<<mob_no;
       gotoxy(22,7);
       cout<<"email-id: "<<emailid;
       }
      }


  void contacts::edit()
    {
     cout<<"enter new mobile number\n";
     cin>>mob_no;
     cout<<"enter name\n";
     gets(name);
    }

    void modify(int pos)
      {
      ofstream fm(u.user_num,ios::ate);
      fm.seekp(pos);
      fm.write((char*)&cs,sizeof(cs));
      fm.close();
      }

    void search()
     {
     int ret,flag=0;
     char nm[35];
     gotoxy(1,4);
     cout<<"enter the name of the person you need to contact: ";
     gets(nm);
     ifstream fin(u.user_num);

     while(fin.read((char*)&cs,sizeof(cs)))
       {
       ret=verify(nm);
	if(ret==1)
	 {
	 cs.display(1);
	 flag=1;

	 }
	}
	fin.close();
       if(flag!=1)
       cout<<"sorry!!!no name matched your search\n";
     }

void contacts()
      {
      clrscr();
      int ch;
      char ans;
       do
	{
	clrscr();
	gotoxy(28,2);

	cout<<" C";delay(70);cout<<"O";
	delay(70);cout<<"N";delay(70);cout<<"T";delay(70);cout<<"A";
	delay(70);cout<<"C";delay(70);cout<<"T";delay(70);cout<<"S";

	int i=0;
	cout<<"\n";
	gotoxy(21,3);
	while(i<25)
	 {
	  cout<<"*";delay(60);
	  i++;
	  }
       delay(150);

      gotoxy(22,5);
      cout<<"1.CREATE NEW CONTACT";
      delay(100);
      gotoxy(22,6);
      cout<<"2.EDIT EXISTING CONTACT";
      delay(100);
      gotoxy(22,7);
      cout<<"3.DELETE";
      delay(100);
      gotoxy(22,8);
      cout<<"4.SEARCH";
      delay(100);
      gotoxy(22,9);
      cout<<"5.DISPLAY CONTACTS";
      delay(100);
      gotoxy(22,10);
      cout<<"6.EXIT\n";
      delay(100);
      gotoxy(50,11);
      cout<<"\nplease enter your choice(1-6)\n";
      cin>>ch;
      clrscr();
      switch(ch)
       {
       case 1:
       cs.input();

       break;

       case 2:
	char nm[35];
	int flag=0;
	int loc;
	gotoxy(2,5);
	cout<<"enter the name of the person to edit the contact:";
	gets(nm);
	ifstream fe(u.user_num);
	while(!fe.eof())
	 {
	 loc=fe.tellg();
	  fe.read((char*)&cs,sizeof(cs));
	 int ret=verify(nm);

	  if(ret==1)
	   {
	    cs.edit();
	    flag=1;
	    break;
	   }
	  }
	 fe.close();
	 if(flag==1)
	 modify(loc);
	 else
	 cout<<"sorry!!no items\n";
	 break;

       case 4:
       search();
       break;

      case 5:
      ifstream fd(u.user_num);
      if(!fd)
    cout<<"sorry no contacts exist\n";
    else
     {

      cout<<"NAME"<<setw(54)<<"MOBILE NUMBER\n";
      while(fd)
      {
      fd.read((char*)&cs,sizeof(cs));
       if(!fd.eof())
	cs.display(ch); }
	}
	fd.close();
	break;

	case 3:
	gotoxy(2,5);

	cout<<"enter the name to be deleted from your contacts: ";
	gets(nm);
	ofstream del("temp",ios::binary);
	ifstream fc(u.user_num);
	while(fc.read((char*)&cs,sizeof(cs)))
	 {
	 int ret=verify(nm);
	  if(ret==-1)
	  del.write((char*)&cs,sizeof(cs));
	  else
	  flag=1;
	 }
	 del.close();
	 fc.close();
	  if(flag==1)
	   {
	    remove(u.user_num);
	    rename("temp",u.user_num);
	    cout<<"\nsuccessfully deleted\n";
	    }
	  else
	   cout<<"account doesn't exist";
	   break;

	   case 6:

	   gotoxy(25,10);
	   delay(110);cout<<"P";delay(110);cout<<"R";delay(110);cout<<"O";
	   delay(110);cout<<"G";delay(110);cout<<"R";delay(110);cout<<"A";
	   delay(110);cout<<"M";delay(110);cout<<" E";delay(110);cout<<"X";
	   delay(110);cout<<"I";delay(110);cout<<"T";delay(110);cout<<"T";
	   delay(110);cout<<"I";delay(110);cout<<"N";delay(110);cout<<"G";


	 menu();





       default:
       cout<<"invalid choice\n";
       }
      cout<<"\ndo u wish to continue\n";
      cin>>ans;
     }
     while(ans=='y'||ans=='Y');


    }


//fortune

void fortune()
{
 clrscr();
 cout<<"Enter a number:";
 int lll ; cin>>lll;
 cout<<endl;
 randomize();
 int prob=((random(lll)+10)%10);
 switch(prob)
 {
  case 0:
  delay(500);
  cout<<"It's your lucky day!! Hit those wonders!";
  delay(5000);
  clrscr();
  menu();
  break;
  case 1:
  delay(500);
  cout<<"You know... meh...";
  delay(5000);
  clrscr();
  menu();
  break;
  case 2:
  delay(500);
  cout<<"Some things aren't meant for everyone...";
  delay(6000);
  clrscr();
  menu();
  break;
  case 3:
  delay(500);
  cout<<"You look good...";
  delay(5000);
  clrscr();
  menu();
  break;
  case 4:
  delay(500);
  cout<<"I smell something fishy...";
  delay(5000);
  clrscr();
  menu();
  break;
  case 5:
  delay(500);             textcolor(RED+BLINK);
  cout<<"Wait a second!!\n\n";
  delay(2000);      textcolor(GREEN);
  cout<<"Oh nothing...";
  delay(3000);
  clrscr();
  menu();
  break;
  case 6:
  delay(500);
  cout<<"Something Important is gonna happen!";
  delay(5000);
  clrscr();
  menu();
  break;
  case 7:
  delay(500);
  cout<<"I feel Good!! (happy bgm)";
  delay(5000);
  clrscr();
  menu();
  break;
  case 8:
  delay(500);
  cout<<"Stay away from greedy people...";
  delay(5000);
  clrscr();
  menu();
  break;
  case 9:
  delay(500);
  cout<<"Woow , something nice will happen";
  delay(5000);
  clrscr();
  menu();
  break;
  case 10:
  delay(500);
  cout<<"Ohh. Boogerrs..you again..";
  delay(5000);
  break;
 }
}
//sms_send  and sms inbox

void sms_send()
{


      clrscr();
      s_flag=0;
      cout<<"Whom to send?\n\n\n";
      ifstream FI;
      FI.open("userlist",ios::in); //shows every name which exists
      FI.seekg(0);
      while(FI.read((char*)&test,sizeof(user)))
       {         //excludes our name
	if(strcmpi(test.user_name,u.user_name)==0)
	continue;
	cout<<test.user_name<<"\t";
       }
       FI.close();
	strcpy(m.from,u.user_name);
       cout<<endl<<"Enter Name:";
       gets(m.to);
       //check if the person exists
       ifstream FII;
       FII.open("userlist",ios::ate|ios::binary);
      FII.seekg(0);
      while(FII.read((char*)&test,sizeof(user)))
       {

	if(strcmpi(test.user_name,m.to)==0)
	 s_flag=1;
       }
      FII.close();
       if (s_flag==1)
	{
	  clrscr();
	 cout<<"Writing to "<<m.to<<":";
	 gets(m.txt);

       ofstream FOOO;
       FOOO.seekp(0,ios::end);
       FOOO.open("inbox_s",ios::ate,ios::binary);
       FOOO.write((char*)&m,sizeof(msg));
       cout<<endl<<"\n\nSENT!";
       delay(300);
       FOOO.close();
       menu();
	}//if
       else
 { clrscr();  cout<<"Person DNE , Try agin(t) exit to menu(e)";
    cout<<endl;
     do{
   CH=getch();
   if(CH=='t'||CH=='T')
      sms_send();
   else if(CH=='e'||CH=='E')
    menu();
}while(!( CH=='t'||CH=='T'||CH=='e'||CH=='E'));
}
}//smssend



void inbox()
{

 clrscr();
 cout<<"INBOX\n"<<"_____"<<endl;
 ifstream I;
 I.open("inbox_s",ios::ate|ios::in);
 I.seekg(0);
 while(I.read((char*)&mtest,sizeof(msg)))
{


 if(strcmpi(mtest.to,u.user_name)==0)
 cout<<mtest.from<<":"<<mtest.txt<<endl;



}
I.seekg(0,ios::end);
I.close();
textcolor(BLUE);
cprintf("\n\nEND\nPress any to MENU\n");
getch();
menu();

}

//snehl sms ovrr

//mani calendar and odd

int Md(char m[3],int y)
{
if(strcmpi(m,"jan")==0||strcmpi(m,"mar")==0||strcmpi(m,"may")==0||strcmpi(m,"jul")==0||strcmpi(m,"aug")==0||strcmpi(m,"oct")==0||strcmpi(m,"dec")==0)
return 31;
else if(strcmpi(m,"apr")==0||strcmpi(m,"jun")==0||strcmpi(m,"sep")==0||strcmpi(m,"nov")==0)
return 30;
else if(strcmpi(m,"feb")==0&&(y%4==0&&y%100!=0||y%400==0))
return 29;
else return 28;
}
void mcheck(char m[3])
{label:
 if(strcmpi(m,"jan")!=0&&strcmpi(m,"mar")!=0&&strcmpi(m,"may")!=0&&strcmpi(m,"jul")!=0&&strcmpi(m,"aug")!=0&&strcmpi(m,"oct")!=0&&strcmpi(m,"dec")!=0&&strcmpi(m,"apr")!=0&&strcmpi(m,"jun")!=0&&strcmpi(m,"sep")!=0&&strcmpi(m,"nov")!=0&&strcmpi(m,"feb")!=0)
 {cout<<"Sorry, please enter 3 letters of a valid month\n";
 gets(m);}
 if(strcmpi(m,"jan")!=0&&strcmpi(m,"mar")!=0&&strcmpi(m,"may")!=0&&strcmpi(m,"jul")!=0&&strcmpi(m,"aug")!=0&&strcmpi(m,"oct")!=0&&strcmpi(m,"dec")!=0&&strcmpi(m,"apr")!=0&&strcmpi(m,"jun")!=0&&strcmpi(m,"sep")!=0&&strcmpi(m,"nov")!=0&&strcmpi(m,"feb")!=0)
 goto label;
}
void ycheck(int& y)
{labels:
 if(y<=0)
 {cout<<"Sorry,enter a positive year\n";
 cin>>y;}
 if(y<=0)
 goto labels;
}
int fday(char m[3],int y)
{int k,p,q,l;
k=y-1;
p=(k/4)-(k/100)+(k/400);
q=(k+p)%7;
if(y%4==0&&y%100!=0||y%400==0)
{if(strcmpi(m,"jan")==0)
l=0;
else if(strcmpi(m,"feb")==0)
l=3;
else if(strcmpi(m,"mar")==0)
l=4;
else if(strcmpi(m,"apr")==0)
l=0;
else if(strcmpi(m,"may")==0)
l=2;
else if(strcmpi(m,"jun")==0)
l=5;
else if(strcmpi(m,"jul")==0)
l=0;
else if(strcmpi(m,"aug")==0)
l=3;
else if(strcmpi(m,"sep")==0)
l=6;
else if(strcmpi(m,"oct")==0)
l=1;
else if(strcmpi(m,"nov")==0)
l=4;
else if(strcmpi(m,"dec")==0)
l=6;
}
else
{ if(strcmpi(m,"jan")==0)
l=0;
else if(strcmpi(m,"feb")==0)
l=3;
else if(strcmpi(m,"mar")==0)
l=3;
else if(strcmpi(m,"apr")==0)
l=6;
else if(strcmpi(m,"may")==0)
l=1;
else if(strcmpi(m,"jun")==0)
l=4;
else if(strcmpi(m,"jul")==0)
l=6;
else if(strcmpi(m,"aug")==0)
l=2;
else if(strcmpi(m,"sep")==0)
l=5;
else if(strcmpi(m,"oct")==0)
l=0;
else if(strcmpi(m,"nov")==0)
l=3;
else if(strcmpi(m,"dec")==0)
l=5;
}
return (l+q)%7;
}



void calendar()
{int a,b,c,year,d[6][7],i,j;char month[3],ans;
do
{clrscr();
cout<<"\t\t\tCALENDAR\n_________________________________________________________________\n";
cout<<"\nEnter the first three letters of the month\n";
gets(month);
mcheck(month);
cout<<"\nEnter the year(yyyy)\n";
cin>>year;
ycheck(year);
cout<<"\n\t\t\t"<<month<<"  "<<year<<endl;
cout<<"\n MON TUE WED THU FRI SAT SUN\n";
a=fday(month,year);
for(i=0;i<6;i++)
for(j=0;j<7;j++)
d[i][j]=0;
d[0][a]=1;
b=2;c=Md(month, year);
for(i=0;i<6;i++)
{for(j=0;j<7;j++)
{
if(i!=0||j>a)
{d[i][j]=b;
b++;}
if(b>c)
break;
}}
for(i=0;i<6;i++)
{for(j=0;j<7;j++)
{if(d[i][j]==0)
cout<<"    ";
else if(d[i][j]/10==0)
cout<<"   "<<d[i][j];
else if(d[i][j]<=c)

cout<<"  "<<d[i][j];
}
cout<<endl;
}
cout<<"do you wish to continue?(y/n)\n";
cin>>ans;
}while(ans=='y'||ans=='Y');
clrscr();
menu();
}


//calendar ends

//odd or even here odd()


void odd()
{
char ch;char ch2;
clrscr();
cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\n\n\n \t\t\tODD OR EVEN\n\n\n\t\t\t\t\t\tPress a key";
getch();
clrscr();
int a,b,c,d,k,i,score,cscore;char ans;
do
{
label3:
clrscr();
cout<<"\n\n\t\t1.Play\n\t\t2.Instructions\n\n\n\t\tEnter your choice: ";
cin>>ch2;
if(ch2!='1'&&ch2!='2')
{cout<<"Sorry, Invalid choice.Please wait.\n";
delay(3000);
goto label3;}
else if(ch2=='2')
{
clrscr();
cout<<"\n\t\t\tINSTRUCTIONS\n";
cout<<"\n\n1.you may enter any number from 0 to 6.\n\n2.Numbers from 1 to 6 directly add to your score but putting a 0 \n  will add the bowler's number to your score.\n\n3.You are out when your and the bowlers numbers are the same\n";
cout<<"\n\n\n\t\t\tpress a key to continue";getch();
i=0;cout<<"\n\t\t\t";
while(i<7)
{cout<<"-";delay(500);i++;}
}
else{
do
{
clrscr();
cout<<"Enter your choice for the toss:\n1.Head(H) \n2.Tail(T):\n";
cin>>ch;
}while(!(ch=='1'||ch=='2'));
cout<<"tossing\n";
i=0;
while(i<7)
{cout<<"-";delay(500);i++;}
randomize();
k=random(2)+'1';
clrscr();
if(k==ch)
{cout<<"you win the toss\n";
label2:
cout<<"you choose to ?:\n1.BAT\n2.BOWL\n";
cin>>b;
if(b==1) cout<<"You've chosen to bat first\n";
else if(b==2) cout<<"You've chosen to bowl first\n";
else{ cout<<"invalid choice. Please wait";delay(1000);clrscr();goto label2;}
}
else
{cout<<"You lost the toss\n";
 b=random(2)+1;
 if(b==1)
 cout<<"computer chooses to bowl first\n";
 else cout<<"computer chooses to bat first\n";
}
if( b==1)
{score=0;delay(3000);clrscr();cout<<"First innings(your batting)\n";
do
{
cout<<"\nEnter your no:";
cin>>d;
cout<<"\t\tcomp.no:";
c=random(7);
cout<<c;
if((d%7)!=0&&(d%7)!=c)
score=(d%7)+score;
if((d%7)==0&&(d%7)!=c)
score=c+score;
cout<<"\t\tscore:"<<score<<endl;
}while(c!=(d%7));
cout<<"\n\n\t\t\tyou are out";
cout<<"\n\n\nYour total score is:"<<score<<"\n\n\nPlease wait till the 2nd innings begins";
i=0;
while(i<7)
{cout<<"-";delay(500);i++;}
clrscr();
cout<<"Second innings(Your bowling)  ";
cscore=0;
cout<<score-cscore<<" runs to defend\n";
do
{
cout<<"\nEnter your no:";
cin>>d;
cout<<"\t\tcomp.no:";
c=random(7);
cout<<c;
if(c!=0&&(d%7)!=c)
cscore=c+cscore;
if(c==0&&(d%7)!=c)
cscore=(d%7)+cscore;
cout<<"\t\tscore:"<<cscore<<endl;
if(cscore>score)
{cout<<"\n\n\n\t\t\tcomp wins !!!!";
delay(4000);
break;}
}while(c!=(d%7));
if(cscore==score)
cout<<"\n\n\t\t\tDraw !!!!";
if(cscore<score)
cout<<"\n\n\t\t\tYou win by a margin of "<<score-cscore<<"!!!!";
delay(4000);
}
else
{
delay(3000);clrscr();
cout<<"First innings (Your bowling)\n\n";
cscore=0;
do
{
cout<<"Enter your no:";
cin>>d;
cout<<"\t\tcomp.no:";
c=random(7);
cout<<c;
if(c!=0&&(d%7)!=c)
cscore=c+cscore;
if(c==0&&(d%7)!=c)
cscore=(d%7)+cscore;
cout<<"\t\tscore:"<<cscore<<endl;
}while(c!=(d%7));
cout<<"\n\n\n\t\t\tcomp is out\n\n\n\t\t\ttotal score:"<<cscore;
cout<<"\n\n\nPlease wait till the 2nd innings begin\n";
i=0;
while(i<7)
{cout<<"-";delay(500);i++;}
clrscr();
score=0;
cout<<"Second innings(Your batting)  "<<cscore+1<<"runs to win\n\n";
do
{
cout<<"\nEnter your no:";
cin>>d;
cout<<"\t\tcomp.no:";
c=random(7);
cout<<c;
if((d%7)!=0&&(d%7)!=c)
score=(d%7)+score;
if((d%7)==0&&(d%7)!=c)
score=c+score;
cout<<"\t\tscore:"<<score;
if(score>cscore)
{cout<<"\n\n\n\t\t\tyou win!!!!";
i=0;
while(i<7)
{cout<<"-";delay(500);i++;}
break;}
}while(c!=(d%7));
if(cscore==score)
{cout<<"\n\n\n\t\t\tDraw!!!!";delay(4000);}
if(score<cscore)
{cout<<"\n\n\n\t\t\tYou lost by a margin of "<<cscore-score<<"!!!!";delay(3000);}
}}clrscr();
cout<<"Do you wish to play ";
cin>>ans;
}while(ans=='y'||ans=='Y');
clrscr();
menu();
}


// odd ends

//calculator

int factor(int o)
{int b=1;
for(int i=1;i<=o;i++)
{
b*=i;
}

return b;
}


void calculator()
{clrscr();
char g;
int ch,a,b;
double c;
float h,l,u;
char k;
do
{
clrscr();
textcolor(3);
gotoxy(23,0);
cout<<"\t\t\t      CALCULATOR {14 FUNCTIONS}\n\t\t\t|------------------------------------|\n\n\n";
textcolor(15);
cout<<"\t\t\t1.ADD\t2.SBTCT\t3.MULTIPLY\n\n\t\t\t4.DVDE\t5.POWER\t6.REMAINDER\n\n\t\t\t7.LOG\t8.SIN\t9.COS\n\n\t\t\t10.TAN\t11.EXP\t12.FACTORIAL\n\n\t\t\t13.COMB\t14.PRMT\t15.EXIT\n";
cout<<"\n\nENTER YOUR CHOICE\n";
cin>>ch;
switch(ch)
{
case 1:
cout<<"enter two numbers to be added\n";
cin>>a>>b;
c=a+b;
cout<<"the sum is "<<c<<endl;
break;

case 2:cout<<"enter two numbers to be subtracted\n";

cin>>a>>b;
c=a-b;
cout<<"the difference is "<<c<<endl;
break;
case 3:
cout<<"enter the two numbers to be multiplied\n";
cin>>a>>b;
c=a*b;
cout<<"the product is "<<c<<endl;
break;
case 4:
cout<<"enter the two numbers a and b (for(a/b))\n";
cin>>h>>l;
if(l==0)
{cout<<"math error try again\n";
cin>>h>>l;
u=float(h/l); }
else
u=float(h/l);
cout<<"the quotient is "<<u<<endl;
break;
case 5:
cout<<"enter the base followed by exponent\n";
cin>>a>>b;
c=pow(a,b);
cout<<"the result is "<<c<<endl;
break;
case 6:
cout<<"enter the dividend followed by divisor\n";
cin>>a>>b;
c=a%b;
cout<<"the remainder is "<<c<<endl;
break;
case 7:
cout<<"enter the number\n";
cin>>a;
if(a<=0)
cout<<"math eror try again\n";
else
h=log(a);
cout<<"the logarithm is "<<h<<endl;
break;
case 8:
cout<<"enter the angle in radians\n";
cin>>h;
l=sin(h);
cout<<"the sine is "<<l<<endl;
break;
case 9:
cout<<"enter the angle in radians\n";
cin>>h;
l=cos(h);
cout<<"the cosine is "<<l<<endl;


break;
case 10:

cout<<"enter the angle in radians\n";
cin>>h;
l=tan(h);
cout<<"the tangent is "<<l<<endl;

break;
case 11:
cout<<"enter the exponent\n";
cin>>h;
l=exp(h);
cout<<"the antilog is "<<l<<endl;
break;
case 12:
b=1;
cout<<"enter the number\n";
cin>>a;
if(a==0)
{
cout<<"the factorial is 1"<<endl;
}
else
{
for(int i=1;i<=a;i++)
{
b*=i;
}
cout<<"the factorial is "<<b<<endl;
}
break;
case 13:
cout<<"enter the two numbers a,b (for aCb)\n";
cin>>a>>b;
if(b>a)
{
cout<<"math error enter numbers again\n";
cin>>a>>b;
}
if(b==a)
{
cout<<"the combination is 1"<<endl;
}
else
{
int q,w,z,x,s,t;
x=a-b;

q=factor(a);

w=factor(b);

z=factor(x);

t=w*z;
s=q/t;
cout<<"the combination is "<<s<<endl;
}
break;
case 14:
cout<<"enter the numbers a,b (for aPb)\n";
cin>>a>>b;
if(b>a)
{


cout<<"math error enter numbers again\n";
cin>>a>>b;
}
if(b==a)
{


cout<<"the permutation is "<<factor(a)<<endl;
}
else
{


int q,w,z,x,s,t;
x=a-b;
q=factor(a);
z=factor(x);
s=q/z;
cout<<"the permutation is "<<s<<endl;
}
break;

case 15:
cout<<"exiting...";
getch();
menu();

break;
default:
cout<<"enter a valid choice\n";


}
cout<<"do you wish to continue(y/n)\n";
cin>>k;
}
while(k=='y'||k=='Y');
clrscr();
menu();

}

//clcultor ends


//tic tac toe


int check(char h[3][3])
{int p;
	 if(h[0][0]==h[0][1]&&h[0][0]==h[0][2]||h[1][0]==h[1][1]&&h[1][0]==h[1][2]||h[2][0]==h[2][1]&&h[2][0]==h[2][2]||h[0][0]==h[1][0]&&h[0][0]==h[2][0]||h[0][1]==h[1][1]&&h[0][1]==h[2][1]||h[0][2]==h[1][2]&&h[0][2]==h[2][2]||h[0][0]==h[1][1]&&h[0][0]==h[2][2]||h[0][2]==h[1][1]&&h[0][2]==h[2][0])//longest if

p=0;
else
p=1;
return p;

}

void tic()
{
clrscr();
char ar[3][3],chk[3][3];
for(int y=0;y<3;y++)
{
for(int g=0;g<3;g++)
{
chk[y][g]='0';
}}
int a;
char d;
int D=0;
strcpy(tmsg,"INSTRUCTIONS\n\nThe game is played on the numeric keypad(right)\n Press a number to put your mark in the position \nof the key \nIf there is a Draw press (0)\nEnter your mark->");
    do
     {
      cout<<tmsg[D++];
      if(tmsg[D]==' ')
      delay(300);
     }while(tmsg[D]!='\0');
d=getch();
char c='0';
do
{
switch(d)
{
case '1':
if(chk[2][0]=='k')
{
break;
}
gotoxy(33,17);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[2][0]=c;
chk[2][0]='k';
break;
case '2':
if(chk[2][1]=='k')
{
break;
}
gotoxy(35,17);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[2][1]=c;
chk[2][1]='k';
break;
case '3':
if(chk[2][2]=='k')
{
break;
}
gotoxy(37,17);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[2][2]=c;
chk[2][2]='k';
break;
case '4':
if(chk[1][0]=='k')
{
break;
}
gotoxy(33,15);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[1][0]=c;
chk[1][0]='k';
break;
case '5':
if(chk[1][1]=='k')
{
break;
}
gotoxy(35,15);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[1][1]=c;
chk[1][1]='k';
break;
case '6':
if(chk[1][2]=='k')
{
break;
}
gotoxy(37,15);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[1][2]=c;
chk[1][2]='k';
break;
case '7':
if(chk[0][0]=='k')
{
break;
}
gotoxy(33,13);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[0][0]=c;
chk[0][0]='k';
break;
case '8':
if(chk[0][1]=='k')
{
break;
}
gotoxy(35,13);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[0][1]=c;
chk[0][1]='k';
break;
case '9':
if(chk[0][2]=='k')
{
break;
}
gotoxy(37,13);
cprintf("%c",c);
if(c=='0'){c='1';}else c='0';
ar[0][2]=c;
chk[0][2]='k';
break;
default :
break;
}
 int u=check(ar);
 if(u==0)
 {
 cout<<"\nWe have a Winner!!!!\n";
 getch();
 clrscr();
 menu();
 }

d=getch();
}while(d!='0');
cout<<"\n\n";
cout<<"DRAW...";
delay(3000);
clrscr();

menu();
}


void homescreen()
 {
 for(int kkk=0;kkk<20;kkk++) // for homescreen exception handling
 {
 while(!kbhit())
{
 delay(500);
 clrscr();
 struct tm *ptr;
 time_t It;
 It=time(NULL);
 ptr=localtime(&It);
 gotoxy(26,13);
  cprintf(asctime(ptr));
 gotoxy(20,20);
cprintf("Menu(m)");
 gotoxy(45,20);
cprintf("Power OFF(p)");

}
clrscr();
ans3=getch();
clrscr();
if(ans3=='p')
{clrscr();
cout<<endl<<"Sure? (y)";
cH=getch();
if(cH=='y'||cH=='Y')
{
  for(int gig=5;gig>-1;gig--)
 {  delay(1000);clrscr();

  cout<<"Shutting down in "<<gig<<" seconds\n\n";

  cout<<"Press any to go back";

  if(kbhit())
   homescreen();
 }
 exit(0);
}

  }
else if(ans3=='m')
menu();
}
}





//main()




void main()
{       clrscr();
	textcolor(3);
 cout<<"\n\n\t\t\n\n\n\n\nWELCOME";
 delay(2000);
 do
 {
  clrscr();
  u_flag=0;
  ans1='*';
  textcolor(GREEN);
  cout<<"Enter phone number:";
  gets(u.user_num);
  ifstream Fi;
  Fi.open("userlist",ios::ate|ios::binary);
  Fi.seekg(0);
  while(Fi)
  {
   Fi.read((char*)&test,sizeof(user));
   if(strcmpi(test.user_num,u.user_num)==0)
    u_flag++;
  }
  Fi.close();
  if(u_flag==0)//new user
  {
   do
   {
    clrscr();
    cout<<"Are you creating a new Phone ID?(y/n)\n";
    ans1=getch();
    if(ans1=='y'||ans1=='Y')
    {
     cout<<"Hello,\nWhat's your nickname?\n";
     gets(u.user_name);
     strupr(u.user_name);
     delay(2000);
     clrscr();

     //write name & num to "userlist"
    ofstream Fo;
    Fo.open("userlist",ios::ate|ios::binary);
    Fo.write((char*)&u,sizeof(user));
    Fo.close();
   // new   message (word printing)
    cout<<endl;
    char mesgge[300];int II=0;
    strcpy(mesgge,"Hello \n Introducing our new Phone try out the cool features\n just tap the letter next to app to access it!\n Now going to Homescreen\n\n ");
    do
     {
      cout<<mesgge[II++];
      if(mesgge[II]==' ')
      delay(300);
     }while(mesgge[II]!='\0');
    delay(200);
    gotoxy(0,20);
    puts(u.user_name);
    gotoxy(0,21);
    puts(u.user_num);
    delay(4000);
    u_flag++;
  }//if
   //new phone creation ends
   if(ans1=='n'||ans1=='N')
    break;//gets  out
  }while(!(ans1=='n'||ans1=='y'||ans1=='N'||ans1=='Y'));
 }
 }while(u_flag==0);

  ifstream N;
  N.open("userlist",ios::in);

  while(N.read((char*)&U,sizeof(user)))
  {

   if(strcmpi(U.user_num,u.user_num)==0)
    strcpy(u.user_name,U.user_name);
   }
   N.close();

 homescreen();
}








