#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cmath>
#include "mygraphics.h"
#include "myconsole.h"
#include <conio.h>
#include <time.h>
using namespace std;
class Date {
	int date;
	int month;
	int year;
public:
	Date() { date = month = year = 0; }
	Date(int d, int m, int y) { setDate(d, m, y); }
	Date(const Date& d) {
		date = d.date;
		month = d.month;
		year = d.year;
	}
	void setDate(int d, int m, int y) {
		date = d;
		month = m;
		year = y;
	}
	Date getDate() { return *this; }
	bool operator == (Date d) {
		if (this->date == d.date)
			if (this->month == d.month)
				if (this->year == d.year)
					return true;
		return false;
	}
	void PrintDate() { cout << date << "/" << month << "/" << year; }
};

class Time {
	int hour;
	int minutes;
public:
	Time() { hour = minutes = 0; }
	Time(int h, int m) { setTime(h, m); }
	Time(const Time& t) {
		hour = t.hour;
		minutes = t.minutes;
	}
	void setTime(int h, int m) {
		hour = h;
		minutes = m;
	}
	Time getTime() { return *this; }
	bool operator == (Time d) {
		if (this->hour == d.hour)
			if (this->minutes == d.minutes)
				return true;
		return false;
	}
	void PrintTime() { cout << hour << ":" << minutes; }
};

class Dealers
{
	int ID;
	string name;
public:
	Dealers(int i, string n)
	{
		ID = i;
		name = n;
	}
	int getid() { return ID; }
	string getname() { return name; }
	void setID(int i) { ID = i; }
	void setName(string n) { name = n; }
	void GatherData()
	{
		//read data from file
	}

};

class WorkingShift
{
	int ID;
	Time StartingTime;
	Time EndingTime;
public:
	WorkingShift()
	{
		ID = 0;
		
	}

	WorkingShift(int i, Time St, Time Et)
	{
		ID = i;
		StartingTime = St;
		EndingTime = Et;
	}
	void SetStartTime(Time st) { StartingTime = st; }
	void setendtime(Time et) { EndingTime = et; }
	void setId(int i) { ID = i; }
	int getid() { return ID; }
	Time getstarttime() { return StartingTime; }
	Time getendtime() { return EndingTime; }
	void modifyworkingshift();

};

class Schedule
{
	int ID;
	WorkingShift* shift;
public:
	Schedule()
	{
		ID = 0;
		shift = nullptr;
	}
	Schedule(int i, WorkingShift* s)
	{
		setID(i);
		setshift(s);
	}
	int getid() { return ID; }
	void setID(int i) { ID = i; }
	void setshift(WorkingShift* sh) { shift = sh; }
	void createschedule();
	void modifyschedule();


};

class Attendance
{
	Time checkin[12][30];
	Time  checkout[12][30];

public:
	Attendance()
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 30; j++) {
				checkin[i][j].setTime(0, 0);
				checkout[i][j].setTime(0, 0);
			}
		}
	}
};

class Staff
{
	int ID;
	string name;
	string address;
	string phoneno;
	string designation;
	Schedule* staffschedule;
	Time AvgTime;
	string status;
	Attendance* markattendance;

public:

	Staff() {
		ID = 0;
		name = "";
		address = " ";
		phoneno = "";
		designation = " ";
		status = " ";
		AvgTime.setTime(0, 0);
		staffschedule = nullptr;
		markattendance = nullptr;
	}
	Staff(int i, string a, string ph, string d, string s, Time av, Schedule* sc, Attendance* at)
	{
		ID = i;
		address = a;
		phoneno = ph;
		designation = d;
		status = s;
		AvgTime = av;
		staffschedule = sc;
		markattendance = at;
	}
	void setID(int i) { ID = i; }
	void setName(string n) { name = n; }
	void setaddress(string a) { address = a; }
	void setphoneno(string p) { phoneno = p; }
	void setdesignation(string d) { designation = d; }
	void setAvgTime(Time t) { AvgTime = t; }
	void setStatus(string s) { status = s; }
	int getID() { return ID; }
	string getName() { return name; }
	string getaddress() { return address; }
	string getphoneno() { return phoneno; }
	string getdesignation() { return designation; }
	string getstatus() { return status; }
	Time getAvgTime() { return AvgTime.getTime(); }
	void MarkAttendance(char c)
	{
		//if checkin call checkin fun and vice versa
	}
};

