# include <iostream>
# include <bitset>
# include <map>
using namespace std;

bool isUnique(string s){
	bitset<256> bset;
	
	for (int i = 0; i < s.size(); i++){
		char c = s[i];
		
		if (bset[c]){
			return false;
		}
		
		bset[c] = 1;
	}
	
	return true;
}

bool isUnique_map(string &s){
	map <char, bool> mp;
	map <char, bool> :: iterator itr;
	
	for (int i = 0; i < s.size(); i++){
		char c = s[i];
		
		itr = mp.find(c);
		if (itr->second == true){
			return false;
		}
		
		mp[c] = true;
	}
	
	return true;
}

int main(){
	string s;
	cout<<"Enter the string: "<<endl;
	cin>>s;
	
	cout<<boolalpha<<isUnique(s)<<endl;
	cout<<boolalpha<<isUnique_map(s)<<endl;
	return 0;
}
