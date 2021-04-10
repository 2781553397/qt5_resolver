#include "pch.h"
#include <MathPlus.h>


/*********************************************************************************
*��������OperationExtend
*�βΣ�MH��mWord,output�������
*���ã����˷���չ��64λ����32λ�͵�32λ���ֱ����output��
**********************************************************************************/
void OperationExtend(int MH, int mWord,int *output) {
	//ÿһ��Ԫ��ֻ����2���ֽڣ����ֽ���չ��8��
	int stopOverflow[4];
	//��λ��־λ
	unsigned short int CF = 0;
	stopOverflow[3] = MH & 0xFFFF;
	stopOverflow[2] = (MH & 0xFFFF0000) >> 16;
	stopOverflow[1] = 0;
	stopOverflow[0] = 0;
	//��0x55555556��mWord���ȡ���и�32λ
	for (int a = 3;a >= 0;a--) {
		stopOverflow[a] *= mWord;
		stopOverflow[a] += CF;
		CF = (stopOverflow[a] & 0xFFFF0000) >> 16;
	}

	output[0] |= (stopOverflow[0] & 0xFFFF);
	output[0] <<= 16;
	output[0] |= (stopOverflow[1] & 0xFFFF);

	output[1] |= (stopOverflow[3] & 0xFFFF);
	output[1] <<= 16;
	output[1] |= (stopOverflow[4] & 0xFFFF);
}



void_ptr vptr_add_Gauge(void_ptr v, Gauge d) {
	return tovptr(toGauge(v) + d);
}
