#include "stackdbl.h"
#include <iostream>

using namespace std;

StackDbl::StackDbl()
{
}

StackDbl::~StackDbl()
{
}

bool StackDbl::empty() const
{
	return list_.empty();
}

void StackDbl::push(const double& val)
{
	list_.insert(0,val);
}

double const & StackDbl::top() const
{
	if (!list_.empty())
		return list_.get(0);
	else
	{
		cerr << "Stack is empty, returning 0" << endl;
		double bad = 0;
		return bad;
	}
}

void StackDbl::pop()
{
	list_.remove(0);
}