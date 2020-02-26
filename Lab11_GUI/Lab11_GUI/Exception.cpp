#include "Exception.h"

Exception::Exception(const std::string message) : message{ message }
{}

Exception::~Exception()
{
}
