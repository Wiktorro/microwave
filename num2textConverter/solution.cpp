
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
// optymalizacja - zacznij iterowac jeszcze od konca, kopiuj parzyste az do do 1 npar
// nastepne przejsce dowkrotne juz tylko od begin do zmniejszonego end

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
//
