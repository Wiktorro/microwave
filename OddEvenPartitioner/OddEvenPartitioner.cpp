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
//

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

