#pragma once
#include <exception>
#include <string>

class Exception: public std::exception
{
private:
	std::string message;
public:
	Exception(const std::string message);
	const std::string getMessage() const
	{
		return this->message;
	}
	~Exception();
};

