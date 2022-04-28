class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> v;
        int fleets = 1;
        for (int i = 0;i<position.size();i++){
            v.push_back({position[i], (double)(target-position[i])/speed[i]});
        }
        
        //sort according to position
        sort(v.begin(), v.end());
        
//         for (auto c: v){
//             cout<<c.first<<" "<<c.second<<"\n";
//         }
        
        
        //if there is a faster car at a position behind a slower car they will intersect and form a fleet 
        
//         for (auto c : v){
            
            
//         }
        
        double slowest_car = v[v.size()-1].second;
        
        for (int i = v.size()-2;i>=0;i--){
            if (v[i].second > slowest_car){
                fleets++;
                slowest_car = v[i].second;
            }
        }
        
        return fleets;
    }
};
