#pragma once

#include "Account.h"
#include "Array.h"
#include <Windows.h>
#include <string>
#include <iostream>

enum LengthOfTableFields	// ������������� ���-�� �������� ������� ������� 
{
	DATA_FIELD_LENGTH = 14,	// ���-�� �������� ������� ������� ��������� � �������
};

enum IndexConst {
	IND_CONV_FACTOR = 1, // index conversion factor
};

enum DataBuffersSize {
	SUBFILE_SIZE = 7 * DATA_FIELD_LENGTH, // 7*14=98; ������ ��������� ��� ��������/��������� ������
};

								
// ������� �������������� �����
void CreateRandomBinDataset(std::string dir);

// ������� ������ �����
bool ReadingBinaryFile(const std::string& dir, my::Array& usersData, const u_int& dataReadIndBeg,
		const u_int& dataReadIndCount, u_int& dataCountOut);
// ������� ������ � ����
bool WriteInBinaryFile(const std::string& dir, my::Array& usersData);

// ��������� �� ��������������� �������
using readingBinaryFileFnc = bool(*)(const std::string& dir, my::Array& usersData, const u_int& dataReadIndBeg,
	const u_int& dataReadIndCount, u_int& dataCountOut);
using writeInBinaryFileFnc = bool(*)(const std::string& dir, my::Array& usersData);