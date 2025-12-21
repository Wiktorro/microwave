
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
virtual ~OddEvenPartitioner()  =default;
virtual std::vector<int> process(const std::vector<int>& input) override;
};

std::vector<int> OddEvenPartitioner::process(const std::vector<int>& input)
{
    std::vector<int> output (input.size());
    auto iter = output.begin();
    
    for(const int val : input)
        if(1 == val %2)
        {
            *iter = val;
            ++iter;
        }
                
    for(const int val : input)
        if(0 == val %2)
        {
            *iter = val;
            ++iter;
        }
            
    return output;
}
//

//

//
