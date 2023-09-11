#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

//포인터는 변수의 주소를 저장하는 변수입니다. 다시 말해, 포인터는 메모리 상의 특정 위치를 가리키는 역할을 합니다. 
// ++과 같은 프로그래밍 언어에서는 포인터를 사용하여 메모리에 직접 접근하고, 변수나 배열, 함수, 또는 다른 데이터 구조의 주소를 저장하고 참조할 수 있습니다.

/*포인터는 다음과 같은 특징과 용도로 사용됩니다 :

메모리 절약 : 포인터를 통해 큰 데이터 구조를 복사하지 않고도 참조할 수 있습니다.
동적 메모리 할당 : new와 delete 를 사용하여 런타임에 메모리를 동적으로 할당하고 해제할 수 있습니다.
배열과 문자열 처리 : 포인터를 사용하여 배열과 문자열을 효율적으로 처리할 수 있습니다.
함수 인자 : 포인터를 사용하여 함수에 변수를 전달할 때, 해당 변수의 복사본을 만들지 않고 원래 변수를 직접 수정할 수 있습니다.
데이터 구조 : 링크드 리스트, 트리, 그래프 등의 복잡한 데이터 구조를 구현할 때 포인터가 사용됩니다. */

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
	// 정수 변수 
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	int* ptr = &a; // a의 주소값을 가진 포인터 ptr
	int aValue = *ptr + 2; // 포인터 ptr에 2를 더한 값을 역참조한 aValue

	vector<int*> intPtrVector; // 정수 포인터의 백터 
	intPtrVector.push_back(&a);
	intPtrVector.push_back(&b);
	intPtrVector.push_back(&c);
	intPtrVector.push_back(&d);

	vector<int*>* IntPtrVector = &intPtrVector; // 정수 포인터 백터의 포인터 백터
	vector<int> Vector = { 1,2,3,4 }; // 정수 vector
	vector<int>* ptrVector = &Vector; // 정수 vector의 포인터 ptrVector

	vector<string>String = { "a","b","c","d" }; // 문자열 vector String
	vector<string>* ptrString = &String; // 문자열 vector의 포인터 ptrString 

	map<vector<int>*, vector<string>*> ptrMap; //정수형 vector키 문자열 vector값의 포인터 map ptrMap
	ptrMap[&Vector] = &String; // 키 값 매핑

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