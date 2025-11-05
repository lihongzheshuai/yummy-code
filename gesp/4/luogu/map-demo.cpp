#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int> mp;
	mp["wang"] = 80;
	mp.insert({"li",91});
	mp.insert({"wangjia",95});
	mp.insert({"wangyin",86});
	mp.insert({"lize",89});
	cout << "map:\n";
	for(auto &p : mp){
		cout << p.first << " -> " << p.second << endl;
	}
	auto it = mp.find("wang");
	if(it != mp.end()){
		cout << "value=" << it->second << "\n";
	}
	mp.erase("li");
	cout << mp.size() << "\n";
} 
