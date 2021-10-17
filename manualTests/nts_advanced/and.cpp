#include <fstream>
#include <ctime>
#include <array>

int main()
{
    std::array<std::string, 5> in{"in_a=", "in_b=", "in_c=", "in_d=", "in_e="};
    for (std::size_t it = 3; 11 > it; ++it) {
	std::ofstream file{"and" + std::to_string(it) + ".txt"};
	file << "display" << std::endl;
	for (std::size_t y = 0; 5 > y; ++y) {
	    std::size_t rd = rand() % 3;
	    file << in[y];
	    if (2 == rd)
		file << "U" << std::endl;
	    else
		file << std::to_string(rd) << std::endl;
	}
	file << "simulate" << std::endl << "display" << std::endl << "exit" << std::endl;
    }
    return 0;
}
