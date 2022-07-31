#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>

enum ASCII {
	BINARY = 1,
	HEXADECIMAL
};

void msgInBinary()
{
	std::string str;
	std::fstream file;

	file.open("translation_ASCII_BINARY.txt", std::fstream::in | 
		std::fstream::out | std::fstream::trunc | std::fstream::binary);

	std::cout << "Translate into Binary\n";
	std::cin >> str;
	for (int i = 0; i < str.length(); ++i)
		//file << std::bitset<8>(str[i]);
		std::cout << std::bitset<8>(str[i]);

}

void msgInHex()
{
	std::string str;
	std::fstream file;
	int option{};

	file.open("translation_ASCII_HEX.txt", std::fstream::in 
		| std::fstream::out | std::fstream::trunc | std::fstream::binary);

		std::cout << "Translate into Hexadecimal\n";
		std::cin >> str;
		for (int i = 0; i < str.length(); ++i)
			//file << std::hex << int(str[i]);
			std::cout << std::hex << int(str[i]);
	
}

int  main()
{
	int option{};
	std::cout << "\tTranslate your messages" << std::endl;

	while (true)
	{
		printf("\n");
		std::vector < std::pair<int, std::string>>options{
			{1,  "Binary"},
			{2, "Hexadecimal\n"}
		};

		for (auto it = options.begin(); it != options.end(); ++it) {
			std::cout << it->first << " " << it->second << std::endl;
		}

		std::cin >> option;
		switch (option)
		{
		case ASCII::BINARY:msgInBinary();
				break;
		case ASCII::HEXADECIMAL:msgInHex();
				break;
			default:
				break;
		}
	}
	
	return 0;

}