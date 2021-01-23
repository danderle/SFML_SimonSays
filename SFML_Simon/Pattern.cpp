#include "Pattern.h"

Pattern::Pattern()
	:
	rng(rnd())
{
	buttonIndex = std::uniform_int_distribution<int>(0, 3);
}

void Pattern::Add()
{
	//adds a random buttons index to the sequence
	sequence.push_back(buttonIndex(rng));
	
	/*std::stringstream ss;
	ss << "Current pattern: \n";
	for (auto seq : sequence)
	{
		ss << seq << "\n";
	}
	std::cout << ss.str();*/
}

void Pattern::Clear()
{
	sequence.clear();
	currentIndex = 0;
}

const std::vector<unsigned int>& Pattern::Get() const
{
	return sequence;
}

const unsigned int Pattern::GetLength() const
{
	return sequence.size();
}
