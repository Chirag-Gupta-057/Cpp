#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
void cursor1(int r,char *s)
{
	window(2,2,79,24);
	window(11,r+1,27,r+1);
	textbackground(GREEN);
	clrscr();
	gotoxy(11,r+1);
	cout<<s;
}
void nocursor1(int r,char *s)
{
	window(2,2,79,24);
	window(11,r+1,27,r+1);
	textbackground(BLACK);
	clrscr();
	gotoxy(11,r+1);
	cout<<s;
}
void cursor2(int r,char *s)
{
	window(2,2,79,24);
	window(51,r+1,67,r+1);
	textbackground(MAGENTA);
	clrscr();
	gotoxy(51,r+1);
	cout<<s;
}
void nocursor2(int r,char *s)
{
	window(2,2,79,24);
	window(51,r+1,67,r+1);
	textbackground(BLACK);
	clrscr();
	gotoxy(51,r+1);
	cout<<s;
}

void box1(int x1,int y1,int x2,int y2)
{
	char tr=(char)187;
	char tl=(char)201;
	char br=(char)188;
	char bl=(char)200;
	char horz=(char)205;
	char vert=(char)186;
	_setcursortype(_NOCURSOR);
	window(1,1,80,25);
	textbackground(YELLOW);
	clrscr();
	window(x1,y1,x2,y2);
	textcolor(WHITE);
	textbackground(BLACK);
	clrscr();
	gotoxy(x1-1,y1-1);
	cout<<tl;
	gotoxy(x2-1,y1-1);
	cout<<tr;
	gotoxy(x1-1,y2-1);
	cout<<bl;
	gotoxy(x2-1,y2-1);
	cout<<br;
	for(int i=x1;i<=x2-2;i++)
	{
		gotoxy(i,y1-1);
		cout<<horz;
	}
	for(i=y1;i<=y2-2;i++)
	{
		gotoxy(x1-1,i);
		cout<<vert;
	}for(i=y1;i<=y2-2;i++)
	{
		gotoxy(x2-1,i);
		cout<<vert;
	}for(i=x1;i<=x2-2;i++)
	{
		gotoxy(i,y2-1);
		cout<<horz;
	}
	gotoxy((x2/2)-5,y1-1);
	cout<<"TOUR & TRAVELS";
	gotoxy((x2/2),y1-1);
	for(i=y1;i<y2-1;i++)
	{
		gotoxy((x2/2),i);
		cout<<vert;
	}
}
void box2(int x1,int y1,int x2,int y2)
{
	char tr=(char)187;
	char tl=(char)201;
	char br=(char)188;
	char bl=(char)200;
	char horz=(char)205;
	char vert=(char)186;
	window(1,1,80,25);
	textbackground(WHITE);
	clrscr();
	window(x1,y1,x2,y2);
	textcolor(BLACK);
	textbackground(BLUE);
	clrscr();
	gotoxy(x1-1,y1-1);
	cout<<tl;
	gotoxy(x2-1,y1-1);
	cout<<tr;
	gotoxy(x1-1,y2-1);
	cout<<bl;
	gotoxy(x2-1,y2-1);
	cout<<br;
	for(int i=x1;i<=x2-2;i++)
	{
		gotoxy(i,y1-1);
		cout<<horz;
	}
	for(i=y1;i<=y2-2;i++)
	{
		gotoxy(x1-1,i);
		cout<<vert;
	}
	for(i=y1;i<=y2-2;i++)
	{
		gotoxy(x2-1,i);
		cout<<vert;
	}
	for(i=x1;i<=x2-2;i++)
	{
		gotoxy(i,y2-1);
		cout<<horz;
	}
	gotoxy((x2/2)-5,y1-1);
	cout<<"TOUR & TRAVELS";
}
void main()
{
	clrscr();
	int k=3;
	char m1[3][20]={"Resort management","User management","Issue management"};
	char m2[2][20]={"Add resort","Delete resort"};
	box1(2,2,79,24);
	gotoxy(10,k+=2);
	cout<<"MAHINDRA RESORTS";
	int i;
	for(i=0;i<3;i++)
	{
		gotoxy(10,k+=2);
		cout<<m1[i];
	}
	k=7;
	i=0;
	char ch;
	cursor1(k,m1[i]);
	do
	{
		ch=getch();
		if(ch==0)
		ch=getch();
		switch(ch)
		{
			case 80:nocursor1(k,m1[i]);               //down
				i++;
				if(i==3)
				{
					i=0; k=7;
				}
				else
				k+=2;
				cursor1(k,m1[i]);
				break;
			case 72:nocursor1(k,m1[i]);             //upper
				i--;
				if(i==-1)
				{
					i=2; k=11;
				}
				else
				k-=2;
				cursor1(k,m1[i]);
				break;
		}               //switch ends
	}while(ch!=13);         //main menu

	if(ch==13)
	{
		window(2,2,79,24);
		k=5;
		if(i==0)
		{

			int j;
			for(j=0;j<2;j++)
			{
				gotoxy(50,k+=2);
				cout<<m2[j]<<endl;
			}
		k=7;
		j=0;
		char ch;
		cursor2(k,m2[j]);
		do
		{
			ch=getch();
			if(ch==0)
			ch=getch();
			switch(ch)
			{
				case 80:nocursor2(k,m2[j]);               //down
					j++;
					if(j==1)
					{
						j=0; k=7;
					}
					else
					k+=2;
					cursor2(k,m2[j]);
					break;
				case 72:nocursor2(k,m2[j]);             //upper
					j--;
					if(j==-1)
				{
					j=1; k=9;
				}
					else
					k-=2;
					cursor2(k,m2[j]);
					break;
			}       //switch ends
		}while(ch!=13); //menu 2

		}		//ifi==0
		else if(i==1)
		{
			gotoxy(50,7);
			cout<<"Under construction.....";
		}
		else
		{
			gotoxy(50,7);
			cout<<"Under construction.....";
		}

	}			//if ch==13
	getch();
}