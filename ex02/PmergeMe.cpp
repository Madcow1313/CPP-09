#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe( PmergeMe const &other )
{
	*this = other;
}
PmergeMe & PmergeMe::operator=( PmergeMe const &other )
{
	this->vec_cont = other.vec_cont;
	this->list_cont = other.list_cont;
	return(*this);
}

void PmergeMe::fillContainers(std::vector<int> &numbers) {
	vec_cont = numbers;
	for (size_t i = 0; i < numbers.size(); i++) {
		list_cont.push_front(numbers[i]);
	}
}

void PmergeMe::makePairs(std::vector<int> &numbers) {
	t_pair p;
	for (size_t i = 0; i < numbers.size(); i += 2) {
		if (i + 1 < numbers.size()) {
			if (numbers[i] < numbers[i+1]){
				p.bigger = numbers[i+1];
				p.smaller = numbers[i];
			} else {
				p.bigger = numbers[i];
				p.smaller = numbers[i+1];
			}
			pairs.push_back(p);
		}
	}
}

std::vector<int> PmergeMe::sortVec() {
	
}