class Solution {
public:
    unordered_map<string,string> mpp;
    int counter=1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shorturl="https://tinyurl.com/" + to_string(counter);
        counter++;
        mpp[shorturl]=longUrl;
        return shorturl;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));