#pragma once

#include <string>
#include <sredefs.h>
using std::string;


#define FILE_SIZE_ADD 1
#define FILE_SIZE_SUB 4


struct IMAGE_MAP_INFO {
	HANDLE file;
	HANDLE map;
};
//�����ļ����ڴ�ӳ��
LPVOID CreateImageMapFile(IN string fileName, IN DWORD maxSize, OUT IMAGE_MAP_INFO* info, OUT DWORD* result);
LPVOID CreateImageMapFile(IN HANDLE file,
	IN DWORD maxSize,
	IN DWORD flMappingProtect,
	IN DWORD flMappingDesiredAccess,
	OUT HANDLE& map, OUT DWORD* result);
//ж���ļ����ڴ�ӳ��
bool UnmapOfFile(IN LPVOID addr, IMAGE_MAP_INFO* info);
bool UnmapOfFile(IN LPVOID addr, HANDLE map);
DWORD SetFileSize(string fileName, LONG size, DWORD mode);
DWORD SetFileSize(HANDLE file, LONG size, DWORD mode);
