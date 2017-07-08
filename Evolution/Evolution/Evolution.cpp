

#include "stdafx.h"
#include "evolve.cpp"

double evolve::determinating_function(double a)
{
	return abs(0.7*pow(a, 5) + pow(a, 4) - pow(a, 3) + 0.3*pow(a, 2) - a - 5);
}

using namespace std;
int main()
{
	int abc,df=1;
	evolve a;
	a.generate(20, -20000, 20000);

	while (df<10000)
	{
		a.crossing_and_mutation();
		a.change_det();
		a.sortbydet();
		df++;

	}

	a.get();
	system("pause");
    return 0;

}

