#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
class Animal {
public:
	//Abstract functions
	virtual void ShareReserve(int Shares) = 0;
	virtual void display() = 0;
	virtual bool isSharesValid(int Shares) = 0;
	virtual double getPrice(int Shares) = 0;
	//virtual char* status() = 0;
	virtual void SetStatus(char* str) = 0;
	virtual void setQurbaniDate(char* str) = 0;
	virtual int GetPrice() = 0;
};
class Cow : public Animal {
	int cowShares;
	int cowToken;
	int price;
	char* status;
	char* QurbaniDate;
public:
	Cow()
	{
		cowShares = 7;
		cowToken = 0;
		price = 0;
		status = NULL;
		QurbaniDate = NULL;
	}
	Cow(int id,int Shares, int _price,char* _status) {
		cowShares = Shares;
		setCowID(id);
		price = _price;
		int size = strlen(_status);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = _status[i];
		}
		status[size] = '\0';
	}
	Cow(int id, int Shares, int _price, char* _status,char* Date) {
		cowShares = Shares;
		setCowID(id);
		price = _price;
		int size = strlen(_status);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = _status[i];
		}
		status[size] = '\0';
		size = strlen(Date);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = Date[i];
		}
		QurbaniDate[size] = '\0';
	}
	void ShareReserve(int Shares) {
		cowShares = cowShares - Shares;
		char str[] = "Reserved";
		if (cowShares == 0)
		{
			status = str;
		}
	}
	void setQurbaniDate(char* str) {
		int size = strlen(str);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = str[i];
		}
		QurbaniDate[size] = '\0';
	}
	int GetPrice() {
		return price;
	}
	char* getstatus() {
		return status;
	}
	void SetStatus(char* str) {
		int size = strlen(str);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = str[i];
		}
		status[size] = '\0';
	}
	/*void purchase(int ) {
		cout << "You are Buying Against ID: " << getCowID() << endl;
		cout << "you can Only Buy for Once: " << endl;
		if (getCowBuy() < getCowParts()) {
			cout << "You Bought Cow: " << endl;
			cowBuy++;
			srand(time(0));
			while (1) {
				price = rand() + 1;
				if (price >= 5000 && price <= 10000) {
					cout << "The price is : " << price << endl;
					break;
				}
			}
		}
		else {
			cout << "you cannot Buy More your Purchase is Full: " << endl;
		}
	}*/
	bool isSharesValid(int Shares) {
		if (cowShares >= Shares) {
			ShareReserve(Shares);
			return true;
		}
		return false;
	}
	double getPrice(int Shares) {
		double n = price / 7;      //calculating price per share
		n = n * Shares;            //calculating price of required Shares
		return n;
	}
	void setCowParts(int cowParts) {
		this->cowShares = cowParts;
	}
	int getCowParts() {
		return this->cowShares;
	}
	void setCowID(int id) {
		this->cowToken = id;
	}
	int getCowID() {
		return this->cowToken;
	}
	void display() {
		cout << "Token: " << getCowID() << endl;
		cout << "Number of Shares Available = " << cowShares << endl;
		cout << "Number of Shares Reserved: " << 7 - cowShares << endl;
		cout << "Price: " << price << endl;
		cout << "Status: " << status << endl;
	}

};
class Camel : public Animal {
	int camelShares;
	int camelToken;
	int price;
	char* status;
	char* QurbaniDate;
public:
	Camel()
	{
		camelShares = 14;
		camelToken = 0;
		price = 0;
		status = NULL;
		QurbaniDate = NULL;
	}
	Camel(int id, int Shares, int _price, char* _status) {
		camelShares = Shares;
		setCamelID(id);
		price = _price;
		int size = strlen(_status);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = _status[i];
		}
		status[size] = '\0';
	}
	Camel( int id, int Shares, int _price,char* _status, char* Date) {
		camelShares = Shares;
		setCamelID(id);
		price = _price;
		int size = strlen(_status);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = _status[i];
		}
		status[size] = '\0';
		size = strlen(Date);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = Date[i];
		}
		QurbaniDate[size] = '\0';
	}
	void ShareReserve(int Shares) {
		camelShares = camelShares - Shares;
		char str[] = "Reserved";
		if (camelShares == 0)
		{
			status = str;
		}
	}
	void setQurbaniDate(char* str) {
		int size = strlen(str);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = str[i];
		}
		QurbaniDate[size] = '\0';
	}
	int GetPrice() {
		return price;
	}
	char* getstatus() {
		return status;
	}
	void SetStatus(char* str) {
		int size = strlen(str);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = str[i];
		}
		status[size] = '\0';
	}
	void setCamelParts(int camelParts) {
		this->camelShares = camelParts;
	}
	int getCamelParts() {
		return this->camelShares;
	}
	void setCamelID(int id) {
		this->camelToken = id;
	}
	bool isSharesValid(int Shares) {
		if (camelShares >= Shares) {
			ShareReserve(Shares);
			return true;
		}
		return false;
	}
	double getPrice(int Shares) {
		double n = price / 14;      //calculating price per share
		n = n * Shares;            //calculating price of required Shares
		return n;
	}
	int getCamelID() {
		return this->camelToken;
	}
	void display() {
		cout << "Token: " << getCamelID() << endl;
		cout << "Number of Shares Available = " << camelShares << endl;
		cout << "Number of Shares Reserved: " << 14 - camelShares << endl;
		cout << "Price: " << price << endl;
		cout << "Status: " << status << endl;
		
	}
};
class Goat : public Animal {
private:
	int goatShares;
	int goatToken;
	int price;
	char* status;
	char* QurbaniDate;
public:
	Goat()
	{
		goatShares = 1;
		goatToken = 0;
		price = 0;
		status = NULL;
		QurbaniDate = NULL;
	}
	Goat( int id,int Shares,int _price,char* _status) {
		setGoatID(id);
		price = _price;
		goatShares = Shares;
		int size = strlen(_status);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = _status[i];
		}
		status[size] = '\0';
	}
	Goat(int id, int Shares, int _price, char* _status,char* Date) {
		setGoatID(id);
		price = _price;
		goatShares = Shares;
		int size = strlen(_status);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = _status[i];
		}
		status[size] = '\0';
		size = strlen(Date);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = Date[i];
		}
		Date[size] = '\0';
	}
	void setQurbaniDate(char* str) {
		int size = strlen(str);
		QurbaniDate = new char[size + 1];
		for (int i = 0; i < size; i++) {
			QurbaniDate[i] = str[i];
		}
		QurbaniDate[size] = '\0';
	}
	char* getstatus() {
		return status;
	}
	void ShareReserve(int Shares) {
		goatShares = goatShares - Shares;
		char str[] = "Reserved";
		if (goatShares == 0)
		{
			status = str;
		}
	}
	void SetStatus(char* str) {
		int size = strlen(str);
		status = new char[size + 1];
		for (int i = 0; i < size; i++) {
			status[i] = str[i];
		}
		status[size] = '\0';
	}
	void setGoatParts(int goatParts) {
		this->goatShares = goatParts;
	}
	int getGoatParts() {
		return this->goatShares;
	}
	void setGoatID(int id) {
		this->goatToken = id;
	}
	double getPrice(int Shares) {
		return price;
	}
	bool isSharesValid(int Shares) {
		if (goatShares >= Shares) {
			ShareReserve(Shares);
			return true;
		}
		return false;
	}
	int getGoatID() {
		return this->goatToken;
	}
	int GetPrice() {
		return price;
	}
	void display() {
			cout << "Token: " << getGoatID() << endl;
			cout << "Number of Shares Available = " << goatShares << endl;
			cout << "Number of Shares Reserved: " << 1 - goatShares << endl;
			cout << "Price: " << price << endl;
			cout << "Status: " << status << endl;
			

	}
};

