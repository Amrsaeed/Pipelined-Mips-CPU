#include "EX_MEM_Buffer.h"
EX_MEM_Buffer::EX_MEM_Buffer(): Buffer()
{}

bool EX_MEM_Buffer::getDataEn()
{
    return DataEn;
}

bool EX_MEM_Buffer::getImmEn()
{
    return ImmEn;
}

bool EX_MEM_Buffer::getSECtrl()
{
    return SECtrl;
}

bool EX_MEM_Buffer::getBranchType()
{
    return BranchType;
}

bool EX_MEM_Buffer::getMemRW()
{
    return MemRW;
}

bool EX_MEM_Buffer::getMemSize()
{
    return MemSize;
}

bool EX_MEM_Buffer::getMultEn()
{
    return MultEn;
}
bool EX_MEM_Buffer::getZero_flag()
{
    return zero_flag;
}
bool EX_MEM_Buffer::getNeg_flag()
{
    return neg_flag;
}
bool EX_MEM_Buffer::getBranch_en()
{
    return Branch_en;
}

uint8_t EX_MEM_Buffer::getJType()
{
    return JType;
}

uint8_t EX_MEM_Buffer::getDesSelect()
{
    return DesSelect;
}

uint8_t EX_MEM_Buffer::getALUOp()
{
    return ALUOp;
}

uint8_t EX_MEM_Buffer::getDataDesSelect()
{
    return DataDesSelect;
}

uint8_t EX_MEM_Buffer::getDesAddress()
{
    return DesAddress;
}

int32_t EX_MEM_Buffer::getS1Data()
{
    return S1_Data;
}

int32_t EX_MEM_Buffer::getS2Data()
{
    return S2_Data;
}

int32_t EX_MEM_Buffer::getALUout()
{
    return ALUout;
}


uint32_t EX_MEM_Buffer::getPC()
{
    return PC;
}

int64_t EX_MEM_Buffer::getmult_res()
{
    return mult_res;
}

void EX_MEM_Buffer::setDataEn(bool a)
{
    DataEn = a;
}

void EX_MEM_Buffer::setImmEn(bool a)
{
    ImmEn = a;
}

void EX_MEM_Buffer::setSECtrl(bool a)
{
    SECtrl = a;
}

void EX_MEM_Buffer::setBranchType(bool a)
{
    BranchType = a;
}

void EX_MEM_Buffer::setMemRW(bool a)
{
    MemRW = a;
}

void EX_MEM_Buffer::setMemSize(bool a)
{
    MemSize = a;
}

void EX_MEM_Buffer::setMultEn(bool a)
{
    MultEn = a;
}
void EX_MEM_Buffer::setZero_flag(bool a)
{
    zero_flag = a;
}
void EX_MEM_Buffer::setNeg_flag(bool a)
{
    neg_flag = a;
}
void EX_MEM_Buffer::setBranch_en(bool a)
{
    Branch_en = a;
}

void EX_MEM_Buffer::setJType(uint8_t a)
{
    JType = a;
}

void EX_MEM_Buffer::setDesSelect(uint8_t a)
{
    DesSelect = a;
}

void EX_MEM_Buffer::setALUOp(uint8_t a)
{
    ALUOp = a;
}

void EX_MEM_Buffer::setDataDesSelect(uint8_t a)
{
    DataDesSelect = a;
}

void EX_MEM_Buffer::setDesAddress(uint8_t a)
{
    DesAddress = a;
}

void EX_MEM_Buffer::setS1Data(int32_t a)
{
    S1_Data = a;
}

void EX_MEM_Buffer::setS2Data(int32_t a)
{
    S2_Data = a;
}

void EX_MEM_Buffer::setALUout(int32_t a)
{
    ALUout = a;
}


void EX_MEM_Buffer::setPC(uint32_t a)
{
    PC = a;
}

void EX_MEM_Buffer::setmult_res(int64_t a)
{
    mult_res = a;
}