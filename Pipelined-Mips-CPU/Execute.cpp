#include "Execute.h"

Execute:: Execute(ID_EX_Buffer* ID_EX, EX_MEM_Buffer* EX_MEM, Mem_Buffer* MEMB) : PrevBufferPtr(ID_EX), NextBufferPtr(EX_MEM), MemBuffer(MEMB)
{
    
}

void Execute:: getSignals()
{
    NextBufferPtr->setDesSelect(PrevBufferPtr->getDesSelect());
    NextBufferPtr->setDataEn(PrevBufferPtr->getDataEn());
    NextBufferPtr->setImmEn(PrevBufferPtr->getImmEn());
    NextBufferPtr->setSECtrl(PrevBufferPtr->getSECtrl());
    NextBufferPtr->setBranchType(PrevBufferPtr->getBranchType());
    NextBufferPtr->setMemRW(PrevBufferPtr->getMemRW());
    NextBufferPtr->setMemSize(PrevBufferPtr->getMemSize());
    NextBufferPtr->setMultEn(PrevBufferPtr->getMultEn());
    NextBufferPtr->setJType(PrevBufferPtr->getJType());
    NextBufferPtr->setALUOp(PrevBufferPtr->getALUOp());
    NextBufferPtr->setDataDesSelect(PrevBufferPtr->getDataDesSelect());
    NextBufferPtr->setDesAddress(PrevBufferPtr->getDesAddress());
    NextBufferPtr->setS1Data(PrevBufferPtr->getS1Data());
    NextBufferPtr->setS2Data(PrevBufferPtr->getS2Data());
    NextBufferPtr->setPC(PrevBufferPtr->getPC());
	NextBufferPtr->setNeg_flag(NextBufferPtr->getALUout() < 0 ? 1 : 0);
	NextBufferPtr->setZero_flag(NextBufferPtr->getALUout() == 0 ? 1 : 0);
	//NextBufferPtr->setBranch_en(NextBufferPtr->getZero_flag() ^ NextBufferPtr->getBranchType());
	NextBufferPtr->setOPcode(PrevBufferPtr->getOPcode());
   
}

void Execute::multiply()
{
    NextBufferPtr->setmult_res(PrevBufferPtr->getS1Data() * PrevBufferPtr->getS2Data());
}

void Execute::ALUOperation()
{
    if(PrevBufferPtr->getALUOp() == 6)
        NextBufferPtr->setALUout(Operand1 + Operand2); //add
    
    else if(PrevBufferPtr->getALUOp() == 2)
        NextBufferPtr->setALUout(Operand1 ^ Operand2); //XOR
    
    else if(PrevBufferPtr->getALUOp() == 7)
        NextBufferPtr->setALUout(Operand1 - Operand2);  //SLT
}

void Execute::Forwarding()
{
	int ForwardA = 0;
	int ForwardB = 0;

	if (NextBufferPtr->getDataEn() == 1 && NextBufferPtr->getDesAddress() == PrevBufferPtr->getS1Add() )
		ForwardA = 2;

	if (NextBufferPtr->getDataEn() == 1 && NextBufferPtr->getDesAddress() == PrevBufferPtr->getS2Add() && (NextBufferPtr->getOPcode() == 0 || NextBufferPtr->getOPcode() == 35))
		ForwardB = 2;

	if (OldMemory.getDataEn() == 1 && (OldMemory.getDesAddress() == PrevBufferPtr->getS1Add()) &&
		(NextBufferPtr->getDesAddress() != PrevBufferPtr->getS1Add() || NextBufferPtr->getDataEn() == 0))
		ForwardA = 1;

	if (OldMemory.getDataEn() == 1 &&(OldMemory.getDesAddress() == PrevBufferPtr->getS2Add()) &&
		(NextBufferPtr->getDesAddress() != PrevBufferPtr->getS2Add() || NextBufferPtr->getDataEn() == 0) && PrevBufferPtr->getOPcode() != 43
		&& PrevBufferPtr->getOPcode() != 35)
		ForwardB = 1;

	if (ForwardA == 0)
		Operand1 = PrevBufferPtr->getS1Data();
	else if (ForwardA == 1)
		Operand1 = OldMemory.getALUout();
	else if (ForwardA == 2)
		if (NextBufferPtr->getOPcode() == 35)
			Operand1 = OldMemory.getS2Data();
		else
			Operand1 = NextBufferPtr->getALUout();

	if (ForwardB == 0)
		Operand2 = PrevBufferPtr->getB();
	else if (ForwardB == 1)
		Operand2 = OldMemory.getALUout();
	else if (ForwardB == 2)
		if (NextBufferPtr->getOPcode() == 35)
			Operand2 = OldMemory.getS2Data();
		else
			Operand2 = NextBufferPtr->getALUout();
}

void Execute::Run()
{
	Forwarding();
	multiply();
	ALUOperation();
	getSignals();
	OldMemory = *MemBuffer;
}