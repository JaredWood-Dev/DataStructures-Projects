#include <iostream>
#include <cmath>

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
        bool sumIsEven()
        {
            int sumNum = 0;
            int tempNum = userNumber;
            while (tempNum > 0)
            {
                int digit = tempNum % 10;
                tempNum = tempNum / 10;
                sumNum = sumNum + digit;
            }
            if (sumNum % 2 == 0)
            {
                return true;
            }
            return false;
        }
        double getSquareRoot()
        {
            return pow(userNumber, 0.5);
        }
        bool isPrime()
        {
            int multCount = 0;
            for (int i = 1; i <= userNumber; i++) {
                if (userNumber % i == 0)
                {
                    multCount++;
                }
            }
            if (multCount > 2)
            {
                return false;
            }
            return true;
        }
        bool isPerfect()
        {
            int perfectCount = 0;
            for (int i = 1; i < userNumber; ++i) {
                if (userNumber % i == 0)
                {
                    perfectCount = perfectCount + i;
                }
            }
            if (perfectCount == userNumber)
            {
                return true;
            }
            return false;
        }
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
    cout << "Sum of digits: " << num1.sumIsEven() << endl;
    cout << "Square Root: " << num1.getSquareRoot() << endl;
    cout << "Is Prime: " << num1.isPrime() << endl;
    cout << "Is Perfect: " << num1.isPerfect() << endl;
    return 0;
}
