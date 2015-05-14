#include "stackdbl.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

double calculate(string& expr, bool& success);

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		cerr << "Usage: ./postfix <input filename> <output filename>" << endl;
		return 1;
	}

	ifstream ifile(argv[1]);
	if(ifile.fail())
	{
		cerr << "Unable to open file: " << argv[1] << endl;
		return 1;
	}
	ofstream ofile(argv[2]);
	if(ofile.fail())
	{
		cerr << "Unable to open file: " << argv[2] << endl;
		return 1;
	}

	string expr;
	bool success = false;

	while(getline(ifile, expr))
	{
		double result = calculate(expr, success);
		if(success)
			ofile << result << endl;
		else
			ofile << "invalid" << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}


double calculate(string& expr, bool& success)
{
	StackDbl calcStack;
	istringstream iss(expr);
	string test;

	while(iss >> test)
	{
		if(test.length() == 1)
		{
			//A 1-character input can be an int or operation (assuming proper spacing)
			if(isdigit(test[0]))
				calcStack.push(atof(test.c_str()));

			//If it is an operation
			else
			{
				//Try to get to numbers from the stack, invalid if impossible
				double op1, op2;
				if(!calcStack.empty())
				{
					op2 = calcStack.top();
					calcStack.pop();
				}
				else
				{
					success = false;
					return 0;
				}
				if(!calcStack.empty())
				{
					op1 = calcStack.top();
					calcStack.pop();
				}
				else
				{
					success = false;
					return 0;
				}

				//Peform the operation (no error checking for bad chars)
				if(test[0] == '+')
					calcStack.push(op1+op2);
				else if(test[0] == '-')
					calcStack.push(op1-op2);
				else if(test[0] == '*')
					calcStack.push(op1*op2);
				else
					calcStack.push(op1/op2);
			}
		}
		else
			calcStack.push(atof(test.c_str()));
	}

	double ans = calcStack.top();
	calcStack.pop();
	//If there is more than one item on the stack at the end, the calculation is invalid
	if(!calcStack.empty())
	{
		success = false;
		return 0;
	}
	else
	{
		success = true;
		return ans;
	}
}