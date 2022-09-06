#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name_;
		int id_;

	public:
		Zombie();
		Zombie(const std::string& name);
		~Zombie();

	public:
		void announce() const;
		void setName(const std::string& name, const int id);
		std::string getName(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif