//
//  main.cpp
//  ASD2_2015
//  Labo 4
//
//  Created by Fabien Dutoit on 24.09.15.
//  Copyright © 2015 IICT, HEIG-VD. All rights reserved.
//

#define FILENAME "liste1.txt"
//#define FILENAME "liste2.txt"

#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <limits>

#include "HashTableTester.h"

#include "DirectoryInt.h"
#include "DirectoryLong.h"
#include "DirectoryPol.h"
#include "DirectoryStl.h"
#include "DirectorySha256.h"
#include "DirectoryCity.h"

#include "DirectoryWithoutAVS.h"

float MAX_LOAD_FACTOR = 0.1f;

template <typename Type>
void test(std::string filename) {
    
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Test for " << typeid(Type).name() << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    HashTableTester<Type> tester(filename, MAX_LOAD_FACTOR);
    std::ostringstream oss;
        oss << typeid(Type).name() << "," << MAX_LOAD_FACTOR << ",";
    tester.saveStats(oss.str());    
    
    std::cout << "Insertion: " << std::endl;
    tester.displayInsertionStats();
    std::cout << "Distribution: " << std::endl;
    tester.displayDistributionStats();
    tester.performSearch();
    std::cout << "Search: " << std::endl;
    
    tester.displaySearchStats();
    std::cout << std::endl;
     
    tester.saveStats("\n");
}

int main() {
    std::string filename(FILENAME);
    for(int i = 1; i < 10; i++) {
        //PART 1
        test<DirectoryInt>(filename);
        /*
        test<DirectoryLong>(filename);
        test<DirectoryPol<2>>(filename);    //polynomial with z =  2
        test<DirectoryPol<31>>(filename);   //polynomial with z = 31
        test<DirectoryPol<37>>(filename);   //polynomial with z = 37
        test<DirectoryStl>(filename);
        test<DirectorySha256>(filename);
        test<DirectoryCity>(filename);
        */
        MAX_LOAD_FACTOR += 0.1;
    }
    //PART 2
    //test<DirectoryWithoutAVS>(filename);
    
    return EXIT_SUCCESS;
    
}
