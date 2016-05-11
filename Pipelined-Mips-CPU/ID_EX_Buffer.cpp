#include "ID_EX_Buffer.h"

ID_EX_Buffer::ID_EX_Buffer()
{}

bool ID_EX_Buffer::getDataEn()
{
	return DataEn;
}

bool ID_EX_Buffer::getImmEn()
{
	return ImmEn;
}

bool ID_EX_Buffer::getSECtrl()
{
	return SECtrl;
}

bool ID_EX_Buffer::getBranchType()
{
	return BranchType;
}

bool ID_EX_Buffer::getMemRW()
{
	return MemRW;
}

bool ID_EX_Buffer::getMemSize()
{
	return MemSize;
}

bool ID_EX_Buffer::getMultEn()
{
	return MultEn;
}

uint8_t ID_EX_Buffer::getJType()
{
	return JType;
}

uint8_t ID_EX_Buffer::getDesSelect()
{
	return DesSelect;
}

uint8_t ID_EX_Buffer::getALUOp()
{
	return ALUOp;
}

uint8_t ID_EX_Buffer::getDataDesSelect()
{
	return DataDesSelect;
}

uint8_t ID_EX_Buffer::getDesAddress()
{
	return DesAddress;
}

int32_t ID_EX_Buffer::getS1Data()
{
	return S1_Data;
}

int32_t ID_EX_Buffer::getS2Data()
{
	return S2_Data;
}

uint32_t ID_EX_Buffer::getPC()
{
	return PC;
}

void ID_EX_Buffer::setDataEn(bool a)
{
	DataEn = a;
}

void ID_EX_Buffer::setImmEn(bool a)
{
	ImmEn = a;
}

void ID_EX_Buffer::setSECtrl(bool a)
{
	SECtrl = a;
}

void ID_EX_Buffer::setBranchType(bool a)
{
	BranchType = a;
}

void ID_EX_Buffer::setMemRW(bool a)
{
	MemRW = a;
}

void ID_EX_Buffer::setMemSize(bool a)
{
	MemSize = a;
}

void ID_EX_Buffer::setMultEn(bool a)
{
	MultEn = a;
}

void ID_EX_Buffer::setJType(uint8_t a)
{
	JType = a;
}

void ID_EX_Buffer::setDesSelect(uint8_t a)
{
	DesSelect = a;
}

void ID_EX_Buffer::setALUOp(uint8_t a)
{
	ALUOp = a;
}

void ID_EX_Buffer::setDataDesSelect(uint8_t a)
{
	DataDesSelect = a;
}

void ID_EX_Buffer::setDesAddress(uint8_t a)
{
	DesAddress = a;
}

void ID_EX_Buffer::setS1Data(int32_t a)
{
	S1_Data = a;
}

void ID_EX_Buffer::setS2Data(int32_t a)
{
	S2_Data = a;
}

void ID_EX_Buffer::setPC(uint32_t a)
{
	PC = a;
}