#include "WriteBack.h"

WriteBack::WriteBack(F_Buffer* F_B, IF_ID_Buffer* IFID_B, Mem_Buffer* MEM_B)
{
	FB = F_B;
	IF_ID_B = IFID_B;
	Mem_B = MEM_B;
}

void WriteBack::Run()
{
	DesSelect = Mem_B->getDataDesSelect();
	uint64_t Value = Mem_B->getmult_res();
	uint32_t Hi = (Value & 0xFFFF0000) >> 32;
	uint32_t Lo = Value & 0xFFFF;

	switch (DesSelect)
	{
	case 0: //ALU Out
		IF_ID_B->setDestData(Mem_B->getALUout());
		break;
	case 1: //Read Memory
		IF_ID_B->setDestData(Mem_B->getMemOut());
		break;
	case 2: //High
		IF_ID_B->setDestData(Hi);
		break;
	case 3: //Low
		IF_ID_B->setDestData(Lo);
		break;
	case 4: //nPc
		IF_ID_B->setDestData(Mem_B->getPC() + 4);
		break;
	case 5: //Negative Flag
		IF_ID_B->setDestData(Mem_B->getNeg_flag());
		break;
	}

	IF_ID_B->setDataEn(Mem_B->getDataEn());
	IF_ID_B->setDataAddress(Mem_B->getDesAddress());
}