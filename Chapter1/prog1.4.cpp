# include <iostream>
# include <string>
# include <algorithm>
using namespace std;

bool checkPalindrome(string s){
	int arr[256] = {0};
	int ctr = 0;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	//s = s.tolower();
	cout<< s<<endl;
	int odd = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] != ' '){
			int c = s[i];
			if (arr[c] == 1){
				arr[c] = 0;
				odd--;
			}else {
				arr[c] = 1;
				odd++;
			}
			//arr[s[i]]++;
		}	
	}
	
	if (odd > 1)return false;
	return true;
	
}
int main(){
	string s;
	getline(cin,s);
	
	cout<<boolalpha<<checkPalindrome(s)<<endl;
	
	return 0;
}
