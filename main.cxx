#include "hexshit.hxx"
#include <fstream>
#include <sstream>
#include <utility>


int main(int ac, char** av) {
	size_t     buffSz = 160;
	DataBuffer code;

	if (ac >= 1) {
		std::string       input = "";

		if (ac == 1) {
            char buffer[buffSz];
			code.data = std::move((void*)buffer);
			code.size = buffSz;
		}
		else if (isdigit(av[1][0])) {
			std::stringstream ss;
			ss << av[1];
			ss >> buffSz;

            char buffer[buffSz];
			
            code.data = std::move((void*)buffer);
			code.size = buffSz;
		}
		else {
			std::fstream in(av[1]);

			if (in.is_open()) {
				while (in.good())
					input += in.get();
				in.close();

				code.data = (void*)input.c_str();
				code.size = input.size();
			} 
		}
	}

	hexshit(code);
	
	return EXIT_SUCCESS;
}