class User
{
	int ID;
	string name;
	string address;
	string phoneno;
	string email;
	string password;
	string* UserVehicleList;
	Date** appointments;

public:
	User() {
		ID = 0;
		name = "";
		address = " ";
		email = "";
		password = " ";
		phoneno = " ";
		UserVehicleList = nullptr;
		appointments = nullptr;
	}
	User(int i, string a, string ph, string e, string p, string* vl, Date** ap)
	{
		ID = i;
		address = a;
		phoneno = ph;
		email = e;
		password = p;
		UserVehicleList = vl;
		appointments = ap;
	}
	void setID(int i) { ID = i; }
	void setName(string n) { name = n; }
	void setaddress(string a) { address = a; }
	void setphoneno(string p) { phoneno = p; }
	void setpassword(string d) { password = d; }
	void setemail(string e) { email = e; }
	int getID() { return ID; }
	string getName() { return name; }
	string getaddress() { return address; }
	string getphoneno() { return phoneno; }
	string getpassword() { return password; }
	string getemail() { return email; }
	bool SignIn(string id, string password) {
		string userID, userPass, word;

		ifstream userfile;
		bool userLogin = false;

		userID = id;

		userPass = password;
		userfile.open("UserCredentials.txt");
		while (!userfile.eof()) {
			userfile >> word;
			if (word == userID) {
				userfile >> word;
				if (word == userPass) {
					userLogin = true;
				}
			}
			else {
				userfile >> word;
			}
		}
		userfile.close();
		if (userLogin == true) {
			return true;
		}
		else {
			cout << "Wrong User credentials\n";
			return false;
		}



	}
	bool Signup(string id, string password) {
		ofstream userfile;
		string userID, userPass, word;
		userID = id;
		userPass = password;
		userfile.open("UserCredentials.txt");
		userfile << userID;
		userfile << "\n";
		userfile << userPass;
		userfile.close();
		return true;
	}
	bool Signout();
	void Payment();
	void BookAppointment();
	void editmileage();
};

class OutletAdmin : public Staff
{
	int OutletID;
	User** userlist;

public:
	OutletAdmin()
	{
		OutletID = 0;
		userlist = nullptr;
	}
	OutletAdmin(int id, User** ul)
	{
		OutletID = id;
		userlist = ul;
	}
	void createoutlets();
	void updateoutlets();
	void  blockoullets();
	void deleteoullets();
	void deactivaleaccount();
	void terminateomployee();
	void transferemployee();
	void transferuser();


	~OutletAdmin()
	{
		userlist = nullptr;
	}
};

class InventoryManager : public Staff
{
public:
	InventoryManager()
	{
		Staff();
	}
	void allocateinventory();
	void definereorderlevel();
	void changereorderlevel();
};

class WorkshopManager : public Staff
{
	Schedule* workschedule;
public:
	WorkshopManager()
	{
		Staff();
		workschedule = nullptr;
	}
	void manageschedules();
	void approveleaves();
	void addleavequotas();
	void runmonthlyreports();
	void runannualreports();
	void viewpredictedjobs();


};

class FloorManager : public Staff
{
public:
	FloorManager()
	{
		Staff();
	}
	bool returnitems();
	void viewjobs();
	void runreports();
};

class Outlet
{
	int OutletID;
	string Location;
	Staff** StaffList;

public:
	Outlet(int i, string c) {
		OutletID = i;
		Location = c;
	}
	void NotifyCustomerVisit();
	void setOutletID(int i) {
		OutletID = i;
	}
	void setLocation(string s) {
		Location = s;
	}

};

