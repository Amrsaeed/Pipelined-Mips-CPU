#include <iostream>
#include "Decode.h"
#include "ID_EX_Buffer.h"
#include "IF_ID_Buffer.h"

int main()
{
	IF_ID_Buffer test;
	ID_EX_Buffer test2;

	Decode DC(&test, &test2);

	test.setInstruction(536936498);
	test.setDataEn(1);
	test.setDestData(5);
	test.setPC(4);
	test.setDataAddress(1);

	DC.Run();


	return 0;
}