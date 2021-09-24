#include "Account.h"
//#include "Keyboard.h"
//#include "CMenu.h"
#include "BinFO.h"
#include "Array.h"

#include <conio.h>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
#include <random>
#include <Windows.h>



int main(int argc, char* argv[])
{
	using namespace std;

	setlocale(LC_ALL, "ru");

	// ����� ���� �����
	string path;
	//string path = "random_data.bin";	//to do dbg
	if (argc > 1) {
		path = argv[1];
	}
	else {
		cout << "������� ���� � �������� �����: ";
		getline(cin, path);
	}

	// ��������� ����������� ������
	uint16_t passingScore = 100;
	uint16_t minMathScore = 0, minRuLangScore = 0, minEnLangScore = 0;

	//cout << "������� ����� ��������� ������: ";
	//cin >> passingScore;
	//cout << "������� ����������� �������� ������ �� ����������: ";
	//cin >> minMathScore;
	//cout << "������� ����������� �������� ������ �� �������� �����: ";
	//cin >> minRuLangScore;
	//cout << "������� ����������� �������� ������ �� �����������: ";
	//cin >> minEnLangScore;

	//	�������� ���������� 
	my::Array Exam;			//	��������� ��� ���������������� �������� ������ ������������ � ������
	//u_int horizontalPos = 1, verticalPos = 1;	//	���������� ��������� ����

	bool	exitFlag = true;	//	���� ������ �� ��������� 
	short	codeItem(0);		//	��������� ����������
	uint32_t len;
	ReadingBinaryFile(path, Exam, 0, 0, len);
	cout << "len: " << len << endl;
	cout << "len Exam: " << Exam.getSize() << endl;
	ReadingBinaryFile(path, Exam, 0, 100, len);
	cout << "len Exam: " << Exam.getSize() << endl;

	for (short i = 0; i < Exam.getSize(); ++i) {
		cout << "�" << i << endl;
		std::cout << "���: " << Exam[i].getFirstName() << " ";
		std::cout << "�������: " << Exam[i].getLastName() << " ";
		std::cout << Exam[i].getMathScore() << " ";
		std::cout << Exam[i].getRuLangScore() << " ";
		std::cout << Exam[i].getEnLangScore() << " ";
		std::cout << Exam[i].getTotalScore() << std::endl;
	}

	WriteInBinaryFile(path, Exam);

	//while (exitFlag)
	//{
	//	PrintMainMenu(verticalPos, allMenuTemplates, InsertCursorPosition);	// ����� ��������� ����

	//	codeItem = ButtonsReading(horizontalPos, verticalPos);					// ������ ����������
	//	FindingCursorPosition(verticalPos, static_cast<int>(HEIGHT_ITEM_MAIN));	// ��������� �������

	//	if (codeItem == KEY_ENTER)
	//	{
	//		switch (verticalPos)
	//		{
	//		case ITEM_VIEW:
	//			PrintTable(path, usersData, allMenuTemplates,
	//				InsertCursorPosition, SelectionMenuPrinting, ButtonsReading,
	//				FindingCursorPosition, FindingCursorPosition,
	//				ReadingBinaryFile, WriteInBinaryFile, DeletingFromBinaryFile,
	//				ChangeDataInBinaryFile, AppendInBinaryFile, UserInput);
	//			break;

	//		case ITEM_STATISTICS:
	//			ComputeStatistics(passingScore, minMathScore, minRuLangScore, minEnLangScore, path, usersData,
	//				ReadingBinaryFile, PrintTable, InsertCursorPosition, ButtonsReading, FindingCursorPosition);
	//			break;

	//		case ITEM_CREATE:
	//			PrintCreateItem(path, InsertCursorPosition, ButtonsReading, FindingCursorPosition, SelectionMenuPrinting, UserInput);
	//			//CreateRandomBinDataset(path);
	//			break;

	//		case ITEM_EXIT:
	//			exitFlag = false;

	//		}
	//	}
	//}


	return 0;
}