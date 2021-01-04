#pragma once
#include <iostream>
#include <sstream>
#include <random>
#include <vector>
class Pattern
{
public:
	Pattern();
	void AddRandom();
	void Clear();
	const std::vector<unsigned int>& Get() const;

private:
	std::random_device rnd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> buttonIndex;
	std::vector<unsigned int> sequence;

	unsigned int currentIndex = 0;
};

