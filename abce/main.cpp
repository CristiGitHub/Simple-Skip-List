#include <fstream>
#include <memory.h>
#include <cmath>

#define fn "abce."
using namespace std;
ifstream f(fn"in");
ofstream g(fn"out");
class Node {
private:
    int val;
public:
    Node **next;
    Node(int valoare, int nivel){
        val=valoare;
        next = new Node*[nivel+1];
        memset(next,0,sizeof(Node*)*(nivel+1));
    }

    int getVal() const {
        return val;
    }

    void setVal(int val) {
        Node::val = val;
    }

};

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
            g<<x->getVal()<<'\n';


    }
    void predecesor(int val){
        Node *x = begin;
        for(int i = nivel ; i >= 0 ; --i)
        {
            while(x->next[i] !=NULL && x->next[i]->getVal() <= val){
                x=x->next[i];
            }
        }
            g<<x->getVal()<<'\n';

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
            g<<endl;
        }
    }

    void contine(int val) {
        Node *x = begin;
        for (int i = nivel; i >= 0; --i) {
            while (x->next[i] != NULL && x->next[i]->getVal() < val) {
                x = x->next[i];
            }
        }
        x = x->next[0];
        if(x!=NULL && x->getVal() == val)
            g<<1;
        else
            g<<0;
        g<<'\n';
    }

    void interval(int val1,int val2) {
        Node *x = begin;
        for (int i = nivel; i >= 0; --i) {
            while (x->next[i] != NULL && x->next[i]->getVal() < val1) {
                x = x->next[i];
            }
        }
        while (x->next[0] != NULL && x->next[0]->getVal() >= val1 && x->next[0]->getVal() <= val2) {
            x = x->next[0];
            g << x->getVal() << " ";
        }
        g << '\n';
    }
};


int n,x,y,z;
int main() {
    f>>n;
    SkipList lst(round(sqrt(n)),0.5);
    for(int i = 0 ; i < n ; ++i)
    {
        f>>x>>y;
        if(x==1)
            lst.insert(y);
        else
            if(x==2)
                lst.sterge(y);
            else
                if(x==3)
                    lst.contine(y);
                    else
                        if(x==4)
                            lst.predecesor(y);
                        else
                            if(x==5)
                                lst.succesor(y);
                            if(x==6)
                            {
                                f>>z;
                                lst.interval(y,z);
                            }
    }

    return 0;
}
