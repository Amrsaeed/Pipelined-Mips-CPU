#ifndef WRITEBACK_H
#define WRITEBACK_H
#include "Mem_Buffer.h"
#include "F_Buffer.h"
#include "IF_ID_Buffer.h"

class WriteBack
{
public:
	WriteBack(F_Buffer*, IF_ID_Buffer*, Mem_Buffer*);
	void Run();
private:
	F_Buffer* FB;
	IF_ID_Buffer* IF_ID_B;
	Mem_Buffer* Mem_B;
	uint8_t DesSelect;
};

#endif