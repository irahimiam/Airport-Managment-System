//BOOKING FUNCTION
#include "stdafx.h"
#include "customer.h"
#include <iostream>
#include <iomanip>

using namespace std;

void customer::create_customer(){

	cout << "\nEnter Passenget ID :-";
	cin >> id;
	cout << "Enter Admision no. : ";
	cin >> admno;
	cout << "Enter Passenger's Name :- ";
	cin.get();
	cin.getline(name, 20);

	cout << "Enter your email address :- ";
	cin.getline(email, 50);

	cout << "Enter your Phone Number :- ";
	cin >> mobile;
	tiketnumber = 0;
	price = 0;
	cutno[0] = '\0';
}

void customer::disInfo(){
	cout << setw(6) << admno << setw(18)
		<< name << setw(10) << tiketnumber << setw(14) << mobile << setw(12) << email << endl;
}

char* customer::retadmno(){
	return admno;
}

void customer::getcutno(char t[]){
	strcpy(cutno, t);
}

void customer::settiketnumber(int n){
	tiketnumber = n;
}

int customer::rettiketnumber(){
	return tiketnumber;
}

char* customer::retcutno(){
	return cutno;
}

void customer::resettiketnumber(){
	tiketnumber = 0;
}