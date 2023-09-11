#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

//�����ʹ� ������ �ּҸ� �����ϴ� �����Դϴ�. �ٽ� ����, �����ʹ� �޸� ���� Ư�� ��ġ�� ����Ű�� ������ �մϴ�. 
// ++�� ���� ���α׷��� ������ �����͸� ����Ͽ� �޸𸮿� ���� �����ϰ�, ������ �迭, �Լ�, �Ǵ� �ٸ� ������ ������ �ּҸ� �����ϰ� ������ �� �ֽ��ϴ�.

/*�����ʹ� ������ ���� Ư¡�� �뵵�� ���˴ϴ� :

�޸� ���� : �����͸� ���� ū ������ ������ �������� �ʰ� ������ �� �ֽ��ϴ�.
���� �޸� �Ҵ� : new�� delete �� ����Ͽ� ��Ÿ�ӿ� �޸𸮸� �������� �Ҵ��ϰ� ������ �� �ֽ��ϴ�.
�迭�� ���ڿ� ó�� : �����͸� ����Ͽ� �迭�� ���ڿ��� ȿ�������� ó���� �� �ֽ��ϴ�.
�Լ� ���� : �����͸� ����Ͽ� �Լ��� ������ ������ ��, �ش� ������ ���纻�� ������ �ʰ� ���� ������ ���� ������ �� �ֽ��ϴ�.
������ ���� : ��ũ�� ����Ʈ, Ʈ��, �׷��� ���� ������ ������ ������ ������ �� �����Ͱ� ���˴ϴ�. */

void PrintPtrMapKey(const vector<int>& Key)
{
	for (int key : Key)
	{
		cout << key << " ";
	}
}
void PrintPtrMapVal(const vector<string>& Val)
{
	for (const string& val : Val)
	{
		cout << val << " ";
	}
}

int main()
{
	// ���� ���� 
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	int* ptr = &a; // a�� �ּҰ��� ���� ������ ptr
	int aValue = *ptr + 2; // ������ ptr�� 2�� ���� ���� �������� aValue

	vector<int*> intPtrVector; // ���� �������� ���� 
	intPtrVector.push_back(&a);
	intPtrVector.push_back(&b);
	intPtrVector.push_back(&c);
	intPtrVector.push_back(&d);

	vector<int*>* IntPtrVector = &intPtrVector; // ���� ������ ������ ������ ����
	vector<int> Vector = { 1,2,3,4 }; // ���� vector
	vector<int>* ptrVector = &Vector; // ���� vector�� ������ ptrVector

	vector<string>String = { "a","b","c","d" }; // ���ڿ� vector String
	vector<string>* ptrString = &String; // ���ڿ� vector�� ������ ptrString 

	map<vector<int>*, vector<string>*> ptrMap; //������ vectorŰ ���ڿ� vector���� ������ map ptrMap
	ptrMap[&Vector] = &String; // Ű �� ����

	cout << "a pointer Reference : " << ptr << endl;
	cout << "a value : " << a << endl;
	cout << "a pointer :" << ptr << endl;
	cout << "aValue : " << aValue << endl;

	cout << "int pointer vector : ";
	for (int i = 0; i < intPtrVector.size(); i++)
	{
		cout << *(intPtrVector)[i] << " ";
	}
	cout << endl;

	cout << "int pointer vector Reference : ";
	for (int i = 0; i < intPtrVector.size(); i++)
	{
		cout << intPtrVector[i] << " ";
	}
	cout << endl;

	cout << "int pointer vector Pointer vector : ";
	for (int i = 0; i < IntPtrVector->size(); i++)
	{
		cout << *(*IntPtrVector)[i] << " ";
	}
	cout << endl;

	cout << "vector : ";
	for (int i = 0; i < Vector.size(); i++)
	{
		cout << Vector[i] << " ";
	}
	cout << endl;

	cout << "pointer Vector :";
	for (int i = 0; i < ptrVector->size(); i++)
	{
		cout << (*ptrVector)[i] << " ";
	}
	cout << endl;

	cout << "String : ";
	for (int i = 0; i < String.size(); i++)
	{
		cout << String[i] << " ";

	}
	cout << endl;

	cout << "pointer String : ";
	for (int i = 0; i < ptrString->size(); i++)
	{
		cout << (*ptrString)[i] << " ";
	}
	cout << endl;

	for (const auto& PtrMap : ptrMap)
	{
		cout << "Map pointer Key : ";
		PrintPtrMapKey(*(PtrMap.first));
		cout << endl;
		cout << "Map pointer Val : ";
		PrintPtrMapVal(*(PtrMap.second));
	}

};