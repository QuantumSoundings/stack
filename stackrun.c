#include<string>
#include<iostream>
#include "stack.c"

using namespace std;
void help(){
			cout<<"Commands:\n 'p'-pushes the current item onto the stack.\n 'o'-pops the top item off of the stack.\n 'e'-peeks at the top item on the stack.\n 'j'-prints out the entire stack from bottom to top.\n 'quit'-quits the program."<<endl;
			cout<<"Commands can be sequential. For example '12po23pe' would push 12 onto the stack, pop 12 off the stack, push 23 on and peek at 23.\n You must have a number before the p command because you can't do anything with nothing."<<endl;
}		
int main(){
	stack<int> stk;
	cout<<"Welcome to the stack interpreter! For the sake of demostration this stack will be using int. For a list of commands type 'help'. Enjoy!"<<endl;
	string s;
	cin>>s;
	//bool help=true;
	while(s!="quit"){
		//if(s=="help"&&s.length()==4)
		//	help();
		if(s.length()>=1){
			int temp=-1;
			for(int k=0;k<s.length();k++){
				switch(s[k]){
					case 'j':cout<<stk<<endl;break;
					case 'p':if(temp>-1&&k!=0&&s[k-1]<'a')stk.push(temp);else cout<<"Error Pushing nothing"<<endl;temp=-1;break;
					case 'o':if(stk.getTop()>-1)cout<<stk.pop()<<endl;break;
					case 'e':if(stk.getTop()>-1)cout<<stk.peek()<<endl;break;
					case '1':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '2':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '3':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '4':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '5':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '6':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '7':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '8':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '9':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case '0':if(temp==-1)temp=s[k]-'0';else{temp*=10;temp+=s[k]-'0';};break;
					case 'h':if(s.substr(k,k+4)=="help"){help();k+=4;}else cout<<"Error character 'h' not recognized"<<endl;break;
					case 'q':if(s.substr(k,k+4)=="quit")return 0;break;
					default: cout<<"Error character '"<<s[k]<< "' not recognized"<<endl;break;
				}
			}
		}
		cin>>s;
	}
	return 0;
}
					

