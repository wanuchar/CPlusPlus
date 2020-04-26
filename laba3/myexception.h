#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include "exception"
#include <string>

using namespace std;

class MyException: public exception
{
private:
	string m_error;
public:
	MyException(std::string error) : m_error(error)
	{
	}

	const char* what() const noexcept { return m_error.c_str(); }
};

#endif // MYEXCEPTION_H
