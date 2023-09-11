#include <iostream>

using namespace std;


//template : C++�� ���ø��� �ڵ��� �Ϲ�ȭ�� �����ϰ� �ϸ�, �پ��� ������ Ÿ�Կ� ���� ������ �� �ִ� �Լ��� Ŭ������ �ۼ��� �� �ֵ��� �մϴ�.�̸� ���� �ڵ� ���뼺�� ũ�� ���˴ϴ�.
//�Լ� ���ø��� �پ��� Ÿ�Կ� ���� ������ �۾��� �����ϴ� �Լ��� ������ �� �ֽ��ϴ�.���� ���, �� ���ڸ� ���Ͽ� �� ū ���ڸ� ��ȯ�ϴ� �Լ��� �ۼ��Ϸ��� �� ��, 
//����, �ε��Ҽ���, �Ǵ� �ٸ� ���� Ÿ�Կ� ���� ���� �ٸ� �Լ��� �ۼ��� �ʿ� ���� ���ø��� ����Ͽ� �Ϲ�ȭ�� �Լ��� �ۼ��� �� �ֽ��ϴ� 

//typename: �� Ű����� ���ø� �ڵ忡�� �ſ� �߿��� ������ �մϴ�.���ø� �ڵ带 �ۼ��� �� �����Ϸ��� ���ø� �Ű������� � �������� ������ �� �� �����ϴ�.
//���� typename Ű���带 ����Ͽ� Ư�� �̸��� Ÿ���� ��Ÿ���� ������ ��������� �������ݴϴ�.

template <typename T>
T Min(T a, T b)
{
	return (a < b ? a : b)  // 3�� ������ true a , fasle b ��ȯ
}

template <typename T>
T Max(T a, T b)
{
	return (a > b ? a : b); // 3�� ������ true a , fasle b ��ȯ
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
