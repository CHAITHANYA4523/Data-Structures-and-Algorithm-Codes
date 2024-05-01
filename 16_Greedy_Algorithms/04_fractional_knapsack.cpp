struct Item{
    int value;
    int weight;
};

class cmp{
    public:
    bool operator()(pair<double, Item> a, pair<double, Item> b){
        return a.first > b.first;
    }
};

class Solution{
    public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n){
        // Your code here
        vector<pair<double, Item>> v;
        for(int i=0; i<n; i++){
            double perUnitValue = (1.0*arr[i].value)/arr[i].weight;
            pair<double, Item> p = make_pair(perUnitValue, arr[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp());
        double totalValue = 0.0;
        for(int i=0; i<n; i++){
            if(w < v[i].second.weight){
                //take partial portion = remaining weight * perUnitValue 
                totalValue += w*v[i].first;
                w = 0;
                if(w == 0) break;
            }
            //if weight is less the available weight take total portion
            else{
                totalValue += v[i].second.value;
                w = w - v[i].second.weight;
            }
            
        }
        return totalValue;
    }
};