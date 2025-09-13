class Solution {
public:
    string validIPAddress(string queryIP) {
        int dot_count = count(queryIP.begin(), queryIP.end(), '.');
        int colon_count = count(queryIP.begin(), queryIP.end(), ':');
        if (dot_count == 3) {
            if (check_ip4(queryIP)) {
                return "IPv4";
            }
        }
        if (colon_count == 7) {
            if (check_ip6(queryIP)) {
                return "IPv6";
            }
        }
        return "Neither";
    }
    bool check_ip6(string& ip) {
        string temp = "";
        int i = 0;

        while (i < ip.size()) {
            if (isdigit(ip[i]) || (ip[i] >= 'a' && ip[i] <= 'f') ||
                (ip[i] >= 'A' && ip[i] <= 'F')) {
                temp.push_back(ip[i]);
            } else if (ip[i] == ':') {
                if(temp.size()==0){
                    return false;
                }
                if (temp.size() > 4) {
                    return false;
                }
                temp.clear();
            } else {
                return false;
            }
            i++;
        }
        if(temp.size()>4){
            return false;
        }
        if(temp.size()==0){
            return false;
        }
        return true;
    }
    bool check_ip4(string& ip) {
        string temp = "";
        int i = 0;
        int block = 0;
        while (i <= ip.size()) {
            if (i==ip.size() || ip[i] == '.') {
                if(temp.size()==0){
                    return false;
                }
                if(temp.size()>1 && temp[0]=='0'){
                    return false;
                }
                if(temp.size()>3){
                    return false;
                }
                int val=stoi(temp);
                if(val<0 || val>255){
                    return false;
                }
                block++;
                temp.clear();
               

            }

            else if (isdigit(ip[i])) {
                temp.push_back(ip[i]);
            }
            else{
                return false;
            }

          
            i++;
        }
        if (block < 4) {
            return false;
        }
        return true;
    }
};