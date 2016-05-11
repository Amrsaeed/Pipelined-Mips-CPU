#ifndef F_BUFFER_H
#define F_BUFFER_H
#include "Buffer.h"
#include <iostream>
#include <exception>

class F_Buffer : private Buffer
{
private:
	uint8_t Jtype;
	uint8_t Ben;
	uint32_t Jimm;
	uint32_t Bimm;
	uint32_t jr;
	uint32_t npc;
public:
	F_Buffer();
	bool stall;
	void reset();
	void setJtype(int x);
	void setJimm(uint32_t x);
	void setBimm(uint32_t x);
	void setBen(uint8_t x);
	void setjr(uint32_t x);
	void setnpc(uint32_t x);
	uint8_t getJtype() const;
	uint32_t getBimm() const;
	uint32_t getJimm() const;
	uint32_t getjr() const;
	uint32_t getnpc() const;
	uint8_t getBen() const;

};

#endif