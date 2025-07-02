#include<windows.h>
#include<unistd.h>
#include<iostream>
#include<conio.h>
#include <cstdlib>
#include<cstring>
#include<cctype>
#include<dos.h>
#include<ctime>
using namespace std;
#define RETURNTIME 15
char catagories[][15] =
  { "Rings", "Ear Rings", "Bracelet", "Pendant", "Chain", "Jewellery Set" };

void returnfunc (void);
void mainmenu (void);
void additem (void);
void deleteitem (void);
void edititem (void);
void searchitem (void);
void viewitem (void);
void closeapplication (void);
void calculatebill (void);
int getdata ();
int checkid (int);
int t (void);
void Password ();
void issuerecord ();
void loaderanim ();
FILE *fp, *ft, *fs;
COORD coord = { 0, 0 };

int s;
char findstaff;
char password[10] = { "pass" };	//replace "pass" with your own if you wish to change the password

void
gotoxy (int x, int y)
{
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
  int mm, dd, yy;
};
struct staff
{
  int id;
  char stname[20];
  char name[20];
  char Material[20];
  int Quantity;
  int count;
  int weight;
  int karat;
  char *cat;
  struct meroDate issued;
  struct meroDate duedate;
};
struct staff a;
int
main ()
{
  Password ();
  getch ();
  return 0;
}

void
mainmenu ()
{
  system ("cls");
  int i;
  gotoxy (20, 3);
  cout << "\t\tMAIN MENU \n ";
  cout <<
    "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
  gotoxy (20, 5);
  cout << "<1> Add Jewellery Items ";
  gotoxy (20, 7);
  cout << "<2> Remove Items";
  gotoxy (20, 9);
  cout << "<3> Search Items";
  gotoxy (20, 11);
  cout << "<4> View Item's List'";
  gotoxy (20, 13);
  cout << "<5> Edit Items";
  gotoxy (20, 15);
  cout << "<6> Calculate Bill";
  gotoxy (20, 17);
  gotoxy (20, 2);
  t ();
  gotoxy (20, 20);
  cout << "Enter your choice:";
  switch (getch ())
    {
    case '1':
      additem ();
      break;
    case '2':
      deleteitem ();
      break;
    case '3':
      searchitem ();
      break;
    case '4':
      viewitem ();
      break;
    case '5':
      edititem ();
      break;
    case '7':
      {
	system ("cls");
	gotoxy (16, 3);
	cout << "\tJewellery Store Management System";
	gotoxy (16, 4);
	cout << "\tIn C Programming";
	gotoxy (16, 5);
	cout << "\tDeveloped By";
	gotoxy (16, 7);
	cout << "\t\t.....PARAS SONAR";
	cout << "\n\t\t\tPROJECT MADE BY....PARAS , NILESH & JIVAN";
	gotoxy (16, 8);
	exit (0);
      }
    case '6':
      calculatebill ();
      break;
    default:
      {
	gotoxy (10, 25);
	cout << "\aWrong Entry!!Please re-entered correct option";
	if (getch ())
	  mainmenu ();
      }
    }
}

void
additem (void)
{
  system ("cls");
  int i;
  gotoxy (20, 5);
  cout << "SELECT CATEGOIES";
  gotoxy (20, 7);
  cout << "<1> Rings";
  gotoxy (20, 9);
  cout << "<2> Ear Rings";
  gotoxy (20, 11);
  cout << "<3> Bracelet";
  gotoxy (20, 13);
  cout << "<4> Pendant";
  gotoxy (20, 15);
  cout << "<5> Chain";
  gotoxy (20, 17);
  cout << "<6> Jewellery Set";
  gotoxy (20, 19);
  cout << "<7> Back to main menu";
  gotoxy (20, 21);
  cout << "Enter your choice:";
  cin >> s;
  if (s == 7)
    mainmenu ();
  system ("cls");
  fp = fopen ("stf.dat", "ab+");
  if (getdata () == 1)
    {
      a.cat = catagories[s - 1];
      fseek (fp, 0, SEEK_END);
      fwrite (&a, sizeof (a), 1, fp);
      fclose (fp);
      gotoxy (21, 14);
      cout << "The record is sucessfully saved";
      gotoxy (21, 15);
      cout << "Save any more?(Y / N):";
      if (getch () == 'n')
	mainmenu ();
      else
	system ("cls");
      additem ();
    }
}

