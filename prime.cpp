#include <iostream>
#include <vector>
#include <sstream>



#include"Prime.h"
#include"otherFuncs.h"

using namespace std;
//void unique_elements(std::vector<string>& v);
void Prime::SetPrimeStatus(bool i){
    primeStatus=i;
}
     int Prime::GetPrimeStatus(){
         return primeStatus;
     }

void Prime::setPrimes(int i)
{
    primes->push_back(i);
}


std::vector <int> Prime::getPrimes()
{
    return *primes;
}

void Prime::SetNum(int i)
{
    num=i;
}


int Prime::GetNum()
{
    return num;
}


void Prime::SetbelowPrimeNum(int i)
{
    belowPrimeNum=i;
}


int Prime::GetbelowPrimeNum()
{
    return belowPrimeNum;
}





bool Prime::checkPrime(int n)
{

    bool numIsPrime = true;




    for(int i = 2; i <= n / 2; ++i)
    {
        if(n % i == 0)
        {
            numIsPrime = false;
            break;
        }
    }

    if (numIsPrime&&n>=2)
    {
        return true;
    }

    return false;

}


void  Prime::printPrimeStatus(){
GetPrimeStatus()==true ? printf("\n%d is a Prime number\n",GetNum()):printf("\n%d is not a Prime number\n",GetNum());

}

void Prime::assignBelowPrime(int n)//good
{
int counter=0;

if(this->primes->size()>0)//if already assigned for the number
{return;}

    for(int i=2; i<=n; ++i) //assigning
    {



        if(checkPrime(i)==true&&i!=n)
        {

            setPrimes(i);
            SetbelowPrimeNum(++counter);

        }


    }



}


void Prime::printBelowPrime()
{

    int countL=0;


cout<<"Prime below "<<num<<endl;

    cout<<endl;

    int largestDigit=0;

    if(num>2)
    largestDigit=
    read_digits(primes->at((primes->size())-1));

if(num>2)
    for(auto const& value: getPrimes())
    {



        for(int j=0; j<largestDigit; ++j)cout<<" ";//spacing (depend on the larges prime number value)
if(read_digits(value)<largestDigit){//get the small number digit aligned with the larger digits like 3 to 100 or 10

        int extraSpacing=largestDigit-read_digits(value);
    for(int k=0;k<extraSpacing;k++)cout<<" ";

}
        std::cout << value << " ";
        if(countL%5==4)cout<<endl;//go to new line every 5 number
        ++countL;

    }

    cout<<endl<<endl;
    cout<<"There's "<<GetbelowPrimeNum()<<" Prime numbers below "<<GetNum();
    cout<<endl<<endl;
}



void Prime::findSumsToPrime(int num)
{

//const int limit=3000;
   std::ostringstream ss;//formatting str
    std::string str;
    unsigned int Size = getPrimes().size();

if(num<=2){
     goto print;
       }//important

if((doubleSumsForPrime->size()>=1&&flagDouble)||(tripleSumsForPrime->size()>=1&&flagTriple))//to skip if numbers below prime for a number has been already found
{goto print;}




    for(size_t i=0; i<=Size-1; ++i)
    {





        for(size_t j=i; j<=Size-1; ++j)
        {


      if(this->flagDouble==true)
            if(getPrimes().at(i)+getPrimes().at(j)==num)//find double Sums For Prime
            {

                ss  << getPrimes().at(i)<<" + "<<getPrimes().at(j)<<" = "<<num;
                str = ss.str();

                doubleSumsForPrime->push_back(str);
                ss.str("");//clear string stream content

            }//end if

       //  if(GetNum()<=limit)
       if(this->flagTriple==true)
         for(size_t k=j; k<=Size-1; ++k)//to assign tripleSumsForPrime
            {


                if(getPrimes().at(i)+getPrimes().at(j)+getPrimes().at(k)==num)
                {
                    ss  << getPrimes().at(i)<<" + "<<getPrimes().at(j)<<" + "<<getPrimes().at(k)<<" = "<<num;
                    str = ss.str();

                    tripleSumsForPrime->push_back(str);
                    ss.str("");
                }

            }//end loop k

        }//end loop j



    }//end loop i


print:
    cout<<endl;

    //if(GetNum()>limit){cout<<endl<<GetNum()<<" is above "<<limit<<" so prime+prime+prime = is not supported\n";}


    if(doubleSumsForPrime->size()>=1||tripleSumsForPrime->size()>=1)
    cout<<"Prime numbers sums that = "<<GetNum();
    else {cout<<"there is no Prime numbers sums that = "<<GetNum();}
    cout<<endl;



    // Print the vectors string
    cout<<endl;
if(flagDouble){
    if(doubleSumsForPrime->size()>=1)
    for (auto it : *doubleSumsForPrime) {
        cout << it << "\n";
    }
    cout<<endl;

}
if(flagTriple){
     if(tripleSumsForPrime->size()>=1)
    for (auto it : *tripleSumsForPrime) {
        cout << it << "\n";
    }

}

}//end find sums to prime

