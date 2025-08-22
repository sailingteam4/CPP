#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open database file.");
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
            
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        
        std::istringstream iss(rateStr);
        double rate;
        if (iss >> rate)
        {
            _exchangeRates[date] = rate;
        }
    }
    
    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 3));
        
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        try
        {
            double value = parseValue(valueStr);
            
            if (!isValidValue(value))
            {
                if (value < 0)
                    std::cerr << "Error: not a positive number." << std::endl;
                else
                    std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            
            double rate = getExchangeRate(date);
            double result = value * rate;
            
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    
    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end())
        return it->second;
    
    std::string closestDate = findClosestDate(date);
    it = _exchangeRates.find(closestDate);
    if (it != _exchangeRates.end())
        return it->second;
        
    		return 0.0;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
        
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    if (year < 1000 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
        
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(double value) const
{
    return value >= 0.0 && value <= 1000.0;
}

double BitcoinExchange::parseValue(const std::string& valueStr) const
{
    std::istringstream iss(valueStr);
    double value;
    
    if (!(iss >> value) || !iss.eof())
        throw std::invalid_argument("Invalid value format");
        
    return value;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
        
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
    std::string closestDate;
    
    for (std::map<std::string, double>::const_iterator it = _exchangeRates.begin();
         it != _exchangeRates.end(); ++it)
    {
        if (it->first <= date)
        {
            if (closestDate.empty() || it->first > closestDate)
                closestDate = it->first;
        }
    }
    
    return closestDate;
}
