#include <iostream>
#include <ctime>
using namespace std;


int main() {

    const time_t Time = time(0);

    const tm * Now = localtime(&Time);

    cout << "Year: " << Now->tm_year +1900 <<endl;
    cout << "Month: " << Now->tm_mon+1<<endl;
    cout << "Day: "<< Now->tm_mday<<endl;
    cout << "Hour: "<< Now->tm_hour<<endl;
    cout << "Minutes: "<< Now->tm_min<<endl;
    cout << "Sec: "<< Now->tm_sec<<endl;
    cout << "Day of week: "<< Now->tm_wday<<endl;
    cout << "Days since 1st jan: "<< Now->tm_yday<<endl;
    cout << "Day time saving: "<< Now->tm_isdst<<endl;
    cout << "Minuts east of UTC! "<< Now->tm_gmtoff / 60<<endl;
    cout << "Time zone! "<< Now->tm_zone<<endl;


}