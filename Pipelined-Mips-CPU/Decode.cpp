#include "Decode.h"

Decode::Decode(IF_ID_Buffer* IF_ID, ID_EX_Buffer* ID_EX) : PrevBufferPtr(IF_ID), NextBufferPtr(ID_EX)
{
	RF = new RegisterFile(PrevBufferPtr, NextBufferPtr);
	CU = new ControlUnit(PrevBufferPtr, NextBufferPtr);
}

void Decode::Run()
{
	RunSynchronous();
	RunAsynchronous();
}

void Decode::RunAsynchronous()
{
	RF->read();
	CU->generateSignals();

	uint8_t tempDesSelect = NextBufferPtr->getDesSelect();
	uint8_t tempSource1 = (PrevBufferPtr->getInstruction() & 0x7C00) >> 11;
	uint8_t tempSource2 = (PrevBufferPtr->getInstruction() & 0xF8000) >> 16;
	bool tempSECtrl = NextBufferPtr->getSECtrl();
	bool tempImmEn = NextBufferPtr->getImmEn();
	int32_t extended;
	int16_t Immediate = (PrevBufferPtr->getInstruction() & 0xFFFF);

	if (tempDesSelect == 0)
		NextBufferPtr->setDesAddress(tempSource1);
	else if (tempDesSelect == 1)
		NextBufferPtr->setDesAddress(tempSource2);
	else if (tempDesSelect == 2)
		NextBufferPtr->setDesAddress(31);
	else
		NextBufferPtr->setDesAddress(0);

	if (tempSECtrl == 0)
		extended = Immediate;
	else
		extended = Immediate; //Fix to Sign Extend

	if (tempImmEn == 1)
		NextBufferPtr->setB(extended);
	else
		NextBufferPtr->setB(NextBufferPtr->getS2Data());

}

void Decode::RunSynchronous()
{
	RF->write();

}