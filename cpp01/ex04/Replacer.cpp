#include "Replacer.hpp"
#include <iostream>
#include <fstream>

Replacer::Replacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

std::string Replacer::processLine(const std::string& line) const {
    std::string result;
    size_t last = 0;
    size_t pos = 0;

    while ((pos = line.find(s1, last)) != std::string::npos) {
        result.append(line, last, pos - last);
        result.append(s2);
        last = pos + s1.length();
    }
    result.append(line, last, line.length() - last);

    return result;
}

bool Replacer::replaceInFile() const {
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return false;
    }

    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return false;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
        inFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << processLine(line);
        if (!inFile.eof()) {
            outFile << '\n';
        }
    }

    inFile.close();
    outFile.close();
    return true;
}
