#include "Fetch.h"

Fetch::Fetch(vector<string> Name, F_Buffer* x, IF_ID_Buffer* y, ID_EX_Buffer* z, EX_MEM_Buffer* k): Path(Name)
{
	m = x;
	n = y;
	l = z;
	EXMEM_B = k;
	pc = 0;
	IM[0] = 0;
	x->stall = false;
	setIM();
}

void Fetch::setIM()
{
	/*for (int i = 0; i < Path.size(); i++)
		IM[i] = Path[i];*/

	IM[0] = 536936498;
	IM[1] = 537002014;
	IM[2] = 4266016;
	IM[3] = 537133056;
	IM[4] = 537329738;
	IM[5] = 552009730;
	IM[6] = 2894266368;
	IM[7] = 2357526528;
	IM[8] = 10946602;
	IM[9] = 270598140;
	IM[10] = 10758186;
	IM[11] = 10498086;
	IM[12] = 4026531842;

}

void Fetch::Run()
{
	m->setJtype(l->getJType());
	m->setBen(EXMEM_B->getBranch_en());
	m->setBimm(l->getB() * 4 + pc);
	m->setjr(l->getPC());

	if (!m->stall)
	{

		if (m->getJtype() == 0)
			pc = m->getnpc();
		else if (m->getJtype() == 1)
			pc = m->getBimm();
		else if (m->getJtype() == 2 || m->getJtype() == 5)
		{
			pc = m->getJimm();
			m->stall = true;
		}
		else if (m->getJtype() == 3 || m->getJtype() == 4)
		{
			pc = m->getjr();
			m->stall = true;
		}

		n->setPC(pc);
		n->setInstruction(IM[pc/4]);
		uint32_t temp = IM[pc/4];
		m->setnpc(pc + 4);

		temp = ((0x03ffffff&temp) << 2);
		temp |= (0xf0000000 & pc);
		m->setJimm(temp);

	}
	else
	{
		m->stall = false;
		n->setInstruction(IM[0]);
	}
}

int Fetch::getPC()
{
	return pc;
}