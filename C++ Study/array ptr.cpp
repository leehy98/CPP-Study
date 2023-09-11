#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 1,2,3,4 }; // 정수 배열
	cout << arr[0] << endl;
	cout << arr[1] << endl;

	int* arrPtr = arr; // 정수 배열의 포인터 
	cout << *arrPtr << endl;
	cout << arrPtr << endl;
	cout << *arrPtr + 1 << endl;
	cout << arrPtr + 1 << endl;

}