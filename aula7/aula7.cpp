#include<iostream>
#include<vector>
#include<algorithm>
#include <random>
using namespace std;

struct item {
    int id;
    int weight; 
    int value;
};

int main(){
    default_random_engine generator(10);
    uniform_real_distribution<double> distribution(0.0,1.0);

    int n = 0;
    int W = 0;
    int best_value = 0;
    int samples = 40000;


    vector<item> items;
    vector<item> best_bag;
    vector<item> bag;
    
    cin >> n >> W;
    items.reserve(n);

    int weight = 0, value = 0;

    for(int i = 0; i < n; i++){
        cin >> weight;
        cin >> value;
        items.push_back({i, weight, value});
    }
    
    random_shuffle(items.begin(), items.end());

    for(int c = 0; c < samples; c++){
        bag.clear();
        vector<item> items2;
        items2.reserve(n);
        weight = 0;
        value = 0;
        for(int i = 0; i < n; i++){
        if(distribution(generator) > 0.5){
         if(items[i].weight + weight <= W){
             bag.push_back(items[i]);
             weight += items[i].weight;
             value += items[i].value;
         }
         else{
            items2.push_back(items[i]);
         }
        }
         else{
            items2.push_back(items[i]);
         }
    }
    
    for (auto& el: items2){
        if(el.weight + weight <= W){
            bag.push_back(el);
            weight += el.weight;
            value += el.value;
        }
    }
    if(value > best_value){
        best_value = value;
        best_bag = bag;
    }
    }
    weight = 0;
    value = 0;
    for (auto& el: best_bag){
        weight += el.weight;
        value += el.value;
    }
    cout << weight << " " << value << " 0" << endl;
    sort(best_bag.begin(), best_bag.end(), [](auto& i, auto& j){return i.id < j.id;});
    for(auto& el: best_bag) {
        cout << el.id << " ";
    }

    return 0;
    }