#include "RandomIdentity.h"
#include "emptyVec.h"

Identity::RandomIdentity::RandomIdentity()
{	
	std::vector<std::string>FirstName = { "Gang","Kim","Lee","Park","Choi","Yang","Young","Xin","Yu","Yoon","Jang" };
	std::vector<std::string>MiddleName = { "ChulSu","JjangGu","Sangbaeg","Hyehwan","Byungseo","Gibok","Cheongmo","Ilhoon","Cheolhyung","Seohoon","Hyeyeon" };
	std::vector<std::string>CauseOfDead = { "suicide", "murdered","elevator fall","head pierced by gun", "disintegration of limbs","Traffic Accident",
		"Unknown","drowning","electrocution","excessive bleeding","strangulation" };

	std::vector<std::string>Result = RandomDeathList(MiddleName, FirstName, CauseOfDead);

	int Age = RandomAge();

	for (const std::string result : Result)
	{
		std::cout << result << std::endl;

	}
	std::cout << "Age : " << Age;

}

std::vector<std::string> Identity::RandomIdentity::RandomDeathList(std::vector<std::string> MiddleName, std::vector<std::string> FirstName,
	std::vector<std::string>CauseOfDead)
{
	srand(time(NULL));

	std::vector<std::string>RandomIdentity;
	
	int RandomIdx = rand() % 10;
	RandomIdentity.push_back(FirstName[RandomIdx]);
	RandomIdentity.push_back(MiddleName[RandomIdx]);
	RandomIdentity.push_back(CauseOfDead[RandomIdx]);

	if (!RandomIdentity.empty())
	{
		return RandomIdentity;
	}
	else
	{
		return EMPTY_STR_VEC;
	}
	
}

int Identity::RandomIdentity::RandomAge()
{
	srand(time(NULL));
	int RandomAge = rand() % 100;

	return RandomAge;
}



