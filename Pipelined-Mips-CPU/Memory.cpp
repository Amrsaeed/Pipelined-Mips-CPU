#include "Memory.h"

Memory:: Memory(EX_MEM_Buffer* EX_MEM, Mem_Buffer* Mem) : PrevBufferPtr(EX_MEM), NextBufferPtr(Mem)
{
    
}


void Memory:: getSignals()
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
	NextBufferPtr->setALUout(PrevBufferPtr->getALUout());
}

void Memory:: setMem_array()
{
    Mem_array[(PrevBufferPtr->getALUout()&4092)>>2] = PrevBufferPtr->getS2Data();
}

uint32_t Memory:: getMem_array()
{
    return Mem_array[(PrevBufferPtr->getALUout()&4092)>>2];
}


void Memory:: MemWrite()
{
    if(PrevBufferPtr->getMemRW())
            setMem_array();
    else
            NextBufferPtr->setMemOut(getMem_array());

}

void Memory:: Run()
{
    getSignals();
    MemWrite();
    
}