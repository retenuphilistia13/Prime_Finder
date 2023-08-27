#pragma once
#include<vector>
#include<string>

#include<mutex>
class Prime{

private:
std:: vector <int> *primes=new  std::vector <int>;
std:: mutex primesMutex;

std:: vector <std::string> *doubleSumsForPrime=new std::vector <std::string>;
std:: vector <std::string> *tripleSumsForPrime=new std::vector <std::string>;
int num;
  int belowPrimeNum;//amount of bleow prime for a number

std::mutex belowPrimeNumMutex;
std::mutex GetbelowPrimeNumMutex;

std::mutex checkPrimeMutex;


    bool primeStatus=false;
public:
bool flagDouble=false;
bool flagTriple=false;

std::vector <int> getPrimes();//function
void setPrimes(int i);

void SetbelowPrimeNum(int i);
    int GetbelowPrimeNum();

void SetPrimeStatus(bool i);
     int GetPrimeStatus();

void SetNum(int i);
     int GetNum();

bool checkPrime(int n);
void findSumsToPrime(int n);
void assignBelowPrime(int n);
void printBelowPrime();
void printPrimeStatus();

Prime(int num1){


SetNum(num1);


checkPrime(num1)==true ? SetPrimeStatus(true):SetPrimeStatus(false);

}

~Prime(){//it works when object get deleted dahh

delete primes;
delete doubleSumsForPrime;
delete tripleSumsForPrime;
}


};

