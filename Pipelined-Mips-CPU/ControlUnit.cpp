#include <iostream>
#include "ControlUnit.h"

ControlUnit::ControlUnit(IF_ID_Buffer* IF_ID, ID_EX_Buffer* ID_EX) : PrevBufferPtr(IF_ID), NextBufferPtr(ID_EX)
{
	ClearSignals();

}

void ControlUnit::generateSignals()
{
	opCode = (PrevBufferPtr->getInstruction() & 0xFC000000) >> 26;
	Func = (PrevBufferPtr->getInstruction() & 0x3F);

	switch (opCode)
	{
	case 3:
		generateJAL();
		break;
	case 35:
		generateLW();
		break;
	case 43:
		generateSW();
		break;
	case 8:
		generateADDI();
		break;
	case 2:
		generateJump();
		break;
	case 0:
		switch (Func)
		{
		case 32:
		case 33:
			generateAdd();
			break;
		case 38:
			generateXOR();
			break;
		case 42:
			generateSLT();
			break;
		case 8:
			generateJR();
			break;
		}
		break;

	}

	setSignals();
}

void ControlUnit::ClearSignals()
{
	DataEn = false;
	ImmEn = false;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = false;
	MultEn = false;
	JType = 0;
	DesSelect = 0;
	ALUOp = 0;
	DataDesSelect = 0;
}

void ControlUnit::generateAdd()
{
	DataEn = true;
	ImmEn = false;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 0;
	ALUOp = 6;
	DataDesSelect = 0;

}

void ControlUnit::generateADDI()
{

	DataEn = true;
	ImmEn = true;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 1;
	ALUOp = 6;
	DataDesSelect = 0;

}

void ControlUnit::generateXOR()
{
	DataEn = true;
	ImmEn = false;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 0;
	ALUOp = 2;
	DataDesSelect = 0;

}

void ControlUnit::generateLW()
{
	DataEn = true;
	ImmEn = true;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 1;
	ALUOp = 6;
	DataDesSelect = 1;

}

void ControlUnit::generateSW()
{
	DataEn = false;
	ImmEn = true;
	SECtrl = false;
	BranchType = false;
	MemRW = true;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 1;
	ALUOp = 6;
	DataDesSelect = 0;

}

void ControlUnit::generateJump()
{
	DataEn = false;
	ImmEn = true;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 2;
	DesSelect = 0;
	ALUOp = 0;
	DataDesSelect = 0;
	
}

void ControlUnit::generateSLT()
{
	DataEn = true;
	ImmEn = false;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 0;
	ALUOp = 7;
	DataDesSelect = 5;

}

void ControlUnit::generateJAL()
{
	DataEn = true;
	ImmEn = true;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 0;
	DesSelect = 0;
	ALUOp = 0;
	DataDesSelect = 0;
}

void ControlUnit::generateJR()
{
	DataEn = false;
	ImmEn = false;
	SECtrl = false;
	BranchType = false;
	MemRW = false;
	MemSize = true;
	MultEn = false;
	JType = 3;
	DesSelect = 0;
	ALUOp = 0;
	DataDesSelect = 4;

}

void ControlUnit::setSignals()
{
	NextBufferPtr->setDataEn(DataEn);
	NextBufferPtr->setImmEn(ImmEn);
	NextBufferPtr->setSECtrl(SECtrl);
	NextBufferPtr->setALUOp(ALUOp);
	NextBufferPtr->setBranchType(BranchType);
	NextBufferPtr->setMemRW(MemRW);
	NextBufferPtr->setMemSize(MemSize);
	NextBufferPtr->setMultEn(MultEn);
	NextBufferPtr->setJType(JType);
	NextBufferPtr->setDesSelect(DesSelect);
	NextBufferPtr->setDataDesSelect(DataDesSelect);
}