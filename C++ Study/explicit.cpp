
#include <string>
#include <iostream>

// exlicit : Ŭ������ �����ڿ��� ����� ����ȯ�� �ʿ��Ҷ� ���Ǵ� Ű����. 
// �Ͻ��� ����ȯ���� �ǵ����� ���� ����ȯ�� �Ͼ ������ �߻��ϴ� ���� �����ϱ� ���� ����Ѵ�.

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
	// �Ͻ��� ����ȯ
	ImplicitFunc(10); 
	ImplicitFunc("qwerty"); 
	/*
	ExlicitFunc(10);
	ExlicitFunc("qwert");

	 Exlicit Ÿ���� �Ű������� �޴� ExlicitFunc�Լ��� �� ������δ� ȣ�� �Ұ�. Exlicit Ŭ������ �����ڴ� ��� explicit(�����) ���� ���� �Ǿ��ִ�.
	*/
	ExlicitFunc(Exlicit(10));
	ExlicitFunc(Exlicit("qwert"));

	return 0;
}