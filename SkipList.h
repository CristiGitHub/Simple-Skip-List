//
// Created by Cristi on 5/19/2021.
//

#ifndef SKIPLISTPROJECT_SKIPLIST_H
#define SKIPLISTPROJECT_SKIPLIST_H


#include <memory.h>
#include "Node.h"
#include <iostream>
using namespace std;

class SkipList {
private:
    int MaxLevel;
    float fract;
    int nivel;
    Node *begin;
public:
    SkipList(int nivelMaxim , float fra){
        MaxLevel=nivelMaxim;
        fract=fra;
        nivel=0;
        begin = new Node(-1, nivelMaxim);
    }
    int Randomizer(){
        float ran = (float)rand()/RAND_MAX;
        int lvl = 0 ;
         while(ran < fract && lvl < MaxLevel)
         {
             lvl++;
             ran=(float)rand()/RAND_MAX;
         }
         return lvl;
    }
    Node* createNode(int val , int nivel)
    {
        Node *x = new Node(val,nivel);
        return x;
    }
    void insert(int val){
        Node* curent = begin;
        Node* update[MaxLevel+1];
        memset(update,0 , sizeof(Node*)*(MaxLevel+1));
        for(int i = nivel ; i>= 0 ; --i)
        {
            while(curent->next[i] != NULL && curent->next[i]->getVal() < val)
                curent = curent->next[i];
            update[i]=curent;
        }
        curent = curent->next[0];
        if( curent == NULL || curent->getVal() != val)
        {
            int auxNivel = Randomizer();
            if(auxNivel > nivel)
            {
                for(int i=nivel+1 ; i < auxNivel ; ++i)
                    update[i]=begin;
                nivel = auxNivel;
            }
            Node *n =createNode(val,auxNivel);
            for(int i = 0 ; i <= auxNivel ; ++i)
            {
                    if(update[i]!= NULL ) {
                        n->next[i] = update[i]->next[i];
                        update[i]->next[i] = n;
                    }
            }
        }
    }
    void sterge(int val){
        Node *x = begin;
        Node *update[MaxLevel+1];
        memset(update,0,sizeof(Node*)*(MaxLevel+1));
        for(int i = nivel ; i >= 0 ; --i)
        {
            while(x->next[i] !=NULL && x->next[i]->getVal() < val){
                x=x->next[i];
            }
            update[i]=x;

        }
        x=x->next[0];
        if(x->getVal() == val)
        {
            for(int i = 0 ; i <= nivel ; ++i)
            {
                if(update[i]->next[i] != x)
                    break;
                update[i]->next[i]=x->next[i];
            }
            delete x;
            while(nivel > 0 && begin->next[nivel] == NULL)
            {
                nivel--;
            }
        }
    }
    void succesor(int val){
        Node *x = begin;
        for(int i = nivel ; i >= 0 ; --i)
        {
            while(x->next[i] !=NULL && x->next[i]->getVal() < val){
                x=x->next[i];
            }
        }
        x=x->next[0];
        if(x->getVal()==val && x->next[0]!=NULL)
            cout<<"Succesorul lui "<<val<<" este "<<x->next[0]->getVal()<<'\n';


    }
    void predecesor(int val){
        Node *x = begin;
        for(int i = nivel ; i >= 0 ; --i)
        {
            while(x->next[i] !=NULL && x->next[i]->getVal() < val){
                x=x->next[i];
            }
        }
        if(x != NULL && x->next[0]->getVal() == val)
            cout<<"Predecesorul lui "<<val<<" este "<<x->getVal()<<'\n';

    }

   friend ostream &operator<<(ostream& os , const SkipList * lista){
        for(int i = 0 ; i <= lista->nivel ; ++i)
        {
            Node *nod = lista->begin;
            if(nod->next[i]!=NULL)
                os<<"Nivelul "<<i<<": ";
            while(nod != NULL){
                if(nod->getVal()!=-1)
                os<<nod->getVal()<<" ";
                nod=nod->next[i];
            }
            cout<<endl;
        }
    }

};


#endif //SKIPLISTPROJECT_SKIPLIST_H