void
deleteitem ()
{
  system ("cls");
  int d;
  char another = 'y';
  while (another == 'y')
    {
      system ("cls");
      gotoxy (10, 5);
      cout << "Enter the Item Code to delete:";
      cin >> d;
      fp = fopen ("stf.dat", "rb+");
      rewind (fp);
      while (fread (&a, sizeof (a), 1, fp) == 1)
	{
	  if (a.id == d)
	    {
	      gotoxy (10, 7);
	      cout << "The Item is available";
	      gotoxy (10, 8);
	      cout << "Item's name is " << a.name;
	      gotoxy (10, 9);
	      findstaff = 't';
	    }
	}
      if (findstaff != 't')
	{
	  gotoxy (10, 10);
	  cout << "No record is found modify the search";
	  if (getch ())
	    mainmenu ();
	}
      if (findstaff == 't')
	{
	  gotoxy (10, 9);
	  cout << "Do you want to delete it?(Y/N):";
	  if (getch () == 'y')
	    {
	      ft = fopen ("test.dat", "wb+");
	      rewind (fp);
	      while (fread (&a, sizeof (a), 1, fp) == 1)
		{
		  if (a.id != d)
		    {
		      fseek (ft, 0, SEEK_CUR);
		      fwrite (&a, sizeof (a), 1, ft);
		    }
		}
	      fclose (ft);
	      fclose (fp);
	      remove ("stf.dat");
	      rename ("test.dat", "stf.dat");
	      fp = fopen ("stf.dat", "rb+");
	      if (findstaff == 't')
		{
		  gotoxy (10, 10);
		  cout << "The record is sucessfully deleted";
		  gotoxy (10, 11);
		  cout << "\n\tDelete another record?(Y/N)";
		}
	    }
	  else
	    mainmenu ();
	  fflush (stdin);
	  another = getch ();
	}
    }
  gotoxy (10, 15);
  mainmenu ();
}

void
searchitem ()
{
  system ("cls");
  int d;
  cout <<
    "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Search Item\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
  gotoxy (20, 10);
  cout << "1. Search By Code";
  gotoxy (20, 14);
  cout << "2. Search By Name";
  gotoxy (15, 20);
  cout << "Enter Your Choice";
  fp = fopen ("stf.dat", "rb+");
  rewind (fp);
  switch (getch ())
    {
    case '1':
      {
	system ("cls");
	gotoxy (25, 4);
	cout <<
	  "\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Code\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy (20, 5);
	cout << "Enter the Item Code:";
	cin >> d;
	gotoxy (20, 7);
	while (fread (&a, sizeof (a), 1, fp) == 1)
	  {
	    if (a.id == d)
	      {
		sleep (2);
		gotoxy (20, 6);
		cout << "The Item is available\n";
		gotoxy (20, 8);
		cout << "Item Code:" << a.id;
		gotoxy (20, 9);
		cout << "Category:" << a.cat;
		gotoxy (20, 10);
		cout << "Name:" << a.name;
		gotoxy (20, 11);
		cout << "Material: " << a.Material;
		gotoxy (20, 12);
		cout << "Quantity: " << a.Quantity;
		gotoxy (20, 13);
		cout << "Weight: " << a.weight;
		gotoxy (20, 14);
		cout << "Karat: " << a.karat;
		gotoxy (20, d + 15);
		findstaff = 't';
	      }
	  }
	if (findstaff != 't')
	  {
	    cout << "\aNo Record Found";
	  }
	gotoxy (20, 17);
	cout << "Try another search?(Y/N)";
	if (getch () == 'y')
	  searchitem ();
	else
	  mainmenu ();
	break;
      }
    case '2':
      {
	char s[15];
	system ("cls");
	gotoxy (25, 4);
	cout <<
	  "\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Name\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy (20, 5);
	cout << "Enter Item's Name:";
	cin >> s;
	int d = 0;
	while (fread (&a, sizeof (a), 1, fp) == 1)
	  {
	    if (strcmp (a.name, (s)) == 0)
	      {
		gotoxy (20, d + 7);
		cout << "The Staff is available";
		gotoxy (20, d + 8);
		cout << "Item Code:" << a.id;
		gotoxy (20, d + 10);
		cout << "Name:" << a.name;
		gotoxy (20, d + 11);
		cout << "Material:" << a.Material;
		gotoxy (20, d + 12);
		cout << "Quantity:" << a.Quantity;
		gotoxy (20, d + 13);
		cout << "Weight:" << a.weight;
		gotoxy (20, d + 14);
		cout << "Karat:" << a.karat;
		gotoxy (20, d + 15);
		getch ();
		d += 6;
	      }
	  }
	if (d == 0)
	  cout << "\aNo Record Found";
	gotoxy (20, d + 11);
	cout << "Try another search?(Y/N)";
	if (getch () == 'y')
	  searchitem ();
	else
	  mainmenu ();
	break;
      }
    default:
      getch ();
      searchitem ();
    }
  fclose (fp);
}

