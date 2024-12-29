#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include "angajat.h"
#include "manager.h"
#include "operatorr.h"
#include "asistent.h"
#include "articol_vestimentar.h"
#include "disc.h"
#include "disc_vintage.h"
#pragma once

using namespace std;
template <typename T>
class gestiune 
{
    vector<T> entitati;

    public:

        template <typename Functor> //folosim functor pentru a putea introduce o functie lambda; T nu merge decat pentru criterii de acelasi tip cu elementele vectorului.
        int numara(Functor criteriu) const 
        {
            return count_if(entitati.begin(), entitati.end(), criteriu);
        }

        void adauga(T entitate) 
        {
            entitati.push_back(entitate);
        }

        T cauta(const string& criteriu, const string& valoare) const 
        {
            auto lambada=[&criteriu, &valoare](const T& element)->bool 
            {
                if constexpr(is_base_of<angajat, typename remove_pointer<T>::type>::value) 
                {
                    if(criteriu=="CNP") 
                        return element->get_cnp()==valoare;
                    else 
                        if(criteriu=="ID")
                            return to_string(element->get_id())==valoare;
                }
                 else 
                    if constexpr(is_base_of<produs, typename remove_pointer<T>::type>::value) 
                    {
                        if(criteriu=="COD")
                        return element->get_cod()==valoare;
                    }
                        return false;
            };

            auto it=find_if(entitati.begin(), entitati.end(), lambada);
            if(it!=entitati.end()) 
                return *it; 
             else 
                throw invalid_argument("Nu exista!");
            
        }

        void sterge(const string& criteriu, const string& valoare) 
        {
            auto lambada=[&criteriu, &valoare](const T& element)->bool 
            {
                if constexpr(is_base_of<angajat, typename remove_pointer<T>::type>::value) 
                {
                    if(criteriu=="CNP") 
                        return element->get_cnp()==valoare;
                    else 
                        if(criteriu=="ID")
                            return to_string(element->get_id())==valoare;
                }
                 else 
                    if constexpr(is_base_of<produs, typename remove_pointer<T>::type>::value) 
                    {
                        if(criteriu=="COD")
                        return element->get_cod()==valoare;
                    }
                        return false;
            };

            auto it=find_if(entitati.begin(), entitati.end(), lambada);

            if (it==entitati.end()) 
            {
                cout << "Niciun element nu a fost găsit cu criteriul specificat.\n";
                return;
            }
            if constexpr(is_base_of<angajat, typename remove_pointer<T>::type>::value) 
            {
                int numar_manageri=numara([](T element)
                {
                    return dynamic_cast<manager*>(element)!=nullptr;
                });

                int numar_operatori=numara([](T element) 
                {
                    return dynamic_cast<operatorr*>(element)!=nullptr;
                });

                int numar_asistenti=numara([](T element) 
                {
                    return dynamic_cast<asistent*>(element)!=nullptr;
                });

                if(dynamic_cast<manager*>(*it) && numar_manageri==1)
                {
                    cout << "NU PUTETI STERGE MANAGERUL! Magazinul trebuie să aibă cel puțin un manager.\n";
                    return;
                } 
                else 
                    if(dynamic_cast<operatorr*>(*it) && numar_operatori==3) 
                    {
                        cout << "NU PUTETI STERGE OPERATORUL! Magazinul trebuie să aibă minim 3 operatori.\n";
                        return;
                    }
                    else 
                        if(dynamic_cast<asistent*>(*it) && numar_asistenti==1) 
                        {
                            cout << "NU PUTETI STERGE ASISTENTUL! Magazinul trebuie să aibă cel puțin un asistent.\n";
                        return;
                        }
            }

            delete *it;
            entitati.erase(it);
            std::cout << "Elementul care respectă criteriul a fost sters!\n";
        }


        void afisare() const 
        {
            for (const auto& entitate:entitati) 
                entitate->afisare();
            
        }

        ~gestiune() 
        {
            for (auto& entitate : entitati) 
                delete entitate;
            entitati.clear();
        }
};
