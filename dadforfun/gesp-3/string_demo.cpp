#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main() {

    string s1 = "abc";
    char s2[4] = "abc";
    string s3 = s1 + s2;
    cout << s2 << endl;
    cout << (s1 == s2) << endl; // 1
    cout << s3 << endl; 
    cout << strlen(s2) << endl;
    cout << s2 + s3 << endl;
    // cout << strcat(s2, "abcd") << endl;
    cout << strstr(s2, "bc") << endl;
    cout << s1.size() << endl;
    return 0;
}