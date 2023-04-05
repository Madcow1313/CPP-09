#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <chrono>	

typedef struct s_pair {
	int bigger;
	int smaller;
} t_pair;

class PmergeMe
{
	private:
		std::vector<t_pair> pairs;
		std::list<t_pair> list_pairs;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe( PmergeMe const &other );
		PmergeMe & operator=( PmergeMe const &other );

		std::vector<int> sortVec();
		std::list<int> sortList();
		void makePairsVec(std::vector<int> &numbers);
		void makePairsList(std::vector<int> &numbers);
		std::vector<int> mergeVec(std::vector<int> firstSubarray, std::vector<int> secondSubarray);
		std::list<int> mergeList(std::list<int> firstSubarray, std::list<int> secondSubarray);
};
