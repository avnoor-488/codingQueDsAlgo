#include <iostream>
#include <queue>
#include <vector>

// The 'std::' prefix need not be used if we write the below line, but the code will still compile if used
using namespace std;

// By default C++ uses max-heap
void application_of_max_heap() 
{
    // Creation of priority queue named max_pq
    std::priority_queue<int> max_pq;

    // Pushing values into the queue (these values are only for testing)
    int values[10] = {7,2,3,8,4,1,0,9,6,5};
    
    for(int i=0; i<10; i++) {
        max_pq.push(values[i]);
    }

    // Printing out the size of the queue and the queue itself
    std::cout << "The size of the max-heap Priority Queue is: " << max_pq.size() << endl;
    
    std::cout << "Its elements are:" << endl;
    while(!max_pq.empty()) {
        std::cout << max_pq.top() << " ";
        max_pq.pop(); 
    }
    std::cout << endl;   
}

// Using min-heap concept
void application_of_min_heap()
{
    // Syntax of creating min-heap priority queue
    std::priority_queue <int, vector<int>, greater<int>> min_pq; 
    
    // Pushing values into the queue (these values are only for testing)
    int values[10] = {7,2,3,8,4,1,0,9,6,5};
    
    for(int i=0; i<10; i++) {
        min_pq.push(values[i]);
    }
  
    // Printing out the size of the queue and the queue itself
    std::cout << "The size of the min-heap Priority Queue is: " << min_pq.size() << endl;
    
    std::cout << "Its elements are:" << endl;
    while(!min_pq.empty()) {
        std::cout << min_pq.top() << " ";
        min_pq.pop(); 
    } 
}

// Driver function
int main()
{
    // Using max-heap method we can print out the elements in non-increasing order
    application_of_max_heap();

    // Using min-heap method we can print out the elements in increasing order
    application_of_min_heap();

    return 0;
}
