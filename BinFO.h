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

// ��������� �� ��������������� �������
using readingBinaryFileFnc = bool(*)(const std::string& dir, my::Array& usersData);
using writeInBinaryFileFnc = bool(*)(const std::string& dir, my::Array& usersData);

// ������� ������ �����
bool ReadingBinaryFile(const std::string& dir, my::Array& usersData);
// ������� ������ � ����
bool WriteInBinaryFile(const std::string& dir, my::Array& usersData);
