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
        bool isMultiple(int multiplier);
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
    num1.setInt(5);
    cout << num1.getInt() << endl;

    myInt num2;
    cout << num2.getInt() << endl;
    return 0;
}
