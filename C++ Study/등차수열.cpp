#include <iostream>

// for
int ArithmeticSequence_for(int StartingNum, int LastNum)
{
	int Count = 0;
	int Sum = 0;
	for (int i = StartingNum; i <= LastNum; i++)
	{
		Sum += i;
		Count++;

	}
	return Sum;
}

// while
int ArithmeticSequence_while(int StartingNum, int LastNum)
{
	int Count = 0;
	int Sum = 0;
	int Num = 1;
	while (Count < 100)
	{
		Sum += Num;
		Num++;
		Count++;
	}
	return Sum;
}

// recursion 
int ArithmeticSequence_recursion(int StartingNum , int LastNum)
{
	if (StartingNum > LastNum) // termination condition
		return 0;
	else
		return StartingNum + ArithmeticSequence_recursion(StartingNum + 1, LastNum); // recall

}

int main()
{
	int forSum = ArithmeticSequence_for(1,100);
	int whileSum = ArithmeticSequence_while(1,100);
	int recursionSum = ArithmeticSequence_recursion(1,100);

	std::cout << forSum << std::endl;
	std::cout << whileSum << std::endl;
	std::cout << recursionSum << std::endl;
}