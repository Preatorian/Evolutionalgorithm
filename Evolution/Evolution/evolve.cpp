
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class evolve
{

	double **solutions;
	int aa,modulo,begin=0,end=0;
public:
	void sortbydet()//this method sorts all the solutions by the determinant
	{
		int f = 1;
		double container1 = 0, container0 = 0;
		while (f != 0)
		{
			f = 0;
			for (int a = 0; a < aa - 1; a++)
				if (solutions[a + 1][1] < solutions[a][1])
				{
					container1 = solutions[a + 1][1];
					container0 = solutions[a + 1][0];
					solutions[a + 1][1] = solutions[a][1];
					solutions[a + 1][0] = solutions[a][0];
					solutions[a][1] = container1;
					solutions[a][0] = container0;
					f++;
				}
		}
	}




	void change_det()// this method is setting the determinant for all solutions
	{
		for (int a = 0; a < aa; a++)
		{
			solutions[a][1] = determinating_function(solutions[a][0]);
		}
	}



	void generate(int a,int begin,int end)// this method creates (int a) random solutions from range [begin,end] 
	{
		evolve::begin = begin;
		evolve::end = end;
		srand(time(NULL));
		/*
		solution[solution number][0] -> the value of the solution
		solution[solution number][1] -> "envirement fitness" (determinant in here);
		its a value that represends how good this solution is solving our problem.

		*/
		aa = a;//dlugosc tablicy wskaznikow
		solutions = new double*[a];
		for (int m = 0; m < a; m++)
		{
			*(solutions + m) = new double[2];
			for (int i = 0; i < 2; i++)
			{
				*(*(solutions + m) + i) = (double) (begin+(rand() % (end-begin+1)));
			}
		}
	}
	void crossing_and_mutation()
	{
		int mutant,thisone;
		double *childrens = new double[10];
		for (int i = 0; i < 10; i++)
		{
			thisone = rand() % 2;
			//childrens[i] = solutions[i][0]*abs(thisone) + solutions[i + 1][0]*abs(thisone-1) + (rand()%100)*0.01*(solutions[i][0] - solutions[i + 1][0]);
			childrens[i] = (solutions[i][0] - solutions[i + 1][0])/2;
		}
		mutant = rand() % 10;
		childrens[mutant] += childrens[mutant] + (-10+(rand()%20))*pow(10,-(rand()%6));// changes a random value in a random solution

		for (int i = 0; i < 10; i++)
			solutions[i+10][0] = childrens[i];
	}


	void get()// prints out all the solutions with their determinants
	{
		for (int n = 0; n < aa; n++)
		{
			for (int m = 0; m < 2; m++)
			{
				std::cout << solutions[n][m] << " ";
			}
			std::cout << std::endl;
		}
	}
	double determinating_function(double a);//header of the function that sets the determinant
	

	


};
