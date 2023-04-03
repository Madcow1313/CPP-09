#pragma once
#include <iostream>
#include <vector>
#include <list>

typedef struct s_pair {
	int bigger;
	int smaller;
} t_pair;

class PmergeMe
{
	private:
		std::vector<int> vec_cont;
		std::list<int> list_cont;
		std::vector<t_pair> pairs;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe( PmergeMe const &other );
		PmergeMe & operator=( PmergeMe const &other );

		std::vector<int> sortVec();
		std::list<int> sortList();
		void makePairs(std::vector<int> &numbers);
		void fillContainers(std::vector<int> &numbers);
};
