#include "fstream"
#include "iostream"

using namespace std;

class file{
	
	fstream fr;
	char charr[101] ;
	string path;
	char end;
	int count;
	
	void Convert(string str){
	
		for(int i = 0 ; i < str.length() ; i++){
		
			charr[i] = str.at(i);	
		}
	}
	
	string ConToString(int num){
	
		char ch[1001] = {};
		int i = 0;
		int digit;
	
	
		do{
		
			digit = num % 10;
			ch[i++] = digit + 48;
			num /= 10;
		
		}while(num > 0 );
	
		int k = 0;
		char ch2[1001] = {};
	
		for(int j = i - 1 ; j >=0 ; j--){
		
			ch2[k++] = ch[j];		
		}
	
		string str = ch2;
		return str;
	}

	
	public :
		
		file(){
			
			end = '*';
		}
		
		void Clear(){
			
			Convert(path);
			fstream f(charr, ios :: out);
			
		}
		
		void SetEnd(char ch){
			
			this -> end = ch;
			
		}
		
		char EndFile(){
			
			return this -> end;
		}
		
		void SetPath(string path){
			
			this -> path = path ;
			Convert(path);
			fr.open(charr, ios :: in);	
		}
		
		string GetPath(){
			
			return path;
		}
		
		bool WriteLine(int str){
			
		    return 	this -> WriteLine(ConToString(str));
		}
		
		bool Write(int str){
			
		    return 	this -> Write(ConToString(str));	
		}
		
		bool WriteLine(string str){
			
			if(this -> GetPath() == ""){
				
				return false;	
			}
				Convert(path);	
				fstream f(charr, ios :: app);
				f << str << endl;
				f.close();
				return true;
		}
		
		bool Write(string str){
			
			if(this -> GetPath() == ""){
				
				return false;
			}
				Convert(path);
				fstream f(charr, ios :: app);
				f << str ;
				f.close();	
				return true;
		}
		
		
		string ReadWord(){
			
			string str;
			
			fr >> str;
			
			return str;
		}
		
		char ReadChar(){
			
			char ch ;
			
			if(!fr.eof()){
			
				fr.get(ch);
				return ch;
			}
			return this->end ;
		}
		
};

file File;
