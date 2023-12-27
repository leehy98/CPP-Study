
#include <string>
#include <iostream>

// exlicit : 클래스의 생성자에서 명시적 형변환이 필요할때 사용되는 키워드. 
// 암시적 형변환으로 의도하지 않은 형변환이 일어나 오류가 발생하는 것을 방지하기 위해 사용한다.

class Implicit
{
public:
	Implicit(int a)
	{
		std::cout << a << std::endl;
	}
	Implicit(const char* a)
	{
		std::cout << a << std::endl;
	}
};

class Exlicit
{
public:
	explicit Exlicit(int a)
	{
		std::cout << a << std::endl;
	}
	explicit Exlicit(std::string a)
	{
		std::cout << a << std::endl;
	}

};
void ImplicitFunc(Implicit a)
{

}

void ExlicitFunc(Exlicit a)
{

}
int main()
{
	// 암시적 형변환
	ImplicitFunc(10); 
	ImplicitFunc("qwerty"); 
	/*
	ExlicitFunc(10);
	ExlicitFunc("qwert");

	 Exlicit 타입을 매개변수로 받는 ExlicitFunc함수는 두 방식으로는 호출 불가. Exlicit 클래스의 생성자는 모두 explicit(명시적) 으로 선언 되어있다.
	*/
	ExlicitFunc(Exlicit(10));
	ExlicitFunc(Exlicit("qwert"));

	return 0;
}