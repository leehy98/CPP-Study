#include <iostream>

using namespace std;

//inline: 함수의 정의가 여러 번 복사되어 프로그램의 여러 곳에서 사용되어도 안전하다는 것을 컴파일러에 알려주는 역할을 합니다.이는 보통 작은 함수에서 성능 최적화를 위해 사용됩니다. 
//inline 함수가 호출되면, 함수 호출의 오버헤드를 피하기 위해 함수의 본문이 호출 지점에 "인라인"으로 삽입되기 때문입니다.
//하지만, inline 키워드를 지나치게 사용하면 프로그램의 전체적인 크기가 커질 수 있습니다(코드 볼륨이 증가할 수 있음) 또한 모든 컴파일러가 inline 지시에 따라서 반드시 인라인화를 수행하는 것은 아닙니다.이는 최종 결정은 컴파일러가 내린다는 것을 의미합니다.

inline double inlineExample(double a , double b)
{
	return a * b;
}

void main()
{
	double a = inlineExample(3.1, 2.2);
	cout << a;
}