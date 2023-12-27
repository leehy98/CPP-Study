#pragma once
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <string>

class MD5H
{
public:
	string MD5Hash(const std::string& data)
	{
		unsigned char digest[MD5_DIGEST_LENGTH];
		MD5(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), digest);

		std::stringstream ss;
		for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
			ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);

		return ss.str();
	}
};
