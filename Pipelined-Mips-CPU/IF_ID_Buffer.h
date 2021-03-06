#include "Buffer.h"
#include <stdint.h>
#ifndef IF_ID_BUFFER_H
#define IF_ID_BUFFER_H

class IF_ID_Buffer : public Buffer
{
public:
	IF_ID_Buffer();

	//Get Methods
	uint32_t getInstruction();
	uint32_t getPC();
	uint32_t getnPC();
	uint8_t getDataAddress();
	uint32_t getDestData();
	bool getDataEn();

	//Set Methods
	void setInstruction(uint32_t);
	void setPC(uint32_t);
	void setnPC(uint32_t);
	void setDataAddress(uint8_t);
	void setDestData(uint32_t);
	void setDataEn(bool);
	void kill();

private:
	uint32_t Instruction;
	uint32_t PC;
	uint32_t nPC;
	uint8_t Data_Address;
	uint32_t DestData;
	bool Data_En;
};

#endif