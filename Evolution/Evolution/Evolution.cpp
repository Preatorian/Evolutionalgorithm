// Evolution.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "evolve.cpp"


using namespace std;
int main()
{
	int abc,df=1;
	evolve a;
	a.generate(20, -20, 20);
	while (df<100000)
	{
		a.crossing_and_mutation();
		a.change_det();
		a.sortbydet();
		df++;
	}

	a.get();
    return 0;

}

