#pragma once
#include<iostream>
#include"Animal.h"
#include "Person.h"
#include"Booking.h"
#include<fstream>
using namespace std;

class QBMS {
private:
	User** userlist;
	Saleman** salesmanlist;
	int noOfUsers;
	int noOfsaleman;
	Bookings** bookinglist;
	int bookingcount;
	Goat** goatlist;
	int noOfGoats;
	Cow** cowlist;
	int noOfCows;
	Camel** camellist;
	int noOfCamels;
public:
	QBMS()
	{
		userlist = new User * [1000];
		salesmanlist = new Saleman * [1000];
		bookinglist = new Bookings * [1000];
		goatlist = new Goat * [200];
		cowlist = new Cow * [200];
		camellist = new Camel * [200];
		noOfCamels = 0;
		noOfCows = 0;
		noOfGoats = 0;
		bookingcount = 0;
		noOfUsers = 0;
		noOfsaleman = 0;
	}
	bool isInputValid(int token, int Shares, double& price, char* Animal) {
		char str1[] = "Camel";
		char str2[] = "Cow";
		char str3[] = "Goat";
		for (int i = 0; i < noOfCamels; i++) {
			if (camellist[i]->getCamelID() == token && camellist[i]->isSharesValid(Shares)) {
				price = camellist[i]->getPrice(Shares);
				Animal = str1;
				return true;
			}
		}
		for (int i = 0; i < noOfCows; i++)
		{
			if (cowlist[i]->getCowID() == token && cowlist[i]->isSharesValid(Shares)) {
				price = cowlist[i]->getPrice(Shares);
				Animal = str2;
				return true;
			}
		}
		for (int i = 0; i < noOfGoats; i++) {
			if (goatlist[i]->getGoatID() == token && goatlist[i]->isSharesValid(Shares)) {
				price = goatlist[i]->getPrice(Shares);
				Animal = str3;
				return true;
			}
		}
		return false;
	}
	void ReserveAShare() {
		cout << "                  Enter Booking Details               " << endl;
		cout << "Enter the buyer's CNIC: ";
		char* _CNIC = new char[40];
		char* Date = new char[40];
		char* Time = new char[40];
		cin >> _CNIC;
		cout << "Enter the token number of the animal: ";
		int _token;
		cin >> _token;
		cout << "Enter the number of Shares you want to buy: ";
		int Shares;
		cin >> Shares;
		double price;
		char* Animal = new char[40];
		int n;
		if (isInputValid(_token, Shares, price, Animal)) {
			cout << "Price of the Animal: " << price << endl;
			cout << "If you have received the Amount, click 1, else click 2: ";
			cin >> n;
			if (n == 1) {
				cout << "Enter the Qurbani Date in DD/MM/YYYY format: ";
				cin >> Date;
				cout << "Enter the Estimated Qurbani Time in HH/MM format: ";
				cin >> Time;
				Bookings* b = new Bookings();
				b->AddBooking(_CNIC, _token, Shares, Date, Time, price);
				bookinglist[bookingcount++] = b;
				cout << "Booking Successful" << endl;
			}
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
	bool isCNICunique(char* CNIC) {
		for (int i = 0; i < noOfsaleman; i++) {
			if (strcmp(salesmanlist[i]->getCNIC(), CNIC) == 0) {
				return false;
			}
		}
		return true;
	}
	bool isSalesmanUsernameunique(char* username) {
		for (int i = 0; i < noOfsaleman; i++) {
			if (strcmp(salesmanlist[i]->getUsername(), username) == 0) {
				return false;
			}
		}
		return true;
	}
	void AddSalesman(char* _firstname, char* _lastname, char* _CNIC, char* _username, char* _password) {
		Saleman* s = new Saleman(_firstname, _lastname, _CNIC, _username, _password);
		//salesmanlist = new Saleman * ();
		salesmanlist[noOfsaleman++] = s;
	}
	void addSaleman() {
		cout << "              Enter Salesman Details               " << endl;
		cout << "Enter first name: ";
		char* firstname = new char[40];
		cin >> firstname;
		cout << "Enter last name: ";
		char* lastname = new char[40];
		cin >> lastname;
		cout << "Enter CNIC: ";
		char* CNIC = new char[13];
		cin >> CNIC;
		if (isCNICunique(CNIC)) {
			cout << "Enter user name: ";
			char* username = new char[40];
			cin >> username;
			while (!isSalesmanUsernameunique(username)) {
				cout << "Username already exist, Enter again: ";
				cin >> username;
			}
			cout << "Enter 8 character password: ";
			char* password = new char[8];
			cin >> password;
			AddSalesman(firstname, lastname, CNIC, username, password);
		}
		else {
			cout << "Salesman with this CNIC already exist" << endl;
		}
	}
	void ViewListofAnimals() {
		cout << "Goats:" << endl;
		for (int i = 0; i < noOfGoats; i++) {
			goatlist[i]->display();
		}
		cout << "Cows:" << endl;
		for (int i = 0; i < noOfCows; i++) {
			cowlist[i]->display();
		}
		cout << "Camels:" << endl;
		for (int i = 0; i < noOfCamels; i++) {
			camellist[i]->display();
		}
	}
	void ViewListofAvailableAnimals() {
		cout << "Goats:" << endl;
		for (int i = 0; i < noOfGoats; i++) {
			if (goatlist[i]->getGoatParts() != 0) {
				goatlist[i]->display();
			}
		}
		cout << "Cows:" << endl;
		for (int i = 0; i < noOfCows; i++) {
			if (cowlist[i]->getCowParts() != 0) {
				cowlist[i]->display();
			}
		}
		cout << "Camels:" << endl;
		for (int i = 0; i < noOfCamels; i++) {
			if (camellist[i]->getCamelParts() != 0) {
				camellist[i]->display();
			}
		}
	}
	void ViewAnimalDetail() {
		int token;
		cout << "Enter the Token Number of the Animal: ";
		cin >> token;
		bool flag = true;
		for (int i = 0; i < noOfGoats && flag == true; i++) {
			if (goatlist[i]->getGoatID() == token) {
				cout << "Animal is a Goat and Details are:" << endl;
				goatlist[i]->display();
				flag = false;
			}

		}

		for (int i = 0; i < noOfCows && flag == true; i++) {
			if (cowlist[i]->getCowID() == token) {
				cout << "Animal is a Cow and Details are:" << endl;
				cowlist[i]->display();
				flag = false;
			}
		}

		for (int i = 0; i < noOfCamels && flag == true; i++) {
			if (camellist[i]->getCamelID() == token) {
				cout << "Animal is a Camel and Details are:" << endl;
				camellist[i]->display();
				flag = false;
			}
		}
		if (flag) {
			cout << "You have entered an Invalid Token Number" << endl;
		}
	}
	void MakeASchedule() {
		cout << "Enter the Token Number of the Animal: ";
		int token;
		char* _Date = new char[40];
		cin >> token;
		cout << "Enter Qurbani Date in DD//MM/YYYY Format: ";
		cin >> _Date;
		char* time = new char[40];
		cout << "Enter the Qurbani Time in HH:MM Format: ";
		cin >> time;
		bool flag = true, flag1 = true;
		for (int i = 0; i < noOfGoats && flag == true; i++) {
			if (goatlist[i]->getGoatID() == token) {

				goatlist[i]->setQurbaniDate(_Date);
				flag = false;
			}

		}

		for (int i = 0; i < noOfCows && flag == true; i++) {
			if (cowlist[i]->getCowID() == token) {

				cowlist[i]->setQurbaniDate(_Date);
				flag = false;
			}
		}

		for (int i = 0; i < noOfCamels && flag == true; i++) {
			if (camellist[i]->getCamelID() == token) {

				camellist[i]->setQurbaniDate(_Date);
				flag = false;
			}
		}
		if (!flag) {
			for (int i = 0; i < bookingcount && flag1 == true; i++) {
				if (bookinglist[i]->getToken() == token) {
					bookinglist[i]->setQurbaniDate(_Date);
					bookinglist[i]->setQurbaniTime(time);
					flag1 = false;
				}
			}
			cout << "Successful" << endl;
			ofstream fout;
			fout.open("schedule.txt");
			fout << "Animal Token: " << token << " ";
			fout << "Qurbani Date: " << _Date << endl;
			fout.close();
		}
		else {
			cout << "You have entered the invalid Token Number" << endl;
		}
	}
	bool isTokenUnique(int token) {
		for (int i = 0; i < noOfGoats; i++) {
			if (goatlist[i]->getGoatID() == token) {
				return false;
			}
		}
		for (int i = 0; i < noOfCows; i++) {
			if (cowlist[i]->getCowID() == token) {
				return false;
			}
		}
		for (int i = 0; i < noOfCamels; i++) {
			if (camellist[i]->getCamelID() == token) {
				return false;
			}
		}
	}
	void AddAnimal() {
		cout << "                Animal Details              " << endl;
		cout << "Enter the Token Number of the Animal: ";
		int token;
		cin >> token;
		if (isTokenUnique(token)) {
			cout << "Enter Number of Shares: ";
			int Shares;
			cin >> Shares;
			cout << "Enter the price: ";
			int price;
			cin >> price;
			char* status = new char[40];
			cout << "Enter the Status of the Animal: ";
			cin >> status;
			if (Shares == 1) {
				Goat* g = new Goat(token, Shares, price, status);
				goatlist[noOfGoats++] = g;
				cout << "Successfully Added" << endl;
			}
			else if (Shares == 7) {
				Cow* c = new Cow(token, Shares, price, status);
				cowlist[noOfCows++] = c;
				cout << "Successfully Added" << endl;
			}
			else if (Shares == 14) {
				Camel* c = new Camel(token, Shares, price, status);
				camellist[noOfCamels++] = c;
				cout << "Successfully Added" << endl;
			}
			else {
				cout << "You have entered invalid number of Shares" << endl;
			}
		}
		else {
			cout << "Token is not Unique" << endl;
		}
	}
	void ChangeStatus() {
		int token;
		cout << "Enter the Token Number of the Animal: ";
		cin >> token;
		bool flag = true;
		char* status = new char[40];
		for (int i = 0; i < noOfGoats && flag == true; i++) {
			if (goatlist[i]->getGoatID() == token) {
				cout << "Enter the Status of Animal: ";
				cin >> status;
				goatlist[i]->SetStatus(status);
				cout << "Status updated succesfully" << endl;
				flag = false;
			}
		}
		for (int i = 0; i < noOfCows && flag == true; i++) {
			if (cowlist[i]->getCowID() == token) {
				cout << "Enter the Status of Animal: ";
				cin >> status;
				cowlist[i]->SetStatus(status);
				cout << "Status updated succesfully" << endl;
				flag = false;
			}
		}
		for (int i = 0; i < noOfCamels && flag == true; i++) {
			if (camellist[i]->getCamelID() == token) {
				cout << "Enter the Status of Animal: ";
				cin >> status;
				camellist[i]->SetStatus(status);
				cout << "Status updated succesfully" << endl;
				flag = false;
			}
		}
		if (flag) {
			cout << "You've entered the invalid token number" << endl;
		}
	}
	void viewSchedule() {
		ifstream fin;
		fin.open("schedule.txt");
		cout << "Schedule: " << endl;
		while (!fin.eof()) {
			char* temp = new char[255];
			fin.getline(temp, 255);
			for (int i = 0; temp[i] != '\0'; i++) {
				cout << temp[i];
			}
			cout << endl;
		}
		fin.close();
	}
	void SeeReservationsOfACustomer() {
		char* CNIC = new char[40];
		cout << "Enter the CNIC of the Customer: ";
		cin >> CNIC;
		int a = 1;
		int price = 0;
		for (int i = 0; i < bookingcount; i++) {
			if (strcmp(bookinglist[i]->getCNC(), CNIC) == 0) {
				cout << "Reservation " << a << " details: " << endl;
				bookinglist[i]->print();
				price = price + bookinglist[i]->getPrice();
				a++;
			}
		}
		if (price == 0) {
			cout << "No Customer with the entered CNIC exists" << endl;
		}
		else {
			cout << "Total Amount: " << price << endl;
		}
	}
	void readBookings() {
		ifstream fin;
		fin.open("booking.txt");
		while (!fin.eof()) {
			char* temp = new char[255];
			fin.getline(temp, 255);
			char* str = new char[10];
			char* time = new char[10];
			char* CNIC = new char[13];
			char* QurbaniDate = new char[8];
			int price, Shares, Animaltoken;
			int index = 0, count = 0;
			if (temp[index] == NULL) {
				break;
			}
			while (temp[index] != 32)
			{
				CNIC[count++] = temp[index++];
			}
			CNIC[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				str[count++] = temp[index++];
			}
			str[count] = '\0';
			Animaltoken = atoi(str);
			count = 0, index++;
			str = NULL;
			str = new char[10];
			while (temp[index] != 32)
			{
				str[count++] = temp[index++];
			}
			str[count] = '\0';
			Shares = atoi(str);
			count = 0, index++;
			str = NULL;
			str = new char[10];
			while (temp[index] != 32)
			{
				str[count++] = temp[index++];
			}
			str[count] = '\0';
			price = atoi(str);
			count = 0, index++;
			str = NULL;

			if (temp[index] != NULL) {   //if Qurbani Date is mentioned in the list
				str = new char[10];
				while (temp[index] != 32) {

					str[count++] = temp[index++];
				}
				str[count] = '\0';
				while (temp[index] != 32) {

					time[count++] = temp[index++];
				}
				time[count] = '\0';
				Bookings* b = new Bookings();
				b->AddBooking(CNIC, Animaltoken, Shares, str, time, price);
				bookinglist[bookingcount++] = b;
			}
			else {

				Bookings* b = new Bookings(CNIC, Animaltoken, Shares, price);
				bookinglist[bookingcount++] = b;
			}
		}
		fin.close();
	}
	void DisplayBooking() {
		for (int i = 0; i < bookingcount; i++) {
			bookinglist[i]->print();
		}
	}
	void readAnimal() {
		ifstream fin;
		fin.open("animal.txt");
		while (!fin.eof()) {
			char* temp = new char[255];
			char* str = new char[10];
			char* status = new char[10];
			char* Type = new char[10];
			int token, Shares, price;
			fin.getline(temp, 255);
			int index = 0, count = 0;
			if (temp[index] == NULL) {
				break;
			}
			while (temp[index] != 32)
			{
				str[count++] = temp[index++];
			}
			str[count] = '\0';
			token = atoi(str);
			count = 0, index++;
			str = NULL;
			str = new char[10];
			while (temp[index] != 32)
			{
				str[count++] = temp[index++];
			}
			str[count] = '\0';
			Shares = atoi(str);
			count = 0, index++;
			str = NULL;
			str = new char[10];
			while (temp[index] != 32)
			{
				str[count++] = temp[index++];
			}
			str[count] = '\0';
			price = atoi(str);
			count = 0, index++;
			while (temp[index] != 32)
			{
				status[count++] = temp[index++];
			}
			status[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				Type[count++] = temp[index++];
			}
			Type[count] = '\0';
			str = NULL;

			if (temp[index] != NULL) {   //if Qurbani Date is mentioned in the list
				str = new char[10];
				while (temp[index] != 32) {

					str[count++] = temp[index++];
				}
				str[count] = '\0';
				if (strcmp(Type, "Goat") == 0) {
					Goat* g = new Goat(token, Shares, price, status, str);
					goatlist[noOfGoats++] = g;
				}
				else if (strcmp(Type, "Cow") == 0) {
					Cow* c = new Cow(token, Shares, price, status, str);
					cowlist[noOfCows++] = c;
				}
				else if (strcmp(Type, "Camel") == 0) {
					Camel* c = new Camel(token, Shares, price, status, str);
					camellist[noOfCamels++] = c;
				}
			}
			else {

				if (strcmp(Type, "Goat") == 0) {
					Goat* g = new Goat(token, Shares, price, status);
					goatlist[noOfGoats++] = g;
				}
				else if (strcmp(Type, "Cow") == 0) {
					Cow* c = new Cow(token, Shares, price, status);
					cowlist[noOfCows++] = c;
				}
				else if (strcmp(Type, "Camel") == 0) {
					Camel* c = new Camel(token, Shares, price, status);
					camellist[noOfCamels++] = c;
				}
			}
		}
	}
	bool isUser(char* username, char* password) {
		for (int i = 0; i < noOfUsers; i++)
		{
			if (strcmp(userlist[i]->getUsername(), username) == 0 && strcmp(userlist[i]->getpassword(), password) == 0) {
				return true;
			}
		}
		cout << "You've entered a wrong username or password" << endl;
		return false;
	}
	bool isSaleman(char* username, char* password) {
		for (int i = 0; i < noOfsaleman; i++)
		{
			if (strcmp(salesmanlist[i]->getUsername(), username) == 0 && strcmp(salesmanlist[i]->getpassword(), password) == 0) {
				return true;
			}
		}
		cout << "You've entered a wrong username or password" << endl;
		return false;
	}
	bool isCustomer(char* CNIC) {
		for (int i = 0; i < bookingcount; i++) {
			if (strcmp(bookinglist[i]->getCNC(), CNIC) == 0) {
				return true;
			}
		}
		cout << "No Customer with this CNIC exist" << endl;
		return false;
	}
	void AddUser(char* _firstname, char* _lastname, char* _CNIC, char* _username, char* _password) {
		User* u = new User(_firstname, _lastname, _CNIC, _username, _password);
		//userlist = new User * ();
		userlist[noOfUsers++] = u;
	}
	void readUser()
	{
		ifstream fin;
		fin.open("user.txt");
		while (!fin.eof()) {
			char* temp = new char[255];
			fin.getline(temp, 255);
			char* firstname = new char[40];
			char* lastname = new char[40];
			char* CNIC = new char[13];
			char* username = new char[40];
			char* password = new char[8];
			int index = 0, count = 0;
			if (temp[index] == NULL) {
				break;
			}
			while (temp[index] != 32)
			{
				firstname[count++] = temp[index++];
			}
			firstname[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				lastname[count++] = temp[index++];
			}
			lastname[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				CNIC[count++] = temp[index++];
			}
			CNIC[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				username[count++] = temp[index++];
			}
			username[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				password[count++] = temp[index++];
			}
			password[count] = '\0';
			count = 0, index++;
			AddUser(firstname, lastname, CNIC, username, password);
		}
		fin.close();
	}
	void readSaleman()
	{
		ifstream fin;
		char* temp;
		//char firstname[40];
		
		fin.open("saleman.txt");
		while (!fin.eof()) {
			temp = new char[255];
			char firstname[40];
			//firstname = new char[40];
			char lastname[40];
			char CNIC[40];
			char username[40];
			char password[9];
			int index = 0, count = 0;
			fin.getline(temp, 255);
			if (temp[index] == NULL) {
				break;
			}
			while (temp[index] != 32)
			{
				firstname[count++] = temp[index++];
			}
			firstname[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				lastname[count++] = temp[index++];
			}
			lastname[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				CNIC[count++] = temp[index++];
			}
			CNIC[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				username[count++] = temp[index++];
			}
			username[count] = '\0';
			count = 0, index++;
			while (temp[index] != 32)
			{
				password[count++] = temp[index++];
			}
			password[count] = '\0';
			count = 0, index++;
			AddSalesman(firstname, lastname, CNIC, username, password);
			
		}
		fin.close();
	}
	void writeBookings() {
		ofstream fout;
		fout.open("booking.txt");
		for (int i = 0; i < bookingcount; i++) {
			fout << bookinglist[i]->getCNC() << " ";
			fout << bookinglist[i]->getToken() << " ";
			fout << bookinglist[i]->getShares() << " ";
			fout << bookinglist[i]->getPrice() << " ";
			if (bookinglist[i]->isDate()) {
				fout << bookinglist[i]->getQurbaniDate() << " ";
				fout << bookinglist[i]->getQurbaniTime() << " ";
			}
			fout << endl;
		}
		fout.close();
	}
	void writeAnimal() {
		ofstream fout;
		fout.open("animal.txt");
		char str[] = "Goat";
		char str1[] = "Cow";
		char str2[] = "Camel";
		for (int i = 0; i < noOfGoats; i++) {
			fout << goatlist[i]->getGoatID() << " ";
			fout << goatlist[i]->getGoatParts() << " ";
			fout << goatlist[i]->GetPrice() << " ";
			fout << goatlist[i]->getstatus() << " ";
			fout << str << " ";
			fout << endl;
		}

		for (int i = 0; i < noOfCows; i++) {
			fout << cowlist[i]->getCowID() << " ";
			fout << cowlist[i]->getCowParts() << " ";
			fout << cowlist[i]->GetPrice() << " ";
			fout << cowlist[i]->getstatus() << " ";
			fout << str1 << " ";
			fout << endl;
		}

		for (int i = 0; i < noOfCamels; i++) {
			fout << camellist[i]->getCamelID() << " ";
			fout << camellist[i]->getCamelParts() << " ";
			fout << camellist[i]->GetPrice() << " ";
			fout << camellist[i]->getstatus() << " ";
			fout << str1 << " ";
			fout << endl;
		}
		fout.close();
	}
	void writeUser() {
		ofstream fout;
		fout.open("user.txt");
		for (int i = 0; i < noOfUsers; i++) {
			fout << userlist[i]->getfirstname() << " ";
			fout << userlist[i]->getlastname() << " ";
			fout << userlist[i]->getCNIC() << " ";
			fout << userlist[i]->getUsername() << " ";
			fout << userlist[i]->getpassword() << " ";
			fout << endl;
		}
	}
	void writeSaleman() {
		ofstream fout;
		fout.open("saleman.txt");
		for (int i = 0; i < noOfsaleman; i++) {
			fout << salesmanlist[i]->getfirstname() << " ";
			fout << salesmanlist[i]->getlastname() << " ";
			fout << salesmanlist[i]->getCNIC() << " ";
			fout << salesmanlist[i]->getUsername() << " ";
			fout << salesmanlist[i]->getpassword() << " ";
			fout << endl;
		}
	}
	void menu() {
		readAnimal();
		readBookings();
		readUser();
		readSaleman();
		while (1) {
			cout << "---------------------------------Welcome To Qurbani Management System-----------------------------------------------" << endl;
			int n;
			cout << "If you are an Admin, press 1, If Saleman, press 2, If Customer, press 3, and Press 4 to Exit" << endl;
			cin >> n;
			if (n == 1) {
				char* username = new char[40], * password = new char[40];
				cout << "Enter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> password;

				if (isUser(username, password)) {
					while (1) {
						cout << "Welcome!" << endl << "1. Add Animal" << endl << "2. Add Saleman" << endl << "3. Make a Schedule"
							<< endl << "4. View List of All Animals" << endl << "5. View List of Available Animals" << endl
							<< "6. Animal Details" << endl << "7. View Schedule" << endl << "8. View Reservation of A Customer" << endl
							<< "9. Rreserve A Share" << endl << "10. Change Status of an Animal" << endl << "11. Add Customer" << endl << "12. Logout" << endl;
						cout << "Enter the number corresponding to the function you want to perform :";
						cin >> n;
						cout << endl << endl;
						if (n == 1) {
							AddAnimal();
							cout << endl;
						}
						else if (n == 2) {
							addSaleman();
							cout << endl;
						}
						else if (n == 3) {
							MakeASchedule();
							cout << endl;
						}
						else if (n == 4) {
							ViewListofAnimals();
							cout << endl;
						}
						else if (n == 5) {
							ViewListofAvailableAnimals();
							cout << endl;
						}
						else if (n == 6) {
							ViewAnimalDetail();
							cout << endl;
						}
						else if (n == 7) {
							viewSchedule();
							cout << endl;
						}
						else if (n == 8) {
							SeeReservationsOfACustomer();
							cout << endl;
						}
						else if (n == 9) {
							cout << "List of All Available Animals: " << endl << endl;
							ViewListofAnimals();
							cout << endl;
							ReserveAShare();
							cout << endl;
						}
						else if (n == 10) {
							ChangeStatus();
							cout << endl;
						}
						else if (n == 11) {
							ReserveAShare();
							cout << endl;
						}
						else if (n == 12) {
							cout << "Logging out.." << endl << endl;
							cout << "Logout Succesful" << endl << endl;
							break;
						}
						else {
							cout << "Invalid Input" << endl << endl;
						}
					}
				}

			}
			else if (n == 2) {
				char* username = new char[40], * password = new char[40];
				cout << "Enter Username: ";
				cin >> username;
				cout << "Enter Password: ";
				cin >> password;
				if (isSaleman(username, password)) {
					while (1) {
						cout << "1. View List of All Animals" << endl << "2. View List of Available Animals" << endl
							<< "3. Animal Details" << endl << "4. View Schedule" << endl << "5. View Reservation of A Customer" << endl
							<< "6. Rreserve A Share" << endl << "7. Change Status of an Animal" << endl << "8. Add Customer" << endl << "9. Logout" << endl;
						cout << "Enter the number corresponding to the function you want to perform :";
						cin >> n;
						if (n == 1) {
							ViewListofAnimals();
							cout << endl;
						}
						else if (n == 2) {
							ViewListofAvailableAnimals();
							cout << endl;
						}
						else if (n == 3) {
							ViewAnimalDetail();
							cout << endl;
						}
						else if (n == 4) {
							viewSchedule();
							cout << endl;
						}
						else if (n == 5) {
							SeeReservationsOfACustomer();
							cout << endl;
						}
						else if (n == 6) {
							cout << "List of All Available Animals: " << endl << endl;
							ViewListofAnimals();
							cout << endl;
							ReserveAShare();
							cout << endl;
						}
						else if (n == 7) {
							ChangeStatus();
							cout << endl;
						}
						else if (n == 8) {
							ReserveAShare();
							cout << endl;
						}
						else if (n == 9) {
							cout << "Logging out.." << endl << endl;
							cout << "Logout Succesful" << endl << endl;
							break;
						}
						else {
							cout << "Invalid Input" << endl << endl;
						}
					}
				}
			}
			
			else if (n == 3) {
				while (1) {
					cout << "Welcome!" << endl << "1. Reserve a Share" << endl << "2. View Your Bookings" << "3. Log Out" << endl;
					cin >> n;
					if (n == 1) {
						cout << "List of All Available Animals: " << endl<<endl;
						ViewListofAnimals();
						cout << endl;
						ReserveAShare();
						cout << endl;
					}
					else if (n == 2) {
						SeeReservationsOfACustomer();
						cout << endl;
					}
					else if (n == 3) {
						cout << "Logging out.." << endl << endl;
						cout << "Logout Succesful" << endl << endl;
						break;
					}
					else {
						cout << "Invalid input" << endl << endl;
					}
				}

			}
			else if (n == 4) {
				writeUser();
				writeBookings();
				writeSaleman();
				writeAnimal();
				break;
			}
			else {
				cout << "Invalid Input" << endl;
			}
		}
	}
};
