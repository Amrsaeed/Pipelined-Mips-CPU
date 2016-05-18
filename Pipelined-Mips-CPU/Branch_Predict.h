#ifndef BRANCH_PREDICT_H
#define BRANCH_PREDICT_H

#include <map>
#include "Fetch.h"
#include "F_Buffer.h"
#include "IF_ID_Buffer.h"

class Branch_Predict
{
private:
	Fetch* Fetcher;
	F_Buffer* F_B;
	IF_ID_Buffer* IFID_B;
	map<int, pair<int, int>> npc;
	map<int, int> wrong;
	int last, cyc;
	bool branching;

public:
	Branch_Predict(Fetch*, F_Buffer*, IF_ID_Buffer*);
	void predict();

};

#endif