
#include "stdafx.h"
#include <iostream>
#include <cstdlib>

class evolve
{

	double **spiecies;
	int aa, bb,modulo;
public:
	void generate(int a, int b,int mod) 
	{
		
		aa = a;//dlugosc tablicy wskaznikow
		bb = b;//dlugosc tablicy double
		spiecies = new double*[a];
		for (int m = 0; m < a; m++)
		{
			*(spiecies + m) = new double[b];
			for (int i = 0; i < b; i++)
			{
				*(*(spiecies + m) + i) = (double) (rand() % mod);
			}
		}
	}
	void get()
	{
		for (int n = 0; n < aa; n++)
		{
			for (int m = 0; m < bb; m++)
			{
				std::cout << spiecies[n][m] << " ";
			}
			std::cout << std::endl;
		}
	}
	double determinate(double a);



};