#include <iostream>
#include <stdint.h>
#include "Buffer.h"
#ifndef IF_EX_BUFFER_H
#define IF_EX_BUFFER_H

class ID_EX_Buffer : public Buffer
{
public:
	ID_EX_Buffer();

	//Get Methods
	bool getDataEn();
	bool getImmEn();
	bool getSECtrl();
	bool getBranchType();
	bool getMemRW();
	bool getMemSize();
	bool getMultEn();
	uint8_t getJType();
	uint8_t getDesSelect();
	uint8_t getALUOp();
	uint8_t getDataDesSelect();
	uint32_t getS1Data();
	uint32_t getS2Data();
	uint32_t getPC();

	//Set Methods
	void setDataEn(bool);
	void setImmEn(bool);
	void setSECtrl(bool);
	void setBranchType(bool);
	void setMemRW(bool);
	void setMemSize(bool);
	void setMultEn(bool);
	void setJType(uint8_t);
	void setDesSelect(uint8_t);
	void setALUOp(uint8_t);
	void setDataDesSelect(uint8_t);
	void setS1Data(uint32_t);
	void setS2Data(uint32_t);
	void setPC(uint32_t);

private:
	bool DataEn;
	bool ImmEn;
	bool SECtrl;
	bool BranchType;
	bool MemRW;
	bool MemSize;
	bool MultEn;
	uint8_t JType;
	uint8_t DesSelect;
	uint8_t ALUOp;
	uint8_t DataDesSelect;
	uint32_t S1_Data;
	uint32_t S2_Data;
	uint32_t PC;
};

#endif