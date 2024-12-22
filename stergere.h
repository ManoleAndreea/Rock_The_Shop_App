#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class stergere 
{
    string criteriu; 
    string valoare;   

    public:
        stergere(const string&, const string&);


        template <typename T>
        bool operator()(const T* element) const 
        {
            if(criteriu=="CNP") 
                return element->get_cnp()==valoare;
            else 
                if(criteriu=="ID")
                {
                    int id_valoare=stoi(valoare);
                    return element->get_id() == id_valoare;
               
                }
                  
                    
                return false;
            }
                
        };
