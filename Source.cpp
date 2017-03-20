#include <iostream> 
#include "CastException.h" 

using namespace std;

int intFromChar(char data)
{
	if ('0' <= data && data <= '9')
		return data - '0';
	else
		throw Error_1();
}

bool boolFromString(const char * data)
{
	if (strcmp(data, "true") == 0 || strcmp(data, "1") == 0)
		return true;
	if (strcmp(data, "false") == 0 || strcmp(data, "0") == 0)
		return false;
	throw Error_1();
}

int intFromString(const char* data) 
{
	bool minus = false;
	int shift = 0;
	int dlina = 0;

	if (data[0] == '-') 
	{
		minus = true;
		shift = 1;
	}
	while (data[shift + dlina] != '\0')
	{
		if (dlina == 0 && data[shift + dlina] == '0')
		{
			shift++;
		}
		else
		{
			dlina++;
		}
	}

	int result = 0;
	long long result2 = 0;
	for (int i = (shift + dlina) - 1; i >= shift; i--)
	{
		long long plus = intFromChar(data[i]) * pow(10, (shift + dlina) - i - 1);
		if (minus) 
		{
			plus *= -1;
		}
		result += plus;
		result2 += plus;
		if (result != result2)
		{
			throw Error_2();
		}
	}
	return result;
}

float floatFromString(const char * data) 
{
	int dlina1 = 0;
	while (data[dlina1] != '.')
	{
		dlina1++;
	}
	int dlina2 = 0;
	while (data[dlina1 + 1 + dlina2] != '\0')
	{
		dlina2++;
	}
	float result = 0;
	for (int i = dlina1 - 1; i >= 0; i--)
	{
		result += intFromChar(data[i]) * pow(10, dlina1 - i - 1);
	}
	for (int i = dlina1 + 1; i <= dlina1 + dlina2; i++)
	{
		result += intFromChar(data[i]) * pow(10, -1 * (i - dlina1));
	}
	return result;
}

int main() 
{
	try
	{
		bool b;
		b = boolFromString("true");
		cout << b << endl;
		b = boolFromString("tr");
		cout << b << endl;
	}
	catch (Error_1 & e)
	{
		cout << "Error 1!" <<endl;
	}

	try
	{
		int i;
		i = intFromString("2147483647");
		cout << i << endl;
		i = intFromString("-00002147483648");
		cout <<i << endl;
		i = intFromString("57c79");
		cout << i << endl;
	}
	catch (Error_1 & e) 
	{
		cout << "Error 1!" <<endl;
	}

	try
	{
		int i;
		i = intFromString("7777777777");
		cout << i <<endl;
	}
	catch (Error_2 & e) 
	{
		cout << "Error 2!" << endl;
	}

	try
	{
		float fl;
		fl = floatFromString("123.321");
		cout << fl << endl;
		fl = floatFromString("7777777.777.778");
		cout << fl << endl;
	}
	catch (Error_1 & e) 
	{
		cout << "Error 1!" << endl;
	}

	system("pause");
	return 0;
}
