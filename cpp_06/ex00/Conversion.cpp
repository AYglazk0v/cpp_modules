#include "Conversion.hpp"

Conversion::Conversion(const std::string& data) : data_(data) {}

Conversion::~Conversion() {}

Conversion::Conversion(const Conversion& rhs) : data_(rhs.data_), letter_(rhs.letter_), int_num_(rhs.int_num_), float_num_(rhs.float_num_), double_num_(rhs.double_num_) {
	*this = rhs;
}

Conversion & Conversion::operator=(const Conversion & rhs) {
	if (this == &rhs) {
		return *this;
	}
	data_ = rhs.data_;
	letter_ = rhs.letter_;
	int_num_ = rhs.int_num_;
	float_num_ = rhs.float_num_;
	double_num_ = rhs.double_num_;
	return *this;
}

void Conversion::FindActualTypeOfData() {
	if (data_.size() == 1 && !isdigit(data_[0])){
		letter_ = static_cast<char>(data_[0]);
		ConvertChar();
	} else if (CheckForSpecial() && CheckForInt() && CheckForFloat() && CheckForDouble()) {
		throw std::invalid_argument("invalid data");
	}
}

int Conversion::CheckForSpecial() {
	if (data_ == "+inf" || data_ == "-inf" || data_ == "nanf" || data_ == "+inff"
		|| data_ == "-inff" || data_ == "nan") {
		ConvertSpecial();
		return 0;
	}
	return 1;
}

void Conversion::ConvertSpecial() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (data_ == "+inff" || data_ == "+inf") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (data_ == "-inff" || data_ == "-inf") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else if (data_ == "nanf" || data_ == "nan") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void Conversion::ConvertChar() {
	if (!isprint(letter_) || letter_ == ' ') {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << letter_ << std::endl;
	}
	std::cout << "int: " << static_cast<int>(letter_) << std::endl;
	std::cout << "float: " << static_cast<float>(letter_) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(letter_) << ".0" << std::endl;
}

int Conversion::CheckForInt() {
	std::stringstream ss(data_);
	int num;
	ss >> num;
	if (ss.fail() && ss.eof()) {
		throw std::invalid_argument("Int: invalid argument!");
	}
	if (!ss.fail() && ss.eof()) {
		int_num_ = num;
		ConvertInt();
		return 0;
	}
	return 1;
}

void Conversion::ConvertInt() {
	std::cout << "char: ";
	if (int_num_ >= 0 && int_num_ < 128) {
		char l = static_cast<char>(int_num_);
		if (!isprint(l) || l == ' ') {
			std::cout << "Non displayable" << std::endl;
		} else {
			std::cout << l << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: " << int_num_ << std::endl;
	std::cout << "float: " << static_cast<float>(int_num_);
	if (int_num_ < 1000000 && int_num_ > -1000000) {
		std::cout << ".0f" << std::endl;
	} else {
		std::cout << 'f' << std::endl;
	}
	std::cout << "double: " << static_cast<double>(int_num_);
	if (int_num_ < 1000000 && int_num_ > -1000000) {
		std::cout << ".0" << std::endl;
	} else {
		std::cout << std::endl;
	}
}

int Conversion::CheckForFloat() {
	if (data_[data_.size() - 1] == 'f') {
		std::string tmp = data_;
		tmp.pop_back();
		std::stringstream ss(tmp);
		float n;
		ss >> n;
		if (!ss.fail() && ss.eof()) {
			double num = atof(data_.c_str());
			if (errno != ERANGE) {
				float_num_ = num;
				ConvertFloat();
				return 0;
			}
		}
	}
	return 1;
}

void Conversion::ConvertFloat() {
	std::cout << "char: ";
	if (float_num_ >= 0 && float_num_ < 128) {
		char l = static_cast<char>(float_num_);
		if (!isprint(l) || l == ' ') {
			std::cout << "Non displayable" << std::endl;
		} else {
			std::cout << l << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	if (float_num_ >= std::numeric_limits<int>::min() &&
		float_num_ <= std::numeric_limits<int>::max()) {
		std::cout << static_cast<int>(float_num_) << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
	if (float_num_ == static_cast<int>(float_num_)
	&& (float_num_ < 1000000 && float_num_ > -1000000))
	{
		std::cout << "float: " << static_cast<float>(float_num_) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(float_num_) << ".0" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(float_num_) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(float_num_) << std::endl;
	}
}

int Conversion::CheckForDouble() {
	std::stringstream ss(data_);
	double n;
	ss >> n;
	if (!ss.fail() && ss.eof()) {
		double_num_ = atof(data_.c_str());
		if (errno != ERANGE) {
			ConvertDouble();
			return 0;
		}
	}
	return 1;
}

void Conversion::ConvertDouble() {
	std::cout << "char: ";
	if (double_num_ >= 0 && double_num_ < 128) {
		char l = static_cast<char>(double_num_);
		if (!isprint(l) || l == ' ') {
			std::cout << "Non displayable" << std::endl;
		} else {
			std::cout << l << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	if (double_num_ >= std::numeric_limits<int>::min() &&
		double_num_ <= std::numeric_limits<int>::max()) {
		std::cout << static_cast<int>(double_num_) << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	if ((double_num_ >= std::numeric_limits<float>::min() &&
		double_num_ <= std::numeric_limits<float>::max()) || double_num_ == 0) {
		std::cout << static_cast<float>(double_num_);
		if (double_num_ == static_cast<int>(double_num_)
			&& (double_num_ < 1000000 && double_num_ > -1000000)) {
			std::cout << ".0f" << std::endl;
		} else {
			std::cout  << "f" << std::endl;
		}
	} else {
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: " << static_cast<double>(double_num_);
	if (double_num_ == static_cast<int>(double_num_)
		&& (double_num_ < 1000000 && double_num_ > -1000000)) {
		std::cout << ".0" << std::endl;
	} else {
		std::cout << std::endl;
	}
}

void Conversion::ConvertData() {
	FindActualTypeOfData();
}

