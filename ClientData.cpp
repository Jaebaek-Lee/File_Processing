#include "ClientData.h"
#include <iostream>
#include <string>

using namespace std;

ClientData::ClientData(int accountNumberValue, const string& lastName, const string& firstName, double balanceValue) //const string타입의 주소를 참조. 즉, 내부 값 수정 불가. string도 객체라 참조하는게 효율.
	: accountNumber(accountNumberValue), balance(balanceValue) {
	setLastName(lastName);
	setFirstName(firstName); //사실 이니셜라이저 리스트에서 해도 됨.
}

int ClientData::getAccountNumber() const { return accountNumber; } //설명

void ClientData::setAccountNumber(int accountNumberValue) { //불필요
	accountNumber = accountNumberValue;
}

string ClientData::getLastName() const { return lastName; } //마찬가지

void ClientData::setLastName(const string& lastNameString) { //데이터가 차지하는 공간을 설정해준다.
	size_t length{ lastNameString.size() };
	length = (length < 15 ? length : 14); //빈 객체면 length는 0이 되고
	lastNameString.copy(lastName, length); //lastName에 lastNameString을 length만큼 복사한다.
	lastName[length] = '\0'; //라스트 네임은 널문자를 저장한다.
	//최대 사이즈는 14이다.
}

string ClientData::getFirstName() const { return firstName; } //x

void ClientData::setFirstName(const string& firstNameString) { //위의 라스트 네임과 동일하다. 최대 공간 9
	size_t length{ firstNameString.size() };
	length = (length < 10 ? length : 9);
	firstNameString.copy(firstName, length);
	firstName[length] = '\0';
}

double ClientData::getBalance() const { return balance; }

void ClientData::setBalance(double balanceValue) { balance = balanceValue; }