#include "Keyboard.h"
#include "Array.h"

#include <conio.h>
#include <string>
#include <sstream>
#include <iostream>

// ������� ������ ������ ����������
u_short ButtonsReading(u_int& horPosOut, u_int& vertPosOut)
{
	using std::cout;
	using std::endl;

	// ������ ����� �������
	switch (_getch())
	{
	case CODE_ESCAPE:
		return KEY_ESCAPE;

	case CODE_ENTER:
		return KEY_ENTER;

	}

	// ������ ����� _getch() ��� ���������� �������������� ������� 
	switch (_getch())
	{
	case CODE_UP:
		vertPosOut -= VERTICAL_STEP;
		return KEY_UP;

	case CODE_DOWN:
		vertPosOut += VERTICAL_STEP;
		return KEY_DOWN;

	case CODE_LEFT:
		horPosOut -= HORIZONTAL_STEP;
		return KEY_LEFT;

	case CODE_RIGHT:
		horPosOut += HORIZONTAL_STEP;
		return KEY_RIGHT;

	case CODE_DELETE:
		return KEY_DELETE;

	default:
		return KEY_OTHER;
	}
}

// ������� ����� � �����������
void UserInput(my::Account& userData)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	using namespace std;

	stringstream input;	//	����� ��� ������
	string buffer;		//	������
	string subBuffer;	//	������ ��� �����
	getline(cin, buffer);
	input << buffer;

	// ������ �����
	while (buffer.length() == 0) {
		getline(cin, buffer);
		input << buffer;
	}

	// ������ �����
	string strBuffer;
	input >> strBuffer;
	userData.setFirstName(strBuffer);
	input >> strBuffer;
	userData.setLastName(strBuffer);

	// ������ ����� � ��������������� �� �����
	input >> subBuffer;
	userData.setMathScore(atoi(subBuffer.c_str()));
	input >> subBuffer;
	userData.setRuLangScore(atoi(subBuffer.c_str()));
	input >> subBuffer;
	userData.setEnLangScore(atoi(subBuffer.c_str()));
}