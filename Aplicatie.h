////
//// Created by Cristi on 5/20/2021.
////
//Scraped Idea

//#ifndef SKIPLISTPROJECT_APLICATIE_H
//#define SKIPLISTPROJECT_APLICATIE_H
//#include <ctime>
//#include "SkipList.h"
//#include <map>
//
//using namespace std;
//    enum Comenzi{Adauga,Sterge,Succesor,Predecesor,Afiseaza,Exit};
//template<typename T> struct map_init_helper
//{
//    T& data;
//    map_init_helper(T& d) : data(d) {}
//    map_init_helper& operator() (typename T::key_type const& key, typename T::mapped_type const& value)
//    {
//        data[key] = value;
//        return *this;
//    }
//};
//
//template<typename T> map_init_helper<T> map_init(T& item)
//{
//    return map_init_helper<T>(item);
//}
//class Aplicatie {
//private:
//    map<Comenzi,string> meniuAfis;
//    Aplicatie * instanta;
//    Aplicatie(int val){
//        SkipList lst(val, 0.60);
//        srand((unsigned)time(0));
//        map_init(meniuAfis)
//                (Adauga, "Adauga un numar natural in Skip List")
//                (Sterge, "Sterge un numar din Skip List")
//                (Succesor, "Afiseaza succesorul unui numar din Skip List")
//                (Predecesor,"Afiseaza predecesorul unui numar din Skip List")
//                (Afiseaza,"Afiseaza intreg Skip Listul")
//                (Exit,"Iesi din aplicatie");
//    }
//public:
//      Aplicatie* getStarted(){
//        if(instanta==NULL)
//        {   cout<<"Cate nivele poate avea maxim Skip Listul?";
//            int val;
//            cin>>val;
//            instanta= new Aplicatie(val);
//        }
//        return instanta;
//    }
//    void optiuni(){
//        for(auto i : meniuAfis){
//            cout<<i.first<<" "<<i.second;
//        }
//    }
//};
//
//
//#endif //SKIPLISTPROJECT_APLICATIE_H
