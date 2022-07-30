#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

class sargam
{
   double mid;
   int year;
   char tor, mname[80], aname[40], award[80], mdir[80], genre[20], album[40];
   float rating;

   public:

   void getd()   //FUNCTION TO INPUT THE DATA
   {
      cout<<"\nEnter music id: ";
      cin>>mid;
      cout<<"Enter music name: ";
      gets(mname);
      cout<<"Enter genre: ";
      gets(genre);
      cout<<"Enter album: ";
      gets(album);
      cout<<"Enter artist name: ";
      gets(aname);
      cout<<"Enter director name: ";
      gets(mdir);
      cout<<"Enter year of release: ";
      cin>>year;
      cout<<"Enter type of release(a/v): ";
      cin>>tor;
      cout<<"Enter rating: ";
      cin>>rating;
      cout<<"Enter award: ";
      gets(award);
   }

   void getdata()   //FUNCTION TO INPUT THE DATA FOR EDITING A RECORD
   {
      cout<<"Enter music name: ";
      gets(mname);
      cout<<"Enter genre: ";
      gets(genre);
      cout<<"Enter album: ";
      gets(album);
      cout<<"Enter artist name: ";
      gets(aname);
      cout<<"Enter director name: ";
      gets(mdir);
      cout<<"Enter year of release: ";
      cin>>year;
      cout<<"Enter type of release(a/v): ";
      cin>>tor;
      cout<<"Enter rating: ";
      cin>>rating;
      cout<<"Enter award: ";
      gets(award);
   }

   void show()  //FUNCTION TO SHOW THE RECORDS
   {
      cout<<"\nMusic id: "<<mid;
      cout<<"\nMusic name: "<<mname;
      cout<<"\nGenre: "<<genre;
      cout<<"\nAlbum: "<<album;
      cout<<"\nArtist name: "<<aname;
      cout<<"\nDirector name: "<<mdir;
      cout<<"\nYear of release: "<<year;
      cout<<"\nType of release(a/v): "<<tor;
      cout<<"\nAward: "<<award;
      cout<<'\n';
   }

   int retid()   //FUNCTION TO RETURN MUSIC ID
   {
      return mid;
   }

   int retyr()   //FUNCTION TO RETURN YEAR OF RELEASE
   {
      return year;
   }

   char* retnm()   //FUNCTION TO RETURN MUSIC NAME
   {
      return mname;
   }

   char* retdir()   //FUNCTION TO RETURN DIRECTOR NAME
   {
      return mdir;
   }

   char* retan()     //FUNCTION TO RETURN ARTIST NAME
   {
      return aname;
   }

   char* retgen()    //FUNCTION TO RETURN GENRE
   {
      return genre;
   }

   char* retalbum()    //FUNCTION TO RETURN ALBUM
   {
      return album;
   }

   char* retawd()        //FUNCTION TO RETURN AWARD
   {
      return award;
   }

   char rettor()       //FUNCTION TO RETURN TYPE OF RELEASE(a/v)
   {
      return tor;
   }

   float retrtg()       //FUNCTION TO RETURN RATING
   {
      return rating;
   }

};

sargam s1, s2;
fstream file, temp;
char ans='y', nm[80], dir[80], gen[20], awd[40], an[80], albm[40], type;
int ct=0, ch, id, yr;
float rtg;

void create()   //FUNCTION TO CREATE FILE
{
   file.open("sargam.dat", ios::app| ios::binary);
   while (ans=='y'|| ans=='Y')
   {
      s1.getd();
      file.write((char*)&s1, sizeof(s1));
      cout<<"\nDo you want to enter another record?(y/n)";
      cin>>ans;
   }
   file.close();
}

void readfile()   //FUNCTION TO READ THE FILE
{
   file.open("sargam.dat", ios::in|ios::binary);
   while(file.read((char*)&s1, sizeof(s1)))
   {
       s1.show();
   }
   file.close();
}

