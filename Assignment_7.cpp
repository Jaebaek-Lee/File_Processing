#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "ClientData.h"

using namespace std;

void outputLine(ostream&, const ClientData&);

int main() {
	//cin.ignore(); //???? 정의되지 않은 행동.
	//in out을 동시에 할 경우, 파일이 초기화가 안되는 것 같은데...? 0 입력하면 그대로 출력 근데 딱 한 번만. -in을 같이하면 삭제 안한다.
	//out으로 하고 아무 입력 없이 종료하면 객체 데이터가 안들어가있는 이유는?
	//1열 더 생기는 이유는?
	//마지막이 안뜨는 이유는?
	fstream outCredit{ "credit.bin", ios::in | ios::out | ios::binary }; //파일에 입출력 하고 싶다. 근데 이제 변환 없이 binary로다가
	//이름에 out만 있으니까 살짝 답답하다.
	//읽어오지도 않을거 뭐더러 in해줬나?
	//fact: 처음에 in을 같이 쓰면 파일을 생성하지 않아서 감점...
	if (!outCredit) { //파일 못 열었으면 오류!
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	ClientData blankClient; //빈 객체 생성해버린다. 엄밀히 말하면 0 "" "" 0으로 초기화
	outCredit.seekg(0); //명시적으로 지정
	for (int i{ 0 }; i < 100; ++i) { //100번 작성
		outCredit.write(
			reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));
		//생성한 객체의 사이즈만큼(변수 세개 - 8*3바이트) 그 주소에 든걸 파일에 작성. 솔직히 무슨 원리인지 모르겠다.
		//출력된 쓰레기 값이 도대체 무슨 기준으로 저렇게 정갈하게 작성된건지도 모르겠다. 중간에 공백이 난무하는데 그럼 seek가 어떻게 그걸 계산하냐
		//왜 1열이 하나 더 많나?
	}

	cout << "Enter account number (1 to 100, 0 to end input)\n? ";

	int accountNumber;
	string lastName;
	string firstName;
	double balance;

	cin >> accountNumber;

	while (accountNumber > 0 && accountNumber <= 100) { //0은 없다. 100개밖에 없다.
		cout << "Enter lastname, firstname and balance\n? ";
		cin >> lastName;
		cin >> firstName;
		cin >> balance;

		ClientData client{ accountNumber, lastName, firstName, balance };

		outCredit.seekp( //파일에 출력해주고 싶은 위치 지정
			(client.getAccountNumber() - 1) * sizeof(ClientData)); //원하는 계좌가 첫 번째면 0에 커서를 둬야함. 1 - 1. 그래서 항상 -1해줘야함.
		//만약 두 번째를 원하면 1 * 객체 크기 되어서 24바이트라 치면 24로 이동할 것.
		//outCredit.clear();
		outCredit.write( //현재 위치에다가 client의 포인터로 값을 참조하여 그 객체 크기만큼 값을 따와서 버퍼에 작성해준다.
			reinterpret_cast<const char*>(&client), sizeof(ClientData));

		cout << "Enter account number\n? ";
		cin >> accountNumber;
	}//자 이제 내가 원하는 계좌번호에 내가 원하는 데이터가 잘 들어갔을 것이다.
	
	outCredit.close(); //이게 없을때, 100 뿐만이 아닌 모든 마지막 입력에 대해서는 버퍼에만 남는다.
	//그럼 언제 버퍼의 내용이 파일로 옮겨질까? write때일까 아니면 while scope 종료때일까?
	//write이겠지. 그래야 마지막 입력만 새로운 write를 못 만나서 파일로 옮겨지지 못한다.
	//즉, write는 기존 버퍼 내용을 파일로 옮겨주는 역할도 하는 것 같다.
	//while scope 종료는 아무런 의미가 없나? 당연하다. outCredit 객체는 main 스코프에 있다.
	//버퍼는 계속 이어진다.
	//fact: seekp 함수가 버퍼를 비워준다. write는 무조건 버퍼에만 담는다.
	//마지막 write는 seek가 처리 안해줘서 파일을 닫아야 저장된다.

	ifstream inCredit{ "credit.bin", ios::in | ios::binary }; //이제는 읽어올거야!
	//처음부터 객체 이름을 inoutCredit으로 만들거나 위에서 그냥 out모드로 따로 했으면 좋았을텐데
	//이도저도 아니게 만들어져 있다...

	if (!inCredit) { //파일 못 열었으면 오류!
		cerr << "File could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	cout << '\n';
	cout << left << setw(10) << "Account" << setw(16) << "Last Name"
		<< setw(11) << "First Name" << setw(11) << right << "Balance\n"; //공간 잡고 정렬하고 반복 //교제가 이상하다. 여기서 개행때문에 한 칸 더 잡아줘야함.

	ClientData client; //여기다가 옮겨와서 유의미한 형태로 출력할거다.

	inCredit.seekg(0);//명시적으로 시작위치 지정

	inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData)); //객체 사이즈만큼 파일에서 읽고 client의 시작주소에 저장.
	//여기선 버퍼같은거 없나...? 이 다음에 client를 즉시 사용 가능한 것 보니까 버퍼 없이 바로 저장되는 것 같다.
	//아닌...가...?

	while (inCredit) { //파일의 커서가 end에 위치하며 -1이 되면 eof상태에 돌입. 탈출.
		if (client.getAccountNumber() != 0) { //넘버가 0 말고 다른걸로 존재한다면. 즉 유저 지정 초기화 되어있다면
			outputLine(cout, client); //출력 함수 실행.
		}
		inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData)); //앞에서 읽을때 커서가 옮겨졌다. 따로 seek 할 필요 없이 그냥 다시 읽음.
		//if (client.getAccountNumber() == 100) { //100번째에 대한 예외처리문 없으면 출력 전에 eof됨. 왜 없어도 되는걸까
		// //fact: 마지막에 eof 마커라는게 존재해서 바로 종료 안한다.
		//	inCredit.clear();
		//	inCredit.seekg(0);
		//	outputLine(cout, client);
		//	inCredit.seekg(-1);
		//}
	}
	inCredit.close();
}

void outputLine(ostream& output, const ClientData& record) { //output 객체로 옮겨받는 이유를 사실 잘 모르겠다. 그냥 cout 하면 되는거 아닌가...?
	output << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << setprecision(2) << right << fixed //소수점 두자리 고정
		<< showpoint << record.getBalance() << endl; //소수점을 보여준다.
}

/*
1
wook lee 100.00
2
by park 12.34
100
wlrma dl 123.9
0

*/