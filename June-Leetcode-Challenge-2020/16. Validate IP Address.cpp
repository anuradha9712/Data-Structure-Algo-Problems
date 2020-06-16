# Validate IP Address

/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers,
each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits.
The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one.
Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones,
so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity.
For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".

Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".

Example 3:
Input: "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

/*Approach 1: using REGEX
Time complexity: O(1) because the patterns to match have constant length.
Space complexity: O(1).
*/

class Solution {
public:
    string validIPAddress(string IP) {
        
        regex ipv4("^((25[0-5]|(2[0-4]|1[0-9]|[1-9]|)[0-9])(\.(?!$)|$)){4}$");
        regex ipv6("^[0-9a-fA-F]{1,4}(:[0-9a-fA-F]{1,4}){7}$") ;
        string result = "";
        
        if ( regex_match(IP, ipv4) ) result = "IPv4";
        else if(regex_match(IP,ipv6)) result = "IPv6";
        else result = "Neither";
        
        return result;
        
    }
};

//Approach 2

class Solution {
public:
    string validIPAddress(string IP) {
        int deli;
        deli = IP.find('.');
        if (deli != string::npos) {
            //cout<<"ipv4"<<endl;
            deli = 0;
            for (int i = 0; i < 4; ++i) {
                if (deli >= IP.size()) {
                    //cout<<deli<<endl;
                    return "Neither";
                }
                int j;
                for (j = deli; j < IP.size(); ++j) {
                    if(IP[j] == '.') break;
                    else if(IP[j] < '0' || IP[j] > '9') {
                        //cout<<IP[j]<<endl;
                        return "Neither";
                    }
                }
                if (j - deli <= 0) {
                    //cout<<j<<' '<<deli<<endl;
                    return "Neither";
                }
                string sub = IP.substr(deli, j - deli);
                if(sub[0] == '0' && sub.size() > 1) return "Neither";
                int s = atoi(sub.c_str());
                if (s < 0 || s > 255) {
                    //cout<<s<<endl;
                    return "Neither";
                }
                deli = j + 1;
            }
            if (deli -1 < IP.size()) {
                //cout<<deli<<endl;
                return "Neither";
            }
            else return "IPv4";
        }
        else {
            deli = 0;
            for (int i = 0; i < 8; ++i) {
                if (deli >= IP.size()) return "Neither";
                int j;
                for (j = deli; j < IP.size(); ++j) {
                    if (IP[j] == ':') break;
                    else if(!(IP[j] >='0' && IP[j]<='9' || IP[j]>='a' && IP[j]<='f' || IP[j]>='A' && IP[j]<='F')) {
                        //cout<<IP[j]<<(IP[j]>='0')<<(IP[j]<='9')<<endl;
                        return "Neither";
                    }
                }
                if (j - deli <= 0 || j-deli > 4) return "Neither";
                deli = j + 1;
            }
            if (deli -1 < IP.size()) {
                //cout<< deli-1<<endl;
                return "Neither";
            }
            else return "IPv6";
        }
    }
};

