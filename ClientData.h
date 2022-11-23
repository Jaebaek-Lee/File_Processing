#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#pragma once

#include <string>

class ClientData { //고객정보 클래스
public:
	ClientData(int = 0, const std::string& = "", const std::string& = "", double = 0.0); //정보 안들어오면 다 0과 ""로.

	void setAccountNumber(int); //일반적인 셋함수
	int getAccountNumber() const; //일반적인 겟함수. 내부에서 값을 변경 불가. const 멤버는 const 멤버함수만

	void setLastName(const std::string&); //위와 동일
	std::string getLastName() const;

	void setFirstName(const std::string&); //위와 동일
	std::string getFirstName() const;

	void setBalance(double); //위와 동일
	double getBalance() const;
private:
	int accountNumber; //계좌번호
	char lastName[15]; //라스트네임
	char firstName[10]; //퍼스트네임
	double balance; //잔고
};
#endif