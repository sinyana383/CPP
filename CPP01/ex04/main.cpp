#include <iostream>
#include <fstream>
#include <string>

void replaceSubStr(const std::string& s1, const std::string& s2, std::string& line)
{
	size_t pos;

	(void )s2;
	while (( pos = line.find(s1) ) < line.length())
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
	}
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "error: " << "wrong number of arguments" << std::endl;
		return (-1);
	}
	std::ifstream fin;
	std::ofstream fout;

	fin.open(argv[1], std::ios::in);
	if(!fin.is_open())
	{
		std::cout << "error: " << "can't open " << argv[1] << std::endl;
		return (-1);
	}

	std::string rep_file(argv[1]);
	rep_file.append(".replace");
	fout.open(rep_file, std::ios::out | std::ios::trunc);
	if(!fin.is_open())
	{
		std::cout << "error: " << "can't open or create " << rep_file << std::endl;
		return (-1);
	}
	std::string line;
	std::getline(fin, line);
	if (fin.eof())
	{
		std::cout << "error: " << argv[1] << " is empty" << std::endl;
		return (-1);
	}
	do
	{
		replaceSubStr(argv[2], argv[3], line);
		fout << line;
		if (!fin.eof())
			fout << std::endl;
	} while (std::getline(fin, line));
	fout.close();
	fin.close();
}
