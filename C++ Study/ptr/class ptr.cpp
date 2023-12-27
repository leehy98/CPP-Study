#include <iostream>

using namespace std;


class myClass
{
public:
	int a = 10;
	void func()
	{
		cout << a;
		cout << "class pointer";
	}
};

int main()
{
	myClass classObject; // myClass 오브젝트
	myClass* classPtr = &classObject; // 오브젝트의 주소 할당

	// 맴버에 접근
	classPtr->a;
	classPtr->func();

	delete classPtr;

	//동적 할당
	myClass* ClassPtr = new myClass;
	ClassPtr->func();

	delete ClassPtr;
}