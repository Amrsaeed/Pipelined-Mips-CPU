//
//  Mem_Buffer.c
//  project
//
//  Created by MacBook Pro on 5/9/16.
//  Copyright © 2016 MacBook Pro. All rights reserved.
//

#include "Mem_Buffer.h"

Mem_Buffer::Mem_Buffer(): Buffer()
{
	Stall = false;
	StallCount = false;
}

void Mem_Buffer::operator=(const Mem_Buffer& a)
{
	DataEn = a.DataEn;
	ImmEn = a.ImmEn;
	SECtrl = a.SECtrl;
	BranchType = a.BranchType;
	MemRW = a.MemRW;
	MemSize = a.MemSize;
	MultEn = a.MultEn;
	zero_flag = a.zero_flag;
	neg_flag = a. neg_flag;
	Branch_en = a.Branch_en;
	JType = a.JType;
	DesSelect = a.DesSelect;
	ALUOp = a.ALUOp;
	DataDesSelect = a.DataDesSelect;
	DesAddress = a.DesAddress;
	S1_Data = a.S1_Data;
	S2_Data = a.S2_Data;
	ALUout = a.ALUout;
	PC = a.PC;
	mult_res = a.mult_res;
	MemOut = a.MemOut;
	S1Add = a.S1Add;
	S2Add = a.S2Add;
	OPcode = a.OPcode;
	Stall = a.Stall;
	StallCount = a.StallCount;
}

int32_t Mem_Buffer::getS1Add()
{
	return S1Add;
}

int32_t Mem_Buffer::getS2Add()
{
	return S2Add;
}

void Mem_Buffer::setS1Add(int32_t a)
{
	S1Add = a;
}

void Mem_Buffer::setS2Add(int32_t a)
{
	S2Add = a;
}

void Mem_Buffer::setStall(bool a)
{
	Stall = a;
}

bool Mem_Buffer::getStall()
{
	return Stall;
}

void Mem_Buffer::setStallCount(bool a)
{
	StallCount = a;
}

bool Mem_Buffer::getStallCount()
{
	return StallCount;
}

bool Mem_Buffer::getDataEn()
{
    return DataEn;
}

bool Mem_Buffer::getImmEn()
{
    return ImmEn;
}

bool Mem_Buffer::getSECtrl()
{
    return SECtrl;
}

bool Mem_Buffer::getBranchType()
{
    return BranchType;
}

bool Mem_Buffer::getMemRW()
{
    return MemRW;
}

bool Mem_Buffer::getMemSize()
{
    return MemSize;
}

bool Mem_Buffer::getMultEn()
{
    return MultEn;
}
bool Mem_Buffer::getZero_flag()
{
    return zero_flag;
}
bool Mem_Buffer::getNeg_flag()
{
    return neg_flag;
}
bool Mem_Buffer::getBranch_en()
{
    return Branch_en;
}

uint8_t Mem_Buffer::getJType()
{
    return JType;
}

uint8_t Mem_Buffer::getDesSelect()
{
    return DesSelect;
}

uint8_t Mem_Buffer::getALUOp()
{
    return ALUOp;
}

uint8_t Mem_Buffer::getDataDesSelect()
{
    return DataDesSelect;
}

uint8_t Mem_Buffer::getDesAddress()
{
    return DesAddress;
}

int32_t Mem_Buffer::getS1Data()
{
    return S1_Data;
}

int32_t Mem_Buffer::getS2Data()
{
    return S2_Data;
}

uint32_t Mem_Buffer::getALUout()
{
    return ALUout;
}


uint32_t Mem_Buffer::getPC()
{
    return PC;
}

int64_t Mem_Buffer::getmult_res()
{
    return mult_res;
}

int32_t Mem_Buffer::getMemOut()
{
	return MemOut;
}

uint32_t Mem_Buffer::getOPcode()
{
	return OPcode;
}

void Mem_Buffer::setOPcode(uint32_t opc)
{
	OPcode = opc;
}

void Mem_Buffer::setDataEn(bool a)
{
    DataEn = a;
}

void Mem_Buffer::setImmEn(bool a)
{
    ImmEn = a;
}

void Mem_Buffer::setSECtrl(bool a)
{
    SECtrl = a;
}

void Mem_Buffer::setBranchType(bool a)
{
    BranchType = a;
}

void Mem_Buffer::setMemRW(bool a)
{
    MemRW = a;
}

void Mem_Buffer::setMemSize(bool a)
{
    MemSize = a;
}

void Mem_Buffer::setMultEn(bool a)
{
    MultEn = a;
}
void Mem_Buffer::setZero_flag(bool a)
{
    zero_flag = a;
}
void Mem_Buffer::setNeg_flag(bool a)
{
    neg_flag = a;
}
void Mem_Buffer::setBranch_en(bool a)
{
    Branch_en = a;
}


void Mem_Buffer::setJType(uint8_t a)
{
    JType = a;
}

void Mem_Buffer::setDesSelect(uint8_t a)
{
    DesSelect = a;
}

void Mem_Buffer::setALUOp(uint8_t a)
{
    ALUOp = a;
}

void Mem_Buffer::setDataDesSelect(uint8_t a)
{
    DataDesSelect = a;
}

void Mem_Buffer::setDesAddress(uint8_t a)
{
    DesAddress = a;
}

void Mem_Buffer::setS1Data(int32_t a)
{
    S1_Data = a;
}

void Mem_Buffer::setS2Data(int32_t a)
{
    S2_Data = a;
}

void Mem_Buffer::setALUout(uint32_t a)
{
    ALUout = a;
}


void Mem_Buffer::setPC(uint32_t a)
{
    PC = a;
}

void Mem_Buffer::setmult_res(int64_t a)
{
    mult_res = a;
}

void Mem_Buffer::setMemOut(int32_t a)
{
	MemOut = a;
}