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
	this->list_pairs = other.list_pairs;
	this->pairs = other.pairs;
	return(*this);
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
			list_pairs.push_back(p);
		} else {
			p.bigger = 0;
			p.smaller = numbers[i];
			pairs.push_back(p);
			list_pairs.push_back(p);
		}
	}
}

std::vector<int> PmergeMe::mergeVec(std::vector<int> firstSubarray, std::vector<int> secondSubarray){
	std::vector<int> result(firstSubarray);
	result.insert(result.end(), secondSubarray.begin(), secondSubarray.end());
	for (size_t i = firstSubarray.size(); i < result.size(); i++) {
		if (result[i] < result[i-1]) {
			for (size_t j = i; j > 0; j--) {
				if (j > 0 && result[j] < result[j-1]) {
					std::swap(result[j], result[j-1]);
				} else {
					break;
				}
			}
		}
	}
	return result;
}

std::vector<int> PmergeMe::sortVec() {
	std::vector<std::vector<int> > sortedSubarrays;
	for (size_t i = 0;  i < pairs.size(); i++) {
		if (pairs[i].bigger != 0) {
			std::vector<int> temp;
			temp.push_back(pairs[i].smaller);
			temp.push_back(pairs[i].bigger);
			sortedSubarrays.push_back(temp);
		} else {
			std::vector<int> temp;
			temp.push_back(pairs[i].smaller);
			sortedSubarrays.push_back(temp);
		}
	}
	while (sortedSubarrays.size() > 1) {
		std::vector<std::vector<int> > sortedSubarraysTemp;
		for (size_t i = 0; i < sortedSubarrays.size(); i += 2) {
			if (i + 1 < sortedSubarrays.size()) {
				std::vector<int> tempVec = mergeVec(sortedSubarrays[i], sortedSubarrays[i+1]);
				sortedSubarraysTemp.push_back(tempVec);
			} else {
				sortedSubarraysTemp.push_back(sortedSubarrays[i]);
			}

		}
		sortedSubarrays = sortedSubarraysTemp;
	}
	return sortedSubarrays[0];
}

std::list<int> PmergeMe::mergeList(std::list<int> firstSubarray, std::list<int> secondSubarray){
	std::list<int> result(firstSubarray);
	result.insert(result.end(), secondSubarray.begin(), secondSubarray.end());
	std::list<int>::iterator it = result.begin();
	while (it != result.end()) {
		it++;
		if (it != result.end()) {
			std::list<int>::iterator current = it;
			it--;
			if (*current < *it) {
				std::list<int>::iterator temp_it = it;
				while (*current < *temp_it && temp_it != result.begin()) {
					temp_it--;
				}
				if (*current > *temp_it) {
					temp_it++;
				}
				result.insert(temp_it, *current);
				result.erase(current);
			} else {
				it++;
			}
		}
	}
	return result;
}

std::list<int> PmergeMe::sortList() {
	std::list<std::list<int> > sortedSubarrays;
	for (size_t i = 0;  i < pairs.size(); i++) {
		if (pairs[i].bigger != 0) {
			std::list<int> temp;
			temp.push_back(pairs[i].smaller);
			temp.push_back(pairs[i].bigger);
			sortedSubarrays.push_back(temp);
		} else {
			std::list<int> temp;
			temp.push_back(pairs[i].smaller);
			sortedSubarrays.push_back(temp);
		}
	}
	while (sortedSubarrays.size() > 1) {
		std::list<std::list<int> > sortedSubarraysTemp;
		std::list<std::list<int> >::iterator it = sortedSubarrays.begin();
		for (;it != sortedSubarrays.end();){
			std::list<int> tempFromIterator = *it;
			it++;
			if (it != sortedSubarrays.end()) {
				std::list<int> tempList = mergeList(tempFromIterator, *it);
				it++;
				sortedSubarraysTemp.push_back(tempList);
			} else {
				sortedSubarraysTemp.push_back(tempFromIterator);
			}

		}
		sortedSubarrays = sortedSubarraysTemp;
	}
	return *sortedSubarrays.begin();
}