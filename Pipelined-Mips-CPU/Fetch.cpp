#include "Fetch.h"

Fetch::Fetch(string Name, F_Buffer* x, IF_ID_Buffer* y, ID_EX_Buffer* z, EX_MEM_Buffer* k): Path(Name)
{
	m = x;
	n = y;
	l = z;
	EXMEM_B = k;
	pc = 0;
	IM[0] = 0;
	setIM(Path);
	x->stall = false;
}

void Fetch::setIM(string filename)
{
	IM[0] = 536936498;
	IM[1] = 537002024;
	IM[2] = 537067550;
	IM[3] = 2170918;
	IM[4] = 4204582;
	IM[5] = 4272170;
	IM[6] = 2885877760;
	IM[7] = 4274218;
	IM[8] = 4472874;
	IM[9] = 2349400064;
	IM[10] = 272957440;
}

void Fetch::Run()
{
	m->setJtype(l->getJType());
	m->setBen(EXMEM_B->getBranch_en());
	m->setBimm(l->getB());
	m->setjr(l->getPC());

	if (!m->stall)
	{

		if (m->getJtype() == 0 || m->getJtype() == 5 || (m->getJtype() == 1 && !m->getBen()))
			pc = m->getnpc();
		else if (m->getJtype() == 1)
			pc = m->getBimm();
		else if (m->getJtype() == 2)
		{
			pc = m->getBimm();
			m->stall = true;
		}
		else if (m->getJtype() == 3 || m->getJtype() == 4)
		{
			pc = m->getjr();
			m->stall = true;
		}

		n->setPC(pc);
		n->setInstruction(IM[pc/4]);
		uint32_t temp = IM[pc];
		m->setnpc(pc + 4);
		temp = (temp << 2);
		temp |= (0xf0000000 & pc);
		m->setJimm(temp);

	}
	else
	{
		m->stall = false;
		n->setInstruction(IM[0]);
	}
}