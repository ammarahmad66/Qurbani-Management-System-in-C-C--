#include"QBMS.h"
#include<fstream>
#include<iostream>
using namespace std;

int main() {
	QBMS* q=new QBMS();
	q->menu();
	//q->readAnimal();
	//q->readBookings();
	//q->readSaleman();
	//q->readUser();
	//q->AddAnimal();
	//q->ReserveAShare();
	//q->addSaleman();
	//q->writeAnimal();
	//q->writeBookings();
	//q->writeSaleman();
//	q->AddAnimal();
//	q->ChangeStatus();
//	q->ViewAnimalDetail();
//	q->ViewListofAvailableAnimals();
//	q->addSaleman();
//	q->SeeReservationsOfACustomer();
//	q->ViewListofAnimals();
//	q->DisplayBooking();
//	q->readUser();
//	q->viewSchedule();
//	q->MakeASchedule();
//	q->ReserveAShare();
	return 0;
}






















//User** userlist;
//Saleman** salesmanlist;
//int noOfUsers=0;
//int noOfsaleman=0;
//
//bool isUser(char* username,char* password) {
//	for (int i = 0; i < noOfUsers; i++)
//	{
//		if (strcmp(userlist[i]->getUsername(), username) == 0 && strcmp(userlist[i]->getpassword(), password) == 0) {
//			return true;
//		}
//	}
//	return false;
//}
//void AddUser(char* _firstname, char* _lastname, char* _CNIC, char* _username, char* _password) {
//	User* u = new User(_firstname, _lastname, _CNIC, _username, _password);
//	//userlist = new User * ();
//	userlist[noOfUsers++] = u;
//}
//void AddSalesman(char* _firstname, char* _lastname, char* _CNIC, char* _username, char* _password) {
//	Saleman* s = new Saleman(_firstname, _lastname, _CNIC, _username, _password);
//	//salesmanlist = new Saleman * ();
//	salesmanlist[noOfsaleman++] = s;
//}
//
//void readUser()
//{
//	ifstream fin;
//	fin.open("user.txt");
//	while (!fin.eof()) {
//		char* temp = new char[255];
//		fin.getline(temp, 255);
//		char* firstname = new char[40];
//		char* lastname = new char[40];
//		char* CNIC = new char[13];
//		char* username = new char[40];
//		char* password = new char[8];
//		int index = 0, count = 0;
//		while (temp[index] != 32)
//		{
//			firstname[count++] = temp[index++];
//		}
//		firstname[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			lastname[count++] = temp[index++];
//		}
//		lastname[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			CNIC[count++] = temp[index++];
//		}
//		CNIC[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			username[count++] = temp[index++];
//		}
//		username[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			password[count++] = temp[index++];
//		}
//		password[count] = '\0';
//		count = 0, index++;
//		AddUser(firstname, lastname, CNIC, username, password);
//	}
//	fin.close();
//}
//void readSaleman()
//{
//	ifstream fin;
//	fin.open("saleman.txt");
//	while (!fin.eof()) {
//		char* temp = new char[255];
//		fin.getline(temp, 255);
//		char* firstname = new char[40];
//		char* lastname = new char[40];
//		char* CNIC = new char[13];
//		char* username = new char[40];
//		char* password = new char[8];
//		int index = 0, count = 0;
//		while (temp[index] != 32)
//		{
//			firstname[count++] = temp[index++];
//		}
//		firstname[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			lastname[count++] = temp[index++];
//		}
//		lastname[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			CNIC[count++] = temp[index++];
//		}
//		CNIC[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			username[count++] = temp[index++];
//		}
//		username[count] = '\0';
//		count = 0, index++;
//		while (temp[index] != 32)
//		{
//			password[count++] = temp[index++];
//		}
//		password[count] = '\0';
//		count = 0, index++;
//		AddSalesman(firstname, lastname, CNIC, username, password);
//	}
//	fin.close();
//}
//
//int main()
//{
//	userlist = new User*[100];
//	salesmanlist = new Saleman*[100];
//	readUser();
//	readSaleman();
//	/*userlist = NULL;
//	salesmanlist = NULL;
//	cout << "Enter your first name: ";
//	char* firstname = new char[40];
//	cin.getline(firstname, 40);
//	cout << "Enter your last name: ";
//	char* lastname = new char[40];
//	cin.getline(lastname, 40);
//	cout << "Enter your CNIC: ";
//	char* CNIC = new char[13];
//	cin.getline(CNIC, 13);
//	cout << "Enter your user name: ";
//	char* username = new char[40];
//	cin.getline(username, 40);
//	cout << "Enter 8 character password: ";
//	char* password = new char[8];
//	cin.getline(password, 8);
//	AddUser(firstname, lastname, CNIC, username, password);
//	AddSalesman(firstname, lastname, CNIC, username, password);*/
//	//userlist[noOfUsers - 1]->print();
//	/*for (int i = 0; i < noOfUsers; i++)
//	{
//		cout << "User " << i + 1 << " Details:" << endl;
//		userlist[i]->print();
//	}
//	for (int i = 0; i < noOfsaleman; i++)
//	{
//		cout << "Saleman " << i + 1 << " Details:" << endl;
//		salesmanlist[i]->print();
//	}*/
//	cout << "---------------------------------Welcome To Qurbani Management System-----------------------------------------------" << endl;
//	int n;
//	cout << "If you are an Admin, press 1, If Saleman, press 2, If Customer, press 3, and Press 4 to Exit" << endl;
//	cin >> n;
//	if (n == 1) {
//		char* username = new char[40], *password = new char[40];
//		cout << "Enter Username: ";
//		cin.getline(username, 40);
//		cout << "Enter Password: ";
//		cin.getline(password, 40);
//		if (isUser(username, password)) {
//			cout << "Welcome!" << endl << "1. Add Animal" << "2. Add Saleman" << endl << "3. Make a Schedule"
//				<< endl << "4. View List of All Animals" << endl << "5. View List of Available Animals" << endl
//				<< "5. Animal Details" << endl << "6. View Schedule" << endl << "7. View Reservation of A Customer" << endl
//				<< "8. Rreserve A Share" << endl << "9. Change Status of an Animal" << endl << "10. Add Customer" << endl << "11. Logout" << endl;
//			cout << "Enter the number corresponding to the function you want to perform :";
//			cin >> n;
//
//		}
//	}
//	return 0;
//}