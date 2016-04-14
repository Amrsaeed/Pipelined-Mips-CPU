#include <iostream>
#include "RegisterFile.h"

RegisterFile::RegisterFile(IF_ID_Buffer* IF_ID, Buffer* ID_EX): PrevBufferPtr(IF_ID), NextBufferPtr(ID_EX)
{
	for (auto i : Registers)
		Registers[i] = 0;
	
}

void RegisterFile::read()
{
	Instruction = PrevBufferPtr->getInstruction();

	S1_Address = ((Instruction & 0x3E00000) >> 21);
	S2_Address = ((Instruction & 0x1F0000) >> 16);

	S1_Data = Registers[S1_Address];
	S2_Data = Registers[S2_Address];

	//Insert Data to NextBufferPtr
}

void RegisterFile::write()
{
	//for (auto i : R_Ens)
	//	R_Ens[i] = 0;

	Data_En = PrevBufferPtr->getDataEn();
	Data_Address = PrevBufferPtr->getDataAddress();
	Dest_Data = PrevBufferPtr->getDestData();

	if (Data_En)
		Registers[Data_Address] = Dest_Data;

}

void RegisterFile::clear()
{
	for (auto i : Registers)
		Registers[i] = 0;
}

RegisterFile::~RegisterFile()
{
	delete PrevBufferPtr;
	delete NextBufferPtr;
}