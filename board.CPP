#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cmath>
#include<iomanip>
#include<string.h>
#include<process.h>
#include<ctype.h>
#include<windows.h>
#include<process.h>
using namespace std;
const unsigned char BLACK = 219;
 
BOOL gotoxy(const WORD x, const WORD y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
enum colour { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

struct setcolour
{
   colour _c;
   HANDLE _console_handle;


       setcolour(colour c, HANDLE console_handle)
           : _c(c), _console_handle(0)
       { 
           _console_handle = console_handle;
       }
};

HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);


basic_ostream<char> &operator<<(basic_ostream<char> &s, const setcolour &ref)
{
    SetConsoleTextAttribute(ref._console_handle, ref._c);
    return s;
}

class Player
	{
	public:
	int i,j;
	char temp,a;
	void P_1(char b[50][50]);
	void P_2(char b[50][50]);
	void move(int &,int &);
	int check(char b[50][50],char p,int i,int j) ;
	}obj;

	void board(char b[50][50]);
	void view_board(char b[50][50],int k);
	int mate(char [50][50]);
char dot(int ,int);


int main()
{
system("cls");

char b[50][50];
	
board(b);
while(mate(b)!=1)
{
view_board(b,1);
obj.P_1(b);
view_board(b,2);
obj.P_2(b);
}

return 0;
}


	int cqW(char b[50][50],int i,int j)
		{
		if(b[i][j]=='P'||b[i][j]=='Q'||b[i][j]=='K'||b[i][j]=='R'||b[i][j]=='B')
		 return 1;
		 else return 0;
		}
	int cqw(char b[50][50],int i,int j)
		{
		if(b[i][j]=='p'||b[i][j]=='q'||b[i][j]=='k'||b[i][j]=='r'||b[i][j]=='b')
		 return 1;
		 else return 0;
		}
		int mate(char b[50][50])
		{
		int k=0,i,j;
		for(i=2;i<24;i+=3)
		for(j=3;j<45;j+=6)
			if((b[i][j]=='K'&&b[i][j+1]==' ')||(b[i][j]=='k'&&b[i][j+1]==' '))
			k++;
		     if(k==1)
		     return 1;
		     else return 0;
		}

void view_board( char b[50][50],int k)
{


	gotoxy(4,3);
	cout <<setcolour(BLUE, chandle) <<"PLAYER 1";
	gotoxy(68,3);
	cout << setcolour(GREEN, chandle) <<"PLAYER 2";

	if(k==1)
	{
	gotoxy(70,6);
	cout<<"    ";
	gotoxy(6,6);
	cout << setcolour(YELLOW, chandle) << "TURN";
	}
	else{
	gotoxy(70,6);
	cout << setcolour(YELLOW, chandle) << "TURN";
gotoxy(6,6);
cout<<"    ";}
int i,j;
for(i=1;i<25;i++)
	{
	gotoxy(16,i+1);
	for(j=0;j<49;j++)
	if(b[i][j]=='R'){cout << setcolour(BLUE, chandle) <<"R";}
	else if(b[i][j]=='K'){cout << setcolour(BLUE, chandle) << "K";}
	else if(b[i][j]=='T'){cout << setcolour(BLUE, chandle) << "T";}
	else if(b[i][j]=='Q'){cout << setcolour(BLUE, chandle) << "Q";}
	else if(b[i][j]=='P'){cout << setcolour(BLUE, chandle) << "P";}
	else if(b[i][j]=='B'){cout << setcolour(BLUE, chandle) << "B";}
	else if(b[i][j]=='k'){cout << setcolour(GREEN, chandle) << "K";}
	else if(b[i][j]=='r'){cout << setcolour(GREEN, chandle) << "R";}
	else if(b[i][j]=='q'){cout << setcolour(GREEN, chandle) << "Q";}
	else if(b[i][j]=='t'){cout << setcolour(GREEN, chandle) << "T";}
	else if(b[i][j]=='b'){cout << setcolour(GREEN, chandle) << "B";}
	else if(b[i][j]=='p'){cout << setcolour(GREEN, chandle) << "P";}
	else {cout << setcolour(WHITE, chandle) <<b[i][j];}

	cout<<endl;
	}

}

void board(char b[50][50])
{
int i,j;
		for(i=0;i<26;i++)
			for(j=0;j<49;j++)
			  b[i][j]=' ';

		for(i=0;i<26;i++)
		  {

		     b[i][0]='|';
		     b[i][49]='|';
		   for(j=0;j<49;j+=6)
		      b[i][j]='|';
		   }

		for(i=0;i<26;i+=3)
			for(j=1;j<48;j++)
			   {

			     if(j%6==0&&i!=0)
			     continue;
			     else
			     b[i][j]='_';
			   }

		for(i=2;i<24;i+=3)
			for(j=3;j<48;j+=6)
			b[i][j]=dot(i,j);

		for(j=3;j<49;j+=6)
		{
			b[5][j]='P';
			b[20][j]='p';
		}

		b[2][3]='R';b[2][9]='K';b[2][10]='T';b[2][15]='B';
		b[2][21]='K';b[2][27]='Q';b[2][33]='B';b[2][39]='K';
		b[2][40]='T';b[2][45]='R';
		b[23][3]='r';b[23][9]='k';b[23][10]='t';b[23][15]='b';
		b[23][21]='k';b[23][27]='q';b[23][33]='b';b[23][39]='k';
		b[23][40]='t';b[23][45]='r';

	b[0][0]='_';
	b[0][49]='_';
}
char dot(int i,int j)
	{
	if(i%2==0)
		{
		if((j+1)%4==0)
		return ' ';
		else return '.';
		}
	else

		{
		if((j+1)%4==0)
		return '.';
		else
		return ' ';
		}
	}

	void Player :: move(int &i,int &j)
		{
			char a;
			gotoxy(j+16,i+1);
			do
			{
			a=getch();
			if(a==27)
			exit(0);
			 if(a==119||a==87||a==72)
			 {      if(i-3>=2)
				 i-=3;


			 }
			 else if(a==115||a==83||a==80)

			 {      if(i+3<=23)
				i+=3;

			 }
			 else if(a==97||a==65||a==75)
			 {
			       if(j-6>=3)
				j-=6;
			 }
			 else if(a==100||a==68||a==77)
			 {       if(j+6<=45)
			 j+=6;
			 }
			 gotoxy(j+16,i+1)   ;
			 }while(a!=13);
		  }
void Player :: P_1(char b[50][50])
	{
	   int L=0,R=0;
	   top:
	   i=11,j=21;
	   move(i,j);
	   gotoxy(2,10);
	   cout<<"            ";
	   gotoxy(3,11);
	   cout<<"         ";
	   gotoxy(2,15);
	   cout<<"             ";
	   gotoxy(4,17);
	   cout<<"        ";
	if(b[i][j]==' '||b[i][j]=='.'||cqw(b,i,j)==1)
	{

	gotoxy(4,10);
	cout << setcolour(RED, chandle) << "INVALID ";
	gotoxy(3,11);
	cout << setcolour(RED, chandle) << "SELECTION";
	 goto top;
	}
	else
	{
	  char temp,temp1;

	  if(b[i][j]=='P')
		 {int m=1,l,k;
		k=i,l=j;
		move(i,j);
		if(k==5)m=2;
		if(i>k&&((i-k)/3<=m))
		{
		 if((j==l&&b[i][j]==dot(i,j))&&(m==1||(m==2&&b[k+3][l]==dot(k+3,l))))
		  {     temp=b[k][l];
			b[k][l]=dot(k,l);
			temp1=b[i][j];
			if(b[i][j]=='k')
			b[i][j+1]=' ';
			if(i==23)
			b[i][j]='Q';
			else
			b[i][j]='P';

			if(check(b,'K',0,0)!=0)
			{
			
			b[k][l]=temp;
			b[i][j]=temp1;
			if(temp1=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}

		  }
		  else if((abs(j-l)/6==1)&&(abs(i-k)/3==1)&&(cqw(b,i,j)==1))
		  {     temp=b[k][l];
			b[k][l]=dot(k,l);
			temp1=b[i][j];
			if(b[i][j]=='k')
			b[i][j+1]=' ';
			if(i==23)
			b[i][j]='Q';
			else
			b[i][j]='P';
				if(check(b,'K',0,0)!=0)
			{
			b[k][l]=temp;
			b[i][j]=temp1;
			if(temp=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}


		  }
		  else goto bot;
		}
		else
		{
			bot:
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			goto top;
		}

	    }//p
	else if(b[i][j]== 'K')
		 {
		       int k,l;
		       k=i,l=j;
		       move(i,j);
		    if(b[k][l+1]=='T')
			   {
			   if((((abs(i-k))/3==2&&(abs(j-l))/6==1)||((abs(i-k))/3==1&&(abs(j-l))/6==2))&&(b[i][j]==dot(i,j)||cqw(b,i,j)==1))
			   {
			   temp=b[k][l];
			   temp1=b[i][j];
			   b[i][j]='K';
			   b[i][j+1]='T';
			   b[k][l]=dot(k,l);
			   b[k][l+1]=' ';

		    if(check(b,'K',0,0)!=0)
			{
			b[k][l]=temp;
			b[i][j+1]=' ';
			b[k][l+1]='T';
			b[i][j]=temp1;
			if(temp=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}

			   }
			   else
			   {
			   gotoxy(2,10);
			   cout << setcolour(RED, chandle) << "INVALID MOVE";

				goto top;
			    }

			}//kt
			else     //k
			{
				if(((abs(i-k)/3==1&&l==j)||(abs(j-l)/6==1&&k==i)||(abs(j-l)/6==1&&abs(i-k)/3==1))&&(b[i][j]==dot(i,j)||cqw(b,i,j)))
				{
				temp=b[k][l];
				temp1=b[i][j];
				if(b[i][j]=='k')
				b[i][j+1]=' ';
				 b[i][j]='K';
				 b[k][l]=dot(k,l);
					if(check(b,'K',0,0)!=0)
			{
			b[k][l]=temp;
			b[i][j]=temp1;
			if(temp=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}


				}
				else if(b[i][j]=='R')
				  {if(abs(l-j)/6==3&&L==0&&b[2][9]==dot(2,9)&&b[2][15]==dot(2,15))
				   {
				   b[2][3]='K';b[2][21]='R';
				   if(check(b,'P',2,3)!=0||check(b,'P',2,9)!=0||check(b,'P',2,15)!=0)

			{
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			b[2][3]='R';b[2][21]='K';
			goto top;
			} }
				   else if(abs(l-j)/6==4&&R==0&&b[2][27]==dot(2,27)&&b[2][33]==dot(2,33)&&b[2][39]==dot(2,39))
				  { b[2][45]='K';b[2][21]='R';
					   if(check(b,'P',2,45)!=0||check(b,'P',2,39)!=0||check(b,'P',2,33)!=0||check(b,'P',2,27)!=0)

			{
		gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			b[2][35]='R';b[2][21]='K';
			goto top;
			} }
				   else goto z;
				   }
				  else
				   {
				   z:
				 gotoxy(2,10);
				cout << setcolour(RED, chandle) << "INVALID MOVE";
					goto top;
				}

		       }
		   }//k
	else if(b[i][j]== 'R')
		 { int k,l,m,o=0;
		    k=i,l=j;
		    move(i,j);
		    if(j==l&&i!=k)
			{
			 if(i>k)
			 {
			 for(m=k+3;m<i;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			  else
			 if(i<k)
			 {
			 for(m=i+3;m<k;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			 }
		   else	 if(i==k&&j!=l)
			{
				if(j>l)
			 {
			 for(m=l+6;m<j;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			 else
			 if(j<l)
			 {
			 for(m=j+6;m<l;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			 }

			else goto v;
		    if((o==abs(i-k)/3&&j==l)||o==abs(j-l)/6&&k==i)
		    {
		    temp=b[k][l];
		    temp1=b[i][j];
		    if(b[i][j]=='k')
			b[i][j+1]=' ';
		    b[i][j]='R';
		    b[k][l]=dot(k,l);
				if(check(b,'K',0,0)!=0)
			{
			b[k][l]=temp;
			b[i][j]=temp1;
			if(temp=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}


		    if(L==0&&l==3&&k==2)
		    l++;
		    if(R==0&&j==45&&k==2)
		    R++;
		    }
		    else
		    {v:
		    gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
		    goto top;
		    }
		}//R
	else if(b[i][j]== 'B')
		{int k,l,o=0,m,q;
		k=i,l=j;
		move(i,j);
		if(abs(i-k)/3==abs(j-l)/6&&i!=k)
			{
			if(i<k&&j<l)
				{
				for(m=k-3,q=l-6;m>i,q>j;m-=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i<k&&j>l)
				{
				for(m=k-3,q=l+6;m>i,q<j;m-=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j<l)
				{ for(m=k+3,q=l-6;m<i,q>j;m+=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j>l)
				{
				for(m=k+3,q=l+6;m<i,q<j;m+=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
				 if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
				 o++;
			 if(o==abs(i-k)/3)
			 {
			 temp=b[k][l];
			 temp1=b[i][j];
			 if(b[i][j]=='k')
			 b[i][j+1]=' ';
			 b[k][l]=dot(k,l);
			 b[i][j]='B';
					if(check(b,'K',0,0)!=0)
			{
			b[k][l]=temp;
			b[i][j]=temp1;
			if(temp=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}



			 }
			else goto w;
		    }
		       else
		       {
			w:
			gotoxy(2,10);
		cout << setcolour(RED, chandle) << "INVALID MOVE";

			 goto top;
			 }
		   }//b
	else if(b[i][j]== 'Q' ) {
		      int k,l;
		       k=i,l=j;
		    move(i,j);
		    if((j==l&&i!=k)||(i==k&&j!=l))
		    { int m,o=0;
			if(j==l&&i!=k)
			{
			 if(i>k)
			 {
			 for(m=k+3;m<i;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			  else
			 if(i<k)
			 {
			 for(m=i+3;m<k;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			 }
		   else	 if(i==k&&j!=l)
			{
				if(j>l)
			 {
			 for(m=l+6;m<j;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			 else if(j<l)
			 {
			 for(m=j+6;m<l;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
			   o++;
			  }
			 }
		    if((o==abs(i-k)/3&&j==l)||o==abs(j-l)/6&&k==i)
		    goto c;
		    }
		   else if(abs(i-k)/3==abs(j-l)/6&&i!=k)
			{
			int m,o=0,q;
			if(i<k&&j<l)
				{
				for(m=k-3,q=l-6;m>i,q>j;m-=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i<k&&j>l)
				{
				for(m=k-3,q=l+6;m>i,q<j;m-=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j<l)
				{ for(m=k+3,q=l-6;m<i,q>j;m+=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j>l)
				{
				for(m=k+3,q=l+6;m<i,q<j;m+=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
				 if(b[i][j]==dot(i,j)||cqw(b,i,j)==1)
				 o++;
			 if(o==abs(i-k)/3)
			 goto c;
			else goto a;
		    }
		       else
		       {
			a:
			gotoxy(2,10);
		cout << setcolour(RED, chandle) << "INVALID MOVE";
			 goto top;
			 }
			 c:
			 temp=b[k][l];
			 temp1=b[i][j];
			if(b[i][j]=='k')
			 b[i][j+1]=' ';
			 b[i][j]='Q';
			 b[k][l]=dot(k,l);
			 if(check(b,'K',0,0)!=0)
			{
			b[k][l]=temp;
			b[i][j]=temp1;
			if(temp=='k')
			b[i][j+1]='t';
			gotoxy(2,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			gotoxy(2,15);
			cout << setcolour(RED, chandle) << "WILL PUT YOU ";
			gotoxy(4,17);
			cout << setcolour(RED, chandle) << "IN CHECK";
			goto top;
			}



		       }//q

      }                    //else

    }//p1
void Player :: P_2(char b[50][50])
      {
	   int L=0,R=0;

	   top:
	   i=14,j=21;
	   move(i,j);
	   gotoxy(66,10);
	   cout<<"            ";
	   gotoxy(68,11);
	   cout<<"         ";
	if(b[i][j]==' '||b[i][j]=='.'||cqW(b,i,j)==1)
	{
	gotoxy(69,10);
	cout << setcolour(RED, chandle) << "INVALID ";
	gotoxy(68,11);
	cout << setcolour(RED, chandle) << "SELECTION";
	 goto top;
	}
	else
	{
	   if(b[i][j]=='p') {int m=1,l,k;
		k=i,l=j;
		move(i,j);
		if(k==20)m=2;
		if(k>i&&((k-i)/3<=m))
		{
		 if((j==l&&b[i][j]==dot(i,j))&&(m==1||(m==2&&b[k-3][l]==dot(k-3,l))))
		  {
			b[k][l]=dot(k,l);
			if(b[i][j]=='K')
			b[i][j+1]=' ';
			if(i==2)
			b[i][j]='q';
			else
			b[i][j]='p';

		  }
		  else if((abs(j-l)/6==1)&&(abs(i-k)/3==1)&&(cqW(b,i,j)==1))
		  {
			b[k][l]=dot(k,l);
			if(b[i][j]=='K')
			b[i][j+1]=' ';
			if(i==2)
			b[i][j]='q';
			else
			b[i][j]='p';

		  }
		  else goto bot;
		}
		else
		{
			bot:
			gotoxy(66,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			goto top;
		}

	    }//p
	    else if(b[i][j]=='k') {
		       int k,l;
		       k=i,l=j;
		       move(i,j);
		    if(b[k][l+1]=='t')
			   {
			   if((((abs(i-k))/3==2&&(abs(j-l))/6==1)||((abs(i-k))/3==1&&(abs(j-l))/6==2))&&(b[i][j]==dot(i,j)||cqW(b,i,j)==1))
			   {
			   b[i][j]='k';
			   b[i][j+1]='t';
			   b[k][l]=dot(k,l);
			   b[k][l+1]=' ';

			   }
			   else
			   {
			gotoxy(66,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
				goto top;
			    }

			}//kt
			else     //k
			{
				if(((abs(i-k)/3==1&&l==j)||(abs(j-l)/6==1&&k==i)||(abs(j-l)/6==1&&abs(i-k)/3==1))&&(b[i][j]==dot(i,j)||cqW(b,i,j)))
				{
				if(b[i][j]=='K')
				 b[i][j+1]=' ';
				 b[i][j]='k';
				 b[k][l]=dot(k,l);
				}
				else if(b[i][j]=='r')
				  {if(abs(l-j)/6==3&&L==0&&b[23][9]==dot(23,9)&&b[23][15]==dot(23,15))
				   {
				   b[23][3]='k';b[23][21]='r'; }
				   else if(abs(l-j)/6==4&&R==0&&(b[23][27]==dot(23,27)&&b[23][33]==dot(23,33)&&b[23][39]==dot(23,39)))
				  { b[23][45]='k';b[23][21]='r'; }
				   else goto z;
				   }
				  else
				   {
				   z:
				gotoxy(66,10);
				cout << setcolour(RED, chandle) << "INVALID MOVE";
					goto top;
				}

		       }
		   }//k
      else if(b[i][j]=='r') { int k,l,m,o=0;
		    k=i,l=j;
		    move(i,j);
		    if(j==l&&i!=k)
			{
			 if(i>k)
			 {
			 for(m=k+3;m<i;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			  else
			 if(i<k)
			 {
			 for(m=i+3;m<k;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			 }
		   else	 if(i==k&&j!=l)
			{
				if(j>l)
			 {
			 for(m=l+6;m<j;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			 else
			 if(j<l)
			 {
			 for(m=j+6;m<l;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			 }

			else goto v;
		    if((o==abs(i-k)/3&&j==l)||o==abs(j-l)/6&&k==i)
		    {
		    if(b[i][j]=='K')
			b[i][j+1]=' ';
		    b[i][j]='r';
		    b[k][l]=dot(k,l);

		    if(L==0&&l==3&&k==23)
		    l++;
		    if(R==0&&j==45&&k==23)
		    R++;

		    }
		    else
		    {v:

			gotoxy(66,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
		    goto top;
		    }
		}//R
      else if(b[i][j]=='b')
		{int k,l,o=0,m,q;
		k=i,l=j;
		move(i,j);
		if(abs(i-k)/3==abs(j-l)/6&&i!=k)
			{
			if(i<k&&j<l)
				{
				for(m=k-3,q=l-6;m>i,q>j;m-=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i<k&&j>l)
				{
				for(m=k-3,q=l+6;m>i,q<j;m-=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j<l)
				{ for(m=k+3,q=l-6;m<i,q>j;m+=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j>l)
				{
				for(m=k+3,q=l+6;m<i,q<j;m+=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
				 if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
				 o++;
			 if(o==abs(i-k)/3)
			 {
			 if(b[i][j]=='K')
			 b[i][j+1]=' ';
			 b[k][l]=dot(k,l);
			 b[i][j]='b';


			 }
			else goto w;
		    }
		       else
		       {
			w:

			gotoxy(66,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			 goto top;
			 }
		   }//b
      else if(b[i][j]=='q') {
		      int k,l;
		       k=i,l=j;
		    move(i,j);
		    if((j==l&&i!=k)||(i==k&&j!=l))
		    { int m,o=0;
			if(j==l)
			{
			 if(i>k)
			 {
			 for(m=k+3;m<i;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			  else
			 if(i<k)
			 {
			 for(m=i+3;m<k;m+=3)
			  if(b[m][l]==dot(m,l))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			 }
		   else	 if(i==k&&j!=l)
			{
				if(j>l)
			 {
			 for(m=l+6;m<j;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			 else if(j<l)
			 {
			 for(m=j+6;m<l;m+=6)
			  if(b[k][m]==dot(k,m))
			   o++;
			  if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
			   o++;
			  }
			 }
		    if((o==abs(i-k)/3&&j==l)||o==abs(j-l)/6&&k==i)
		    goto c;
		    }
		   else if(abs(i-k)/3==abs(j-l)/6&&i!=k)
			{
			int m,o=0,q;
			if(i<k&&j<l)
				{
				for(m=k-3,q=l-6;m>i,q>j;m-=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i<k&&j>l)
				{
				for(m=k-3,q=l+6;m>i,q<j;m-=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j<l)
				{ for(m=k+3,q=l-6;m<i,q>j;m+=3,q-=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
			else if(i>k&&j>l)
				{
				for(m=k+3,q=l+6;m<i,q<j;m+=3,q+=6)
				 if(b[m][q]==dot(m,q))
				 o++;
				 }
				 if(b[i][j]==dot(i,j)||cqW(b,i,j)==1)
				 o++;
			 if(o==abs(i-k)/3)
			 goto c;
			else goto a;
		    }
		       else
		       {
			a:

			gotoxy(66,10);
			cout << setcolour(RED, chandle) << "INVALID MOVE";
			 goto top;
			 }
			 c:
			if(b[i][j]=='K')
			 b[i][j+1]=' ';
			 b[i][j]='q';
			 b[k][l]=dot(k,l);


		       }

       }//else
}     //p1


int Player ::  check(char b[50][50],char p,int i,int j)
{
int c=0,m,n,k,l,x=0;
if(p=='K'||p=='k')
for( m=2;m<24;m+=3)
for( n=3;n<46;n+=6)
if(b[m][n]==p&&b[m][n+1]==' ')
i=m,j=n;
if(isupper(p))
{
if(b[i+3][j-6]=='p'||b[i+3][j+6]=='p')
c++;
if(b[i+6][j-6]=='k'&&b[i+6][j-5]=='t')
c++;
if(b[i+3][j-12]=='k'&&b[i+3][j-11]=='t')
c++;
if(b[i-3][j-12]=='k'&&b[i-3][j-11]=='t')
c++;
if(b[i+6][j+6]=='k'&&b[i+6][j+7]=='t')
c++;
if(b[i-6][j+6]=='k'&&b[i-6][j+7]=='t')
c++;
if(b[i-6][j-6]=='k'&&b[i-6][j-5]=='t')
c++;
if(b[i+3][j+12]=='k'&&b[i+3][j+13]=='t')
c++;
if(b[i-3][j+12]=='k'&&b[i-3][j+13]=='t')
c++;
for(k=i-3;k>=2;k-=3)
for(l=j-6;l>=3;l-=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{
if(b[k][l]!=dot(k,l)&&(!(b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))))
x++;
else if (b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1) )
{c++;x++;}
}
if(x!=0)
break;
}
for( k=i+3;k<24;k+=3)
for( l=j+6;l<46;l+=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{
if(b[k][l]!=dot(k,l)&&!(b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1)))
x++;
else if (b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))
{c++;x++;}
}if(x!=0)
break;
}
for( k=i-3;k>=2;k-=3)
for( l=j+6;l<46;l+=6)
{
if(abs(i-k)/3==abs(j-l)/6)

{if(b[k][l]!=dot(k,l)&&!(b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)==1&&abs(j-l)==1)))
x++;
else if (b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))
{c++;x++;}
}if(x!=0)
break;
}
for( k=i+3;k<24;k+=3)
for( l=j-6;l>=3;l-=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{if(b[k][l]!=dot(k,l)&&!(b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1)))
x++;
else if (b[k][l]=='q'||b[k][l]=='b'||(b[k][l]=='k'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))
{c++;x++;}
}if(x!=0)
break;
}
for(k=i-3;k>1;k-=3)
{
if(b[k][j]!=dot(k,j)&&!(b[k][j]=='q'||b[k][j]=='r'||(b[k][j]=='k'&&b[k][j+1]==' '&&abs(i-k)/3==1)))

break;
else if (b[k][j]=='q'||b[k][j]=='r'||(b[k][j]=='k'&&b[k][j+1]==' '&&abs(i-k)/3==1))
{c++;break;}}

for(k=i+3;k<24;k+=3)
{
if(b[k][j]!=dot(k,j)&&!(b[k][j]=='q'||b[k][j]=='r'||(b[k][j]=='k'&&b[k][j+1]==' '&&abs(i-k)/3==1)))
break;
else if (b[k][j]=='q'||b[k][j]=='r'||(b[k][j]=='k'&&b[k][j+1]==' ')&&abs(i-k)/3==1)
{c++;break;}}

for(l=j-6;l>2;l-=6)
{
if(b[i][l]!=dot(i,l)&&!(b[i][l]=='q'||b[i][l]=='r'||(b[i][l]=='k'&&b[i][l+1]==' '&&abs(j-l)/6==1)))
break;
else if (b[i][l]=='q'||b[i][l]=='r'||(b[i][l]=='k'&&b[i][l+1]==' '&&abs(j-l)/6==1))
{c++;break;};
}
for(l=j+6;l<46;l+=6)
{
if(b[i][l]!=dot(i,l)&&!(b[i][l]=='q'||b[i][l]=='r'||(b[i][l]=='k'&&b[i][l+1]==' '&&abs(j-l)/6==1)))
break;
else if (b[i][l]=='q'||b[i][l]=='r'||(b[i][l]=='k'&&b[i][l+1]==' '&&abs(j-l)/6==1))
{c++;break;};
}
}
else
{
if(b[i-3][j-6]=='P'||b[i-3][j+6]=='P')
c++;
if(b[i+6][j-6]=='K'&&b[i+6][j-5]=='T')
c++;
if(b[i+3][j-12]=='K'&&b[i+3][j-11]=='T')
c++;
if(b[i-3][j-12]=='K'&&b[i-3][j-11]=='T')
c++;
if(b[i+6][j+6]=='K'&&b[i+6][j+7]=='T')
c++;
if(b[i-6][j+6]=='K'&&b[i-6][j+7]=='T')
c++;
if(b[i-6][j-6]=='K'&&b[i-6][j-5]=='T')
c++;
if(b[i+3][j+12]=='K'&&b[i+3][j+13]=='T')
c++;
if(b[i-3][j+12]=='K'&&b[i-3][j+13]=='T')
c++;
for( k=i-3;k>=2;k-=3)
for( l=j-6;l>=3;l-=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{
if(b[k][l]!=dot(k,l)&&(!(b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1)))
)
x++;
else if (b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1) )
{c++;x++;}
}if(x!=0)
break;
}
for( k=i+3;k<24;k+=3)
for( l=j+6;l<46;l+=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{if(b[k][l]!=dot(k,l)&&!(b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1)))
x++;
else if (b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))
{c++;x++;};
}if(x!=0)
break;
}for( k=i-3;k>=2;k-=3)
for( l=j+6;l<46;l+=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{if(b[k][l]!=dot(k,l)&&!(b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1)))
x++;
else if (b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))
{c++;x++;}
}if(x!=0)
break;
}
for( k=i+3;k<24;k+=3)
for( l=j-6;l>=3;l-=6)
{
if(abs(i-k)/3==abs(j-l)/6)
{if(b[k][l]!=dot(k,l)&&!(b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1)))
x++;
else if (b[k][l]=='Q'||b[k][l]=='B'||(b[k][l]=='K'&&b[k][l+1]==' '&&abs(i-k)/3==1&&abs(j-l)/6==1))
{c++;x++;}
}if(x!=0)
break;
}
for(k=i-3;k>1;k-=3)
{
if(b[k][j]!=dot(k,j)&&(!(b[k][j]=='Q'||b[k][j]=='R'||(b[k][j]=='K'&&b[k][j+1]==' '&&abs(i-k)/3==1))))
break;
else if (b[k][j]=='Q'||b[k][j]=='R'||(b[k][j]=='K'&&b[k][j+1]==' '&&abs(i-k)/3==1))
{c++;break;}
}

for(k=i+3;k<24;k+=3)
{

if(b[k][j]!=dot(k,j)&&(!(b[k][j]=='Q'||b[k][j]=='R'||(b[k][j]=='K'&&b[k][j+1]==' '&&abs(i-k)/3==1))))
break;
else if (b[k][j]=='Q'||b[k][j]=='R'||(b[k][j]=='K'&&b[k][j+1]==' '&&abs(i-k)/3==1))
{c++;break;}}

for(l=j-6;l<46;l-=6)
{
if(b[i][l]!=dot(i,l)&&!(b[i][l]=='Q'||b[i][l]=='R'||(b[i][l]=='K'&&b[i][l+1]==' '&&abs(j-l)/6==1)))
break;
else if (b[i][l]=='Q'||b[i][l]=='R'||(b[i][l]=='K'&&b[i][l+1]==' '&&abs(j-l)/6==1))
{c++;break;}
}
for(l=j+6;l<46;l+=6)
{
if(b[i][l]!=dot(i,l)&&!(b[i][l]=='Q'||b[i][l]=='R'||(b[i][l]=='K'&&b[i][l+1]==' '&&abs(j-l)/6==1)))
break;
else if (b[i][l]=='Q'||b[i][l]=='R'||(b[i][l]=='K'&&b[i][l+1]==' '&&abs(j-l)/6==1))
{c++;break;}
}

}






return c;

}