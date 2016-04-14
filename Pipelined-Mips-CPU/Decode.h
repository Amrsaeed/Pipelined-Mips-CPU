#include <iostream>
#include "ID_EX_Buffer.h"
#include "RegisterFile.h"
#include "ControlUnit.h"
#include "IF_ID_Buffer.h"
#ifndef DECODE_H
#define DECODE_H

class Decode
{
public:
	Decode(IF_ID_Buffer*, ID_EX_Buffer*);
	void run();
private:
	RegisterFile RF();
	ControlUnit CU();

};

#endif