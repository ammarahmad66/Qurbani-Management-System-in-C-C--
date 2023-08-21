#pragma once
#include <iostream>
using namespace std;

class Bookings {
private:
	char* CNIC;
	int Animaltoken;
	int numberOfShares;
	char* QurbaniDate;
	double price;
	char* QurbaniTime;
	bool dateflag;
public:
	Bookings()
	{
		price = 0;
		CNIC = NULL;
		Animaltoken = 0;
		numberOfShares = 0;
		QurbaniDate = NULL;
		QurbaniTime = NULL;
		dateflag = false;
	}
	Bookings(char* _CNIC, int token, int Shares,double _price)
	{
		numberOfShares = Shares;
		Animaltoken = token;
		//char str[] = "3/6/2021";
		int size = strlen(_CNIC);
		CNIC = new char[size + 1];
		for (int i = 0; i < size; i++) {
			CNIC[i] = _CNIC[i];
		}
		CNIC[size] = '\0';
		QurbaniDate = NULL;
		QurbaniTime = NULL;
		price = _price;
		dateflag = false;
	}
	void setQurbaniDate(char* str) {
		int size = strlen(str);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = str[i];
		}
		QurbaniDate[size] = '\0';
		dateflag = true;
	}
	void setQurbaniTime(char* str) {
		int size = strlen(str);
		QurbaniTime = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniTime[i] = str[i];
		}
		QurbaniTime[size] = '\0';
		dateflag = true;
	}
	void AddBooking(char* _CNIC, int token, int Shares, char* Date, char* Time,double _price){
		numberOfShares = Shares;
		Animaltoken = token;
		int size = strlen(_CNIC);
		CNIC = new char[size + 1];
		for (int i = 0; i < size; i++) {
			CNIC[i] = _CNIC[i];
		}
		CNIC[size] = '\0';
		size = strlen(Date);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = Date[i];
		}
		QurbaniDate[size] = '\0';
		size = strlen(Time);
		QurbaniTime = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniTime[i] = Time[i];
		}
		QurbaniTime[size] = '\0';
		price = _price;
		dateflag = true;
	}
	char* getQurbaniDate() {
		return QurbaniDate;
	}
	char* getQurbaniTime() {
		return QurbaniTime;
	}
	int getShares() {
		return numberOfShares;
	}
	int getToken() {
		return Animaltoken;
	}
	char* getCNC() {
		return CNIC;
	}
	double getPrice() {
		return price;
	}
	bool isDate() {
		if (dateflag) {
			return true;
		}
		return false;
	}
	void print() {
		cout << "CNIC of the buyer: " << CNIC << endl;
		cout << "Animal Token: " << Animaltoken << endl;
		cout << "Number of Shares Reserved:" <<numberOfShares<< endl;
		cout << "Price: " << price << endl;
		//cout << "Qurbani Date: " << QurbaniDate << endl;
	}
};
