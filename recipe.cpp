#include "recipe.h"

//return the book of recipes (database), I am starting with 7 recipes to keep things simple
std::vector<recp> recipe_book(){
    std::vector<recp>book;

book.push_back(recp{
        "Breakfast Burrito",
        {"tortilla", "egg", "cheese", "potato", "salt", "pepper"},
        0,
        "Scramble eggs. Warm tortilla. Add eggs, cheese, cooked potatoes. Season and roll."
    });

book.push_back(recp{
        "French Toast",
        {"bread", "egg", "milk", "cinnamon", "butter", "maple syrup", "salt"},
        0,
        "Whisk eggs, milk, cinnamon, salt. Dip bread, cook in butter until golden. Serve with syrup."
    });

book.push_back(recp{
        "Boiled Eggs",
        {"egg", "water", "salt"},
        0,
        "Boil water, gently add eggs, cook 7–10 minutes to preference. Cool and peel. Season."
    });

book.push_back(recp{
        "Grilled Cheese",
        {"bread", "cheese", "butter"},
        1,
        "Butter bread, place cheese between slices, grill in pan until bread is golden and cheese melts."
    });

book.push_back(recp{
        "Chicken Stir-Fry",
        {"chicken", "soy sauce", "garlic", "vegetable oil", "carrot"},
        2,
        "Stir-fry chicken in oil, add garlic, veggies, splash soy. "
    });

book.push_back(recp{
        "Pasta Marinara",
        {"pasta", "tomato sauce", "garlic", "olive oil", "salt", "pepper"},
        2,
        "Boil pasta. Warm sauce with garlic in olive oil. Toss together. Season."
    });

book.push_back(recp{
        "Veggie Omelette",
        {"egg", "milk", "cheese", "bell pepper", "onion", "spinach", "salt", "pepper", "butter"},
        0,
        "Beat eggs with milk. Cook veggies in butter, add eggs, sprinkle cheese, fold when set."
    });

    return book;
}


//given the input ingredient, return true/false based on "does the recipe have such ingredient?""
bool match(recp* recipe, std::string input){
    if (!recipe){
        return false;
    } 
    // referenced https://www.geeksforgeeks.org/cpp/unordered_set-find-function-in-c-stl/
    return recipe->ingredients.find(input) != recipe->ingredients.end();
}

//given the input pantry (SET of ingredients), check if the we are missing any ingredients to make such meal(recipe).
//Return true or false, based on if we have all ingredients listed or not
bool can_i_make(recp* recipe, std::unordered_set<std::string>& input) {
    if (!recipe) {
        return false;
    }
    for (auto& ingredient : recipe->ingredients) {
        if (input.find(ingredient) == input.end()) {
            //if ingredients not in pantry, we return false
            return false;
        }
    }

    return true; 
}

std::unordered_set<std::string> get_all_available(std::unordered_set<std::string>& input, dsu& dsu) {
    std::unordered_set<std::string> available;

    for (auto& x : input) {
        available.insert(x);

        // If x participates in any substitution group, add its whole group
        if (dsu.parent.count(x)) {
            std::string root = dsu.find(x);  // find representative of x's group
            for (auto& entry : dsu.parent) {
                const std::string& name = entry.first; //first is the key of the map
                if (dsu.find(name) == root) {
                    available.insert(name);
                }
            }
        }
    }
    return available;
}



//given the input pantry (SET of ingredients), print a list of recipes you can cook, based on if you have
//all the ingredients needed.
void find_me_recipe(std::vector<recp>& book, std::unordered_set<std::string>& input, dsu& dsu) {
    std::vector<recp*> out1;
    out1.reserve(book.size()); //allocate size
    for (auto& recipe : book) {
        if (can_i_make(&recipe, input)) {
            out1.push_back(&recipe); 
        }
    }

    //now we find what recipe we can cook with sub included
    std::unordered_set<std::string> sub = get_all_available(input, dsu);
    std::vector<recp*> out2;
    out2.reserve(book.size()); //allocate size
    for (auto& recipe : book) {
        if (can_i_make(&recipe, sub)) {
            out2.push_back(&recipe); 
        }
    }



    // Print the output
    std::cout << "=== Recipes you can make WITHOUT substitutions ===\n";
    if (out1.empty()) {
        std::cout << "(none)\n";
    } else {
        for (auto* r : out1) std::cout << "- " << r->name << "\n";
    }

    std::cout << "\n=== Recipes you can make IF YOU WANT TO USE SUBSTITUTION ===\n";
    if (out2.empty()) {
        std::cout << "(none)\n";
    } else {
        for (auto* r : out2) std::cout << "- " << r->name << "\n";
    }

}





