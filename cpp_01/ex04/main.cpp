#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

namespace {

	void validationArgs(const std::string& name, const std::string& src, const std::string& repl) {
		if (name.empty() || src.empty() || repl.empty()) {
			std::cerr << "Error: args shouldn't be empty!" << std::endl;
			exit (2);
		}
	}

	void validationInputStream(const std::string& input, std::ifstream& stream) {
		if (!stream) {
			std::cerr << "Error: Couldn't read from file: " << input << std::endl;
			exit(3);
		} else if (stream.peek() == EOF) {
			std::cerr << "Error: File is empty!" << std::endl;
			stream.close();
			exit(4);
		}
	}

	void validationOutputStram(const std::string& output,
								std::ofstream& ostream,
								std::ifstream& istream) {
		if (!ostream) {
			std::cerr << "Error: Couldn't write from file: " << output << std::endl;
			istream.close();
			exit(5);
		}
	}
}

int main(int argc, char **argv){
	if (argc != 4) {
		std::cerr << "Error: Required three arguments:"
					"File name, word to be replaced, "
					"the word to be replaced with" << std::endl;
		exit(1);
	}
	std::string input_name = argv[1];
	std::string output_name = input_name + ".replace";
	std::string source = argv[2];
	std::string replacement = argv[3];
	validationArgs(input_name, source, replacement);

	std::ifstream input(input_name.c_str());
	validationInputStream(input_name, input);

	std::ofstream output(output_name.c_str());
	validationOutputStram(output_name, output, input);

	std::string fileline;
	while (getline(input, fileline)) {
		int i = 0;
		int endline = static_cast<int>(std::string::npos);
		for (i = fileline.find(source, i++); i != endline; i = fileline.find(source, i++)) {
			fileline.erase(i, source.length());
			fileline.insert(i, replacement);
		}
		output << fileline << std::endl;
	}
	input.close();
	output.close();
	return 0;
}