void search()   //FUNCTION TO SEARCH ON DIFF. CRITERIA
{
   int f=0;

   do
   {
      file.open("sargam.dat", ios::in|ios::binary);
      cout<<"\nSearch on the basis of:\n1.Music ID\n2.Music name\n3.Director";
      cout<<"\n4.Genre\n5.Award\n6.Year of release\n7.Artist name\n";
      cout<<"8.Rating\n9.Album\n10.Type of release\nEnter choice: ";
      cin>>ch;

      switch(ch)
      {
	 case 1: cout<<"\nEnter Music ID to search: ";
		 cin>>id;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(s1.retid()==id) //CHECK FOR MUSIC ID
			{
			  s1.show();
			  f=1;
			  break;
			}
		 }
		 break;

	 case 2: cout<<"\nEnter Music name to search: ";
		 gets(nm);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retnm(),nm)== 0)  //CHECK FOR MUSIC NAME
			{
			  s1.show();
			  f=1;
			}
		 }
		 break;

	 case 3: cout<<"\nEnter Music Director to search: ";
		 gets(albm);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retdir(),dir)== 0)  //CHECK FOR DIRECTOR
			{
			  s1.show();
			  f=1;
			}
		 }
		 break;

	 case 4: cout<<"\nEnter genre to search: ";
		 gets(gen);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retgen(),gen)==0) //CHECK FOR GENRE
			{  s1.show();
			   f=1;
			}
		 }
		 break;

	 case 5: cout<<"\nEnter Award to search: ";
		 gets(awd);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retawd(),awd)==0) //CHECK FOR AWD
			{
			   s1.show();
			   f=1;
			}
		 }
		 break;

	 case 6: cout<<"\nEnter year of release to search: ";
		 cin>>yr;
		 while(file.read((char*)&s1,sizeof(s1)))   //CHECK FOR YEAR
		 {
			if(s1.retyr()==yr)
			{
			   s1.show();
			   f=1;
			}
		 }
		 break;

	 case 7: cout<<"\nEnter Artist Name to search: ";
		 gets(an);
		 while(file.read((char*)&s1, sizeof(s1)))   //CHECK FOR ARTIST NAME
		 {
			if(strcmpi(s1.retan(),an)== 0)
			{
			   s1.show();
			   f=1;
			}
		 }
		 break;

	 case 8: cout<<"\nEnter rating to search: ";
		 cin>>rtg;
		 while(file.read((char*)&s1, sizeof(s1)))    //CHECK FOR RATING
		 {
			if(s1.retrtg()==rtg)
			{  s1.show();
			   f=1;
			}
		 }
		 break;

	 case 9: cout<<"\nEnter Music Album to search: ";
		 gets(albm);
		 while(file.read((char*)&s1,sizeof(s1)))     //CHECK FOR ALBUM
		 {
			if(strcmpi(s1.retalbum(),albm)== 0)
			{  s1.show();
			   f=1;
		 }      }
		 break;

	 case 10: cout<<"\nEnter tupe of release to search: ";
		  cin>>type;
		  while(file.read((char*)&s1,sizeof(s1)))   //CHECK FOR TOR
		  {
			if(s1.rettor()==type)
			{
			   s1.show();
			   f=1;
			}
		  }
		  break;

	 default: cout<<"\nWrong choice";
      }
      if(f==0)
      cout<<"\nNo record found";
      file.close();
      cout<<"\nDo you want to search again?(y/n)";
      cin>>ans;
   }while(ans=='y'||ans=='Y');
}

