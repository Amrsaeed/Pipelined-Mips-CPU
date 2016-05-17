#ifndef BRANCH_PREDICT_H
#define BRANCH_PREDICT_H

#include <map>
#include "Processor.h"

class Branch_Predict
{
private:
	Processor* a;
	map<int, pair<int, int>> npc;
	int last, cyc, temp;

public:
	void predect()
	{
		if (a->F_B.getJtype() == 1)
		{
			cyc = 0;
			last = (a->Fetcher->getPC());
			temp = a->F_B.getnpc();
			if (npc.find(last) == npc.end())
				npc[a->Fetcher->getPC()] = { a->F_B.getBimm() , 0 };
			else
				a->F_B.setBimm(npc[a->Fetcher->getPC()].first);
		}
		if (cyc == 1)
		{
			if (!a->F_B.getBen())
			{
				npc[last].second++;
				a->IFID_B.kill();
				a->F_B.setall(temp);
			}
			if (npc[last].second == 2)
				npc[last] = { temp,0 };
		}
		cyc++;
	}

};

#endif