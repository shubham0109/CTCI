# include <iostream>
# include <string>
# include <sstream>

using namespace std;

string compression(string s){
	string cs = "";
	
	int index = 0, i = 1, ctr = 1;
	stringstream ss;
	
	while (i < s.size()){
		if (s[index] == s[i]){
			ctr++;
		}else{
			cs += s[index];
			ss << ctr;
			string st = ss.str();
			cs += st;
			ss.clear();
			index = i;
			ctr = 1;
		}
		i++;
	}
	
	cs += s[index];
	ss.flush();
	ss << ctr;
	cout<<ctr<<endl;
	cs += ss.str();
	cout<<"cs: "<<cs<<endl;
	if (cs.size() < s.size())return cs;
	
	return s;
}

int main(){
	string s;
	cin>>s;
	
	cout<<compression(s)<<endl;
	
	return 0;
}
