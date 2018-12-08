#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int sumAll(int *prt, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		std::cout << "address:" << &prt[i] << std::endl;
		sum += prt[i];
	}

	return sum;
}

void switchPrt(int *prt)
{
	*prt = 100;

}

int *newArrary(int *p, int size)
{
	for (int i=0; i < size; i++) {
		std::cout<< "p1=" << p[i]<< std::endl;
		p[i]=i;//rand();
		std::cout<< "p2=" << p[i]<< std::endl;
	}
return p;
}
int main()
{

int arrary[] = {3, 8, 4};
int *pt;
int *prt;

pt = &arrary[0];
for (int i = 0; i < 3; i++) {

std::cout << "arrary = " << arrary[i] << std::endl;
std::cout << "arrary addr= " << pt++ << std::endl;
}

std::cout << "arrary addr="<< (arrary+1) <<  "   a+1 addr" << &arrary+1 << std::endl;
//std::cout << "sum =" << sumAll(arrary, 3) << std::endl;

//switchPrt(pt);
//std::cout << "pt =" << *pt << std::endl;

prt = newArrary(arrary, 3);
for (int j = 0; j < 3; j++)
	std::cout << "prt =" << prt[j]<< std::endl;

/*
ofstream outFile;
char data[10];

outFile.open("test.txt");
std::cout<< "input your name:" << std::endl;
cin.getline(data, 10);
outFile << data << std::endl;*/
return 0;
}

