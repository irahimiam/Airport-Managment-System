//class booking
#pragma once

using namespace std;

class customer
{
public:
	char name[20];
	char email[50];
	long int mobile;
	int price;
	int tiketnumber;
	char admno[6]; //Admission number
	char cutno[6];
	//int token;
public:
	int id;
	void create_customer();
	void disInfo();
	char* retadmno();
	void getcutno(char t[]);
	void settiketnumber(int);
	int rettiketnumber();
	char* retcutno();
	void resettiketnumber();
};