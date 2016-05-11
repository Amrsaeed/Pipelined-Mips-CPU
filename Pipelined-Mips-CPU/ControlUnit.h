#include "ID_EX_Buffer.h"
#include "IF_ID_Buffer.h"

#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

class ControlUnit
{
public:
	ControlUnit(IF_ID_Buffer*, ID_EX_Buffer*);
	void generateSignals();
	void ClearSignals();

private:
	IF_ID_Buffer* PrevBufferPtr;
	ID_EX_Buffer* NextBufferPtr;

	uint8_t opCode;
	uint8_t Func;

	bool DataEn;
	bool ImmEn;
	bool SECtrl;
	bool BranchType;
	bool MemRW;
	bool MemSize;
	bool MultEn;
	uint8_t JType;
	uint8_t DesSelect;
	uint8_t ALUOp;
	uint8_t DataDesSelect;

	void generateAdd();
	void generateADDI();
	void generateXOR();
	void generateLW();
	void generateSW();
	//void generateBLE();
	void generateJump();
	void generateSLT();
	void generateJAL();
	void generateJR();
	void setSignals();
};

#endif