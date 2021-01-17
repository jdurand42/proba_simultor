#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

static void man()
{
		std::cout << "How to: ./proba [argument: n chances] [argument: Number of possibilities: 1 < n <= LONG_MAX] [Optional argument: 1 <= n <= LONG_MAX successful draws] [optional argument: allow output: 'on' or 'off'] [optionnal argument: Consecutive mode]" << std::endl;
}

int main(int ac, char **av)
{
	unsigned long successfull_draws = 1;
	bool followed = 0;
	bool output = 0;

	if (ac > 6 || ac < 3 || std::string(av[1]).empty() || !std::isdigit(av[1][0]) || std::stol(std::string(av[1])) <= 0 
	|| std::string(av[2]).empty() || !std::isdigit(av[2][0]) || std::stol(std::string(av[2])) <= 0) 
	{
		man();
		return (0);
	}
	if (ac > 3)
	{
		if (std::string(av[3]).empty() || !std::isdigit(av[3][0]) || std::stol(std::string(av[3])) <= 0)
		{
			man();
			return (0);
		}
		successfull_draws = std::stol(std::string(av[3]));
	}
	if (ac > 4 && std::string(av[4]) == "on")
	{
		std::cout << "lol" << std::endl;
		output = 1;
	}
	if (ac > 5)
		followed = 1;
		 
			

	
	std::srand(std::time(0));
	unsigned long n = std::stol(std::string(av[2]));
	unsigned long i = 1; 
	unsigned long chances = std::stol(std::string(av[1]));
	unsigned long rand = 0;
	unsigned long b = 0;
	unsigned long successfull_b = successfull_draws;

	std::cout << "Simulating " << chances << " on " << n << std::endl;
	
	while (1)
	{
		// Gerer overflow ?
		rand = std::rand() % n + 1;
		//std::cout << "rand: " << rand << std::endl;
		if (rand <= chances)
		{
			successfull_draws--;
			if (!successfull_draws)
			{
				std::cout << "Got a successfull draw on " << i << " tries" << std::endl;
				return (0);
			}
			if (followed && b != i - 1)
				successfull_draws = successfull_b;
			else if (output)
				std::cout << "Got a successfull draw on " << i << " tries " << successfull_draws << " draws remain" << std::endl;
			b = i;
		}
		//else
		//	std::cout << "Missed: " << i << "tries" << std::endl;
		i++;
		if (i == 0)
		{
			// untested, might while(1) indefinitly
			std::cout << "Aborting, number of iterations higher than LONG_MAX" << std::endl;
			return (1);
		}
	}
}

