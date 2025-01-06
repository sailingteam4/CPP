/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontey <nrontey@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:44:26 by nrontey           #+#    #+#             */
/*   Updated: 2025/01/06 13:52:22 by nrontey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string replaceS1S2(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string newLine;
	size_t startPos = 0;
	size_t foundPos = 0;

	while ((foundPos = line.find(s1, startPos)) != std::string::npos) {
		newLine.append(line, startPos, foundPos - startPos);
		newLine.append(s2);
		startPos = foundPos + s1.length();
	}
	newLine.append(line, startPos, std::string::npos);

	return newLine;
}

void execution(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open the file <" << filename << "> !" << std::endl;
		return;
	}

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not open/create the file <" << filename << ".replace> !" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		std::string newLine = replaceS1S2(line, s1, s2);
		outputFile << newLine << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

int main(int ac, char **av)
{

	if (ac != 4) {
		std::cerr << "Error: syntax ./reaplce <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: <s1> cannot be empty!" << std::endl;
		return 1;
	}

	execution(filename, s1, s2);

	return 0;
}