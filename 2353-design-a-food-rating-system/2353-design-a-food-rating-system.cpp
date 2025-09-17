class Food {
public:
    int food_rating;
    string food_name;

    Food(int rating, string name) {
        food_rating = rating;
        food_name = name;
    }

    bool operator<(const Food& other)const {
        if (food_rating == other.food_rating) {
            return food_name > other.food_name;
        }

        return food_rating < other.food_rating;
    }
};

class FoodRatings {
public:
    unordered_map<string, int> foodratingmpp;
    unordered_map<string, string> food_cuisinempp;

    unordered_map<string, priority_queue<Food>> cusinefoodmpp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {

        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodratingmpp[foods[i]] = ratings[i];
            food_cuisinempp[foods[i]] = cuisines[i];
            cusinefoodmpp[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) {
        foodratingmpp[food] = newRating;
        string cuisine = food_cuisinempp[food];
        cusinefoodmpp[cuisine].push(Food( newRating,food));
    }

    string highestRated(string cuisine) {
        Food highest = cusinefoodmpp[cuisine].top();
        while (foodratingmpp[highest.food_name] != highest.food_rating) {
            cusinefoodmpp[cuisine].pop();
            highest = cusinefoodmpp[cuisine].top();
        }
        return highest.food_name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */