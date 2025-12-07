/*
https://www.onlinegdb.com/fork/A4T1ea_nF
Create an interface named INumberProcessor and a class that implements it.
The interface should declare a single method:

std::vector<int> process(const std::vector<int>& input);


This method receives a vector of integers and should return another vector of integers where:

all odd numbers appear first,

followed by all even numbers,

while preserving the original order within each group.

Example

Input:
{4, 1, 3, 2, 8, 5}

Expected output:
{1, 3, 5, 4, 2, 8}

You can name your implementation class however you like (for example, OddEvenPartitioner).

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include  <cstdlib>
	// <math> //for std

// #define RAND_MAX 30 // attempt limit here , but doesnt work...
	
	
bool test(int start,int end) // unused for now
{
bool evenPrev = false, evenCurr = false;
//if(start  end)
  //  return false; // 


if
(1 == start%2 && 0 == end%2)
//(start < end)
{
 return false;
}

return true;
}

void generateData(int size=20)
{
    for(int i =0; i< size; ++i)
    {
    std::cout<<rand()%30 << ", ";
    }
}

template<typename T>
void generateData(T& container)
{
    for(auto& i : container)
    {
    i = rand()%30;
    // std::cout<<rand()%30 << ", ";
    }
}

template<typename T>
void printData(const T& container)
{
    for(const auto& i : container)
    {
    std::cout<<i << ", ";
    }
}

int main()
{
    std::cout<<"Hello World\n";
    std::srand(std::time({})); // use current time as seed for random generator
    std::array<int,20>  data; // for passing arrays cant see bounds
    generateData(data);
    
    printData(data);

    return 0;
}
*/
namespace {
std::vector<int> INPUT_SHORT{4, 1, 3, 2, 8, 5};
std::vector<int> EXPECTED_SHORT{1, 3, 5, 4, 2, 8};
std::vector<int> INPUT_LONG{13, 16, 27, 25, 23, 25, 16, 12, 9, 1, 2, 7, 20, 19, 23, 16, 0, 6, 22, 16  };
std::vector<int> EXPECTED_LONG{13, 16, 27, 25, 23, 25, 16, 12, 9, 1, 2, 7, 20, 19, 23, 16, 0, 6, 22, 16  };
}
//
#include <iostream>
#include <vector>

struct  INumberProcessor
{
virtual ~INumberProcessor() = default;
virtual std::vector<int> process(const std::vector<int>& input) = 0;
};

struct OddEvenPartitioner: public INumberProcessor
{
virtual ~OddEvenPartitioner() = default;
virtual std::vector<int> process(const std::vector<int>& input) override;
};

std::vector<int> OddEvenPartitioner::process(const std::vector<int>& input)
{
  return {};
}
//

int main()
{
    OddEvenPartitioner p;
    std::vector<int> input{4, 1, 3, 2, 8, 5};
    const auto ret = p.process(input);
    std::cout<<"Hello World\ninput\n";
    for(const int val : input)
        std::cout<<val << ' ';
    std::cout<<"\n output\n";
    for(const int val : ret)
        std::cout<<val << ' ';
    

    return 0;
}

