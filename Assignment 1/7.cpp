/*input
3
-+*ABCD
*+AB+CD
-+AB*CD
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
string pre_to_post(string pre_string, int length){
    stack<string> s;
    string temp;
    for (int i = length - 1; i >= 0; i--){
        if (pre_string[i] == '+' || pre_string[i] == '-' || pre_string[i] == '*' || pre_string[i] == '/'){
            string x1 = s.top();
            s.pop();
            string x2 = s.top();
            s.pop();
            temp = x1 + x2 + pre_string[i];
            s.push(temp);
        }
        else{
            temp = string(1, pre_string[i]);
            s.push(temp);
        }
    }
    return s.top();
}
int main(int argc, char const *argv[])
{
    int n;  cin >> n;
    string pre[n];
    for(int i = 0; i < n; i++){
        cin >> pre[i];
        cout << pre_to_post(pre[i], pre[i].size()) << '\n';
    }
    return 0;
}
