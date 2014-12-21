#pragma once
#include <chrono>
class SearchAnalyst
{
public:
	SearchAnalyst();
	~SearchAnalyst();

	void setTempComparisons(int keyComparisons);
	void success(int keyComparisons);
	void failure(int keyComparisons);
	void print();
	void reset();
private:
	std::chrono::high_resolution_clock clock;
	std::chrono::high_resolution_clock::time_point analystCreationTime;
	std::chrono::high_resolution_clock::time_point analystPrintTime;
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;

	int successCount;
	double successTime;
	int successComparisons;
	int failedCount;
	double failedTime;
	int failedComparisons;
	int tempComparisons;
};

