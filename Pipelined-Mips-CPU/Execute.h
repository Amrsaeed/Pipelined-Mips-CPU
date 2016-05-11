#include <iostream>
#include "ID_EX_Buffer.h"
#include "RegisterFile.h"
#include "ControlUnit.h"
#include "EX_MEM_Buffer.h"
#include "Mem_Buffer.h"
#include"Decode.h"
#ifndef Execute_h
#define Execute_h

//#include <stdio.h>
class Execute
{
public:
    Execute(ID_EX_Buffer*, EX_MEM_Buffer*, Mem_Buffer*);
    void Run();
private:
    RegisterFile* RF;
    ControlUnit* CU;
    
    ID_EX_Buffer* PrevBufferPtr;
    EX_MEM_Buffer* NextBufferPtr;
	Mem_Buffer* MemBuffer;

	void multiply();
	void ALUOperation();
	void getSignals();
	void Forwarding();

	int32_t Operand1;
	int32_t Operand2;
    
};

#endif /* Execute_hpp */
