#include <iostream>

using namespace std;


//template : C++의 템플릿은 코드의 일반화를 가능하게 하며, 다양한 데이터 타입에 대해 동작할 수 있는 함수나 클래스를 작성할 수 있도록 합니다.이를 통해 코드 재사용성이 크게 향상됩니다.
//함수 템플릿은 다양한 타입에 대해 동일한 작업을 수행하는 함수를 정의할 수 있습니다.예를 들어, 두 숫자를 비교하여 더 큰 숫자를 반환하는 함수를 작성하려고 할 때, 
//정수, 부동소수점, 또는 다른 숫자 타입에 대해 각각 다른 함수를 작성할 필요 없이 템플릿을 사용하여 일반화된 함수를 작성할 수 있습니다 

//typename: 이 키워드는 템플릿 코드에서 매우 중요한 역할을 합니다.템플릿 코드를 작성할 때 컴파일러는 템플릿 매개변수가 어떤 형식인지 사전에 알 수 없습니다.
//따라서 typename 키워드를 사용하여 특정 이름이 타입을 나타내는 것임을 명시적으로 지정해줍니다.

template <typename T>
T Min(T a, T b)
{
	return (a < b ? a : b)  // 3항 연산자 true a , fasle b 반환
}

template <typename T>
T Max(T a, T b)
{
	return (a > b ? a : b); // 3항 연산자 true a , fasle b 반환
}

void temeplateExample()
{
	cout << "min" << endl;
	cout << Min("127", "128") << endl;
	cout << Min(3, 2) << endl;
	cout << Min(2.0, 2.1) << endl;
	cout << endl;
	cout << "max" << endl;
	cout << Max("127", "128") << endl;
	cout << Max(3, 2) << endl;
	cout << Max(2.0, 2.1) << endl;

}

void main()
{
	temeplateExample();

}
