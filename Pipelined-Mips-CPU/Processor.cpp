#include "Processor.h"

Processor::Processor(vector<string>& Path)
{
	Fetcher = new Fetch(Path, &F_B, &IFID_B, &IDEX_B, &EXMEM_B);
	Decoder = new Decode(&IFID_B, &IDEX_B, &F_B, &EXMEM_B);
	Executor = new Execute(&IDEX_B, &EXMEM_B, &MEM_B);
	DataMemory = new Memory(&EXMEM_B, &MEM_B, &IDEX_B);
	WB = new WriteBack(&F_B, &IFID_B, &MEM_B);
	BTP = new Branch_Predict(Fetcher, &F_B, &IFID_B);
}

void Processor::Start()
{

	while (1)
	{

		WB->Run();
		DataMemory->Run();

		if (!MEM_B.getStall())
		{
			Executor->Run();
			Decoder->Run();
			BTP->predict();
			Fetcher->Run();
		}

		MEM_B.setStall(false);

		for (int i = 0; i < 32; i++)
			std::cout << Decoder->RF->Registers[i] << " - ";

		std::cout << endl;
	}

}