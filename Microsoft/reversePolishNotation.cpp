class Solution {
public:
    bool isOp(string a){
        return (a=="+" || a=="-" || a=="*" || a=="/");
    }

    int cal(int a, int b, string c){
        if(c=="+"){
            return a+b;
        }
        else if(c=="-"){
            return a-b;
        }
        else if(c=="*"){
            return a*b;
        }
        else return a/b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens){
            if(!isOp(i)){
                s.push(stoi(i));
            }
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();

                // cout<<a<<" "<<b<<" "<<cal(a,b,i)<<"\n";

                s.push(cal(b, a, i));
            }
        }

        return s.top();
    }
};
