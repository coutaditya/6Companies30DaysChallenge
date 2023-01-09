class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> c(10, 0);
        for(auto i:secret){
            c[i-'0']++;
        }

        // for(auto i:c){
        //     cout<<i<<" ";
        // }

        int b = 0, co = 0;

        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]){
                c[secret[i]-'0']--;
                b++;
            }
        }

        for(int i=0; i<secret.length(); i++){
            if(secret[i]!=guess[i]){
                if(c[guess[i]-'0']>0){
                    c[guess[i]-'0']--;
                    co++;
                }
            }
        }

        string ans = "";
        ans+=to_string(b);
        ans+="A";
        ans+=to_string(co);
        ans+="B";

        return ans;
    }
};