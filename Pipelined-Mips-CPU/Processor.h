#ifndef PROCESSOR_H
#define PROCESSOR_H

//Stages
#include "Fetch.h"
#include "Decode.h"
#include "Execute.h"
#include "Memory.h"
#include "WriteBack.h"

//Buffers
#include "F_Buffer.h"
#include "IF_ID_Buffer.h"
#include "ID_EX_Buffer.h"
#include "EX_MEM_Buffer.h"
#include "Mem_Buffer.h"
#include "Branch_Predict.h"

class Processor
{
private:
	//Buffers
	F_Buffer F_B;
	IF_ID_Buffer IFID_B;
	ID_EX_Buffer IDEX_B;
	EX_MEM_Buffer EXMEM_B;
	Mem_Buffer MEM_B;

	//Stages
	Fetch* Fetcher;
	Decode* Decoder;
	Execute* Executor;
	Memory* DataMemory;
	WriteBack* WB;

	//Branch Predictor
	Branch_Predict* BTP;

public:
	Processor(vector<string>&);
	void Start();
};

#endif