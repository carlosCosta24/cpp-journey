#include <iostream>
#include <queue>
using namespace std;

int main(){

queue<int> Q;

Q.push(1);
Q.push(2);
Q.push(4);
Q.push(8);
Q.push(16);

cout << "Count: " << Q.size() << endl;
cout << "Front: " << Q.front() << endl;
cout << "Back: " << Q.back() << endl;

cout << "My Queue: ";

while (!Q.empty()) {
cout << Q.front() << " ";
Q.pop();
}
return 0;

}