#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _exchangeRates;
        
        bool isValidDate(const std::string& date) const;
        bool isValidValue(double value) const;
        double parseValue(const std::string& valueStr) const;
        std::string trim(const std::string& str) const;
        std::string findClosestDate(const std::string& date) const;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        void loadDatabase(const std::string& filename);
        void processInputFile(const std::string& filename);
        double getExchangeRate(const std::string& date) const;
};

#endif
