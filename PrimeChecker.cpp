//
// PrimeChecker.cpp
// ds_hw1_warm_up
//
#include "PrimeChecker.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using std::vector;
int check_prime(unsigned long num);

unsigned long PRIMECHECKER::PrimeChecker(unsigned long a, unsigned long b){
		
	vector<unsigned long> prime_list;
		
	if (a==1){
		if (b == 1){
			return 0;
				
		}
		else{
			a++;
		}
			
	}
		
	if ((a % 2) == 0){
		if (a == 2){
			prime_list.push_back(2);
			a++;
		}
		else{
			a++;
		}
	}
		

	for(long count = a; count <= b; count = count + 2){
			
		if (prime_list.empty()){
			
			if (check_prime(count)){
				prime_list.push_back(count);
			}
			else{
				continue;
			}
		}
		else{
			
			int flag1 = 1;
			for(int j = 0; j < prime_list.size(); j++){
				if ((count % prime_list[j]) == 0){
					flag1 = 0;
					break; 
				}
			
			}
			
			if (flag1 == 0){
				continue;
			}
			else{
				if (check_prime(count)){
					prime_list.push_back(count);
				}
				else{
					continue;
				}
			}
				
		}
	}

	return prime_list.size(); 
		
	
	

}

int check_prime(unsigned long num){
	int flag = 1;
	
	for(long i = 3; i <= sqrt(num); i=i+2){
		
		if ((num%i) == 0){
			flag = 0;
			break;
		}
	
	}
	
	return flag;
}