void count() //FUNCTION TO COUNT ENTRIES OF A GIVEN PARAMETER
{
   do
   {
      file.open("sargam.dat",ios::in|ios::binary);

      cout<<"\nCount on the basis of:\n1.Music ID\n2.Music name\n3.Director";
      cout<<"\n4.Genre\n5.Award\n6.Year of release\n7.Artist name";
      cout<<"\n8.Rating\n9.Album\n10.Type of release\nEnter choice: ";
      cin>>ch;

      switch(ch)
      {
	 case 1: cout<<"\nEnter Music ID to count: ";
		 cin>>id;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(s1.retid()==id)
			{
			  ct++;   //COUNT MUSIC ID
			  break;
			}
		 }
		 break;

	 case 2: cout<<"\nEnter Music Name to count: ";
		 gets(nm);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retnm(),nm)==0)
			{
			  ct++; //COUNT MUSIC NAME
			  s1.show();
			}
		 }
		 break;

	 case 3: cout<<"\nEnter Music Director to count: ";
		 gets(dir);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retdir(),dir)== 0)
			{
			  ct++; //COUNT DIRECTOR
			  s1.show();
			}
		 }
		 break;

	 case 4: cout<<"\nEnter genre to count: ";
		 gets(gen);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retgen(),gen)== 0)
			{
			  ct++;  //COUNT GENRE
			  s1.show();
			}
		 }
		 break;

	 case 5: cout<<"\nEnter award to count: ";
		 gets(awd);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retawd(),awd)== 0)
			{
			  ct++;   //COUNT AWARD
			  s1.show();
			}
		 }
		 break;

	 case 6: cout<<"\nEnter year of release to count: ";
		 cin>>yr;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(s1.retyr()==yr)
			{
			  ct++;    //COUNT YEAR
			  s1.show();
			}
		 }
		 break;

	 case 7: cout<<"\nEnter Artist name to count: ";
		 gets(an);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retan(),an)== 0)
			{
			  ct++;   //COUNT ARTIST NAME
			  s1.show();
			}
		 }
		 break;

	 case 8: cout<<"\nEnter rating to count: ";
		 cin>>rtg;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(s1.retrtg()==rtg)
			{
			  ct++;  //COUNT RATING
			  s1.show();
			}
		 }
		 break;

	 case 9: cout<<"\nEnter Music Album to count: ";
		 gets(albm);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retalbum(),albm)== 0)
			{
			  ct++;  //COUNT ALBUM
			  s1.show();
			}
		 }
		 break;

	case 10: cout<<"\nEnter Type of Release to count: ";
		 cin>>type;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(s1.rettor()==type)
			{
			  ct++; //COUNT TYPE OF RELEASE
			  s1.show();
			}
		 }
		 break;
      }
      cout<<"\nNo. of records="<<ct;
      file.close();
      cout<<"\nDo you want to count again?(y/n)";
      cin>>ans;
   }while(ans=='y'||ans=='Y');
}

void delrec()  //FUNCTION TO DELETE A RECORD
{
   int r=1;
   do
   {
      file.open("sargam.dat", ios::in|ios::binary);
      temp.open("temp.dat",  ios::out|ios::binary);

      cout<<"\nDelete:\n1.first record\n2.last record\n3.nth record";
      cout<<"\n4.a Music ID\n5.a Music Name\nEnter choice: ";
      cin>>ch;
      switch(ch)
      {
	 case 1: file.read((char*)&s1, sizeof(s1)); //GET POINTER SHIFT
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			temp.write((char*)&s1, sizeof(s1));
		 }
		 break;

	 case 2: file.seekg(0, ios::end);
		 int lp=file.tellg();
		 int s=sizeof(s1);
		 int lr=lp/s;// POS OF LAST REC
		 file.seekg(0);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
		       if(r!=lr)
		       temp.write((char*)&s1, sizeof(s1));
		       r++;
		 }
		 break;

	 case 3: int dr;
		 cout<<"Enter record no. to delete";
		 cin>>dr;
		 file.seekg(0);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
		       if(r!=dr)
		       temp.write((char*)&s1, sizeof(s1));
		       r++;
		 }
		 break;

	 case 4: cout<<"\nEnter Music ID to delete: ";
		 cin>>id;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(s2.retid()!=id)
			  temp.write((char*)&s1, sizeof(s1));
		 }
		 break;

	 case 5: cout<<"Enter music name to delete";
		 gets(nm);
		 file.seekg(0);
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
		    if(strcmpi(s1.retnm(),nm)!=0)
		    temp.write((char*)&s1, sizeof(s1));
		 }
		 break;

	 default: cout<<"\nWrong choice";
      }
      temp.close();
      file.close();
      remove("sargam.dat");
      rename("temp.dat","sargam.dat");
      cout<<"\nDo you want to delete another record?(y/n)";
      cin>>ans;
   }while(ans=='y'||ans=='Y');
}

