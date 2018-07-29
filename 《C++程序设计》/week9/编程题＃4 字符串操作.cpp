#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <cstdlib>
using namespace std;

int num;
string s_in[21];
queue<string> command;

string int_to_string(int n){
	ostringstream stream;
	stream << n;
	return stream.str();
} 

string copy(int n, int x, int l){
	return s_in[n].substr(x,l);
}

string add(string s1, string s2){
	for(int i = 0; i < s1.length();i++){
		if(s1[i] < '0' || s1[i] > '9')
			return s1 + s2;
	}
	for(int i = 0; i < s2.length();i++){
		if(s2[i] < '0' || s2[i] > '9')
			return s1 + s2;
	}
	
	int a = atoi(s1.c_str()), b = atoi(s2.c_str());
	if(a >= 0 && a <= 99999 && b >= 0 && b<= 99999)
		return int_to_string(a+b);
	else
		return s1 + s2;
}

int find(string s, int n){
	return s_in[n].find(s);
}


int rfind(string s, int n){
	return s_in[n].rfind(s);
}

string insert(string s, int n, int x){
	return s_in[n].insert(x,s);
}

string reset(string s, int n){
	return s_in[n] = s;
}

void print(int n){
	cout << s_in[n] << endl;
}


void printall(){
	for(int i = 1; i <= num; i++){
		cout << s_in[i] << endl;
	}
}

string process_single_string(){
	string str = command.front();
	command.pop();
	if (str == "copy"){
		int n = atoi(process_single_string().c_str());
		int x = atoi(process_single_string().c_str());
		int l = atoi(process_single_string().c_str());
		return copy(n, x, l);
	}
	
	else if (str == "add"){
		string s1 = process_single_string();
		string s2 = process_single_string();
		return add(s1, s2);
	}
	
	else if (str == "find"){
		string s = process_single_string();
		int n = atoi(process_single_string().c_str());
		return int_to_string(find(s,n));
		//return to_string(find(s, n));		
	}
	
	else if (str == "rfind"){
		string s = process_single_string();
		int n = atoi(process_single_string().c_str());
		return int_to_string(rfind(s, n));
		//return to_string(rfind(s, n));	
	}
	
	else{
		return str;
	}

}

bool process_wholeline(){
	string temp = command.front();
	command.pop();
	if (temp == "insert"){
		string s = process_single_string();
		int n = atoi(process_single_string().c_str());
		int x = atoi(process_single_string().c_str());
		insert(s, n, x);
	}
	
	else if (temp == "reset"){
		string s = process_single_string();
		int n = atoi(process_single_string().c_str());
		reset(s, n);
	}
	
	else if (temp == "print"){
		int n = atoi(process_single_string().c_str());
		print(n);
	}
	
	else if (temp == "printall")	{
		printall();
	}	
	
	else if (temp == "over")	{
		return false;
	}
	return true;	
}

int main(){
	cin >> num;
	for(int i = 1; i <= num; i++){
		cin >> s_in[i];
	}
	
	char ch[600]; 
	
	while(1){
		cin.getline(ch, 600, '\n');
		string temp1 = "";
		for(int i = 0; ch[i] != '\0'; i++){
			if(ch[i] != ' ')
			temp1.push_back(ch[i]);
			else{
				command.push(temp1);
				temp1.clear();
			}
		}
		command.push(temp1);
		bool flag = process_wholeline();
		if(!flag)
			break;	
	}	
	return 0;
} 
