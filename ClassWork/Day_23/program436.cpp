#include<iostream>
using namespace std;

class Arithmatic
{
    private:
     int No1,No2;

    public:
        Arithmatic(int A,int B);
        int Addition();
        int Subtration();
};

Arithmatic :: Arithmatic(int A,int B)
{
    this -> No1 = A;
    this -> No2 = B;
}

int Arithmatic :: Addition()
{
    return No1 + No2;
}
int Arithmatic :: Subtration()
{
    return No1 - No2;
}

int main()
{
    Arithmatic obj(11,10);

    cout << obj.Addition()<<endl;
    cout << obj.Subtration()<<endl;

}