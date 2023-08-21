
#include<iostream>
using namespace std;

class Person {
protected:
	char* firstname;
	char* lastname;
	char* CNIC;
public:
	Person()
	{
		firstname = NULL;
		lastname = NULL;
		CNIC = NULL;
	}
	virtual void AddPerson(char* _firstname, char* _lastname, char* _CNIC) = 0;
	virtual void print() = 0; 
	virtual char* getCNIC() = 0;
	virtual char* getfirstname() = 0;
	virtual char* getlastname() = 0;
};

class User : public Person {
private:
	char* username;
	char* password;
public:
	User()
	{
		username = NULL;
		password = NULL;
	}
	User(char* _firstname, char* _lastname, char* _CNIC, char* _username, char* _password) {
		int size = strlen(_firstname);
		firstname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			firstname[i] = _firstname[i];
		}
		firstname[size] = '\0';
		size = strlen(_lastname);
		lastname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			lastname[i] = _lastname[i];
		}
		lastname[size] = '\0';
		size = strlen(_CNIC);
		CNIC = new char[size + 1];
		for (int i = 0; i < size; i++) {
			CNIC[i] = _CNIC[i];
		}
		CNIC[size] = '\0';
		size = strlen(_username);
		username = new char[size + 1];
		for (int i = 0; i < size; i++) {
			username[i] = _username[i];
		}
		username[size] = '\0';
		size = strlen(_password);
		password = new char[size + 1];
		for (int i = 0; i < size; i++) {
			password[i] = _password[i];
		}
		password[size] = '\0';
	}
	void AddPerson(char* _firstname, char* _lastname, char* _CNIC) {
		int size = strlen(_firstname);
		firstname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			firstname[i] = _firstname[i];
		}
		firstname[size] = '\0';
		size = strlen(_lastname);
		lastname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			lastname[i] = _lastname[i];
		}
		lastname[size] = '\0';
		size = strlen(_CNIC);
		CNIC = new char[size + 1];
		for (int i = 0; i < size; i++) {
			CNIC[i] = _CNIC[i];
		}
		CNIC[size] = '\0';
		size = strlen(_firstname);
		username = new char[size + 3];
		for (int i = 0; i < size; i++) {
			username[i] = _firstname[i];
		}
		username[size] = '1';
		username[size + 1] = '9';
		username[size+2] = '\0';
		password = new char[9];
		for (int i = 0; i < 8; i++)
		{
			int num = rand() % 8;
			password[i] = (char)num;
		}
		password[8] = '\0';
	}
	char* getCNIC() {
		return CNIC;
	}
	char* getfirstname() {
		return firstname;
	}
	char* getlastname() {
		return lastname;
	}
	char* getUsername() {
		return username;
	}
	char* getpassword()
	{
		return password;
	}
	void print()
	{
			cout << "Name :"<<this->firstname << " " << this->lastname << endl;
			cout << "CNIC: "<<this->CNIC << endl;
			cout << "Username: " << this->username << endl;
			cout << "Password:" << password << endl;
	}
};

class Saleman: public Person {
private:
	char* username;
	char* password;
public:
	Saleman()
	{
		username = NULL;
		password = NULL;
	}
	Saleman(char* _firstname, char* _lastname, char* _CNIC, char* _username, char* _password) {
		int size = strlen(_firstname);
		firstname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			firstname[i] = _firstname[i];
		}
		firstname[size] = '\0';
		size = strlen(_lastname);
		lastname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			lastname[i] = _lastname[i];
		}
		lastname[size] = '\0';
		size = strlen(_CNIC);
		CNIC = new char[size + 1];
		for (int i = 0; i < size; i++) {
			CNIC[i] = _CNIC[i];
		}
		CNIC[size] = '\0';
		size = strlen(_username);
		username = new char[size + 1];
		for (int i = 0; i < size; i++) {
			username[i] = _username[i];
		}
		username[size] = '\0';
		size = strlen(_password);
		password = new char[size + 1];
		for (int i = 0; i < size; i++) {
			password[i] = _password[i];
		}
		password[size] = '\0';
	}
	char* getCNIC() {
		return CNIC;
	}
	char* getfirstname() {
		return firstname;
	}
	char* getlastname() {
		return lastname;
	}
	char* getUsername() {
		return username;
	}
	char* getpassword()
	{
		return password;
	}
	void AddPerson(char* _firstname, char* _lastname, char* _CNIC) {
		int size = strlen(_firstname);
		firstname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			firstname[i] = _firstname[i];
		}
		firstname[size] = '\0';
		size = strlen(_lastname);
		lastname = new char[size + 1];
		for (int i = 0; i < size; i++) {
			lastname[i] = _lastname[i];
		}
		lastname[size] = '\0';
		size = strlen(_CNIC);
		CNIC = new char[size + 1];
		for (int i = 0; i < size; i++) {
			CNIC[i] = _CNIC[i];
		}
		CNIC[size] = '\0';
		size = strlen(_firstname);
		username = new char[size + 3];
		for (int i = 0; i < size; i++) {
			username[i] = _firstname[i];
		}
		username[size] = '1';
		username[size + 1] = '9';
		username[size + 2] = '\0';
		password = new char[9];
		for (int i = 0; i < 8; i++)
		{
			int num = rand() % 8;
			password[i] = (char)num;
		}
		password[8] = '\0';
	}
	void print()
	{
		cout << "Name :" << this->firstname << " " << this->lastname << endl;
		cout << "CNIC: " << this->CNIC << endl;
		cout << "Username: " << this->username << endl;
		cout << "Password:" << password << endl;
	}
};