void edit()  //FUNCTION TO EDIT A RECORD
{
   do
   {
      cout<<"\nEdit on the basis of:\n1.Music ID\n2.Music Name\nEnter choice: ";
      cin>>ch;

      switch(ch)
      {
	 case 1: cout<<"\nEnter Music ID whose details you wish to edit: ";
		 cin>>id;

		 file.open("sargam.dat", ios::in|ios::binary);
		 temp.open("temp.dat", ios::out|ios::binary);

		 while(file.read((char*)&s1, sizeof(s1)))
		 {
		   if(s1.retid()==id)
		   {
			cout<<"\nEnter new details: ";
			s1.getdata();
		   }
		   temp.write((char*)&s1, sizeof(s1));
		 }

		 temp.close();
		 file.close();
		 remove("sargam.dat");
		 rename("temp.dat","sargam.dat");
		 break;

	 case 2: cout<<"\nEnter the song name whose details you wish to edit";
		 gets(nm);

		 file.open("sargam.dat", ios::in|ios::binary);
		 temp.open("temp.dat", ios::out|ios::binary);

		 file.seekg(0);

		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			if(strcmpi(s1.retnm(),nm)==0)
			{
			   cout<<"\nEnter new details-";
			   s1.getdata();
			}
			temp.write((char*)&s1, sizeof(s1));
		 }

		 temp.close();
		 file.close();
		 remove("sargam.dat");
		 rename("temp.dat","sargam.dat");
		 break;

	 default: cout<<"\nWrong choice!";
      }
      cout<<"\nDo you want to edit another record?(y/n)";
      cin>>ans;
   }while(ans=='y'||ans=='Y');
}


void insrec()  //FUNCTION TO INSERT A RECORD
{
   int r=0;
   do
   {
      file.open("sargam.dat", ios::in|ios::binary);
      temp.open("temp.dat", ios::out|ios::binary);

      cout<<"\nInsert the record:\n1.at first position\n2.at last position";
      cout<<"\n3.at nth position\n4.after a music ID\n5.after a music name\n";
      cout<<"\nEnter choice: ";
      cin>>ch;

      switch(ch)
      {
	 case 1: temp.write((char*)&s2, sizeof(s2));
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
		    temp.write((char*)&s1, sizeof(s1));
		 }
		 break; //INSERTING AT FIRST POSITION

	 case 2: while( file.read((char*)&s1, sizeof(s1)))
		 {
			temp.write((char*)&s1, sizeof(s1));
		 }
		 temp.write((char*)&s2, sizeof(s2));
		 break; //INSERTING AT LAST POSITION

	 case 3: int ir;
		 cout<<"\nEnter record no. after which you want to add a record- ";
		 cin>>ir;
		 while(file.read((char*)&s1, sizeof(s1)))
		 {
		     r++;
		     if(r==ir)
		     {
			temp.write((char*)&s2, sizeof(s2));
		     }
		     temp.write((char*)&s1, sizeof(s1));
		 }
		 break;

	 case 4: cout<<"Enter the music ID after which you want to add a record- ";
		 cin>>id;

		 file.seekg(0);
		 while( file.read((char*)&s1, sizeof(s1)))
		 {
			temp.write((char*)&s1, sizeof(s1));
			if(s1.retid()==id)
			temp.write((char*)&s2, sizeof(s2));
		 }
		 break;

	 case 5: cout<<"\nEnter the music name after which you want to add a record- ";
		 gets(nm);

		 file.seekg(0);

		 while(file.read((char*)&s1, sizeof(s1)))
		 {
			temp.write((char*)&s1, sizeof(s1));
			if(strcmpi(s1.retnm(),nm)==0)
			temp.write((char*)&s2, sizeof(s2));
		 }
		 break;

	 default: cout<<"\nWrong choice!";
      }
      temp.close();
      file.close();
      remove("sargam.dat");
      rename("temp.dat","sargam.dat");

      cout<<"\nDo you want to insert another record?(y/n)";
      cin>>ans;
   }while(ans=='y'||ans=='Y');
}

void main()
{
   clrscr();
   while(ans=='y' || ans=='Y')
   {
      cout<<"\n1.Create file";
      cout<<"\n2.Read file";
      cout<<"\n3.Search";
      cout<<"\n4.Count";
      cout<<"\n5.Edit";
      cout<<"\n6.Insert";
      cout<<"\n7.Delete";
      cout<<"\nEnter choice: ";
      cin>>ch;

      switch(ch)
      {
	 case 1: create();
		 break;

	 case 2: readfile();
		 break;

	 case 3: search();
		 break;

	 case 4: count();
		 break;

	 case 5: edit();
		 break;

	 case 6: cout<<"\nEnter record to be inserted";
		 s2.getd();
		 insrec();
		 break;

	 case 7: delrec();
		 break;

	 default: cout<<"\nWrong choice";
      }
      cout<<"\nDo you want to go back to the main menu?(y/n)";
      cin>>ans;
   }
}
