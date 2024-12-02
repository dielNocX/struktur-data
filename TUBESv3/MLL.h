#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct elm_startup *adr_startup;
typedef struct elm_investor *adr_investor;
typedef struct elm_relation *adr_relation;

struct startup {
    int id_startup;
    string nama_startup;
    string bidang_startup;
};

struct elm_startup {
    startup info;
    adr_startup Next, Prev;
};

struct investor {
    int id_investor;
    string nama_investor;
    int investmentAmount;
};

struct elm_investor {
    investor info;
    adr_investor Next;
};


struct elm_relation {
    adr_investor investor;
    adr_startup startup;
    adr_relation Next, Prev;
};

struct mll {
    adr_investor FirstInvestor;
    adr_startup FirstStartup;
    adr_relation FirstRelation;
    adr_startup LastStartup;
    adr_relation LastRelation;


};


#define Nil nullptr
#define FirstInvestor(L) ((L).FirstInvestor)
#define FirstStartup(L) ((L).FirstStartup)
#define LastStartup(L) ((L).LastStartup)
#define nextInvestor(p) (p->Next)
#define infoInvestor(p) (p->info)
#define nextStartup(c) (c->Next)
#define prevStartup(c) (c->Prev)
#define infoStartup(c) (c->info)
#define FirstRelation(L) ((L).FirstRelation)
#define LastRelation(L) ((L).LastRelation)
#define Investor(R) ((R)->investor)
#define Startup(R) ((R)->startup)
#define nextRelation(R) ((R)->Next)
#define prevRelation(R) ((R)->Prev)




adr_investor New_Element_Investor(investor data) ;

adr_startup New_Element_Startup(startup data) ;


void Create_list(mll& List) ;
void Insert_last_Investor(mll& List, adr_investor I) ;


void Insert_last_Startup(mll& List, adr_startup S) ;

adr_relation New_Element_Relation(adr_investor I, adr_startup S) ;

void Insert_relation(mll& List, adr_investor I, adr_startup S) ;
void Show_All_Investors(mll List) ;

void Show_All_Startups(mll List) ;

void Show_All_Relations(mll List) ;

adr_startup search_startup(mll L, string nama) ;

adr_investor search_investor(mll L, string nama) ;

#endif // MLL_H_INCLUDED
