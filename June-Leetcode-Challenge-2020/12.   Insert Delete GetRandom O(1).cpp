#   Insert Delete GetRandom O(1)

/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/

class RandomizedSet {
public:
    
    vector <int> arr; 
    unordered_map <int, int> Map; 

    /** Initialize your data structure here. */
    RandomizedSet() {
        srand (time(NULL)); 
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
         // If element is already present, then return false
        if(Map.find(val) != Map.end()) 
            return false; 
              
        // Else put element at the end of arr[] 
        int index = arr.size(); 
        arr.push_back(val); 
              
        // and hashmap also 
        Map[val] = index;
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        
         // element not found then return false
        if(Map.find(val) == Map.end()) 
            return false; 
              
        int index = Map[val]; 
        int last = arr.size() - 1; 

        // we only need to do so if the element to be removed is not the last element.
        if(arr[last]!=val){
             
            arr[index] = arr[last];
            
            // Update hash table for new index of last element 
            Map[arr[index]] = index;
        }
        
        Map.erase(val);          // remove element from map 
        arr.pop_back();          // then remove element at back 
       
        return true;  
    }
    
    /* Get a random element from the set. */
    int getRandom() {
        // Find a random index from 0 to size - 1 
        int random_index = rand() % arr.size(); 
              
        // Return element at randomly picked index 
        return arr[random_index]; 
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
