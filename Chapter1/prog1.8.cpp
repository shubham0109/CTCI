# include <iostream>
# include <vector>
# include <set>
using namespace std;

void zeroMatrix(vector<vector <int> > &a, int n){
	int r = a.size();
	int c = a[0].size();
	
	set <int> rows;
	set <int> cols;
	
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (a[i][j] == 0){
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	
	set <int> :: iterator itr;
	
	for (itr = rows.begin(); itr != rows.end(); itr++){
		for (int i = 0; i < c; i++){
			a[*itr][i] = 0;
		}
	}
	
	for (itr = cols.begin(); itr != cols.end(); itr++){
		for (int i = 0; i < r; i++){
			a[i][*itr] = 0;
		}
	}
}

void zeroMatrixFast(vector< vector <int> > &a, int n){
	int r = a.size();
	int c = a[0].size();
	int row = 0, col = 0;
	
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (a[i][j] == 0){
				if (i == 0){
					row = 1;
				}
				if (j == 0){
					col = 1;
				}
				
				if (i != 0 && j != 0){
					a[i][0] = 0;
					a[0][j] = 0;
				}
			}
		}
	}
	
	for (int i = 1; i < r; i++){
		if (a[i][0] == 0){
			for (int j = 0; j < c; j++){
				a[i][j] = 0;
			}
		}
	}
	
	for (int i = 1; i < c; i++){
		if (a[0][i] == 0){
			for (int j = 0; j < c; j++){
				a[j][i] = 0;
			}
		}
	}
	
	if (row){
		for (int i = 0; i < c; i++)a[0][i] = 0;
	}
	
	if (col){
		for (int i = 0; i < r; i++)a[i][0] = 0;
	}
}
int main(){
	int m,n;
	cin>>m>>n;
	vector <vector <int> > a;
	for (int i = 0; i < m; i++){
		vector <int> v;
		for (int j = 0; j < n; j++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		a.push_back(v);
	}
	
	//zeroMatrix(a,n);
	zeroMatrixFast(a,n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}


