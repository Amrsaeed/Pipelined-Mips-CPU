#include "Processor.h"

Processor::Processor(std::string Path)
{
	Fetcher = new Fetch(Path, &F_B, &IFID_B, &IDEX_B, &EXMEM_B);
	Decoder = new Decode(&IFID_B, &IDEX_B);
	Executor = new Execute(&IDEX_B, &EXMEM_B);
	DataMemory = new Memory(&EXMEM_B, &MEM_B);
	WB = new WriteBack(&F_B, &IFID_B, &MEM_B);
}

void Processor::Start()
{

	while (1)
	{

		WB->Run();
		DataMemory->Run();
		Executor->Run();
		Decoder->Run();
		Fetcher->Run();


		for (int i = 0; i < 32; i++)
			std::cout << Decoder->RF->Registers[i] << " - ";

		std::cout << endl;
	}

}