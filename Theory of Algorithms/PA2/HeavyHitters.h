#include <unordered_map>
#include <map>
#include <vector>
#include <string>
using namespace std;

#ifndef HeavyHitters_h
#define HeavyHitters_h

class HeavyHitters {
    
public:
    
    static vector<char> naive(string &stream, int k) {
        unordered_map<char, int> freqMap;
        for (int i = 0; i < stream.length(); i++) {
            char c = stream.at(i);
            int f = freqMap.find(c) != freqMap.end() ? freqMap[c] : 0;
            freqMap[c] = f + 1;
        }
        return heavyHittersHelper(freqMap, stream.length(), k);
    }
    
private:
    
    static vector<char> heavyHittersHelper(unordered_map<char, int> &freqMap, int n, int k) {
        unordered_map<char, int>::iterator it = freqMap.begin();
        vector<char> heavyHitters;
        while (it != freqMap.end()) {
            char c = it->first;
            int f = freqMap[c];
            if (f > n / k)
                heavyHitters.push_back(c);
            it++;
        }
        return heavyHitters;
    }
    
public:
    
    static vector<char> misraGriesOnePass(string &stream, int k) 
    { // complete this method
        unordered_map<char, int> freqMap; 
        for (char c : stream)
        {
            if (freqMap.find(c) != freqMap.end())
            {
                freqMap[c]++; 
            }
            else if (freqMap.size() < k - 1)
            {
                freqMap[c] = 1; 
            }
            else
            {
                for (auto& pair : freqMap)
                {
                    pair.second--; 
                    if (pair.second == 0)
                    {
                        freqMap.erase(pair.first); 
                    }
                }
            }
        }

        vector<char> result; 
        for (auto& pair : freqMap)
        {
            result.push_back(pair.first); 
        }

        return result; 
    }
    
    static vector<char> misraGriesTwoPass(string &stream, int k) 
    { // complete this method
        vector<char> candidates = misraGriesOnePass(stream, k); 
        unordered_map<char, int> freqMap; 

        for (char c : candidates)
        {
            freqMap[c] = 0; 
        }
        for (char c : stream)
        {
            if (freqMap.find(c) != freqMap.end())
            {
                freqMap[c]++;
            }
        }
        return heavyHittersHelper(freqMap, stream.length(), k); 
    }
};

#endif /* HeavyHitters_h */
