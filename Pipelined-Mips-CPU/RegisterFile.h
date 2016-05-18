#include <iostream>
#include <stdint.h>
#include "IF_ID_Buffer.h"
#include "ID_EX_Buffer.h"
#include "F_Buffer.h"


#ifndef REGISTERFILE_H
#define REGISTERFILE_H

class RegisterFile
{
public:
	RegisterFile();
	RegisterFile(IF_ID_Buffer*, ID_EX_Buffer*, F_Buffer*);
	void InsertPrevBuffer(IF_ID_Buffer*);
	void InsertNextBuffer(ID_EX_Buffer*);
	void read();
	void write();
	void clear();
	int32_t Registers[32];
private:
	IF_ID_Buffer* PrevBufferPtr;
	ID_EX_Buffer* NextBufferPtr;
	F_Buffer* FB;
	//bool R_Ens[32];
	uint32_t Instruction;

	//Addresses
	uint8_t S1_Address;
	uint8_t S2_Address;
	uint8_t Data_Address;

	//Data
	uint32_t S1_Data;
	uint32_t S2_Data;
	uint32_t Dest_Data;
	bool Data_En;

	~RegisterFile();

};

#endif