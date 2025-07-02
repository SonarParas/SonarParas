#include <iostream>
#include<ctime>
#include<cmath>
#include<chrono>
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
using namespace std;
class file
{
public:
  file ()
  {
    ofstream fout;
      fout.open ("paras.txt");
      fout << "paras";
      fout.close ();
  }
};
class earn
{
public:
  double profit;
  void show ()
  {
    ifstream x ("ooo.txt");
    if (!x)
        cout << "PROFIT = 0 ";
    else
      {
	x >> profit;
	cout << "\nTOTAL STARTING PROFIT:  " << profit << endl;
	x.close ();
      }

  }

};
class product:public virtual earn
{
public:
  int quan;
  char name[20];
  char id[20];
  double percost;
  double persell;
  double cost;
  double sell;
  void cal ()
  {
    cost = percost * quan;
    sell = persell * quan;
    profit = profit + (sell - cost) * 365;
  }
  void file ();
  void get ();

};

void
product::get ()
{
  int s;
  cout << "\nnumber of jwellery maked or produced?\n";
  cin >> s;
  for (int i = 0; i < s; i++)
    {
      cout << "\ninput jwellery name: \n";
      cin >> name;
      cout << "\ninput jwellery Hallmark id: \n";
      cin >> id;
      cout << "\ninput total price of jwellery: \n";
      cin >> percost;
      cout << "\ninput selling price of jwellery: \n";
      cin >> persell;
      cout << "\ntotal jwellery quantity: \n";
      cin >> quan;
      cal ();
      file ();
    }

}

void
product::file ()
{
  char file[20];
  strcpy (file, id);
  strcat (file, ".txt");
  ofstream f (file);
  f << "\njwellery name: " << name << "\nhallmarking id of jwellery: " << id <<
    "\ncost price of jwellery: " << percost << "\nselling price of jwellery: "
    << persell << "\nquantity: " << quan << "\n total cost: " << cost <<
    "\nsell: " << sell;
  f.close ();
}

class staff:public virtual earn
{
protected:
  double salary;
  char post[12];
  char empid[10];
  int postquan;
  void cal ()
  {
    profit = (profit - salary * postquan) * 12;
  }
  void getstaff ();
  void file ();
};

void
staff::getstaff ()
{
  cout << "\ninput salary: \n";
  cin >> salary;
  cout << "\ninput number of employees: \n";
  cin >> postquan;
  for (int i = 0; i < postquan; i++)
    {
      cout << "input employee name\n";
      cin >> post;
      cout << "\ninput employee ID\n";
      cin >> empid;
      cal ();
      file ();
    }
}

void
staff::file ()
{
  char file[20];
  strcpy (file, empid);
  strcat (file, ".txt");
  ofstream f (file);
  f << "\nnumber of working employees: " << postquan << "\nemployee salary: "
    << salary << "\nemployee name :" << post << "\nemployee id: " << empid;
  f.close ();
}

class amount:public staff, public product
{

public:
  void add ();
  void update_item ();
  void update_emp ();

};
void
amount::add ()
{
  int ch;
  char name[20];
  while (1)
    {
      cout << "1.)Input for jwellery\n2.)Input for employee\n3.)Exit\n";
      cout << "Enter choice\n";
      cin >> ch;
      if (ch == 1)
	{
	  get ();
	  ofstream x ("ooo.txt");
	  x << profit;
	  x.close ();
	}
      else if (ch == 2)
	{
	  getstaff ();
	  ofstream x ("ooo.txt");
	  x << profit;
	  x.close ();
	}
      else if (ch == 3)
	break;
      else
	cout << "Invaid Option. Please re-enter\n";
    }
}


void
amount::update_item ()
{
  char id[20];
  char pid[20];
  char c;
  cout << "\nINPUT Hallmarking ID of Jwellery to modify\n";
  cin >> id;
  char file[20];
  char file2[20];
  strcpy (file, id);
  strcat (file, ".txt");
  fstream fout (file, ios::in | ios::out);
  if (!fout)
    {
      cout << "file couldn't be opened. hallmarking ID not found. \n";
    }
  else
    {
      cout << "file found! \n";
      cout << "\nupdate jwellery name: \n";
      cin >> name;
      cout << "\nupdate percost of jwellery: \n";
      cin >> percost;
      cout << "\nupdate persell of jwellery: \n";
      cin >> persell;
      cout << "\nupdate total jwellery quantity: \n";
      cin >> quan;
      cost = percost * quan;
      sell = persell * quan;
      profit = profit + (sell - cost) * 365;
      fout << "\njwellery name: " << name << "\nhallmarking id: " << id <<
	"\npercost of jwellery: " << percost << "\npersell of jwellery: " <<
	persell << "\nquantity: " << quan << "\n total cost: " << cost <<
	"\nsell: " << sell;
      fout.close ();
    }
}

void
amount::update_emp ()
{
  char id[20];
  char c;
  cout << "\nINPUT employee ID to modify: ";
  cin >> id;
  char file[20];
  strcpy (file, id);
  strcat (file, ".txt");
  fstream fout (file, ios::in | ios::out);
  if (!fout)
    {
      cout << "file couldn't be opened. hallmarking ID not found. \n";
    }
  cout << "modify employee name: \n";
  cin >> post;
  fout << "\nnumber of working employees: " << postquan <<
    "\nemployee salary: " << salary << "\nemployee name :" << post <<
    "\nemployee id: " << empid;
  fout.close ();
}

