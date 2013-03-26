#include<string>
#include<cmath>
#include "stack.c"
using namespace std;
stack<char> ops;
stack<double> stk;
double calc(char c){
	double sec=stk.pop();
	double fir=stk.pop();
	double i=0;
	switch(c){
		case'^':i=pow(fir,sec);break;
		case'*':i=fir*sec;break;
		case'/':i=fir/sec;break;
		case'+':i=fir+sec;break;
		case'-':i=fir-sec;break;
	}
	return i;
}
bool ishigher(char c){
	string s="-+/*^";
	if(ops.getTop()==-1&&(c=='^'||c=='/'))
		return true;
	else if(ops.getTop()==-1)
		return false;
	int on =s.find(ops.peek());
	int off=s.find(c);
	if(off>on)
		return true;
	return false;
}
double infix(string s){
	bool isnum=false;bool cal=false; bool islast=false;bool neg=false; bool isop=false;
	double num=0;
	s+=" ";
	for(int k=0; k<s.length();k++){
		char c=s[k];
		if(c==' '||c=='|'){
			if(isnum){
				if(neg){
					stk.push(num*-1);
					neg=false;
				}
				else
					stk.push(num);
				if(cal){
					stk.push(calc(ops.pop()));
					cal=false;
				}
				num=-1;
				isnum=false;
			}
		}
		else if(string("0123456789").find(c)!=string::npos){
			//if(isop)
			//	neg=true;
			isnum=true;
			if(num==-1) num=0;
			num=num*10+(c-'0');
			if(islast){
				ops.push('*');
				islast=false;
			}
			isop=false;
		}
		else if(string("^*/+-()").find(c)!=string::npos){
			if(c=='-'&&!isnum)
				neg=true;
			else{
			if(isnum){
				if(num!=-1){
					if(neg){
						stk.push(num*-1);
						neg=false;
					}
					else
						stk.push(num);
					if(cal&&!ishigher(c)){
						stk.push(calc(ops.pop()));
						cal=false;
					}
					num=-1;
				}
			}
			if(c=='('){
				if(isnum||islast){
					ops.push('*');
					ops.push(c);
					isnum=false;
					cal=false;
					if(islast)
						islast=false;
				}
				else
					ops.push(c);
			cal=false;
			}
			else if(c==')'){
				while(ops.peek()!='(')
					stk.push(calc(ops.pop()));
				
				ops.pop();
				if(ops.peek()=='*'||ops.peek()=='/')
					stk.push(calc(ops.pop()));
				islast=true;
				isnum=false;
			}
			else if(ishigher(c)){
				ops.push(c);
				cal=true;
				//if(ops.getTop()==0)
				//	cal=alse;
				islast=false;
				isnum=false;
			}
			else{
				if(stk.getTop()>=1)
					stk.push(calc(ops.pop()));
				ops.push(c);
				isnum=false;
				islast=false;
			}
			isop=true;
			}
		}
	cout<<stk<<"   "<<ops<<"  num: "<<num<<"  c: "<<c<<"   isnum: "<<isnum<<"   neg: "<<neg<<"   cal "<<cal<< endl;
	}
	if(isnum&&num!=-1)
		stk.push(num);
	while(stk.getTop()!=0)
		stk.push(calc(ops.pop()));
	return stk.pop();
}
int main(){
	string s="";
	
	getline(cin,s);
	
	

	cout<<"Welcome to the calculator test class"<<endl;
	while(s!="q"){
		cout<<infix(s)<<endl;
		getline(cin,s);
	}

	return 0;
}	
