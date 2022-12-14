#include <iostream>

int CountDigits(int n){
	if(n==0){
		
	return 1;}
	else{
		int count=0;
	
		while (n!=0)
		{ n/=10;
		count++;}
		return count;
	}
}

bool IsNeighbourly(int n){
	int prevNum= n%10;
	for(int i=0; i<=CountDigits(n); i++){
		
		int currNum=(n/10)%10;
		if(prevNum==currNum){return false;}
		prevNum=currNum;
		n/=10;
	}
	return true;
}

int BiggestNeighbourlyNum(int a, int b){
	for(int i=b; i>=a; i--){
		if(IsNeighbourly(i)) return i;
	}
	return 0;
}

int SmallestNeighbourlyNum(int a, int b){
	for(int i=a; i<=b; i++){
		if(IsNeighbourly(i)) return i;
	}
	return 0;
}

int DiffNeighbourly(int a, int b){
	return (BiggestNeighbourlyNum(a,b) - SmallestNeighbourlyNum(a,b));
}

int main() {
int a=1099;
int b=1222;

if(DiffNeighbourly(a,b)==0){
	std:: cout<<"NoAdjacent";
	return 0;
}
else {std:: cout<<DiffNeighbourly(a,b);}
}