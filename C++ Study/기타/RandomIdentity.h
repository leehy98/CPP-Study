#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<time.h>

namespace Identity
{
	class RandomIdentity
	{
	public:

	public:
		RandomIdentity();
		int RandomAge();
		std::vector < std::string> RandomDeathList(std::vector<std::string> MiddleName, std::vector<std::string> FirstName,
			std::vector<std::string>CauseOfDead);
		
	};
}
