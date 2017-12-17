//
//  DirectoryWithoutAVS.h
//  ASD2_2015
//
//  Created by Fabien Dutoit on 19.10.15.
//  Copyright © 2015 IICT, HEIG-VD. All rights reserved.
//

#ifndef DirectoryWithoutAVS_h
#define DirectoryWithoutAVS_h

#include <string>
#include <cctype>
#include <iostream>
#include <functional>
#include <string>

class DirectoryWithoutAVS {
private:
    std::string name;
    std::string firstname;
    std::string gender;
    std::string birthday;
    
public:
    DirectoryWithoutAVS();
    DirectoryWithoutAVS(std::string avs, /* SHOULD NOT BE USED */
                  std::string name,
                  std::string firstname,
                  std::string gender,
                  std::string birthday);
    
    std::string getName() const;
    std::string getFirstname() const;
    std::string getGender() const;
    std::string getBirthday() const;
    
    //operators
    bool operator ==(const DirectoryWithoutAVS &that) const;
    friend std::ostream& operator <<(std::ostream&, const DirectoryWithoutAVS&);
    
};

namespace std
{
    template <>
    struct hash<DirectoryWithoutAVS>
    {
        size_t operator()(const DirectoryWithoutAVS& d) const
        {
            // we use stl hash function for string type on name, we could do much better...
            //std::cout << std::endl << d.getBirthday() << std::endl;
            /**
            string name = d.getName();
           
            string firstName = d.getFirstname();
           
            
            size_t ashName = hash<string>()(d.getName()) ;
            size_t ashFirstName = std::hash<string>()(d.getFirstname());
            size_t ashDate = std::hash<string>()(d.getBirthday());

            
            
            string toAsh = to_string(ashName%1000000) + to_string(ashFirstName%100000) + to_string(ashDate%1000000);
            return std::hash<string>()(toAsh);
            */
            size_t toHash = 23;
            toHash = 31 * toHash + hash<string>()(d.getName());
            toHash = 31 * toHash + hash<string>()(d.getFirstname());
            toHash = 31 * toHash + hash<string>()(d.getGender());
            toHash = 31 * toHash + hash<string>()(d.getBirthday());
            return hashval;
             
        }
    };
}

#endif /* DirectoryWithoutAVS_h */
