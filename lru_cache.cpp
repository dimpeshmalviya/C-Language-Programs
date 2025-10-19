class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
            return;
        }
        
        if (cache.size() == capacity) {
            int lru_key = cache.back().first;
            cache.pop_back();
            map.erase(lru_key);
        }
        
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};