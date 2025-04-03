#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
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
#include <iostream>
using namespace std;

typedef struct elmStartup *adrStartup;
typedef struct elmInvestor *adrInvestor;
typedef struct elmRelation *adrRelation;


struct startup {
    int id_startup;
    string nama_startup;
    string bidang_startup;
};

struct elmStartup {
    startup info;
    adrStartup Next, Prev;
};

struct investor {
    int id_investor;
    string nama_investor;
    int investmentAmount;
};

struct elmInvestor {
    investor info;
    adrInvestor Next;
};

struct elmRelation {
    adrInvestor investor;
    adrStartup startup;
    adrRelation Next;
};

struct mll {
    adrInvestor FirstInvestor;
    adrStartup FirstStartup;
    adrRelation FirstRelation;
    adrStartup LastStartup;
    adrRelation LastRelation;
};

adrInvestor newElementInvestor(investor data) ;
adrStartup newElementStartup(startup data) ;
adrRelation newElementRelation(adrInvestor I, adrStartup S);


void createListInvestor(mll& List) ;
void createListStartup(mll& List) ;
void createListRelation(mll& List) ;

void insertLastInvestor(mll& List, adrInvestor I) ;
void insertFirstInvestor(mll& List, adrInvestor I);
void insertLastStartup(mll& List, adrStartup S) ;
void insertRelation(mll& List, adrInvestor I, adrStartup S) ;

void deleteInvestor(mll &List, adrInvestor I);
void deleteStartup(mll &List, adrStartup S);
void deleteFirstInvestor(mll& List, adrInvestor& I);
void deleteAfterInvestor(mll& List, adrInvestor Prec, adrInvestor& I);
void deleteLastInvestor(mll& List, adrInvestor& I);
void deleteFirstStartup(mll& List, adrStartup& S);
void deleteAfterStartup(mll& List, adrStartup Prec, adrStartup& S);
void deleteLastStartup(mll& List, adrStartup& S);


void showAllInvestor(mll List) ;
void showAllStartup(mll List) ;
void showAllRelation(mll List) ;


adrStartup searchStartup(mll L, string nama) ;
adrInvestor searchInvestor(mll L, string nama) ;
adrRelation searchRelation(mll &List, adrInvestor I, adrStartup S);

void createList(mll& List);

void menuGlobal(mll &List);
void menuInvestor(mll &List);
void menuInvestInsert(mll &List);
void menuStartup(mll &List);
void menuRelation(mll &List);
void menuRelationShow(mll &List);



//UPDATE V6
void deleteLastRelation(mll& List, adrRelation& I);
void deleteFirstRelation(mll& List, adrRelation& I);
void deleteAfterRelation(mll& List, adrRelation Prec, adrRelation& I);
//delete biasa


void deleteRelationInvestor(mll &List, adrInvestor I); //delete semua relasi dengan Investor "A"
void deleteRelationStartup(mll &List, adrStartup I);  //delete semua relasi dengan Startup "A"
void deleteOneRelation(mll &List, adrRelation I); //delete  relasi dengan Startup "X"dan Investor "Y"

void showStartupRelation(mll List, adrStartup S); //show relasi milik startup "A"
void showInvestorRelation(mll List, adrInvestor I); //show relasi milik investor "A"

#endif // MLL_H_INCLUDED
