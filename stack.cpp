#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
stack<int> x;
void mysub(){
int q= 0;
char r = '\n';
r = x.top();
x.pop();
q = x.top();
x.pop();
q = q*20;
r = r+10;
cout << "bottom of mysub" << endl;
cout << "q is "  << q  << endl;
cout << "r is "  << r  << endl;
x.push(q);
x.push(r);

int main(){
 int a = 15;
 char b = 'A';
 cout << "top of main" << endl;
 x.push(a);
 x.push(b);
 mysub();
 b =x.top();
 x.pop();
 a = x.top();
 x.pop();
 cout << "bottom of main" << endl;
cout << "a is "  << a  << endl;
cout << "b is "  << b  << endl;
return 0;
}
