#include <iostream>
#include "ID_EX_Buffer.h"
#include "RegisterFile.h"
#include "ControlUnit.h"
#include "IF_ID_Buffer.h"
#ifndef DECODE_H
#define DECODE_H

class Decode
{
public:
	Decode(IF_ID_Buffer*, ID_EX_Buffer*);
	void RunAsynchronous();
	void RunSynchronous();
	void Run();
private:
	RegisterFile* RF;
	ControlUnit* CU;

	IF_ID_Buffer* PrevBufferPtr;
	ID_EX_Buffer* NextBufferPtr;

};

#endif