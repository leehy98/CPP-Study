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
	myClass classObject; // myClass ������Ʈ
	myClass* classPtr = &classObject; // ������Ʈ�� �ּ� �Ҵ�

	// �ɹ��� ����
	classPtr->a;
	classPtr->func();

	delete classPtr;

	//���� �Ҵ�
	myClass* ClassPtr = new myClass;
	ClassPtr->func();

	delete ClassPtr;
}