void
viewitem (void)
{
  int i = 0, j;
  system ("cls");
  gotoxy (1, 1);
  cout <<
    "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Item's List\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
  gotoxy (2, 2);
  cout <<
    "CATEGORY ITEM CODE ITEM NAME MATERIAL QUANTITY WEIGHT RANGE KARAT (K)";
  j = 4;
  fp = fopen ("stf.dat", "rb");
  while (fread (&a, sizeof (a), 1, fp) == 1)
    {
      gotoxy (3, j);
      cout << "" << a.cat;
      gotoxy (16, j);
      cout << "" << a.id;
      gotoxy (24, j);
      cout << "" << a.name;
      gotoxy (39, j);
      cout << "" << a.Material;
      gotoxy (51, j);
      cout << "" << a.Quantity;
      gotoxy (62, j);
      cout << "" << a.weight;
      gotoxy (76, j);
      cout << "" << a.karat;
      gotoxy (81, j);
      cout << "\n\n";
      j++;
    }
  fclose (fp);
  gotoxy (35, 25);
  returnfunc ();
}

void
edititem (void)
{
  system ("cls");
  int c = 0;
  int d, e;
  gotoxy (20, 4);
  cout <<
    "\xB2\xB2\xB2\xB2\xB2\xB2 Edit Items Section \xB2\xB2\xB2\xB2\xB2\xB2";
  char another = 'y';
  while (another == 'y')
    {
      system ("cls");
      gotoxy (15, 6);
      cout << "Enter Item's code to be edited:";
      cin >> d;
      fp = fopen ("stf.dat", "rb+");
      while (fread (&a, sizeof (a), 1, fp) == 1)
	{
	  if (checkid (d) == 0)
	    {
	      gotoxy (15, 7);
	      cout << "The Item is availble";
	      gotoxy (15, 8);
	      cout << "The Item's Code:" << a.id;
	      gotoxy (15, 9);
	      cout << "Enter new name:";
	      cin >> a.name;
	      gotoxy (15, 10);
	      cout << "Enter new Material:";
	      cin >> a.Material;
	      gotoxy (15, 11);
	      cout << "Enter new Quantity:";
	      cin >> a.Quantity;
	      gotoxy (15, 12);
	      cout << "Enter new Weight Range:";
	      cin >> a.weight;
	      gotoxy (15, 13);
	      cout << "Enter new Karat:";
	      cin >> a.karat;
	      gotoxy (15, 14);
	      cout << "The record is modified";
	      fseek (fp, ftell (fp) - sizeof (a), 0);
	      fwrite (&a, sizeof (a), 1, fp);
	      fclose (fp);
	      c = 1;
	    }
	  if (c == 0)
	    {
	      gotoxy (15, 9);
	      cout << "No record found";
	    }
	}
      gotoxy (15, 16);
      cout << "Modify another Record?(Y/N)";
      fflush (stdin);
      another = getch ();
    }
  returnfunc ();
}

void
returnfunc (void)
{
  {
    gotoxy (15, 20);
    cout << "Press ENTER to return to main menu";
  }
a:
  if (getch () == 13)
    mainmenu ();
  else
    goto a;
}

