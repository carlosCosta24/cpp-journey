#include  <ctime>
#include <iostream>
using namespace std;

int main() {
    time_t t = time(0);

    const char * Time = ctime(&t);

    cout << Time << endl;

    const tm* utc = gmtime(&t);

    Time = asctime(utc);

    cout << Time << endl;
}
