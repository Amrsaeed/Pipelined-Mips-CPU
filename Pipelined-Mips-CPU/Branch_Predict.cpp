#include "Branch_Predict.h"

Branch_Predict::Branch_Predict(Fetch* FetchPtr, F_Buffer* FB, IF_ID_Buffer* IFID): Fetcher(FetchPtr), F_B(FB), IFID_B(IFID)
{

}

void Branch_Predict::predict()
{
	F_B->getBen();
	if (F_B->getJtype() == 1)
	{
		branching = true;
		cyc = 0;
		last = (Fetcher->getPC());		
		if (npc.find(last) == npc.end())
		{
			npc[last] = { F_B->getBimm() , 0 };
			wrong[last] = last + 4;
		}
		else
			F_B->setBimm(npc[Fetcher->getPC()].first);
	}
	if (cyc == 0&&branching)
	{
		cout << ";;;;;;;" << F_B->getBen() << "  ;;;; " << Fetcher->getPC() << endl;
		branching = false;
		if (F_B->getBen()==0)
		{
			npc[last].second++;
			IFID_B->kill();
			F_B->setBimm(wrong[last]);
			F_B->setJtype(1);
		}
		else
			npc[last].second = 0;
		if (npc[last].second == 2)
		{
			int temp = npc[last].second;
			npc[last] = { wrong[last],0 };
			wrong[last] = temp;
		}
	}
	cyc++;
}