#include <iostream>
#include<set>
using namespace std;

set<int> arr;

void jumping_no(long long x, int n){
    if(x > n){
        return;
    }
    arr.insert(x);
    long long temp;
    int mod = x % 10;
    if(mod == 0){
        temp = x * 10 + (mod + 1);
        jumping_no(temp, n);
    }else if(mod == 9){
        temp = x * 10 + (mod - 1);
        jumping_no(temp, n);
    }else{
        temp = x * 10 + (mod + 1);
        jumping_no(temp, n);
        temp = x * 10 + (mod - 1);
        jumping_no(temp, n);
    }
}

int main() {
	//code
	int t,n;
	cin>>t;

	while(t--){
	    cin>>n;

	    for(int i=0; i<=9; i++){
            jumping_no(i, n);
        }

        for(auto i = arr.begin(); i != arr.end(); ++i){
            cout<<*i<<" ";
        }
        cout<<endl;
        arr.clear();
	}
	return 0;
}
