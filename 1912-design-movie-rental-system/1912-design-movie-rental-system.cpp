class MovieRentingSystem {
public:
    unordered_map<int,set<vector<int>>> unrented;
    set<vector<int>> rented;
    unordered_map<int,unordered_map<int,int>> price;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        for(auto it: entries){
            unrented[it[1]].insert({it[2],it[0]});
            price[it[1]][it[0]]=it[2];
        }

        
    }
    
    vector<int> search(int movie) {
        vector<int> ans={};
        for(auto it:unrented[movie]){
            if(ans.size()==5){
                break;
            }
            ans.push_back(it[1]);
        }
        return ans;
        
    }
    
    void rent(int shop, int movie) {
        unrented[movie].erase({price[movie][shop],shop});
        rented.insert({price[movie][shop],shop,movie});


        
    }
    
    void drop(int shop, int movie) {
       
        rented.erase({price[movie][shop],shop,movie});
        unrented[movie].insert({price[movie][shop],shop});
        
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto it: rented){
            if(ans.size()==5){
                break;
            }
            ans.push_back({it[1],it[2]});

        }
        return ans;
        
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */