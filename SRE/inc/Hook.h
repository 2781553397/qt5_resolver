#pragma once
#include <string>
#include <sredefs.h>
#include <MathPlus.h>


using std::wstring;
using std::string;


struct HABORIGIN {
	byte* fun_code;
	size_t code_size;

};

struct HCHIP {
	void_ptr hook_addr;
	HABORIGIN aborigin;
	void_ptr pedal_addr;
	size_t pedal_size;
};

HABORIGIN ReadFunCodeToHook(string opcode, void_ptr addr, HANDLE hProcess);

HCHIP RelaCallInstall(
	void_ptr tag,//��תĿ�꺯��
	void_ptr hook_addr,	//hook��ַ
	bool idx_mode, //�����Ĵ�����trueΪesp,falseΪebp
	Gauge param_offset,//������������Ĵ�����ƫ��
	Gauge param_amount,//��Ҫ�Ĳ�������
	HANDLE hProcess=nullptr);

bool Unhook(HCHIP& data);



		

bool InjectLibrary(HANDLE process, wstring library);

