#ifndef Brain_HPP

# define BRAIN_HPP

# include <iostream>

class Brain {
	private:
		std::string ideas_[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain & rhs);
		Brain& operator=(const Brain& rhs);

	public:
		const std::string GetIdea(const int index) const;
		void SetIdea(std::string& idea, int index);
};
#endif