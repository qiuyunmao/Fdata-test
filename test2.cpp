#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;


void strCpy(char *from, char *to)
{
	for ( ; from != '\0'; from++, to++){
		*to = *from;

		cout << "from addr =" << from << ", from =" << *from << endl;
	}
	 *to = '\0';
}

int main()
{

int buf[2][3]={1, 2,3, 4, 5, 6};
int a = 10;
int (*p)[3]= buf;
//int *p2[6]
//p=&a;
//*p = 20;

char str[] = {'a', 'b', 'c'};//字符数组
char str2[] = "abc";//字符串 以\0结尾
char str3[10];

for(int i =0; i<strlen(str2); i++){
	cout << "from addr" << str+i << endl;
}
strCpy(str2, str3);
for (int i =0; i < 2; i++)
    cout << "p=" << **p++ << endl;

cout << "str sizeof = " << sizeof(str) << "str2 size=" << sizeof(str2) << endl;
cout << "str len=" << strlen(str) << " ,str2 len=" << strlen(str2) << endl;
cout << "&p:" << p << " , p=" << *p << ", a = " << a << endl;//p 是第一行的地址，*p是

p = (int (*)[3])0x7fff15a2dc28;

cout << "p = " << p << endl;
return 0;
}

