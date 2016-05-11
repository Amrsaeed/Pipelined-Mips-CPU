#include "Execute.h"

Execute:: Execute(ID_EX_Buffer* ID_EX, EX_MEM_Buffer* EX_MEM) : PrevBufferPtr(ID_EX), NextBufferPtr(EX_MEM)
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
	NextBufferPtr->setBranch_en(NextBufferPtr->getZero_flag() ^ NextBufferPtr->getBranchType());
   
}

void Execute::multiply()
{
    NextBufferPtr->setmult_res(PrevBufferPtr->getS1Data() * PrevBufferPtr->getS2Data());
}

void Execute::ALUOperation()
{
    if(PrevBufferPtr->getALUOp() == 6)
        NextBufferPtr->setALUout(PrevBufferPtr->getS1Data()+PrevBufferPtr->getB()); //add
    
    else if(PrevBufferPtr->getALUOp() == 2)
        NextBufferPtr->setALUout(PrevBufferPtr->getS1Data()^ PrevBufferPtr->getB()); //XOR
    
    else if(PrevBufferPtr->getALUOp() == 7)
        NextBufferPtr->setALUout(PrevBufferPtr->getS1Data()- PrevBufferPtr->getB());  //SLT
}

void Execute::Run()
{
	multiply();
	ALUOperation();
	getSignals();
}