class RandomizedSet
{
public:
    unordered_map<int, int> set;
    vector<int> arr;
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (set.find(val) == set.end())
        {
            arr.push_back(val);
            set[val] = arr.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (set.find(val) != set.end())
        {
            int idx = set[val];
            swap(arr[idx], arr[arr.size() - 1]);
            arr.pop_back();
            set[arr[idx]] = idx;
            set.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {

        if (arr.size())
        {
            int idx = rand() % arr.size();
            return arr[idx];
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */cd