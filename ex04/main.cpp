#include <iostream>
#include <string>
#include <fstream>

std::string replace(const std::string &line, const std::string &find, const std::string &sub)
{
    if (find.empty() || line.empty())
        return line;

    std::string res;
    size_t startP = 0;
    size_t foundP;

    while ((foundP = line.find(find, startP)) != std::string::npos)
    {
        res.append(line, startP, foundP - startP);
        res.append(sub);
        startP = foundP + find.length();
    }

    res.append(line, startP, line.length() - startP);
    return res;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::fstream file;

    file.open(argv[1], std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open input file '" << argv[1] << "'" << std::endl;
        return (1);
    }

    std::ofstream file_replace;
    std::string replace_file_name;

    replace_file_name = argv[1];
    replace_file_name += ".replace";
    file_replace.open(replace_file_name.c_str()); // .c_str() is safer for some older compilers

    if (!file_replace.is_open())
    {
        std::cerr << "Error: Could not open output file '" << replace_file_name << "'" << std::endl;
        file.close(); // Close the already opened input file
        return (1);
    }
    
    std::string line;
    while (getline(file, line))
    {
        file_replace << replace(line, argv[2], argv[3]);
        if (!file.eof())
            file_replace << std::endl;
    }

    file_replace.close();
    file.close();
        
    return (0);
}