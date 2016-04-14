#include <iostream>
#include "ControlUnit.h"

ControlUnit::ControlUnit(IF_ID_Buffer* IF_ID, ID_EX_Buffer* ID_EX) : PrevBufferPtr(IF_ID), NextBufferPtr(ID_EX)
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
	S1_Data = 0;
	S2_Data = 0;
	PC = 0;
}

void ControlUnit::generateSignals()
{
	opCode = (PrevBufferPtr->getInstruction() & 0xFC000000) >> 26;
	Func = (PrevBufferPtr->getInstruction() & 0x3F);

	switch (opCode)
	{
		//Call Instruction Generators.
	}
}