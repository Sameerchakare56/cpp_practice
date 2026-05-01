#include <iostream>
#include <vector>
using namespace std;

int maxprofit(vector<int> & prices){
    int maxprofit  = 0 ,bestBuy = prices[0];

    for(int i = 1 ; i< prices.size(); i++){
        if(prices[i] > bestBuy){
            maxprofit = max(maxprofit , prices[i]- bestBuy);

        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxprofit;
}

int main(){
    vector<int>stock = {7,1,5,3,6,4};
    int maxprofitvalue = maxprofit(stock);
    cout << " maximum profit " << maxprofitvalue ;



}