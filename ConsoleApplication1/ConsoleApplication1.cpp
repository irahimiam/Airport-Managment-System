#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "tiket.h"
#include "customer.h"

using  namespace std;

const int size = 100;
tiket b[size];
customer s[size];

void admin_menu();
void write_tiket();
void write_customer();
void display_allt();
void display_allc();
void delete_customer();
void delete_tiket();
void modify_tiket();
void search();
void booking();
void cancellation();

int i = 0;
int a = 0, c = 0;

void main(){

	fstream f1;
	f1.open("customer.dat", ios::in | ios::out | ios::app | ios::binary);
	int k = 0;
	while (k < size && f1.eof() != 1){
		f1.read((char *)&s[k], sizeof(s[k]));
		k++;
	}
	a = k;
	f1.close();
	remove("customer.dat");

	fstream f;
	f.open("tiket.dat", ios::in | ios::out | ios::app | ios::binary);
	int j = 0;
	while (j < size && f.eof() != 1){
		f.read((char *)&b[j], sizeof(b[j]));
		j++;
	}
	c = j;
	f.close();
	remove("tiket.dat");

	char ch;
	do{
		std::system("cls");
		cout << "\n\n*********************************************************************\n";
		cout << "...............Welcome to the IRAN AIR Airline Services .............\n";
		cout << "*********************************************************************\n";
		cout << "\n\n\tMAIN MENU";
		cout << "\n\n\t(1) BOOKING";
		cout << "\n\n\t(2) CANCELLATION";
		cout << "\n\n\t(3) SEARCH";
		cout << "\n\n\t(4) ADMINISTRATOR MENU";
		cout << "\n\n\t(5) SAVE & EXIT";
		cout << "\n\n\tPlease Select Your Option (1-5) ";
		cin >> ch;

		switch (ch){
		case '1':
			booking();
			break;
		case '2':
			cancellation();
			break;
		case '3':
			search();
			break;
		case '4':
			admin_menu();
			break;
		case '5':
		{

					fstream f1;
					f1.open("customer.dat", ios::out | ios::binary | ios::app);
					int z = 0;
					while (z < size){
						if (s[z].id != 0){
							f1.write((char *)&s[z], sizeof(s[z]));
						}
						z++;
					}
					f1.close();

					fstream f;
					f.open("tiket.dat", ios::out | ios::binary | ios::app);
					int x = 0;
					while (x < size){
						if (b[x].id != 0){
							f.write((char *)&b[x], sizeof(b[x]));
						}
						x++;
					}
					f.close();

					exit(0);
		}

		default:
			cout << "\a";
		}
	} while (ch != '5');
}
////////////////////////////////////////////
void admin_menu(){
	std::system("cls");
	int ch2;
	cout << "\n\n\n\tADMINISTRATOR MENU";
	cout << "\n\n\t(1) CREATE CUSTOMER RECORD";
	cout << "\n\n\t(2) DISPLAY ALL CUSTOMER RECORD";
	cout << "\n\n\t(3) DELETE CUSTOMER RECORD";
	cout << "\n\n\t(4) CREATE TIKET ";
	cout << "\n\n\t(5) DISPLAY ALL TIKET ";
	cout << "\n\n\t(6) MODIFY TIKET ";
	cout << "\n\n\t(7) DELETE TIKET ";
	cout << "\n\n\t(8) BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-8) ";
	cin >> ch2;
	switch (ch2){
	case 1:
		std::system("cls");
		write_customer();
		break;
	case 2:
		display_allc();
		break;
	case 3:
		delete_customer();
		break;
	case 4:
		std::system("cls");
		write_tiket();
		break;
	case 5:
		display_allt();
		break;
	case 6:
		modify_tiket();
		break;
	case 7:
		delete_tiket();
		break;
	case 8:
		main();
	default:
		cout << "\a";
	}
	admin_menu();
}
////////////////////////////////////////////
void write_tiket(){
	char ch;

	do{
		std::system("cls");
		b[c].create_tiket();
		c++;
		cout << "\n\nDo you want to add more Tiket...(y/n?)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}

void write_customer(){
	char ch;
	do{
		s[a].create_customer();
		a++;
		cout << "\n\nDo you want to add more Customer...(y/n?)";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}
////////////////////////////////////////////
void display_allc(){
	std::system("cls");
	i = 0;
	cout << "\n\n\t\tCUSTOMER LIST\n\n";
	cout << "=======================================================================\n";
	cout << setw(6) << "Admission No." << setw(10) << "Name" << setw(15) << "No.Tiket" << setw(12) << "Mobile" << setw(12) << "Email\n";
	cout << "=======================================================================\n";

	while (i < size){
		if (s[i].id != 0){
			s[i].disInfo();
		}
		i++;
	}
	cin.get();
	cin.get();
}

void display_allt(){
	std::system("cls");
	i = 0;
	cout << "\n\n\t\tTiket LIST\n\n";
	cout << "==================================================================================\n";
	cout << "Tiket Number" << setw(15) << "Departure" << setw(20) << "Arrival" << setw(15) << "Price" << setw(12) << "Number\n";
	cout << "==================================================================================\n";

	while (i < size) {
		if (b[i].id != 0){
			b[i].disinfo();
		}
		i++;
	}
	cin.get();
	cin.get();
}
////////////////////////////////////////////
void delete_customer(){
	char n[6];
	int flag = 0;
	i = 0;
	std::system("cls");
	cout << "\n\n\n\tDELETE CUSTOMER...";
	cout << "\n\nEnter The admission no. of the Customer You Want To Delete : ";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(s[i].retadmno(), n) == 0){
			s[i].id = 0;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		cout << "\n\n\tRecord Deleted ..";
	else
		cout << "\n\nRecord not found";
	cin.get();
}

void delete_tiket(){
	char n[6];
	int flag = 0;
	i = 0;
	std::system("cls");
	cout << "\n\n\n\tDELETE TIKET ...";
	cout << "\n\nEnter Tiket number of Tiket to Delete : ";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(b[i].rettno(), n) == 0){
			b[i].id = 0;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		cout << "\n\n\tRecord Deleted ..";
	else
		cout << "\n\nRecord not found";
	cin.get();
}
//////////////////////////////////////////////
void modify_tiket(){
	char n[6];
	i = 0;
	int flag = 0;
	std::system("cls");
	cout << "\n\n\tMODIFY TIKET REOCORD.... ";
	cout << "\n\n\tEnter The Tiket no. of The Tiket";
	cin >> n;
	cin.get();

	while (i < size){
		if (strcmp(b[i].rettno(), n) == 0){
			b[i].show_tiket();
			cout << "\nEnter New Details of Tiket" << endl;
			b[i].modify_tiket();
			flag = 1;
			cin.get();
		}
		i++;
	}
	if (flag == 0)
		cout << "\n\nTiket does not exist";
	else
		cout << "\n\n\t Record Updated";
	cin.get();
}
/////////////////////////////////////////////
void search(){
	std::system("cls");
	int choice_1;
	cout << "\tChoose what you want to search\n";
	cout << "\t1. Passengers\n\t2. Tikets\n";
	cout << "Enter your Choice :- ";
	cin >> choice_1;
	cin.get();

	switch (choice_1)
	{
	case 1:
	{
			  char sName[20];
			  char sEmail[20];
			  long sMobile;
			  int choice_2;
			  cout << "\tChoose how you want to search the PASSENGERS list\n";
			  cout << "\t1. By Name\n\t2. By Email\n";
			  cout << "\t3. By Phone Number\n\t";
			  cout << "Enter your Choice :- ";
			  cin >> choice_2;
			  cin.get();

			  switch (choice_2)
			  {
			  case 1:
			  {

						int flag = 0;
						cout << "Enter the name which you want to search :- ";
						cin >> sName;
						cin.get();
						cout << "=======================================================================\n";
						cout << setw(6) << "Admission No." << setw(10) << "Name" << setw(15) << "No.Tiket" << setw(12) << "Mobile" << setw(12) << "Email\n";
						cout << "=======================================================================\n";
						i = 0;
						while (i < size)
						{
							if (strcmp(sName, s[i].name) == 0)
							{
								s[i].disInfo();
								cin.get();
								flag = 1;
							}
							i++;
						}

						if (flag == 0){
							cout << "\n\t!!!!!!Not Found!!!!!!!!\n";
							cin.get();
						}

			  }
				  break;

			  case 2:
			  {
						int flag = 0;
						cout << "Enter the Email-id you want to search :- ";
						cin >> sEmail;
						cin.get();
						cout << "=======================================================================\n";
						cout << setw(6) << "Admission No." << setw(10) << "Name" << setw(15) << "No.Tiket" << setw(12) << "Mobile" << setw(12) << "Email\n";
						cout << "=======================================================================\n";
						i = 0;
						while (i < size)
						{
							if (strcmp(sEmail, s[i].email) == 0)
							{
								s[i].disInfo();
								cin.get();
								flag = 1;
							}
							i++;
						}

						if (flag == 0){
							cout << "\t\tNot Found !!!\n";
							cin.get();
						}
			  }
				  break;

			  case 3:
			  {
						int flag = 0;
						cout << "Please Enter the phone number which you want to search :- ";
						cin >> sMobile;
						cin.get();

						cout << "=======================================================================\n";
						cout << setw(6) << "Admission No." << setw(10) << "Name" << setw(15) << "No.Tiket" << setw(12) << "Mobile" << setw(12) << "Email\n";
						cout << "=======================================================================\n";
						i = 0;
						while (i < size)
						{
							if (sMobile == s[i].mobile)
							{
								s[i].disInfo();
								cin.get();
								flag = 1;
							}
							i++;
						}

						if (flag == 0){
							cout << "\tNot Found !!!!!!!!\n";
							cin.get();
						}

			  }
				  break;
			  }
	}
		break;

	case 2:
	{
			  char sdeparture[25];
			  char sarrival[25];
			  int id;
			  int choice_3;
			  cout << "\tChoose how you want to search the Tiket list\n";
			  cout << "\t1. By ID\n\t2. By Departure\n";
			  cout << "\t3. By Arrival\n\t";
			  cout << "Enter your Choice :- ";
			  cin >> choice_3;
			  cin.get();

			  switch (choice_3)
			  {
			  case 1:
			  {
						int flag = 0;
						cout << "Enter the ID you want to search :- ";
						cin >> id;
						cin.get();
						i = 0;
						while (i < size)
						{
							if (id==b[i].id)
							{
								b[i].show_tiket();
								cin.get();
								flag = 1;
							}
							i++;
						}

						if (flag == 0){
							cout << "\t\tNot Found !!!\n";
							cin.get();
						}
			  }
				  break;

			  case 2:
			  {
						int flag = 0;
						cout << "Enter the Departure you want to search :- ";
						cin.getline(sdeparture, 25);
						cin.get();
						i = 0;
						while (i < size)
						{
							if (strcmp(sdeparture, b[i].retdep())  == 0)
							{
								b[i].show_tiket();
								cin.get();
								flag = 1;
							}
							i++;
						}

						if (flag == 0){
							cout << "\t\tNot Found !!!\n";
							cin.get();
						}
			  }
				  break;

			  case 3:
			  {
						int flag = 0;
						cout << "Enter the Arrival you want to search :- ";
						cin >> sarrival;
						cin.get();
						i = 0;
						while (i < size)
						{
							if (strcmp(sarrival, b[i].retarri()) == 0)
							{
								b[i].show_tiket();
								cin.get();
								flag = 1;
							}
							i++;
						}

						if (flag == 0){
							cout << "\t\tNot Found !!!\n";
							cin.get();
						}
			  }
				  break;
			  }

	}
		break;
	}


}
///////////////////////////////////////////////
void booking(){
	char sn[6];
	char bn[6];
	int found = 0, flag = 0;
	std::system("cls");
	cout << "\n\nBOOKING...";
	cout << "\n\n\tEnter Passenger's Admission number : ";
	cin >> sn;
	cin.get();

	i = 0;
	int m = 0;

	while (i < size){
		if ((strcmp(s[i].retadmno(), sn) == 0)){
			flag = 1;
			m = i;
		}
		i++;
	}
	if (flag == 0){
		cout << "\n\nPassenger does not exist";
		cin.get();
	}
	else
	{
				  
		cout << "\n\n\tEnter Tiket number : ";
		cin >> bn;
		cin.get();

		int flag3 = 0;
		i = 0;
		int n = 0;
	    while (i < size){
			if (strcmp(b[i].rettno(), bn) == 0){
				 flag3 = 1;
				 n = i;
			}
			i++;
	    }
		if (flag3 == 0){
			cout << "\n\nTiket does not exist";
			cin.get();
	    }
		else{
			int number;
			b[n].show_tiket();

			do{
				cout << "\nHow many Tiket you Want ...Pleas Enter Number :";
				cin >> number;
			} while (number > b[n].retnumber());

			int sum = 0;
			sum += number*b[n].retprice();
			b[n].resettiket(number);
			s[m].getcutno(b[n].rettno());
			s[m].settiketnumber(number);

			cout << "\n\n\t Tiket Booked successfully\n";
			cout << "****************************************YOUR FACTOR****************************************\n";
			cout << "\t\t-----------------------------\n";
			cout << "Your Payment is : " << sum;
			cout << "\nYou bought : " << number << " Tiket.";
			cout << "\nyour flight will toke off in :" << b[n].retdate();
			cout << "\nDeparture :" << b[n].retdep() << "\tArrival :" << b[n].retarri();
			cout << "\nEnjoy your flight...";
			cin.get();

		}

	}
	cin.get();
}
/////////////////////////////////////////////
void cancellation(){
	char sn[6];
	int found = 0, flag = 0;
	std::system("cls");
	cout << "\n\nTiket Cancellation ...";
	cout << "\n\n\tEnter Passenger’s Admission number : ";
	cin >> sn;
	cin.get();

	i = 0;
	int m = 0;
	while (i < size){
		if ((strcmp(s[i].retadmno(), sn) == 0)){
			flag = 1;
			m = i;
		}
		i++;
	}
	if (flag == 0){
		cout << "\n\nPassenger does not exist";
	}
	else{
		if (s[m].rettiketnumber() != 0){
			i = 0;
			while (i < size){
				if (strcmp(b[i].rettno(), s[m].retcutno()) == 0){
					b[i].show_tiket();
					b[i].settiketnumber(s[m].rettiketnumber());
					s[m].resettiketnumber();
					
					cout << "\n\n\t Tiket canceled successfully";
					cout << "\nYour money is gone.";
					cin.get();
				}
				i++;
			}
			
		}
		else
			cout << "No Tiket is Booked..please check!!";
	}
	cin.get();
}