class System
{
	Outlet** outletlist;
	Staff** stafflist;
	Dealers** DealerList;
public:
	System()
	{
		outletlist == nullptr;
		stafflist = nullptr;
		DealerList = nullptr;

	}
	void displayAdminScreen() {
		cout << "Welcome to Admin Panel of S&J Motors\n";
	}
	void displayUserScreen() {
		cout << "Welcome to User Panel of S&J Motors\n";

	}
	void notifynnewcustomers();
	void sendotp();
	void computedailyavgmilage();
	void computeprojectedmilage();
	void predictcost();
};
char DisplayMenu() {
	COLORREF black = RGB(0, 0, 0);
	COLORREF white = RGB(255, 255, 255);
	COLORREF red = RGB(255, 0, 0);
	COLORREF yellow = RGB(255, 255, 0);
	COLORREF blue = RGB(0, 0, 190);
	COLORREF grey = RGB(128, 128, 128);
	COLORREF pink = RGB(249, 139, 136);
	COLORREF purple = RGB(255, 0, 255);
	char ch = 0;
	int x1, y1, y2;
	x1 = 50, y1 = 30, y2 = 650;
	ClearScreen();
	myDrawTextWithFont(450, 120, 80, (char*)"S AND J MOTORS", blue, black);
	myDrawTextWithFont(220, 300, 50, (char*)"1. User Portal", white, black);
	myDrawTextWithFont(800, 300, 50, (char*)"2. Admin Portal", white, black);
	myDrawTextWithFont(600, 500, 50, (char*)"3. Exit", white, black);
	//myDrawTextWithFont(570, 600, 30, (char*)"Choose an option", grey, black);
	for (int i = x1; x1 <= 1130;) {
		myEllipse(x1, y1, x1 + 30, y1 + 30, grey, black);
		myRect(x1 + 32, y1, x1 + 75, y1 + 30, black, grey);
		myEllipse(x1, y2, x1 + 30, y2 + 30, grey, black);
		myRect(x1 + 32, y2, x1 + 75, y2 + 30, black, grey);
		x1 = x1 + 77;
	}
	for (int k = y1; y1 <= 600;) {
		myEllipse(x1, y1, x1 + 30, y1 + 30, grey, black);
		myRect(x1, y1 + 32, x1 + 30, y1 + 75, black, grey);
		myEllipse(50, y1, 80, y1 + 30, grey, black);
		myRect(50, y1 + 32, 80, y1 + 75, black, grey);
		y1 = y1 + 77;
	}
	myEllipse(x1, y1, x1 + 30, y1 + 30, grey, black);
	do {
		ch = _getch();
	} while (!(ch >= '1' && ch <= '5'));
	return ch;
}

int main() {
	DisplayMenu();
	//char option;
	//cout << "Welcome to S&J Motors\nTo enter the system as an Admin, enter 'a'\nTo enter the system as a User, enter 'u'\n";
	//cin >> option;
	//if (option == 'a' || option == 'A') {
	//	string adminID, adminPass, word;
	//	ifstream adminfile;
	//	bool adminLogin = false;
	//	cout << "Enter Admin ID: ";
	//	cin >> adminID;
	//	cout << "Enter Admin password: ";
	//	cin >> adminPass;
	//	adminfile.open("AdminCredentials.txt");
	//	while (!adminfile.EOF()) {
	//		adminfile >> word;
	//		if (word == adminID) {
	//			adminfile >> word;
	//			if (word == adminPass) {
	//				adminLogin = true;
	//			}
	//		}
	//		else {
	//			adminfile >> word;
	//		}
	//	}
	//	adminfile.close();
	//	if (adminLogin == true) {
	//		displayAdminScreen();
	//	}
	//	else {
	//		cout << "Wrong Admin credentials\n";
	//	}

	//}
	//else if (option == 'u' || option == 'U') {
	//	cout << "Enter 'l' to login to your account\nEnter 's' to create a new user account\n";
	//	char userOption;
	//	cin >> userOption;
	//	if (userOption == 'l') {
	//		string userID, userPass, word;
	//		ifstream userfile;
	//		bool userLogin = false;
	//		cout << "Enter User ID: ";
	//		cin >> userID;
	//		cout << "Enter User password: ";
	//		cin >> userPass;
	//		userfile.open("UserCredentials.txt");
	//		while (!userfile.EOF()) {
	//			userfile >> word;
	//			if (word == userID) {
	//				userfile >> word;
	//				if (word == userPass) {
	//					userLogin = true;
	//				}
	//			}
	//			else {
	//				userfile >> word;
	//			}
	//		}
	//		userfile.close();
	//		if (userLogin == true) {
	//			displayUserScreen();
	//		}
	//		else {
	//			cout << "Wrong User credentials\n";
	//		}
	//	}
	//	else {
	//		ofstream userfile;
	//		string userID, userPass, word;
	//		cout << "Enter User ID: ";
	//		cin >> userID;
	//		cout << "Enter User password: ";
	//		cin >> userPass;
	//		userfile.open("UserCredentials.txt");
	//		userfile << userID;
	//		userfile << "\n";
	//		userfile << userPass;
	//		userfile.close();
	//	}
	//}
	system("pause");
	return 0;
}
