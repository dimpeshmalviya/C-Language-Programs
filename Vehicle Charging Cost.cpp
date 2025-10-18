#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int hours; double need;
    cout<<"Enter total hours in day: "; cin>>hours;
    cout<<"Enter hours you need to charge: "; cin>>need;
    vector<pair<double,int>> rate(hours);
    for(int i=0;i<hours;i++){
        cout<<"Rate at hour "<<i<<": ";
        cin>>rate[i].first;
        rate[i].second=i;
    }
    sort(rate.begin(),rate.end());
    double cost=0;
    cout<<"\nBest hours to charge:\n";
    for(int i=0;i<need;i++){
        cout<<"Hour "<<rate[i].second<<" @ "<<rate[i].first<<"\n";
        cost+=rate[i].first;
    }
    cout<<"Total minimum cost: "<<cost<<"\n";
}
