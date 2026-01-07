
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
  
    return {};
    
}
//

//

//
