#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

int* arg;
int* seg;
int* segMin;
int* segMax;
void build(int node, int l, int r, int arr[]);
void buildMIN(int node, int l, int r, int arr[]);
void buildMAX(int node, int l, int r, int arr[]);
int sumRetrieve(int node, int l, int r, int ql, int qr);
int minRetrieve(int node, int l, int r, int ql, int qr);
int maxRetrieve(int node, int l, int r, int ql, int qr);

int main()
{
    int len;
    std::cout << "enter length of the array : " << std::endl;
    std::cin >> len;
    arg = new int[len]();
    seg = new int[len * 4]();
    segMin = new int[len * 4]();
    segMax = new int[len * 4]();
    std::cout << "enter every array element : " << std::endl;
    for(int i = 0; i < len; i++)
    std::cin >> arg[i];
    build(1, 0, len - 1, arg);
    buildMIN(1, 0, len - 1, arg);
    buildMAX(1, 0, len - 1, arg);
    
    while(true)
    {
        int choice;
        std::cout << "1 = Max over range \n2 = Min over range \n3 = Sum over range \n4 = Exit" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            {
                int ql, qr;
                std::cout << "enter range to search : " << std::endl;
                std::cin >> ql;
                std::cin >> qr;
                if(ql < 0 || qr >= len)
                std::cout << "invalid range" << std::endl;
                else
                std::cout << maxRetrieve(1, 0, len - 1, ql, qr) << std::endl;
                break;
            }
            case 2:
            {
                int ql, qr;
                std::cout << "enter range to search : " << std::endl;
                std::cin >> ql;
                std::cin >> qr;
                if(ql < 0 || qr >= len)
                std::cout << "invalid range" << std::endl;
                else
                std::cout << minRetrieve(1, 0, len - 1, ql, qr) << std::endl;
                break;
            }
            case 3:
            {
                int ql, qr;
                std::cout << "enter range to search : " << std::endl;
                std::cin >> ql;
                std::cin >> qr;
                if(ql < 0 || qr >= len)
                std::cout << "invalid range" << std::endl;
                else
                std :: cout << sumRetrieve(1, 0, len - 1, ql, qr) << std::endl;
                break;
            }
            case 4:
            {
                return 0;
            }
        }
    }
    /*
    direct inputs = 
    std::cout << "sum over range [0, 5] : " << sumRetrieve(1, 0, 5, 0, 5) << std::endl;
    std::cout << "sum over range [2, 4] : " << sumRetrieve(1, 0, 5, 2, 5) << std::endl;
    std::cout << "sum over range [0, 0] : " << sumRetrieve(1, 0, 5, 5, 5) << std::endl;
    std::cout << "min over range [0, 5] : " << minRetrieve(1, 0, 5, 0, 5) << std::endl;
    std::cout << "max over range [2, 4] : " << maxRetrieve(1, 0, 5, 2, 4) << std::endl;
    std::cout << "min over range [0, 0] : " << minRetrieve(1, 0, 5, 0, 0) << std::endl;
    std::cout << "max over range [0, 2] : " << maxRetrieve(1, 0, 5, 0, 2) << std::endl;
    */

}

void build(int node, int l, int r, int arr[])
{
    if(l == r)
    {
        seg[node] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(node * 2, l, m, arr);
    build(node * 2 + 1, m + 1, r, arr);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void buildMIN(int node, int l, int r, int arr[])
{
    if(l == r)
    {
        segMin[node] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    buildMIN(node * 2, l, m, arr);
    buildMIN(node * 2 + 1, m + 1, r, arr);
    segMin[node] = std::min(segMin[node * 2], segMin[node * 2 + 1]);
}

void buildMAX(int node, int l, int r, int arr[])
{
    if(l == r)
    {
        segMax[node] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    buildMAX(node * 2, l, m, arr);
    buildMAX(node * 2 + 1, m + 1, r, arr);
    segMax[node] = std::max(segMax[node * 2], segMax[node * 2 + 1]);
}

int sumRetrieve(int node, int l, int r, int ql, int qr)
{
    if(qr < l || r < ql)
    return 0;
    if(ql <= l && r <= qr)
    return seg[node];
    int m = (l + r) / 2;
    int sumLeft = sumRetrieve(2 * node, l, m, ql, qr);
    int sumRight = sumRetrieve(2 * node + 1, m + 1, r, ql, qr);
    return sumLeft + sumRight;
}

int minRetrieve(int node, int l, int r, int ql, int qr)
{
    if(qr < l || r < ql)
    return INT_MAX;
    if(ql <= l && r <= qr)
    return segMin[node];
    int m = (l + r) / 2;
    int minLeft = minRetrieve(node * 2, l, m, ql, qr);
    int minRight = minRetrieve(node * 2 + 1, m + 1, r, ql, qr);
    return std::min(minLeft, minRight);
}

int maxRetrieve(int node, int l, int r, int ql, int qr)
{
    if(qr < l || r < ql)
    return INT_MIN;
    if(ql <= l && r <= qr)
    return segMax[node];
    int m = (l + r) / 2;
    int maxLeft = maxRetrieve(node * 2, l, m, ql, qr);
    int maxRight = maxRetrieve(node * 2 + 1, m + 1, r, ql, qr);
    return std::max(maxLeft, maxRight);
}
