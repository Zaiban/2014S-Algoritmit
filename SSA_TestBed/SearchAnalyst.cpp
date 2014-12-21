#include "SearchAnalyst.h"
#include <iostream>
using std::cout; using std::endl;

SearchAnalyst::SearchAnalyst() :
successComparisons(0), successCount(0), successTime(0), failedComparisons(0), failedCount(0), failedTime(0)
{
	analystCreationTime = clock.now();
}
SearchAnalyst::~SearchAnalyst()
{
}
void SearchAnalyst::setTempComparisons(int keyComparisons)
{
	tempComparisons = keyComparisons; 
	t1 = clock.now();
}
void SearchAnalyst::success(int keyComparisons)
{
	t2 = clock.now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

	successTime += time_span.count();
	successComparisons += keyComparisons - tempComparisons;
	successCount++;
}
void SearchAnalyst::failure(int keyComparisons)
{
	t2 = clock.now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

	failedTime += time_span.count();
	failedComparisons += keyComparisons - tempComparisons;
	failedCount++;
}
void SearchAnalyst::print()
{
	cout << "\nStatus: Successful" << endl;
	if (successCount > 0)
	{
		cout << "Elapsed time per search: " << successTime * 1000 / successCount << " milliseconds" << endl;
		cout << "Comparisons per search: " << successComparisons / successCount << endl;
	}
	else
	{
		cout << "Elapsed time per search: 0 seconds" << endl;
		cout << "Comparisons per search: 0" << endl;
	}
	cout << "Searches: " << successCount << endl;

	cout << "\nStatus: Unsuccessful" << endl;
	if (failedCount > 0)
	{
		cout << "Elapsed time per search: " << failedTime * 1000 / failedCount << " milliseconds" << endl;
		cout << "Comparisons per search: " << failedComparisons / failedCount << endl;
	}
	else
	{
		cout << "Elapsed time per search: 0 seconds" << endl;
		cout << "Comparisons per search: 0" << endl;
	}
	cout << "Searches: " << failedCount << endl;

	analystPrintTime = clock.now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(analystPrintTime - analystCreationTime);
	cout << "Total program run time: " << time_span.count() * 1000 << " milliseconds" << endl;
}
void SearchAnalyst::reset()
{
	successComparisons = 0;
	successCount = 0;
	successTime = 0;
	failedComparisons = 0;
	failedCount = 0;
	failedTime = 0;
}