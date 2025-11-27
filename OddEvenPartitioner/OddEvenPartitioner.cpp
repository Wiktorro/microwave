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
*/
namespace {
std::vector<int> INPUT_SHORT{4, 1, 3, 2, 8, 5};
std::vector<int> EXPECTED_SHORT{1, 3, 5, 4, 2, 8};
std::vector<int> INPUT_LONG{13, 16, 27, 25, 23, 25, 16, 12, 9, 1, 2, 7, 20, 19, 23, 16, 0, 6, 22, 16  };
std::vector<int> EXPECTED_LONG{13, 16, 27, 25, 23, 25, 16, 12, 9, 1, 2, 7, 20, 19, 23, 16, 0, 6, 22, 16  };
}
//

//
