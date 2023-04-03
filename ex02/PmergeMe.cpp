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

std::vector<t_pair> PmergeMe::getSortedPairs() {
	return sorted_pairs;
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
		} else {
			p.bigger = 0;
			p.smaller = numbers[i];
			pairs.push_back(p);
		}
	}
}

void PmergeMe::sortPairs() {
	sorted_pairs.push_back(pairs[0]);
	for (size_t i = 1; i < pairs.size(); i++) {
		size_t j = 0;
		for (;j < sorted_pairs.size() && pairs[i].bigger > sorted_pairs[j].bigger; j++) {
		}
		if (pairs[i].bigger != 0)
			sorted_pairs.insert(sorted_pairs.begin() + j, pairs[i]);
	}
}

std::vector<int> PmergeMe::sortVec() {
	return vec_cont;
}