int
getdata ()
{
  int t;
  gotoxy (20, 3);
  cout << "Enter the Information Below";
  gotoxy (20, 4);
  cout << "Category:";
  gotoxy (31, 5);
  cout << "" << catagories[s - 1];
  gotoxy (21, 6);
  cout << "Item Code:\t";
  gotoxy (31, 6);
  cin >> t;
  if (checkid (t) == 0)
    {
      cout << "\aThe Item Code already exists\a";
      gotoxy (21, 13);
      getch ();
      mainmenu ();
      return 0;
    }
  a.id = t;
  gotoxy (21, 7);
  cout << "Item's Name:";
  gotoxy (33, 7);
  cin >> a.name;
  gotoxy (21, 8);
  cout << "Material:";
  gotoxy (30, 8);
  cin >> a.Material;
  gotoxy (21, 9);
  cout << "Quantity:";
  gotoxy (31, 9);
  cin >> a.Quantity;
  gotoxy (21, 10);
  cout << "Weight Range:";
  gotoxy (34, 10);
  cin >> a.weight;
  gotoxy (21, 11);
  cout << "Karat:";
  gotoxy (27, 11);
  cin >> a.karat;
  gotoxy (21, 11);
  return 1;
}

int
checkid (int t)
{
  rewind (fp);
  while (fread (&a, sizeof (a), 1, fp) == 1)
    if (a.id == t)
      return 0;
  return 1;
}

int
t (void)
{
  time_t t;
  time (&t);
  cout << "Date and time:\n" << ctime (&t);
  return 0;
}

void
Password (void)
{
  system ("cls");
  char d[25] = "Password Protected";
  char ch, pass[10];
  int i = 0, j;
  cout <<
    "\t\t\t\t\tWELCOME\n\t\t\t\t\t To \n\t\t \xB2\xB2\xB2\xB2\xB2\xB2 Jewellery Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n";
  cout << "\t \n\n\n Enter Password:";
  while (ch != 13)
    {
      ch = getch ();
      if (ch != 13 && ch != 8)
	{
	  putch ('*');
	  pass[i] = ch;
	  i++;
	}
    }
  pass[i] = '\0';
  if (strcmp (pass, password) == 0)
    {
      cout << "\n\n\n\t\tPassword matched!!";
      cout << "\n\n\tPress any key to countinue.....";
      getch ();
      mainmenu ();
    }
  else
    {
      cout << "\n\n\n\t\t\aWarning!! \n\t Incorrect Password";
      getch ();
      Password ();
    }
}

void
calculatebill ()
{
  int custid, wgh, chr, rte, dis;
  float chg, surchg = 0, gramt, netamt;
  char connm[25];
  system ("CLS");
  cout << "================================================================";
  cout << "\n";
  cout << "\tEnter Customer ID :";
  cin >> custid;
  cout << "\n";
  cout << "\tEnter the Name of the Customer :";
  cin >> connm;
  cout << "\n";
  cout << "\tEnterw the Weight (In Gram) : ";
  cin >> wgh;
  cout << "\n";
  cout << "\tEnter Making Charges : ";
  cin >> chr;
  cout << "\n";
  cout << "\tEnter Current Gold/Silver rate : ";
  cin >> rte;
  cout << "\n";
  cout << "\tDiscount Amount Rs.: ";
  cin >> dis;
  cout << "================================================================";
  cout << "\n";
  cout << "\t Press Enter To Display Total Bill of Mr/Mrs :" << connm;
  getch ();
  system ("CLS");
  surchg = (rte * wgh) + chr - dis;	//calculation process
  netamt = surchg;
  cout << "\n\t\t===============INVOICE/BILL================\n";
  cout << "\t\t===============PNJ Jewellers================\n";
  cout << "\t\tCustomer IDNO :\n" << custid;
  cout << "\n";
  cout << "\t\tCustomer Name:\n" << connm;
  cout << "\n";
  cout << "\t\tTotal Weight :\n" << wgh;
  cout << "\n";
  cout << "\t\tDiscount Amount :\n" << dis;
  cout << "\n";
  cout << "\t\tSurchage Amount :%8.2f\n" << surchg;
  cout << "\n";
  cout << "\t\tNet Amount Paid By the Customer :%8.2f\n" << netamt;
  cout << "\t\t=============================================\n";
  getch ();
  mainmenu ();
}
