#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#pragma once

#include <string>

class ClientData { //������ Ŭ����
public:
	ClientData(int = 0, const std::string& = "", const std::string& = "", double = 0.0); //���� �ȵ����� �� 0�� ""��.

	void setAccountNumber(int); //�Ϲ����� ���Լ�
	int getAccountNumber() const; //�Ϲ����� ���Լ�. ���ο��� ���� ���� �Ұ�. const ����� const ����Լ���

	void setLastName(const std::string&); //���� ����
	std::string getLastName() const;

	void setFirstName(const std::string&); //���� ����
	std::string getFirstName() const;

	void setBalance(double); //���� ����
	double getBalance() const;
private:
	int accountNumber; //���¹�ȣ
	char lastName[15]; //��Ʈ����
	char firstName[10]; //�۽�Ʈ����
	double balance; //�ܰ�
};
#endif