
//using recursion
#include <bits/stdc++.h> 
void sortInserted(stack<int> &s, int num){
	//base case
	if(s.empty() || (!s.empty() && s.top()<num)){
		s.push(num);
		return;
	}
	int n=s.top();
	s.pop();
	//recursive call
	sortInserted(s,num);
	s.push(n);

}
void sortStack(stack<int> &stack)
{
	if (stack.empty()){
		return ; //no need of any operation in this case
	}
	int num=stack.top();
	stack.pop();
	//recursive call
	sortStack(stack);
	//insert element in sorted order
	sortInserted(stack,num);

}