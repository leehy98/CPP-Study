#include <iostream>
#include "Exclass.h"
using namespace std;

class AnotherClass
{
public:
	void callFunc(ExClass& obj, int (ExClass::* ptrToMemberFunc)(int, int))
	{
		cout << (obj.*ptrToMemberFunc)(3, 4);
	}

};

void function() // 함수 
{
	cout << "function pointer";

}

void MemFuncPtr(ExClass& obj, int (ExClass::* ptrToMemberFunc)(int, int))
{
	cout << (obj.*ptrToMemberFunc)(3, 4);

}

int main()
{
	void(*funcPtr)(); //	 함수 포인터 선언시 매개변수와 반환타입을 명시 해야함 void이니까 빈 괄호
	funcPtr = function; // 함수 주소 할당
	funcPtr(); // 호출
	cout << endl;

	ExClass obj;
	AnotherClass anotherObj;

	int (ExClass:: * ptrToMemberFunc)(int, int) = &ExClass::PtrSumFunc;

	anotherObj.callFunc(obj, ptrToMemberFunc);

	MemFuncPtr(obj, ptrToMemberFunc);
	return 0;
}


