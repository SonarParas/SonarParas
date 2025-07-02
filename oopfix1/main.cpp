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



char catagories[][15]={"Rings","Ear Rings","Bracelet","Pendant","Chain","Jewellery Set"}; 

void returnfunc(void); 

void mainmenu(void); 

void additem(void); 

void deleteitem(void); 

void edititem(void); 

void searchitem(void); 

void viewitem(void); 

void closeapplication(void); 

void calculatebill(void); 

int getdata(); 

int checkid(int); 

int t(void);



void Password(); 

void issuerecord(); 

void loaderanim();





FILE *fp,*ft,*fs;

COORD coord = {0, 0};



int s; 

char findstaff; 

char password[10]={"pass"}; //replace "pass" with your own if you wish to change the password



void gotoxy (int x, int y) 

{ 

coord.X = x; coord.Y = y; 

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 

}



struct meroDate 

{ 

int mm,dd,yy; 

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

int main() 

{ 

Password(); 

getch(); 

return 0;



} 

void mainmenu() 

{ 

system("cls"); 

int i; 

gotoxy(20,3); 

//printf(" \t\tMAIN MENU \n "); 
cout<<"\t\tMAIN MENU \n ";
//printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
cout<<"\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";


gotoxy(20,5); 

//printf("<1> Add Jewellery Items "); 
cout<<"<1> Add Jewellery Items ";
gotoxy(20,7); 

//printf("<2> Remove Items"); 
cout<<"<2> Remove Items";
gotoxy(20,9); 

//printf("<3> Search Items"); 
cout<<"<3> Search Items";
gotoxy(20,11); 

//printf("<4> View Item's List'"); 
cout<<"<4> View Item's List'";
gotoxy(20,13); 

//printf("<5> Edit Items"); 
cout<<"<5> Edit Items";
gotoxy(20,15); 

//printf("<6> Calculate Bill");
cout<<"<6> Calculate Bill"; 

gotoxy(20,17); 
 

gotoxy(20,2); 

t(); 

gotoxy(20,20); 

//printf("Enter your choice:");
cout<<"Enter your choice:"; 



switch(getch()) 

{ 

case '1': 

additem(); 

break; 

case '2': 

deleteitem(); 

break; 

case '3': 

searchitem(); 

break; 

case '4': 

viewitem(); 

break; 

case '5': 

edititem(); 

break; 

case '7': 

{ 

system("cls"); 

gotoxy(16,3); 

//printf("\tJewellery Store Management System"); 
cout<<"\tJewellery Store Management System";
gotoxy(16,4); 

//printf("\tIn C Programming"); 
cout<<"\tIn C Programming";
gotoxy(16,5); 

//printf("\tDeveloped By"); 
cout<<"\tDeveloped By";

gotoxy(16,7); 

//printf("\t\t.....PARAS SONAR");
cout<<"\t\t.....PARAS SONAR";
//printf("\n\t\t\tPROJECT MADE BY....PARAS , NILESH & JIVAN");
cout<<"\n\t\t\tPROJECT MADE BY....PARAS , NILESH & JIVAN";

gotoxy(16,8);



exit(0); 

} 

case '6':
calculatebill();
break; 

default: 

{ 

gotoxy(10,25); 

//printf("\aWrong Entry!!Please re-entered correct option"); 
cout<<"\aWrong Entry!!Please re-entered correct option";
if(getch())


mainmenu(); 

}



} 

} 

void additem(void)

{ 

system("cls"); 

int i; 

gotoxy(20,5); 

//printf("SELECT CATEGOIES"); 
cout<<"SELECT CATEGOIES";
gotoxy(20,7); 

//printf("<1> Rings"); 
cout<<"<1> Rings";
gotoxy(20,9); 

//printf("<2> Ear Rings"); 
cout<<"<2> Ear Rings";
gotoxy(20,11); 

//printf("<3> Bracelet"); 
cout<<"<3> Bracelet";
gotoxy(20,13); 

//printf("<4> Pendant"); 
cout<<"<4> Pendant";
gotoxy(20,15); 

//printf("<5> Chain"); 
cout<<"<5> Chain";
gotoxy(20,17); 

//printf("<6> Jewellery Set"); 
cout<<"<6> Jewellery Set";
gotoxy(20,19); 

//printf("<7> Back to main menu"); 
cout<<"<7> Back to main menu";
gotoxy(20,21);



//printf("Enter your choice:"); 
cout<<"Enter your choice:";
//scanf("%d",&s); 
cin>>s;
if(s==7)



mainmenu() ; 

system("cls"); 

fp=fopen("stf.dat","ab+"); 

if(getdata()==1) 

{ 

a.cat=catagories[s-1]; 

fseek(fp,0,SEEK_END); 

fwrite(&a,sizeof(a),1,fp); 

fclose(fp); 

gotoxy(21,14); 

//printf("The record is sucessfully saved"); 
cout<<"The record is sucessfully saved";
gotoxy(21,15); 

//printf("Save any more?(Y / N):"); 
cout<<"Save any more?(Y / N):";
if(getch()=='n') 

mainmenu(); 

else 

system("cls"); 

additem(); 

} 

} 

void deleteitem() 

{ 

system("cls"); 

int d; 

char another='y'; 

while(another=='y') 

{ 

system("cls"); 

gotoxy(10,5); 

//printf("Enter the Item Code to delete:"); 
cout<<"Enter the Item Code to delete:";
//scanf("%d",&d); 
cin>>d;
fp=fopen("stf.dat","rb+"); 

rewind(fp); 

while(fread(&a,sizeof(a),1,fp)==1) 

{ 

if(a.id==d) 

{



gotoxy(10,7); 

//printf("The Item is available"); 
cout<<"The Item is available";
gotoxy(10,8); 

//printf("Item's name is %s",a.name); 
cout<<"Item's name is "<<a.name;
gotoxy(10,9); 

findstaff='t'; 

} 

} 

if(findstaff!='t') 

{ 

gotoxy(10,10); 

//printf("No record is found modify the search"); 
cout<<"No record is found modify the search";
if(getch()) 

mainmenu(); 

} 

if(findstaff=='t' ) 

{ 

gotoxy(10,9); 

//printf("Do you want to delete it?(Y/N):"); 
cout<<"Do you want to delete it?(Y/N):";
if(getch()=='y') 

{ 

ft=fopen("test.dat","wb+"); 

rewind(fp); 

while(fread(&a,sizeof(a),1,fp)==1) 

{ 

if(a.id!=d) 

{ 

fseek(ft,0,SEEK_CUR); 

fwrite(&a,sizeof(a),1,ft); 

} 

} 

fclose(ft); 

fclose(fp); 

remove("stf.dat"); 

rename("test.dat","stf.dat"); 

fp=fopen("stf.dat","rb+"); 

if(findstaff=='t') 

{ 

gotoxy(10,10); 

//printf("The record is sucessfully deleted"); 
cout<<"The record is sucessfully deleted";
gotoxy(10,11); 

//printf("\n\tDelete another record?(Y/N)"); 
cout<<"\n\tDelete another record?(Y/N)";
} 

} 

else 

mainmenu(); 

fflush(stdin); 

another=getch(); 

} 

} 

gotoxy(10,15); 

mainmenu(); 

} 

void searchitem() 

{ 

system("cls"); 

int d; 

//printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Search Item\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Search Item\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,10); 

//printf("1. Search By Code"); 
cout<<"1. Search By Code";
gotoxy(20,14); 

//printf("2. Search By Name"); 
cout<<"2. Search By Name";
gotoxy( 15,20); 

//printf("Enter Your Choice"); 
cout<<"Enter Your Choice";
fp=fopen("stf.dat","rb+"); 

rewind(fp);

switch(getch()) 

{ 

case '1': 

{ 

system("cls"); 

gotoxy(25,4); 

//printf("\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Code\xB2\xB2\xB2\xB2\xB2\xB2"); 
cout<<"\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Code\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,5); 

//printf("Enter the Item Code:"); 
cout<<"Enter the Item Code:";
//scanf("%d",&d); 
cin>>d;
gotoxy(20,7); 

while(fread(&a,sizeof(a),1,fp)==1) 

{ 

if(a.id==d) 

{ 

sleep(2); 

gotoxy(20,6); 

//printf("The Item is available\n"); 
cout<<"The Item is available\n";
gotoxy(20,8); 

//printf("Item Code:%d",a.id); 
cout<<"Item Code:"<<a.id;
gotoxy(20,9); 

//printf("Category:%s",a.cat); 
cout<<"Category:"<<a.cat;
gotoxy(20,10); 

 
cout<<"Name:"<<a.name;
gotoxy(20,11); 

//printf("Material:%s ",a.Material); 
cout<<"Material: "<<a.Material;
gotoxy(20,12); 


cout<<"Quantity: "<<a.Quantity;
gotoxy(20,13); 

//printf("Weight:%i",a.weight); 
cout<<"Weight: "<<a.weight;
gotoxy(20,14); 

 
cout<<"Karat: "<<a.karat;
gotoxy(20,d+15); 

findstaff='t'; 

}



} 

if(findstaff!='t') 

{ 

//printf("\aNo Record Found"); 
cout<<"\aNo Record Found";
} 

gotoxy(20,17); 

//printf("Try another search?(Y/N)"); 
cout<<"Try another search?(Y/N)";
if(getch()=='y') 

searchitem(); 

else 

mainmenu(); 

break; 

} 

case '2': 

{ 

char s[15]; 

system("cls"); 

gotoxy(25,4); 

//printf("\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Name\xB2\xB2\xB2\xB2\xB2\xB2"); 
cout<<"\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Name\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(20,5); 

//printf("Enter Item's Name:"); 
cout<<"Enter Item's Name:";
//scanf("%s",s); 
cin>>s;
int d=0; 

while(fread(&a,sizeof(a),1,fp)==1) 

{ 

if(strcmp(a.name,(s))==0) 

{ 

gotoxy(20,d+7); 

//printf("The Staff is available"); 
cout<<"The Staff is available";
gotoxy(20,d+8); 

//printf("Item Code:%d",a.id); 
cout<<"Item Code:"<<a.id;
gotoxy(20,d+10);


cout<<"Name:"<<a.name;
gotoxy(20,d+11); 

//printf("Material:%s",a.Material); 
cout<<"Material:"<<a.Material;
gotoxy(20,d+12); 


cout<<"Quantity:"<<a.Quantity;
gotoxy(20,d+13); 


cout<<"Weight:"<<a.weight;
gotoxy(20,d+14);

//printf("Karat:%i",a.karat); 
cout<<"Karat:"<<a.karat;
gotoxy(20,d+15); 

getch(); 

d+=6; 

}



} 

if(d==0)




cout<<"\aNo Record Found";


gotoxy(20,d+11); 


cout<<"Try another search?(Y/N)";
if(getch()=='y') 

searchitem(); 

else 

mainmenu(); 

break; 

} 

default : 

getch(); 

searchitem(); 

} 

fclose(fp); 

}



void viewitem(void) 

{ 

int i=0,j; 

system("cls"); 

gotoxy(1,1); 


cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Item's List\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
gotoxy(2,2); 


cout<<"CATEGORY ITEM CODE ITEM NAME MATERIAL QUANTITY WEIGHT RANGE KARAT (K)";

j=4; 

fp=fopen("stf.dat","rb"); 

while(fread(&a,sizeof(a),1,fp)==1) 

{ 

gotoxy(3,j); 


cout<<""<<a.cat;
gotoxy(16,j);

cout<<""<<a.id;
gotoxy(24,j); 

 
cout<<""<<a.name;
gotoxy(39,j); 

 
cout<<""<<a.Material;
gotoxy(51,j); 


cout<<""<<a.Quantity;
gotoxy(62,j); 


cout<<""<<a.weight;
gotoxy(76,j); 

 
cout<<""<<a.karat;
gotoxy(81,j); 


cout<<"\n\n";
j++; 

} 

fclose(fp); 

gotoxy(35,25); 

returnfunc(); 

} 

void edititem(void) 

{ 

system("cls"); 

int c=0; 

int d,e; 

gotoxy(20,4); 


cout<<"\xB2\xB2\xB2\xB2\xB2\xB2 Edit Items Section \xB2\xB2\xB2\xB2\xB2\xB2";
char another='y'; 

while(another=='y') 

{ 

system("cls"); 

gotoxy(15,6); 


cout<<"Enter Item's code to be edited:";
//scanf("%d",&d); 
cin>>d;
fp=fopen("stf.dat","rb+"); 

while(fread(&a,sizeof(a),1,fp)==1) 

{ 

if(checkid(d)==0) 

{ 

gotoxy(15,7); 


cout<<"The Item is availble";
gotoxy(15,8); 

 
cout<<"The Item's Code:"<<a.id;
gotoxy(15,9); 


cout<<"Enter new name:";
//scanf("%s",a.name); 
cin>>a.name;
gotoxy(15,10); 

 
cout<<"Enter new Material:";
//scanf("%s",a.Material); 
cin>>a.Material;
gotoxy(15,11); 

 
cout<<"Enter new Quantity:";
//scanf("%i",&a.Quantity); 
cin>>a.Quantity;
gotoxy(15,12); 

 
cout<<"Enter new Weight Range:";
//scanf("%i",&a.weight); 
cin>>a.weight;
gotoxy(15,13); 

 
cout<<"Enter new Karat:";
//scanf("%i",&a.karat); 
cin>>a.karat;
gotoxy(15,14); 


cout<<"The record is modified";
fseek(fp,ftell(fp)-sizeof(a),0); 

fwrite(&a,sizeof(a),1,fp); 

fclose(fp); 

c=1; 

} 

if(c==0) 

{ 

gotoxy(15,9); 

 
cout<<"No record found";
} 

} 

gotoxy(15,16); 

 
cout<<"Modify another Record?(Y/N)";
fflush(stdin); 

another=getch() ; 

} 

returnfunc(); 

} 

void returnfunc(void) 

{ 

{ 

gotoxy(15,20); 


cout<<"Press ENTER to return to main menu";
} 

a: 

if(getch()==13) 

mainmenu(); 

else 

goto a; 

} 

int getdata() 

{ 

int t; 

gotoxy(20,3); 


cout<<"Enter the Information Below";
gotoxy(20,4); 


cout<<"Category:";
gotoxy(31,5); 


cout<<""<<catagories[s-1];
gotoxy(21,6);
 
cout<<"Item Code:\t";
gotoxy(31,6); 

//scanf("%d",&t); 
cin>>t;
if(checkid(t) == 0) 

{ 
cout<<"\aThe Item Code already exists\a";
gotoxy(21,13); 

 
getch(); 

mainmenu(); 

return 0; 

} 

a.id=t; 

gotoxy(21,7); 

cout<<"Item's Name:";
gotoxy(33,7); 

//scanf("%s",a.name); 
cin>>a.name;
gotoxy(21,8); 


cout<<"Material:";
gotoxy(30,8); 

//scanf("%s",a.Material); 
cin>>a.Material;
gotoxy(21,9); 

 
cout<<"Quantity:";
gotoxy(31,9); 

//scanf("%i",&a.Quantity); 
cin>>a.Quantity;
gotoxy(21,10); 


cout<<"Weight Range:";
gotoxy(34,10); 

//scanf("%i",&a.weight); 
cin>>a.weight;
gotoxy(21,11); 

//printf("Karat:"); 
cout<<"Karat:";
gotoxy(27,11); 

//scanf("%i",&a.karat); 
cin>>a.karat;
gotoxy(21,11);





return 1; 

} 

int checkid(int t) 

{ 

rewind(fp); 

while(fread(&a,sizeof(a),1,fp)==1) 

if(a.id==t) 

return 0;

return 1; 

} 

int t(void) 

{ 

time_t t; 

time(&t); 


cout<<"Date and time:\n"<<ctime(&t);


return 0 ; 

}



void Password(void) 

{



system("cls"); 

char d[25]="Password Protected"; 

char ch,pass[10]; 

int i=0,j;





//printf("\t\t\t\t\tWELCOME\n\t\t\t\t\t To \n\t\t \xB2\xB2\xB2\xB2\xB2\xB2 Jewellery Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n"); 
cout<<"\t\t\t\t\tWELCOME\n\t\t\t\t\t To \n\t\t \xB2\xB2\xB2\xB2\xB2\xB2 Jewellery Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n";
//printf("\t \n\n\n Enter Password:"); 
cout<<"\t \n\n\n Enter Password:";


while(ch!=13) 

{ 

ch=getch();



if(ch!=13 && ch!=8){ 

putch('*'); 

pass[i] = ch; 

i++; 

} 

} 

pass[i] = '\0'; 

if(strcmp(pass,password)==0) 

{ 

//printf("\n\n\n\t\tPassword matched!!"); 
cout<<"\n\n\n\t\tPassword matched!!";
//printf("\n\n\tPress any key to countinue....."); 
cout<<"\n\n\tPress any key to countinue.....";
getch(); 

mainmenu(); 

} 

else 

{ 

//printf("\n\n\n\t\t\aWarning!! \n\t Incorrect Password"); 
cout<<"\n\n\n\t\t\aWarning!! \n\t Incorrect Password";
getch(); 

Password(); 

} 

} 

void calculatebill()
{
int custid, wgh, chr, rte, dis;
float chg, surchg=0, gramt,netamt;
char connm[25];
system("CLS");
//printf("================================================================");
cout<<"================================================================";
//printf("\n");
cout<<"\n";
//printf("\tEnter Customer ID :");
cout<<"\tEnter Customer ID :";
//scanf("%d",&custid);
cin>>custid;
cout<<"\n";
//printf("\tEnter the Name of the Customer :");
cout<<"\tEnter the Name of the Customer :";
//scanf("%s",connm);
cin>>connm;
cout<<"\n";
//printf("\tEnter the Weight (In Gram) : ");
cout<<"\tEnterw the Weight (In Gram) : ";
//scanf("%d",&ghw);
cin>>wgh;
cout<<"\n";
//printf("\tEnter Making Charges : ");
cout<<"\tEnter Making Charges : ";
//scanf("%d",&chr);
cin>>chr;
cout<<"\n";
//printf("\tEnter Current Gold/Silver rate : ");
cout<<"\tEnter Current Gold/Silver rate : ";
//scanf("%d",&rte);
cin>>rte;
cout<<"\n";
//printf("\tDiscount Amount Rs.: ");
cout<<"\tDiscount Amount Rs.: ";
//scanf("%d",&dis);
cin>>dis;
//printf("================================================================"); 
cout<<"================================================================";
//printf("\n");
cout<<"\n";
//printf("\t Press Enter To Display Total Bill of Mr/Mrs :%s",connm);
cout<<"\t Press Enter To Display Total Bill of Mr/Mrs :"<<connm;
getch();
system("CLS");
surchg = (rte*wgh)+chr-dis; //calculation process
netamt = surchg;
//printing final bill
//printf("\n\t\t===============Jewellery Bill================\n");
cout<<"\n\t\t===============INVOICE/BILL================\n";
cout<<"\t\t===============PNJ Jewellers================\n";
//printf("\t\tCustomer IDNO :%d\n",custid);
cout<<"\t\tCustomer IDNO :"<<custid;
cout<<"\n";
//printf("\t\tCustomer Name:%s\n",connm);
cout<<"\t\tCustomer Name:"<<connm;
cout<<"\n";
//printf("\t\tTotal Weight :%d\n",wgh);
cout<<"\t\tTotal Weight :"<<wgh;
//printf("\n");
cout<<"\n";
cout<<"\t\tDiscount Amount :"<<dis;
cout<<"\n";
//printf("\t\tSurchage Amount :",surchg);
cout<<"\t\tSurchage Amount :"<<surchg;
//printf("\n");
cout<<"\n";
//printf("\t\tNet Amount Paid By the Customer :%8.2f\n",netamt);
cout<<"\t\tNet Amount Paid By the Customer :\n"<<netamt;
cout<<"\t\t=============================================\n";

getch();
mainmenu();
}
