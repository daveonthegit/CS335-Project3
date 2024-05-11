#include "CountingSort.hpp"

void countingSort (const std::string & header, std::vector<int> data)
{
    auto start = std::chrono::high_resolution_clock::now();
    //Sorting code

	int N = data.size();

	// Finding the maximum element of array inputArray[].
	int M = 0;

	for (int i = 0; i < N; i++)
		M = std::max(M, data[i]);

	// Initializing countArray[] with 0
	std::vector<int> countArray(M + 1, 0);

	// Mapping each element of inputArray[] as an index
	// of countArray[] array

	for (int i = 0; i < N; i++)
		countArray[data[i]]++;

	// Calculating prefix sum at every index
	// of array countArray[]
	for (int i = 1; i <= M; i++)
		countArray[i] += countArray[i - 1];

	// Creating outputArray[] from countArray[] array
	std::vector<int> outputArray(N);

	for (int i = N - 1; i >= 0; i--)

	{
		outputArray[countArray[data[i]] - 1]
			= data[i];

		countArray[data[i]]--;
	}

	data = outputArray;
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the duration in milliseconds
    std::chrono::duration<double> duration = end - start;
    //std::cout << "\nSort Completed in: " << duration.count() * 1000 << " milliseconds\n";

    //Output
    std::cout<<header<<std::endl;
    std::cout<<"Min: "<< data[0] <<std::endl;
    //std::cout<<"test: "<< data[1] <<std::endl;
    std::cout<<"P25: "<< data[data.size()/4-1]<<std::endl;
    std::cout<<"P50: "<< data[data.size()/2]<<std::endl;
    std::cout<<"P75: "<< data[data.size()/4+data.size()/2-1]<<std::endl;
    std::cout<<"Max: "<< data[data.size()-1]<<std::endl;
}
