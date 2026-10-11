#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int maxn=0;
        string ans;
        for(int i=1;i<s.size()-1;i++)
        {
            int p1=i-1,p2=i+1,temp=1;
            while(p1>=0&&p2<=s.size()-1&&s[p1]==s[p2])
            {
                p1--;
                p2++;
                temp+=2;
            }
            if(temp>maxn)
            {
                 maxn=temp;
                 ans=s.substr(p1,p2-p1+1);
            }
        }
        for(int i=1;i<s.size()-1;i++)
        {
            int temp=0;
            if(s[i]==s[i+1])
            {
                 int p1=i-1,p2=i+2;
                 temp=2;
            
            while(p1>=0&&p2<=s.size()-1&&s[p1]==s[p2])
            {
                p1--;
                p2++;
                temp+=2;
            }
            if(temp>maxn)
            {
                maxn=temp;
                ans=s.substr(p1,p2-p1+1);
            }
            }
        }
        return ans;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution a;
    cout<<a.long
    return 0;
}