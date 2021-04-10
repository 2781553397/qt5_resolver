#pragma once
#include "pluginmain.h"
#include "MetaData.h"
#include <vector>
#include <SREMemory.h>
#include <map>
#include <string>
using std::string;
using std::vector;
using std::map;

struct MSDContent {
	duint sep;		//�ָ���0xFFFFFFF
	duint len;		//�ַ����ĳ���
	duint fill;		//���Ϊ0
	duint offset;	//�����ƫ������Ե�ǰ���ƫ��
};

struct MethodSign {
	string name;
	vector<string> param;
};



struct CMetaStrData {
	string className;
	vector<MethodSign> signal;
	vector<MethodSign> slot;
};

vector<MethodSign> GetSpecSign(vector<string>& meta, vector<MDMethodDesc>& desc);
void AbjustSlotIndex(vector<string>& meta, vector<MDMethodDesc>& signal, vector<MDMethodDesc>& slot);
void ReadMethodInfo(HANDLE hd,duint addr, vector<string>* out);
vector<MSDContent> ReadMSDContent(duint addr);