#include <iostream>
using namespace std;

int main()
{
    int Age;
    bool HasDrivingLicence, HasRecommendation;

    cout << "Do you have recommendation: (0 for no, 1 for yes): ";
    cin >> HasRecommendation;

    if (HasRecommendation)
    {
        cout << "you are hired !!" << endl;
    }
    else
    {
        cout << "Enter your age: ";
        cin >> Age;

        cout << "Do you have a driving licence (0 for no, 1 for yes): ";
        cin >> HasDrivingLicence;

        if (Age >= 21 && HasDrivingLicence)
        {
            cout << "you are hired congrats!! " << endl;
        }
        else
        {
            cout << "you are rejected, good luck next time !! " << endl;
        }
    }

    return 0;
}