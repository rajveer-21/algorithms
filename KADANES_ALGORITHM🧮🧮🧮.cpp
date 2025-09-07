#include <vector>
#include <iostream>

void kadanesSum(std::vector<int>& original);
int main()
{
    int n;
    std::cout << "enter the number of terms you want = " << std::endl; std::cin >> n;
    std::vector<int> original(n);
    std::cout << "enter the terms you want to enter in:" << std::endl;
    for(int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        original.push_back(num);
    }
    kadanesSum(original);
    return 0;
}

void kadanesSum(std::vector<int>& original)
{
    int maxSum = original[0];
    int curSum = 0;
    for(int i = 0; i < original.size(); i++)
    {
        curSum = std::max(curSum + original[i], original[i]);
        maxSum = std::max(maxSum, curSum);
    }
    std::cout << "max sum is : " << maxSum << std::endl;
}
