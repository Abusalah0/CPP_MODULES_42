#include <iostream>
#include <fstream>

int main()
{
    std::string filename, s1, s2, line;

    std::cout << "Enter the file name: ";
    std::cin >> filename;
    std::cout << "Enter the old string: ";
    std::cin >> s1;
    std::cout << "Enter the new string: ";
    std::cin >> s2;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: file not found" << std::endl;
        return 1;
    }

    std::ofstream new_file((filename + ".replace").c_str());
    if (!new_file.is_open())
    {
        std::cerr << "Error: could not create output file" << std::endl;
        return 1;
    }

    while (std::getline(file, line))
    {
        std::string newLine;
        size_t i = 0;

        while (i < line.length())
        {
            if (line.substr(i, s1.length()) == s1)
            {
                newLine += s2;
                i += s1.length();
            }
            else
            {
                newLine += line[i]; 
                i++;
            }
        }
        new_file << newLine << "\n";
    }

    file.close();
    new_file.close();
    return 0;
}