void
admin ()
{
  while (1)
    {


time_t tt;
// Declaring variable to store return value of
// localtime()
struct tm * ti;
// Applying time()
time (&tt);
// Using localtime()
ti = localtime(&tt);
cout << "\nCurrent Day, Date and Time is = "<< asctime(ti);






      cout << "\n\t\t\t=================================\n";
      cout << "\n\t\t\t   WELCOME TO THE PNJ JWELLERS   \n";
      cout << "\n\t\t\t=================================\n\n";
      cout << "\n\t\t\t* * * * * * * * * * * * * * * *\n";
      cout <<
	"\n\t\t\t1. Add Entries\n\n\t\t\t2. Show profit\n\n\t\t\t3. Search Jwellery Details\n\n\t\t\t4. Search Employee Details\n\n\t\t\t5. Modify Jwellery Details\n\n\t\t\t6. Modify Employee Details\n\n\t\t\t7. Exit\n";
      cout << "\n\n\t\t\tSelect your choice\n";
      int u;
      cin >> u;
      if (u == 1)
	{
	  amount a;
	  a.show ();
	  a.add ();
	}
      else if (u == 2)
	{
	  amount d;
	  d.show ();
	}
      else if (u == 3)
	{
	  char id[20];
	  char c;
	  cout << "\nINPUT Hallmark ID to search\n";
	  cin >> id;
	  char file[20];
	  strcpy (file, id);
	  strcat (file, ".txt");
	  ifstream x (file);
	  if (!x)
	    {
	      cout << "file couldn't be opened. jwellery hallmark ID not found. \n";
	    }
	  while (x)
	    {
	      x.get (c);
	      cout << c;
	    }


	  x.close ();
	}
      else if (u == 4)
	{
	  char eid[20];
	  char d;
	  cout << "\nINPUT employee ID to search\n";
	  cin >> eid;
	  char file[20];
	  strcpy (file, eid);
	  strcat (file, ".txt");
	  ifstream y (file);
	  if (!y)
	    {
	      cout << "file couldn't be opened. employee ID not found. \n";
	    }
	  while (y)
	    {
	      y.get (d);
	      cout << d;
	    }

	  y.close ();
	}
      else if (u == 5)
	{
	  amount u;
	  u.update_item ();
	}
      else if (u == 6)
	{
	  amount v;
	  v.update_emp ();
	}
      else if (u == 7)
	{
	  break;
	}
      else
	cout <<
	  "Invalid option. Please select one of the available options\n";
    }

}
/*//TIME CONVERSION
void cal_IST(int h, float r) 

{
float IST = (h * r * 1.0) / 360; 
// Separate integer part 
int int_IST = (int)IST; 
// Separate float part and return ceil value 
int float_IST = ceil((IST - int_IST) * 60); 
cout << int_IST << ":" << float_IST; 
}*/



int main ()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//password
//int pswrd1=4680;
int pswrd2;
cout<<"\tENTER PASSWORD FOR ENTERING IN SYSTEM:";

cin>>pswrd2;
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

if(pswrd2==4680)
{
    







/*
 cout <<"TO CONFORM YOU ARE HUMAN NOT ROBOT SOFTWARE YOU NEED DO SIMPLE ENTER HRS & MINUTES FROM UNIVERSAL TIME "<<endl;
 int h;
 float r;
 cin >>h;
 cin>>r;
 cal_IST(h, r);
*/

/*
time_t t;
//delay from while function is 1
while(1)
{
    time(&t);
    char*current_time=ctime(&t);
    current_time[strlen(current_time)-1]='\0';
    cout<<"\r current time ="<<current_time;
}
*/

  int ch;
  char username[20];
  char password[20];
  char pwd[20];
  while (1)
    {


time_t tt;
// Declaring variable to store return value of
// localtime()
struct tm * ti;
// Applying time()
time (&tt);
// Using localtime()
ti = localtime(&tt);
cout << "\tCurrent Day, Date and Time is = "<< asctime(ti);





      cout << "\n \t\t\t=========================\n";
      cout << "\n\t\t\t          WELCOME  \n";
      cout << "\n \t\t\t=========================\n\n";
      cout << "\n \t\t\t* * * * * * * * * * * * ";
      cout << "\n\t\t\t  1. ENTER IN PNJ'S SYSTEM";
      cout << "\n\t\t\t  2. EXIT";
      cout << "\n\t\t\t* * * * * * * * * * * *\n";
      cout << "\n\t\t\t Enter Your choice: ";
      cin >> ch;
      switch (ch)
	{
	case 1:
	  admin ();
	  break;
	case 2:
	  exit (0);
	  break;
	default:
	  cout << "Enter valid choice\n";
	  break;
	}
    }
}
else
{
    cout<<"wrong password re-enter in system and try again ";
}
cout<<"THANK YOU!";
  return 0;
}

 

