#ifndef ARRAY_HPP

# include <iostream>
# include <time.h>
# include <cstdlib>

# define ARRAY_HPP

template<typename T>
class Array {
	private:
		T* data_;
		unsigned int lenght_;
		
	public:
		Array() : lenght_(0) {
			data_ = NULL;
		}

		Array(unsigned int n) : lenght_(n) {
			if (n) {
				data_ = new T[n];
			} else {
				data_ = NULL;
			}
		}

		Array(const Array& rhs) {
			lenght_ = rhs.lenght_;
			if (lenght_) {
				data_ = new T[rhs.lenght_];
				for (unsigned int i = 0; i < lenght_; ++i) {
					data_[i] = rhs.data_[i];
				}
			}
		}

		Array& operator=(const Array& rhs) {
			if (this == &rhs){
				return *this;
			}
			delete[] data_;
			if (rhs.lenght_) {
				lenght_ = rhs.lenght_;
				data_ = new T[lenght_];
				for (unsigned int i = 0; i < lenght_; ++i) {
					data_[i] = rhs.data_[i];
				}
			} else {
				data_ = NULL;
				lenght_ = 0;
			}
			return *this;
		}

		T& operator[](unsigned int index) {
			if (index >= lenght_) {
				throw std::range_error("bad index in array!");
			}
			return data_[index];
		}

		unsigned int size() const {
			return lenght_;
		}

		~Array() {
			delete[] data_;
		}
};

#endif
