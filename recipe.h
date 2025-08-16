#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;


struct dsu{
    //referenced to https://www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
    std::unordered_map<std::string, std::string> parent;
    std::string find(const std::string& x) {
        auto it = parent.find(x);
        if (it == parent.end()) {
            return x;
        }
        if (it->second == x) return x;
        it->second = find(it->second);  
        return it->second;
    }
    void unite(const std::string& a, const std::string& b) {
        if (parent.find(a) == parent.end()) parent[a] = a;
        if (parent.find(b) == parent.end()) parent[b] = b;
        std::string arep = find(parent[a]);
        std::string brep = find(parent[b]);
        parent[arep] = brep;
    }

    //i came up with a unite all function when there are more than 2 to unite
    void unite_all(std::vector<std::string>& items) {
        if (items.empty()){
         return;
        }
        for (size_t i = 1; i < items.size(); ++i) {
            unite(items[0], items[i]);
    }
}
};


struct recp { //recipe abbreviated as recp
    // each recipe will contain 4 different information: name, ingredients, meal type and instructions.
    std::string name;
    std::unordered_set<std::string> ingredients;
    int meal_type; // 0 = breakfast, 1 = lunch, 2 = dinner
    std::string instructions;
    
};

//return the book of recipes (database), I am starting with 7 recipes to keep things simple
std::vector<recp> recipe_book(); 

//given the input ingredient, return true/false based on "does the recipe have such ingredient?""
bool match(recp* recipe, std::string input);

//given the input pantry (SET of ingredients), check if the we are missing any ingredients to make such meal(recipe).
//Return true or false, based on if we have all ingredients listed or not
bool can_i_make(recp* recipe, std::unordered_set<std::string>& input);

//instead of finding recipes with substitutes as options, I figured we can just make a new set with ingredients + substitute
//options to make my life easier.
std::unordered_set<std::string> get_all_available(std::unordered_set<std::string>& input, dsu& dsu);


//given the input pantry (SET of ingredients), print a list of recipes you can cook, based on if you have
//all the ingredients needed.
void find_me_recipe(std::vector<recp>& book, std::unordered_set<std::string>& input, dsu& dsu);



#endif 