#include<iostream>
#include<string>
using namespace std;

void encode(int, string);
void decode(int, string);
int mod(int, int, int);

int main(){
	
	int com;
	int key;
	string str;
	
	char space;
	
	
	while(1){
		cout << "�п�ܭn�[�K�٬O�ѱK(�[�K�Ы�1, �ѱK�Ы�2, ���}�Ы���L�Ʀr)�G";
		cin >> com;
		
		//�P�O�[�K�B�ѱK�B���} 
		if(com == 1){		//�[�K 
			cout << "�п�Jkey(���Ʀr)�G";
			cin >> key;
			
			cin.get();	//�M��cin�Ѿl���r
			
			cout << "�п�J�ҭn�[�K���r��G";
			getline(cin, str);
			
			encode(key, str);
		}
		else if(com == 2){	//�ѱK 
			cout << "�п�Jkey(���Ʀr)�G";
			cin >> key;
			
			cin.get();	//�M��cin�Ѿl���r 
			
			cout << "�п�J�ҭn�ѱK���r��G";
			getline(cin, str);
			
			decode(key, str);
		}
		else{	//���} 
			break;
		}
		
	}
	
	
	
	system("pause");
	return 0;
}


void encode(int key, string str){
	int ascii;
	int number;
	//�̧ǽs�X
	for(int i = 0;i < str.length();i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			ascii = str[i] - 'A';
			number = mod(1, key, ascii);
			str[i] = number + 'A';
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			ascii = str[i] - 'a';
			number = mod(1, key, ascii);
			str[i] = number + 'a';
		}
		
	} 
	cout << "output : " << str << endl << endl;
	
}

void decode(int key, string str){
	int ascii;
	int number;
	//�̧ǽs�X
	for(int i = 0;i < str.length();i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			ascii = str[i] - 'A';
			number = mod(2, key, ascii);
			str[i] = number + 'A';
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			ascii = str[i] - 'a';
			number = mod(2, key, ascii);
			str[i] = number + 'a';
		}
		
	} 
	cout << "output : " << str << endl << endl;
	
}

int mod(int code, int key, int ascii){
	int number;
	int asciiNum;
	if(code == 1){
		asciiNum = ascii + key;
		while(asciiNum < 0){
			asciiNum = asciiNum + 26;
		}
		number = asciiNum % 26;
	}
	else if(code == 2){
		asciiNum = ascii - key;
		while(asciiNum < 0){
			asciiNum = asciiNum + 26;
		}
		number = asciiNum % 26;
	}
	
	return number;
}



