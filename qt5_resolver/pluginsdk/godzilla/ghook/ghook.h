#ifndef _GODZILLA_GAUX_GHOOK_H_
#define _GODZILLA_GAUX_GHOOK_H_

#include <sstream>
#include <vector>
using std::vector;



#include "godzilla.h"
#include "gmemory/gmemory.h"
#include "gasm/gasm.h"

struct Debris {
	Gauge target_addr;		//��hook��Ŀ���ַ
	std::vector<Byte> hook_code;	//��hook�Ĵ���

};

bool InsertJmpToAddress(
	gpins_t ins, 
	const csh& cs_handle, 
	ks_engine* ks_handle,
	Gauge address,
	Gauge target_addr,
	Debris* debris
);


vector<Byte> HookCodeWrapper(
	const Debris& debris,
	const vector<Byte>& byte_code
);

#endif