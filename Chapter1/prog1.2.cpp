# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

bool checkPermutation(string s1, string s2){
	
	if (s1.size() != s2.size()){
		return false;
	}
	
	int arr[256] = {0};
	
	for (int i = 0; i < s1.size(); i++){
		arr[s1[i]]++;
	}
	
	for (int i = 0; i < s2.size(); i++){
		arr[s2[i]]--;
		
		if (arr[s2[i]] < 0){
			return false;
		}
	}
	
	return true;	
}

bool checkPermutationSort(string s1, string s2){
	
	if (s1.size() != s2.size()){
		return false;
	}
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] != s2[i]){
			return false;
		}
	}
	
	return true;
}
int main(){
	string s1, s2;
	
	cin>>s1>>s2;
	
	cout<<boolalpha<<checkPermutation(s1, s2)<<endl;
	cout<<boolalpha<<checkPermutationSort(s1, s2)<<endl;
	
	cout<<s1<<" "<<s2<<endl;
	return 0;
}
