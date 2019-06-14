#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
class tour
{
	int resort_id,avail;
	char name[10],location[10];
	public:
	void modify(char*n)//,int i)
	{
	  //	if(i==1)
		strcpy(name,n);
	   /*	else if(i==2)
		strcpy(location,n);
		else
		cout<<"wrong input";     */
	}
	char* retname()//int i)
	{
	     //	if(i==1)
		return(name);
	     //	else
	    //	return(location);
	}
	void display()
	{
		cout<<"\nresort id:";
		cout<<resort_id;
		cout<<"\navailable:";
		cout<<avail;
		cout<<"\nresort name:";
		puts(name);
		cout<<"resort location:";
		puts(location);
	}
	void read()
	{
		cout<<"\nresort id:";
		cin>>resort_id;
		cout<<"\navailable:";
		cin>>avail;
		cout<<"\nresort name:";
		gets(name);
		cout<<"\nresort location:";
		gets(location);
	}
	int retno()
	{
		return(resort_id);
	}
};
void add_resort()
{
	fstream  f;
	tour r;
	char ch;
	f.open("resort.txt",ios::out);
	if(!f)
	{
		cout<<"File doesn\'t exist";
		exit(0);
	}
	do
	{
		r.read();
		f.write((char*)&r,sizeof(r));
		cout<<"\nwant to continue(Y/N)?:";
		cin>>ch;
		tolower(ch);
	}
	while(ch!='n');
	f.close();
}
void display_resort()
{
	fstream  f;
	tour r;
	f.open("resort.txt",ios::in);
	while(!f.eof())
	{
		f.read((char*)&r,sizeof(r));
		if(f.eof())
		break;
		r.display();
	}
	f.close();

}
void delete_resort()
{

	fstream  f,f1;
	tour r;
	int x,found=0,keyf;
	char ch;
	f.open("resort.txt",ios::in);
	f1.open("rsrtmo.txt",ios::out);
	cout<<"enter resort id to delete\n";
	cin>>keyf;
	while(!f.eof())
	{
		f.read((char*)&r,sizeof(r));
		x=r.retno();
		if(x!=keyf)
		f1.write((char*)&r,sizeof(r));
		else
		found++;
	}
	if(found==0)
	cout<<"record doesn\'t exist\n";
	else
	cout<<"record deleted\n";
	f.close();
	f1.close();
//	remove("resort.txt");
	rename("rsrtmo.txt","resort.txt") ;
}
void modify_resort()
{

	tour r;
	fstream f,f1;
	char ch,namem[10],nname[10];
	int found=0;//,i;
//	cout<<"Modify:\n1)Resort name\n2)Resort location";
//     	cin>>i;
	cout<<"\nenter resort name to modify\n";
	gets(namem);
	f.open("resort.txt",ios::in);
	f1.open("resort1.txt",ios::out);
	while(!f.eof())
	{
		f.read((char*)&r,sizeof(r));
		{
			if(f.eof())
			break;
		}
		if(strcmpi(r.retname(/*i*/),namem)==0)
		{
			cout<<"\nEnter new name\n";
			gets(nname);
			r.modify(nname);//,i);
			found++;
			f1.write((char*)&r,sizeof(r));
		}


	}
	if(found==0)
	cout<<"\nRecord doesn\'t exist\n";
	else
	cout<<"\nRecord modified\n";
	f.close();
	f1.close();
	remove("resort.txt");
	rename("resort1.txt","resort.txt");
}
void main()
{
	clrscr();
	add_resort();
	delete_resort();
	modify_resort();
	display_resort();
	getch();
}