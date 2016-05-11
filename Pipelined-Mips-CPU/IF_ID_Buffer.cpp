#include "IF_ID_Buffer.h"

IF_ID_Buffer::IF_ID_Buffer()
{}

uint32_t IF_ID_Buffer::getInstruction()
{
	return Instruction;
}

uint32_t IF_ID_Buffer::getPC()
{
	return PC;
}

uint32_t IF_ID_Buffer::getnPC()
{
	return nPC;
}

uint8_t IF_ID_Buffer::getDataAddress()
{
	return Data_Address;
}

uint32_t IF_ID_Buffer::getDestData()
{
	return DestData;
}

bool IF_ID_Buffer::getDataEn()
{
	return Data_En;
}

void IF_ID_Buffer::setInstruction(uint32_t a)
{
	Instruction = a;
}

void IF_ID_Buffer::setPC(uint32_t a)
{
	PC = a;
}

void IF_ID_Buffer::setnPC(uint32_t a)
{
	nPC = a;
}

void IF_ID_Buffer::setDataAddress(uint8_t a)
{
	Data_Address = a;
}

void IF_ID_Buffer::setDestData(uint32_t a)
{
	DestData = a;
}

void IF_ID_Buffer::setDataEn(bool a)
{
	Data_En = a;
}