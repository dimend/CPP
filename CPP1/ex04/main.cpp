#include <iostream>
#include <fstream>
#include <filesystem>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        std::cout << "Missing filename and both strings." << std::endl;
        return 1;
    }
    else if(argv[2][0] == '\0' || argv[1][0] == '\0')
    {
        std::cout << "Filename and/or first string missing" << std::endl;
        return 1;
    }

    std::string filename1 = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
    std::ifstream file1(filename1);
    if(!file1.is_open())
	{
		std::cerr << "Error opening the file " << filename1 << std::endl;
		return 1;
	}

    std::filesystem::path path = filename1;
    std::string filename2 = path.stem().string() + ".replace" + path.extension().string();
    std::ofstream file2(filename2);
    if(!file2.is_open())
	{
		std::cerr << "Error creating the file " << filename2 << std::endl;
		return 1;
	}

    std::string line;
	std::getline(file1, line, '\0');
	std::string new_line;
	std::size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		new_line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		line = new_line;
		pos += s2.length();
	}
	file2 << line;

    return 0;
}
