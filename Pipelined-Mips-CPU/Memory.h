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
    void getSignals();
    void MemWrite();
    void setMem_array();
    uint32_t getMem_array ();
    
   uint32_t Mem_array[10];
    
};

#endif /* Memory_h */
