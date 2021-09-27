#pragma once

#include "Array.h"
#include "BinFO.h"
#include "Keyboard.h"

#include <string>
#include <Windows.h>


enum MainMenuItems	// ������������ ������� ��������� ����
{
	ITEM_VIEW = 1,
	ITEM_STATISTICS,
	ITEM_CREATE,
	ITEM_EXIT,
};


enum MenuSizes	//	������������ �������� ����
{
	HEIGHT_ITEM_MAIN = 4,
	LENGTH_ITEM_DEFAULT = 1,
	HEIGHT_ITEM_VIEW = 15,
	HEIGHT_ITEM_SELECTION = 2,
};

enum MenuLevels	//	������������ ������� ����
{
	LEVEL_MAIN,
	LEVEL_VIEW,
	LEVEL_SELECTION
};

enum PositionBeginPoint	//	������������ ������ ��������� ���������� � ����
{
	HORIZONTAL_BEGIN_POINT = 1,
	VERTICAL_BEGIN_POINT = 1,
};

enum SelectionMenuItems	//	������������ ���������� ������� ���� ������
{
	ITEM_SELECTION_YES = 1,
	ITEM_SELECTION_NO,
};

enum WidthOfTableFields	//	������������ �������� �������
{
	COUNTER_FIELD_WIDTH = 8,
	FIRST_NAME_FIELD_WIDTH = 25,
	LAST_NAME_FIELD_WIDTH = 25,
	MATCH_SCORE_FIELD_WIDTH = 7,
	RU_SCORE_FIELD_WIDTH = 6,
	EN_SCORE_FIELD_WIDTH = 6,
	TOTAL_SCORE_FIELD_WIDTH = 7,
	OUR_FIELD_WIDTH = 93,
	PAGE_FIELD_WIDTH = 7,
};

// ��������� �������� ����
#ifndef MENU_TEMP
#define MENU_TEMP

#pragma pack(1)
struct MenuTemplates
{
	std::string cursor;
	std::string space;
	std::string percent;

	std::string itemMainDescription;
	std::string lineView;
	std::string lineStatistics;
	std::string lineCreate;
	std::string lineExit;

	std::string itemViewDescription;
	std::string tableHeader;
	std::string tableSeparatorHorizontal;
	std::string tableSeparatorVertical;
	std::string tablePage;
	std::string tablePageSeparator;

	std::string itemStatDescription;
	std::string itemStatLineHeader;
	std::string itemStatLinePercent;

	std::string selLineYes;
	std::string selLineNo;
};
#pragma pack (pop)

extern MenuTemplates allMenuTemplates;

#endif



// ��������� �� ��������������� �������
using findingCursorPositionFnc1 = void(*)(u_int& vertPosOut, const u_int& heigh);
using findingCursorPositionFnc2 = void(*)(u_int& horPosOut, u_int& vertPosOut, const u_int& length, const u_int& height);
using insertCursorPositionFnc = std::string(*)(std::string str, const u_int& vertPos,
	const MenuTemplates& mTemps, u_short level, const u_int& iterator);
using selectionMenuPrintingFnc = bool(*)(std::string title, insertCursorPositionFnc insCurPosFnc,
	buttonsReadingFnc buttReadFnc, findingCursorPositionFnc1 findCurPosFnc);

using printTableFnc = void(*)(const u_int& failCount, std::string dir, my::Array& usersData, const MenuTemplates& mTemps,
	insertCursorPositionFnc insCurPosFnc, buttonsReadingFnc buttReadFnc, findingCursorPositionFnc2 findCurPosFnc2);


//	������� ��������������� ����� ���������� �������������� ��������� �� ������� [V_B_P,height]
void		FindingCursorPosition(u_int& vertPosOut, const u_int& heigh);

//	������� ��������������� ����� ���������� �������������� � ��������������� ��������� �� ������� [V_B_P, height], [H_B_P, length]
void		FindingCursorPosition(u_int& horPosOut, u_int& vertPosOut, const u_int& length, const u_int& height);

//	�������� ������ �� ���������
std::string InsertCursorPosition(std::string str, const u_int& vertPos,
				const MenuTemplates& mTemps, u_short level, const u_int& iterator);

//	���� ������ ��/���
bool		SelectionMenuPrinting(std::string title, insertCursorPositionFnc insCurPosFnc,
				buttonsReadingFnc buttReadFnc, findingCursorPositionFnc1 findCurPosFnc);

//	�������� ����
void		PrintMainMenu(const u_int& vertPos, const MenuTemplates& mTemps, insertCursorPositionFnc insCurPosFnc);

// ���������� ������� � ��������� ��������������
void		PrintTable(std::string dir, my::Array& usersData, const MenuTemplates& mTemps,
				insertCursorPositionFnc insCurPosFnc, selectionMenuPrintingFnc selMenuPrintingFnc,
				buttonsReadingFnc buttReadFnc, findingCursorPositionFnc1 findCurPosFnc1, findingCursorPositionFnc2 findCurPosFnc2,
				readingBinaryFileFnc readBinFileFnc, writeInBinaryFileFnc writeInBinFileFnc,
				userInputFnc userInputFnc);
//// ���������� ������ ��� ���������� ������� 
void		PrintTable(const u_int& failCount, std::string dir, my::Array& usersData, const MenuTemplates& mTemps,
				insertCursorPositionFnc insCurPosFnc, buttonsReadingFnc buttReadFnc, findingCursorPositionFnc2 findCurPosFnc2);

// ������� ���������� �������������� ������
void		ComputeStatistics(const u_short& pasScore, const u_short& minMathScore, const u_short& minRuLangScore,
	const u_short& minEnLangScore, const std::string dir, my::Array& usersData,
	readingBinaryFileFnc readBinFileFnc, printTableFnc printTableFnc, insertCursorPositionFnc insCurPosFnc,
	buttonsReadingFnc buttReadFnc, findingCursorPositionFnc2 findCurPosFnc2);

// ������� �������� ������ ����� � ������
void		PrintCreateItem(std::string& dir, my::Array& usersData, insertCursorPositionFnc insCurPosFnc, buttonsReadingFnc buttReadFnc,
				findingCursorPositionFnc1 findCurPosFnc, selectionMenuPrintingFnc selMenuPrintingFnc, userInputFnc userInputFnc, writeInBinaryFileFnc writeInBinFileFnc);


