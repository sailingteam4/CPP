#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static double parseInput(const std::string &value);
		static void toChar(double val);
		static void toInt(double val);
		static void toFloat(double val);
		static void toDouble(double val);

	public:
		static void convert(const std::string &literal);
};

#endif
