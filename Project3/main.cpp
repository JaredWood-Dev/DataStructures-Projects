#include <iostream>

using namespace std;

class myInt
{
    private:
        int userNumber;
    public:
        int getInt()
        {
            return userNumber;
        }
        void setInt(int num)
        {
            userNumber = num;
        }
        bool isMultiple(int multiplier)
        {
            if (userNumber % multiplier == 0)
            {
                return true;
            }
            return false;
        }
        bool sumIsEven();
        double getSquareRoot();
        bool isPrime();
        bool isPerfect();
        myInt()
        {
            userNumber = 0;
        }
};
int main() {

    myInt num1;
    num1.setInt(497);
    cout << num1.getInt() << endl;
    cout << "7:\t" << num1.isMultiple(7) << endl;
    cout << "11:\t" << num1.isMultiple(11) << endl;
    cout << "13:\t" << num1.isMultiple(13) << endl;

    return 0;
}
