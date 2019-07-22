# include <iostream>
# include <string>
using namespace std;

bool isSubstring(string s1, string s2){
	
	size_t f = s1.find(s2);
	
	cout<<"f: "<<f<<endl;
	
	if (f < s1.size())return true;
	
	return false;
}

bool stringRotation(string& s1, string& s2){
	int l1 = s1.size();
	int l2 = s2.size();
	
	if (l1 != l2)return false;
	
	s1 += s1;
	
	if (isSubstring(s1, s2))return true;
	
	return false;
}

int main(){
	string s1, s2;
	cin>>s1>>s2;
	
	cout << boolalpha << stringRotation(s1, s2);
	
	return 0;
}
