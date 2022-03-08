#include<iostream>
#include<string>
using namespace std;

void decode(string, int);
int mod(int, int);


int main(){
	
	string str;
	
	while(1){
		cout << "�п�J�r��(��Jexit�����})�G";
		getline(cin, str);
		
		if(str.compare("exit") == 0){
			break;
		}
		
		for(int i = 1;i < 26;i++){
			decode(str, i);
		}
		
		
		cout << endl;
	}
	
	system("pause");
	return 0;
}


void decode(string str, int key){
	int ascii;
	int number;
	//�̧ǸѽX 
	for(int i = 0;i < str.length();i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			ascii = str[i] - 'A';
			number = mod(key, ascii);
			str[i] = number + 'A';
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			ascii = str[i] - 'a';
			number = mod(key, ascii);
			str[i] = number + 'a';
		}
		
	} 
	cout << "key = " << key <<" : " << str << endl;
	
}

int mod(int key, int ascii){
	int number;
	int asciiNum;
	
	asciiNum = ascii - key;
	while(asciiNum < 0){
		asciiNum = asciiNum + 26;
	}
	number = asciiNum % 26;
	
	return number;
}


