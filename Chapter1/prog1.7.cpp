# include <iostream>
using namespace std;

void rotateMatrix(int n, int m[][4]){
	int lower = 0,
		upper = n-1,
		left = 0,
		right = n-1,
		j = n-1;
		
	while (lower < upper){
		for (int i = 0; i < j; i++){
			int temp = m[lower][left+i];
			m[lower][left+i] = m[upper-i][left];
			m[upper-i][left] = m[upper][right-i];
			m[upper][right-i] = m[lower+i][right];
			m[lower+i][right] = temp;
		}
		
		lower++; upper--; left++; right--;
		j = j-2;
	}
		
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main(){
	int n;
	cin>>n;
	int m[4][4];
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin>>m[i][j];
		}
	}
	
	rotateMatrix(n, m);
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}
