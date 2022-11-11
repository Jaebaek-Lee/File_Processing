#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void outTofile() {
//	ofstream outFile("test.txt", ios::app); //ofstream 클래스 객체 생성, 인자로 파일경로와 타입을 전달. 이 경우, 자동으로 파일을 open
//	//ofstream outFile;
//	//outFile.open("test.txt", ios::app); //수동으로 파일을 open하는 경우
//	cout << "Enter the account, name, and balance,\n";
//	cout << "Enter end-of-file to end input.\n? ";
//
//	int account;
//	string name;
//	double balance;
//
//	while (cin >> account >> name >> balance) { //cin이 실패하거나 fail bit가 1이 되면 false를 리턴
//		outFile << account << ' ' << name << ' ' << balance << "\n \n \n \n \n \n"; //outFile에 차곡차곡 전달
//		cout << "? ";
//	}
//
//	outFile.close(); //파일 닫아줘야함! 이유 한 번 더 복습 필
//}
//
//void inToConsole() {
//	ifstream inFile{ "test.txt", ios::in }; //파일을 열어. 열어서 콘솔로 출력하고 싶음.
//
//	int account;
//	string name;
//	double balance;
//
//	while (inFile >> account >> name >> balance) { //파일 내용을 차곡차곡... 근데 만약 끝에 \n이 엄청 많다면? -무시하네 ㅋㅋ
//		cout << account << ' ' << name << ' ' << balance << '\n';
//	}
//
//	inFile.close();
//}
//
//int main() {
//	outTofile();
//	cout << '\n';
//	inToConsole();
//}

void outTofile() {
	ofstream outFile("test.txt", ios::app); //ofstream 클래스 객체 생성, 인자로 파일경로와 타입을 전달. 이 경우, 자동으로 파일을 open
	//ofstream outFile;
	//outFile.open("test.txt", ios::app); //수동으로 파일을 open하는 경우
	cout << "Enter the account, name, and balance,\n";
	cout << "Enter end-of-file to end input.\n? ";

	int account;
	string name;
	double balance;

	while (cin >> account >> name >> balance) { //cin이 실패하거나 fail bit가 1이 되면 false를 리턴
		outFile << account << ' ' << name << ' ' << balance << "\n\n\n\n"; //outFile에 차곡차곡 전달
		cout << "? ";
	}

	outFile.close(); //파일 닫아줘야함! 이유 한 번 더 복습 필
}

void inToConsole() {
	ifstream inFile{ "test.txt", ios::in }; //파일을 열어. 열어서 콘솔로 출력하고 싶음.

	int account;
	string name;
	double balance;

	while (inFile >> account >> name >> balance) { //파일 내용을 차곡차곡... 근데 만약 끝에 \n이 엄청 많다면?
		cout << account << ' ' << name << ' ' << balance << '\n';
	}

	inFile.close();
}

int main() {
	outTofile();
	cout << '\n';
	inToConsole();
}