# include <iostream>
using namespace std;

bool oneEdit(string &s1, string &s2){
	if (s1.size() == s2.size()){
		int oneDiff = 0;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[i]){
				if (oneDiff){
					return false;
				}else{
					oneDiff = 1;
				}
			}
		}
		return true;
	}
	
	if (s1.size() > s2.size()){
		int j = 0;
		int oneDiff = 0;
		for (int i = 0; i < s1.size(); i++){
			if (s1[i] != s2[j]){
				if (oneDiff){
					return false;
				}else{
					oneDiff = 1;
				}
			}else{
				j++;
			}
		}
		return true;
	}
	
	int j = 0;
	int oneDiff = 0;
	for (int i = 0; i < s2.size(); i++){
		if (s1[j] != s2[i]){
			if (oneDiff){
				return false;
			}else{
				oneDiff = 1;
			}
		}else{
			j++;
		}
		
		//if (j == s1.size() && oneDiff)return false;
	}
	
	return true;
}

int main(){
	string s1,s2;
	
	cin>>s1>>s2;
	
	cout<<boolalpha<<oneEdit(s1, s2);
	
	return 0;
}
