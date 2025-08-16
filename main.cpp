#include "recipe.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    //Load recipes
    vector<recp> book = recipe_book();

    //Build substitution groups
    dsu D;
     
    D.unite("tomato sauce", "marinara");   
    D.unite("vegetable oil", "canola oil");
    D.unite("bell pepper", "capsicum");    

    //testing out unite all function
    std::vector<std::string> cheese = {"cheese", "cheddar", "blue cheese"};
    D.unite_all(cheese);     

    //Build a pantry
    unordered_set<string> pantry = {
        // exact matches for some recipes
        "egg", "water", "salt", "tortilla", "potato",

        // to test grilled cheese with substituion
        "bread", "butter", "blue cheese",

        // to test pasta marinara with substitution 
        "pasta", "marinara", "garlic", "olive oil", "pepper",

        // to show oil substitution option
        "canola oil"
    };


    // Run finder
    find_me_recipe(book, pantry, D);

    return 0;
}