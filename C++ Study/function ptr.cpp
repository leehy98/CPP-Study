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

void function() // �Լ� 
{
	cout << "function pointer";

}

void MemFuncPtr(ExClass& obj, int (ExClass::* ptrToMemberFunc)(int, int))
{
	cout << (obj.*ptrToMemberFunc)(3, 4);

}

int main()
{
	void(*funcPtr)(); //	 �Լ� ������ ����� �Ű������� ��ȯŸ���� ��� �ؾ��� void�̴ϱ� �� ��ȣ
	funcPtr = function; // �Լ� �ּ� �Ҵ�
	funcPtr(); // ȣ��
	cout << endl;

	ExClass obj;
	AnotherClass anotherObj;

	int (ExClass:: * ptrToMemberFunc)(int, int) = &ExClass::PtrSumFunc;

	anotherObj.callFunc(obj, ptrToMemberFunc);

	MemFuncPtr(obj, ptrToMemberFunc);
	return 0;
}


