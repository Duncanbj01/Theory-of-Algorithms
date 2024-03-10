#include <unordered_map>
#include <string>
using namespace std;

#ifndef HUFFMANDECODER_H_
#define HUFFMANDECODER_H_

class HuffmanDecoder {

public:

	static string decode(string encodedMsg, unordered_map<string, char> encodingToCharMapping) 
    { // complete this method
        string decode; 
        string encode; 
        int n = encodedMsg.length(); 
        
        for (int i = 0; i < n; ++i)
        {
            encode += encodedMsg[i]; 

            if (encodingToCharMapping.find(encode) != encodingToCharMapping.end())
            {
                char c = encodingToCharMapping[encode]; 
                decode += c; 
                encode = ""; 
            }
        }
        return decode; 
    }
};

#endif /* HUFFMANDECODER_H_ */
