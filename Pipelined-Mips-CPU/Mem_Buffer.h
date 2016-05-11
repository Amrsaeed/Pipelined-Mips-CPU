#include <iostream>
#include "ID_EX_Buffer.h"
#include "RegisterFile.h"
#include "ControlUnit.h"
#include "IF_ID_Buffer.h"
#include <stdint.h>
#include "Buffer.h"


#ifndef Mem_Buffer_h
#define Mem_Buffer_h

class Mem_Buffer : public Buffer
{
public:
    Mem_Buffer();
    
    //Get Methods
    bool getDataEn();
    bool getImmEn();
    bool getSECtrl();
    bool getBranchType();
    bool getMemRW();
    bool getMemSize();
    bool getMultEn();
    bool getZero_flag();
    bool getNeg_flag();
    bool getBranch_en();
    uint8_t getJType();
    uint8_t getDesSelect();
    uint8_t getALUOp();
    uint8_t getDataDesSelect();
    uint8_t getDesAddress();
    int32_t getS1Data();
    int32_t getS2Data();
    uint32_t getALUout();
    uint32_t getPC();
    int64_t getmult_res();
	int32_t getMemOut();
	int32_t getS1Add();
	int32_t getS2Add();
    
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
    void setDesAddress(uint8_t);
    void setS1Data(int32_t);
    void setS2Data(int32_t);
    void setALUout(uint32_t);
    void setPC(uint32_t);
    void setZero_flag( bool);
    void setNeg_flag( bool);
    void setBranch_en( bool);
    void setmult_res (int64_t);
	void setMemOut(int32_t);
	void setS1Add(int32_t);
	void setS2Add(int32_t);
    
private:
    bool DataEn;
    bool ImmEn;
    bool SECtrl;
    bool BranchType;
    bool MemRW;
    bool MemSize;
    bool MultEn;
    bool zero_flag;
    bool neg_flag;
    bool Branch_en;
    uint8_t JType;
    uint8_t DesSelect;
    uint8_t ALUOp;
    uint8_t DataDesSelect;
    uint8_t DesAddress;
    int32_t S1_Data;
    int32_t S2_Data;
    uint32_t ALUout;
    uint32_t PC;
    int64_t mult_res;
	int32_t MemOut;
	int32_t S1Add;
	int32_t S2Add;
    
};

#endif /* Mem_Buffer_h */
