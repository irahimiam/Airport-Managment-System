#pragma once
class tiket
{
	char tno[6];
	char date[10];
	int number;
	int price;
	char departure[25];
	char arrival[25];
	//int state;
public:
	int id;
	void create_tiket();
	void disinfo();
	char* rettno();
	void show_tiket();
	void modify_tiket();
	char* retdep();
	char* retarri();
	int retnumber();
	int retprice();
	void resettiket(int);
	char* retdate();
	void settiketnumber(int);
};

