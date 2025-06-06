#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string &value)
{
	if (value.length() == 3 && value[0] == '\'' && value[2] == '\'')
		return true;
	return value.length() == 1 && std::isprint(value[0]) && !std::isdigit(value[0]);
}

double ScalarConverter::parseInput(const std::string &value)
{
	if (isChar(value))
	{
		if (value.length() == 3 && value[0] == '\'' && value[2] == '\'')
			return static_cast<double>(value[1]);
		return static_cast<double>(value[0]);
	}
	
	if (value == "nan" || value == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (value == "+inf" || value == "+inff")
		return std::numeric_limits<double>::infinity();
	if (value == "-inf" || value == "-inff")
		return -std::numeric_limits<double>::infinity();
	
	bool hasDigit = false;
	bool hasDot = false;
	size_t start = 0;
	
	if (value.empty())
		throw std::invalid_argument("impossible");
		
	if (value[0] == '+' || value[0] == '-')
		start = 1;
		
	for (size_t i = start; i < value.length(); i++)
	{
		if (value[i] == '.' && !hasDot)
			hasDot = true;
		else if (value[i] == 'f' && i == value.length() - 1)
			break;
		else if (std::isdigit(value[i]))
			hasDigit = true;
		else
			throw std::invalid_argument("impossible");
	}
	
	if (!hasDigit)
		throw std::invalid_argument("impossible");
		
	return std::atof(value.c_str());
}

void ScalarConverter::toChar(double val)
{
	std::cout << "char: ";
	if (std::isnan(val) || val < 0 || val > 127 || val != static_cast<int>(val))
		throw std::invalid_argument("impossible");
	else if (!std::isprint(static_cast<int>(val)))
		throw std::invalid_argument("Non displayable");
	else
		std::cout << "'" << static_cast<char>(static_cast<int>(val)) << "'" << std::endl;
}

void ScalarConverter::toInt(double val)
{
	std::cout << "int: ";
	if (std::isnan(val) || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		throw std::invalid_argument("impossible");
	else
		std::cout << static_cast<int>(val) << std::endl;
}

void ScalarConverter::toFloat(double val)
{
	std::cout << "float: ";
	if (std::isnan(val))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(val))
		std::cout << (val > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		float f = static_cast<float>(val);
		std::cout << f;
		if (f == static_cast<int>(f) && f >= -1000000 && f <= 1000000)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
}

void ScalarConverter::toDouble(double val)
{
	std::cout << "double: ";
	if (std::isnan(val))
		std::cout << "nan" << std::endl;
	else if (std::isinf(val))
		std::cout << (val > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << val;
		if (val == static_cast<int>(val) && val >= -1000000 && val <= 1000000)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	double value_double;

	try
	{
		value_double = parseInput(literal);
	}
	catch (const std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	try { toChar(value_double); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	try { toInt(value_double); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	try { toFloat(value_double); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }

	try { toDouble(value_double); }
	catch (const std::exception& e) { std::cout << e.what() << std::endl; }
}
