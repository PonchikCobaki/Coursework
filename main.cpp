#include "Account.h"
#include "Keyboard.h"
#include "CMenu.h"
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
	//string path;
	string path = "random_data.bin";	//to do dbg
	/*if (argc > 1) {
		path = argv[1];
	}
	else {
		cout << "������� ���� � �������� �����: ";
		getline(cin, path);
	}*/

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
	u_int horizontalPos = 1, verticalPos = 1;	//	���������� ��������� ����

	bool	exitFlag = false;	//	���� ������ �� ��������� 
	short	codeItem(0);		//	��������� ����������

	CreateRandomBinDataset(path);
	exitFlag = ReadingBinaryFile(path, Exam);

	if (exitFlag) {
		cerr << "\n\t ���� ������ ��� ��� �� ����������!" << endl;
		system("pause");
		exitFlag = true;
	}

	while (!exitFlag)
	{
		PrintMainMenu(verticalPos, allMenuTemplates, InsertCursorPosition);	// ����� ��������� ����

		codeItem = ButtonsReading(horizontalPos, verticalPos);					// ������ ����������
		FindingCursorPosition(verticalPos, static_cast<int>(HEIGHT_ITEM_MAIN));	// ��������� �������

		if (codeItem == KEY_ENTER)
		{
			switch (verticalPos)
			{
			case ITEM_VIEW:
				PrintTable(path, Exam, allMenuTemplates,
					InsertCursorPosition, SelectionMenuPrinting, ButtonsReading,
					FindingCursorPosition, FindingCursorPosition,
					ReadingBinaryFile, WriteInBinaryFile, UserInput);
				break;

			case ITEM_STATISTICS:
				ComputeStatistics(passingScore, minMathScore, minRuLangScore, minEnLangScore, path, Exam,
					ReadingBinaryFile, PrintTable, InsertCursorPosition, ButtonsReading, FindingCursorPosition);
				break;

			case ITEM_CREATE:
				PrintCreateItem(path, Exam, InsertCursorPosition, ButtonsReading,
					FindingCursorPosition, SelectionMenuPrinting, UserInput, WriteInBinaryFile);
				break;

			case ITEM_EXIT:
	 			WriteInBinaryFile(path, Exam);
				exitFlag = true;

			}
		}
	}


	return 0;
}