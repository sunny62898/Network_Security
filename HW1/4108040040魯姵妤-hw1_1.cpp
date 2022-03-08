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
		cout << "請選擇要加密還是解密(加密請按1, 解密請按2, 離開請按其他數字)：";
		cin >> com;
		
		//判別加密、解密、離開 
		if(com == 1){		//加密 
			cout << "請輸入key(為數字)：";
			cin >> key;
			
			cin.get();	//清除cin剩餘的字
			
			cout << "請輸入所要加密的字串：";
			getline(cin, str);
			
			encode(key, str);
		}
		else if(com == 2){	//解密 
			cout << "請輸入key(為數字)：";
			cin >> key;
			
			cin.get();	//清除cin剩餘的字 
			
			cout << "請輸入所要解密的字串：";
			getline(cin, str);
			
			decode(key, str);
		}
		else{	//離開 
			break;
		}
		
	}
	
	
	
	system("pause");
	return 0;
}


void encode(int key, string str){
	int ascii;
	int number;
	//依序編碼
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
	//依序編碼
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



