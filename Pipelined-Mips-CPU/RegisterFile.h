#include <iostream>
#include <stdint.h>
#include "IF_ID_Buffer.h"
#include "ID_EX_Buffer.h"


#ifndef REGISTERFILE_H
#define REGISTERFILE_H

class RegisterFile
{
public:
	RegisterFile(IF_ID_Buffer*, ID_EX_Buffer*);
	void read();
	void write();
	void clear();
private:
	IF_ID_Buffer* PrevBufferPtr;
	ID_EX_Buffer* NextBufferPtr;
	uint32_t Registers[32];
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