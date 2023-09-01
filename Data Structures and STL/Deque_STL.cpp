/*
Deque
double-ended queue is sequence containers with dynamic sizes that can be expanded or contracted on both ends(front and back) 
Deques are not quaranteed to store its elements in contiguous storage locations. accessing elements in a deque by offsetting a pointer to another element caused undefined behavior.
Elements of a deque can be  scattered in different chunks of storage
*/
#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main(){
    deque<int> deque_first(4,100);//size and then the elements
   cout<<"the size of the deque is "<<deque_first.size()<<endl;
   for(auto x:deque_first){
    cout<<x<<" ";
   }
   cout<<endl;
   deque_first.pop_back();
   for(int i=0;i<deque_first.size();i++){
    cout<<deque_first.at(i)<<" ";//if you want to access the deleted element use the iterator to get that element
   }
    return 0;
}