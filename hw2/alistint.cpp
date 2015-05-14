#include "alistint.h"
#include <iostream>

using namespace std;

AListInt::AListInt()
{
	_head = new int[10];
	_size = 0;
	_max = 10;
}

AListInt::AListInt(int cap)
{
	if (cap > 0)
	{
		_head = new int[cap];
		_size = 0;
		_max = cap;
	}
	else
	{
		cerr << "Invalid array size, defaulting to 10" << endl;

		_head = new int[10];
		_size = 0;
		_max = 10;
	}
}

AListInt::~AListInt()
{
	delete [] _head;
}

int AListInt::size() const
{
	return _size;
}

bool AListInt::empty() const
{
	return _size == 0;
}

void AListInt::insert(int pos, const int& val)
{
	if(pos >= 0 && pos <= _size)
	{
		if(_size == _max)
			resize();

		for (int i = _size; i > pos; i--)
			_head[i] = _head[i-1];

		_head[pos] = val;
		_size++;
	}
}

void AListInt::remove(int pos)
{
	if(pos >= 0 && pos < _size)
	{
		for (int i = pos; i < _size-1; i++)
			_head[pos] = _head[pos+1];

		_size--;
	}
}

void AListInt::set(int pos, const int& val)
{
	if (pos >= 0 && pos < _size)
		_head[pos] = val;
}

int& AListInt::get(int pos)
{
	if (pos >= 0 && pos < _size)
		return _head[pos];
	else
	{
		cerr << "Accessing an invalid index, returning 0" << endl;
		int bad = 0;
		return bad;
	}
}

int const & AListInt::get(int pos) const
{
	if (pos >= 0 && pos < _size)
		return _head[pos];
	else
	{
		cerr << "Accessing an invalid index, returning 0" << endl;
		int bad = 0;
		return bad;
	}
}

void AListInt::resize()
{
	int* oldArray = _head;

	_max = 2*_max;
	_head = new int[_max];
	
	for (int i = 0; i < _size; i++)
		_head[i] = oldArray[i];

	delete [] oldArray;
}