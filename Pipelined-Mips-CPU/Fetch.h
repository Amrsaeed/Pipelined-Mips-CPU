#ifndef FETCH_H
#define FETCH_H
#include <fstream>
#include <string>
#include "IF_ID_Buffer.h"
#include "ID_EX_Buffer.h"
#include "F_Buffer.h"
using namespace std;

class Fetch
{
private:
	int pc;
	int IM[32];
	F_Buffer* m;
	IF_ID_Buffer* n;
	ID_EX_Buffer* l;
	string Path;

	void setIM(std::string filename);
public:
	Fetch(string, F_Buffer* x, IF_ID_Buffer* y, ID_EX_Buffer* z);
	void Run();
};

#endif