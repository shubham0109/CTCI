# include <iostream>
# include <string>
using namespace std;

string urlify(string &s, int l){
	
	int len = s.size()-1;
	int first_pos = l-1;
	int last_pos;
	int ctr = 0;
	
	for (int i = 0; i < l; i++){
		if (s[i] == ' ')ctr++;	
	}
	last_pos = l + ctr*2;
	last_pos--;
	if (last_pos > len){
		return "not possible";
	}
	
	while (first_pos != last_pos){
		if (s[first_pos] == ' '){
			s[last_pos--] = '0';
			s[last_pos--] = '2';
			s[last_pos--] = '%';
		}else{
			s[last_pos--] = s[first_pos];
		}
		
		first_pos--;
	}
	
	return s;
}

int main(){
	string s;
	int l;
	//char str[] = "Mr John Smith    ";
	getline(cin,s);
	cin>>l;
	
	cout<<urlify(s,l)<<endl;
	
	return 0;
}
