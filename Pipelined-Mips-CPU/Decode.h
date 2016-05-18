#include <iostream>
#include <vector>
#include "ID_EX_Buffer.h"
#include "RegisterFile.h"
#include "ControlUnit.h"
#include "IF_ID_Buffer.h"
#include "F_Buffer.h"
#include "EX_MEM_Buffer.h"
#ifndef DECODE_H
#define DECODE_H

class Decode
{
public:
	Decode(IF_ID_Buffer*, ID_EX_Buffer*, F_Buffer*, EX_MEM_Buffer*);
	void RunAsynchronous();
	void RunSynchronous();
	void Run();
	RegisterFile* RF;
private:
	//RegisterFile* RF;
	ControlUnit* CU;

	F_Buffer* FB;
	IF_ID_Buffer* PrevBufferPtr;
	ID_EX_Buffer* NextBufferPtr;
	EX_MEM_Buffer* EXMEM_B;

	std::vector<int32_t> Stack;

};

#endif