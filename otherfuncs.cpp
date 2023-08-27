
#include<iostream>
#include"otherFuncs.h"
#include"Prime.h"

int read_digits(const int num){

	int num1=num;
	const int n=10;//divide it to num1
	int count_0s=0;//count how many digit


 while(num1>=n){


    num1/=n;

    count_0s++;
}

   return count_0s;


}

void menu(Prime *p)
{
    unsigned int choice=0;
    unsigned int findSumsChoice=0;


    p->printPrimeStatus();

    do
    {
        std::cout<<"\n\t0)get back\n\t1)print Below Prime\n\t2)findSumsToPrime"<<std::endl;
        choice=input(choice);
        switch(choice)
        {
        case 0:
            break;

        case 1:
if(p->GetNum()>2){
         //   p->assignBelowPrime(p->GetNum());
          // p->printBelowPrime();
           } else{
         //        p->assignBelowPrime(p->GetNum());
           }
           p->printBelowPrime();
            break;
        case 2:
            p->assignBelowPrime(p->GetNum());

        std::cout<<"\n\t0)get back\n\t1)find double prime\n\t2)find triple prime\n\t3)both of them"<<std::endl;
            findSumsChoice=input(findSumsChoice);

            switch(findSumsChoice){
            case 0:break;
            case 1: p->flagDouble=true;
            break;
            case 2: p->flagTriple=true;
            break;
            case 3:
                 p->flagDouble=true;
                 p->flagTriple=true;
            default:

                 break;
            }
           if(findSumsChoice>0&&findSumsChoice<=3) p->findSumsToPrime(p->GetNum());//exucte just in those cases 1 to 3

           p->flagDouble=false;
           p->flagTriple=false;
            break;

        default :
            break;
        }

    }
    while(choice!=0);


    //delete p;
}



int input(int num)
{

  std::string input;
        std::cin >> input;

        if (input == "-1") {
            return -1;
        }

        try {
            if (std::stod(input) == static_cast<int>(std::stod(input))) {
return std::stoi(input);
            }
        } catch (const std::exception&) {
            return -1;
            std::cout << "Invalid input. Please enter a valid number: ";
        }


    return -1;
}
