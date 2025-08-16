1. The project data structure implemented:

The data structure that I implemented is Disjoint Uninon Set. This data structure is used to help me create substitution groups for ingredients.
My project is to make a recipe finder that will allow substitution ingredients. For example, if a recipe calls for ghee, but you don't have ghee,
a normal recipe finder may never return this recipe for you. However, my recipe finder sees that you have butter in your pantry, and since butter
can be substituted for ghee, my recipe finder will return this recipe for you. For this project, disjoint Union is used to help cluster similar
ingredients together (ex:butter, ghee, duck fat) into a group that is interchangable.

*More details of how the whole program works will be demonstrated in the video*




2. A short explanation of the data structure

This data structure -- disjoint set --  stores a collection of non-overlapping sets. In our case, it would be different sets of substituion
groups. For the sake of my project, it supports two operations: Merging two disjoint sets to a single set using Union operation using my
function Union(), and finding representative of a disjoint set using find().

Union() is used when I want to cluster multiple ingredients together to make a substituion set, for example, one of the substitution set 
could be: butter, ghee, duck fat, bacon fat .etc. And when we call find(bacon fat), the function will find the set's representative, which is 
butter. 

By using these operations, I could create a list that contains both the ingredients in my pantry + susbtituions for the ingredients in my pantry.
And using this list, I can fully optimize the recipes I can make based on the ingredients that I have.

3. Video demonstration on how to operate this program:

    https://youtu.be/IQNGpA4StSs

    (As of right now 8/15/25, the video is currently listed as pending. PLEASE let me know if you are having trouble opening it. I will be more 
    than happy to send you a copy of the video through email)



