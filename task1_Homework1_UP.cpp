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

long int RemoveDuplicateDigits(long int n)
{
    int prevDigit = n % 10;
    long int power = 10;
    long int newNum = prevDigit;
	
    while (n!=0){
        int currDigit = n % 10;
 
        if (currDigit != prevDigit) {
            newNum += currDigit * power;
            prevDigit= currDigit;
            power *= 10;
        }
        n = n / 10;
    }
    return newNum;
}

int SortNumber(int number){
	
int sorted = 0;
int digits = 10;
int sortedDigits = 1;
bool first = true;

while (number > 0) {
    int digit = number % 10;

    if (!first) {

        int tmp = sorted;
        int toDivide = 1;
        for (int i = 0; i < sortedDigits; i++) {
            int tmpDigit = tmp % 10;
            if (digit >= tmpDigit) {
                sorted = sorted/toDivide*toDivide*10 + digit*toDivide + sorted % toDivide;
                break;
            } else if (i == sortedDigits-1) {
                sorted = digit * digits + sorted;
            }
            tmp /= 10;
            toDivide *= 10;
        }
        digits *= 10;
        sortedDigits += 1;
    } else {
        sorted = digit;
    }

    first = false;
    number = number / 10;
}
return sorted;
}

void CompareNumbers(int a, int b){
	int num1= RemoveDuplicateDigits(SortNumber(a));
	int num2= RemoveDuplicateDigits(SortNumber(b));
	if(CountDigits(num1)>CountDigits(num2)){
		std:: cout<<"Second is weaker";
	}
	else if(CountDigits(num1)<CountDigits(num2)){
		std:: cout<<"First is weaker";
	}
	else{
		bool isEven= true;
	
		for(int i=CountDigits(num1); i>0; i--){
			int lastDigitOfNum1= num1%10;
			int lastDigitOfNum2= num2%10;
			if (lastDigitOfNum1!=lastDigitOfNum2)
			{isEven =false;}
			num1/=10;
			num2/=10;
		}
		std:: cout<<(isEven?"Equal strength":"Not Comparable");
	}
	
}

int main(){

int number1=456;
int number2=123;

CompareNumbers(abs(number1), abs(number2));
}