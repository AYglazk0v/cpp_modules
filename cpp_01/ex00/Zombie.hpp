#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string name_;
	
	public:
		Zombie(const std::string& name);
		~Zombie();
	
	public:
		void announce(void) const;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif