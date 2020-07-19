#include "stdafx.h"
#include "tiket.h"
#include <iostream>
#include <iomanip>

using namespace std;

void tiket::create_tiket(){

	cout << "Enter Tiket ID :-";
	cin >> id;
	cout << "Enter Admision no. ";
	cin >> tno;
	cout << "Enter Departure : ";
	cin.get();
	cin.getline(departure, 25);
	cout << "Enter Arrival : ";
	cin.get();
	cin.getline(arrival, 25);
	cout << "\nNumber of tiket:-";
	cin >> number;
	cout << "\nEnter Tiket price : ";
	cin >> price;
	cout << "Date of Journey ( DD/MM/YYYY ) :- ";
	cin >> date;
}

void tiket::disinfo(){
	cout << tno << setw(25)
		<< departure << setw(20) << arrival << setw(14) << price << setw(12) << number << endl;
}

char* tiket::rettno(){
	return tno;
}

char* tiket::retdep(){
	return departure;
}

char* tiket::retarri(){
	return arrival;
}

void tiket::show_tiket(){
	cout << "\nTiket number : " << tno;
	cout << "\nDeparture : " << departure;
	cout << "\nArrival : " << arrival;
	cout << "\nPrice : " << price;
	cout << "\nNumber: " << number;
}

void tiket::modify_tiket(){
	cout << "\nTiket number : " << tno;
	cout << "\nModify Departure : ";
	cin.get();
	cin.getline(departure, 25);
	cout << "\nModify Arrival : ";
	cin.get();
	cin.getline(arrival, 25);
	cout << "\nModify Number : ";
	cin >> number;
	cout << "Modify Price : ";
	cin >> price;
}

int tiket::retnumber(){
	return number;
}

int tiket::retprice(){
	return price;
}

void tiket::resettiket(int n){
	number = number - n;
}

char* tiket::retdate(){
	return date;
}

void tiket::settiketnumber(int a){
	number = number + a;
}