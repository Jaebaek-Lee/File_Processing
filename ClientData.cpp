#include "ClientData.h"
#include <iostream>
#include <string>

using namespace std;

ClientData::ClientData(int accountNumberValue, const string& lastName, const string& firstName, double balanceValue) //const stringŸ���� �ּҸ� ����. ��, ���� �� ���� �Ұ�. string�� ��ü�� �����ϴ°� ȿ��.
	: accountNumber(accountNumberValue), balance(balanceValue) {
	setLastName(lastName);
	setFirstName(firstName); //��� �̴ϼȶ����� ����Ʈ���� �ص� ��.
}

int ClientData::getAccountNumber() const { return accountNumber; } //����

void ClientData::setAccountNumber(int accountNumberValue) { //���ʿ�
	accountNumber = accountNumberValue;
}

string ClientData::getLastName() const { return lastName; } //��������

void ClientData::setLastName(const string& lastNameString) { //�����Ͱ� �����ϴ� ������ �������ش�.
	size_t length{ lastNameString.size() };
	length = (length < 15 ? length : 14); //�� ��ü�� length�� 0�� �ǰ�
	lastNameString.copy(lastName, length); //lastName�� lastNameString�� length��ŭ �����Ѵ�.
	lastName[length] = '\0'; //��Ʈ ������ �ι��ڸ� �����Ѵ�.
	//�ִ� ������� 14�̴�.
}

string ClientData::getFirstName() const { return firstName; } //x

void ClientData::setFirstName(const string& firstNameString) { //���� ��Ʈ ���Ӱ� �����ϴ�. �ִ� ���� 9
	size_t length{ firstNameString.size() };
	length = (length < 10 ? length : 9);
	firstNameString.copy(firstName, length);
	firstName[length] = '\0';
}

double ClientData::getBalance() const { return balance; }

void ClientData::setBalance(double balanceValue) { balance = balanceValue; }