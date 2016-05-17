#include <iostream>
#include "Mem_Buffer.h"
#include "RegisterFile.h"
#include "ControlUnit.h"
#include "EX_MEM_Buffer.h"
#include"Execute.h"

#ifndef Memory_h
#define Memory_h

#include <stdio.h>

class Memory{
    
public:
    Memory(EX_MEM_Buffer*, Mem_Buffer*);
    void Run();
private:
    EX_MEM_Buffer* PrevBufferPtr;
    Mem_Buffer* NextBufferPtr;
    void MemWrite();
	void Forwarding();
	uint32_t getMem_array();

	int WriteData;

	bool OldDataEn1 = false;
	bool OldDataEn2;

	uint8_t OldDesAddress1 = 0;
	uint8_t OldDesAddress2;

	int32_t OldMemOut1 = 0;
	uint32_t OldALUout1 = 0;
	uint32_t OldOPcode1 = 0;

	int32_t OldMemOut2;
	uint32_t OldALUout2;
	uint32_t OldOPcode2;

	void getSignals();
	void setMem_array();

    
   uint32_t Mem_array[10];
    
};

#endif /* Memory_h */
