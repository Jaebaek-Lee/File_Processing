#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	fstream originalRead("C:\\Windows\\system.ini", ios::in); //아무래도 중요한 파일처럼 보이니까 읽기만 가능하도록 모드 설정. 자동으로 open하는 형식.
	fstream newFile("이재백.ini", ios::out);//파일을 그대로 복사할 게획이니까 qpp보단 out모드로 새로운 파일을 항상 생성. 자동으로 open.

	if (!originalRead) { cout << "open error!\n"; } //정상적으로
	if (!newFile) { cout << "out error!\n"; } //오픈되었는지 확인

	string temp; //임시 string 객체

	while (originalRead) { //원본 파일이 fail or eof상태(1)에 돌입하면 false. 커서가 end에 위치하여 -1이 되면 파일을 다 읽었다는 뜻이고, eof비트가 1이 된다.
		getline(originalRead, temp); //cin 버퍼가 아닌, 원본 파일의 커서(비트)위치를 이동시켜준다. 공백을 포함하여 temp에 저장. 개행을 종료로 판단한 후 개행을 제거.
		newFile << temp; //개행을 기준으로 저장된 temp를 새 파일에 전달
		if (originalRead.tellg() != -1) { //만약 파일 커서가 파일의 끝에 도달하지 않았다면
			newFile << '\n'; //개행문자를 출력. 이게 없으면 파일의 마지막에 enter가 두 번 들어가서 원본이랑 달라진다.
		}
	}

	originalRead.close(); //명시적으로
	newFile.close(); //파일을 닫아준다.
}