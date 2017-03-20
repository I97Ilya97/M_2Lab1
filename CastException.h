#include <exception>

class CastException
	: std::exception
{
	public:
		~CastException() = default;
};

class Error_1 //Char
	: std::exception
{
public:
			~Error_1() = default;
};

class Error_2 //Over
	: std::exception
{
public:
	~Error_2() = default;
};
