#include "F_Buffer.h"

F_Buffer::F_Buffer()
{}

void F_Buffer::reset() 
{
	jr = npc = Jtype = Ben = Jimm = Bimm = 0;
}

void F_Buffer::setJtype(int x) 
{
	if (x == 1 || x == 0 || x == 2 || x == 3)
		Jtype = x;
	else
		throw ("Invalid JType. Check Decoder!");
}

void F_Buffer::setJimm(uint32_t x)
{
	Jimm = x;
}
void F_Buffer::setBimm(uint32_t x) 
{
	Bimm = x;
}
void F_Buffer::setBen(uint8_t x) 
{
	Ben = x;
}
void F_Buffer::setjr(uint32_t x) 
{
	jr = x;
}
void F_Buffer::setnpc(uint32_t x) 
{
	npc = x;
}
uint8_t F_Buffer::getJtype() const 
{
	return Jtype;
}
uint32_t F_Buffer::getBimm() const 
{
	return Bimm;
}
uint32_t F_Buffer::getJimm() const 
{
	return Jimm;
}
uint32_t F_Buffer::getjr() const 
{
	return jr;
}
uint32_t F_Buffer::getnpc() const 
{
	return npc;
}
uint8_t F_Buffer::getBen() const 
{
	return Ben;
}