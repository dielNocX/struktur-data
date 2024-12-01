#include <iostream>
#include <string>

using namespace std;

struct elm_startup;
struct elm_investor;
struct elm_relation;

typedef elm_startup *adr_startup;
typedef elm_investor *adr_investor;
typedef elm_relation *adr_relation;

struct startup {
    int id_startup;
    string nama_startup;
    string bidang_startup;
};

struct elm_startup {
    startup info;
    adr_startup Next;
};

struct investor {
    int id_investor;
    string nama_investor;
    double investmentAmount;
};

struct elm_investor {
    investor info;
    adr_investor Next;
};

struct relation {
    adr_relation Next;
};

struct elm_relation {
    adr_investor investor;
    adr_startup startup;
    adr_relation Next;
};

struct mll {
    adr_investor FirstInvestor;
    adr_startup FirstStartup;
    adr_relation FirstRelation;
};


#define Nil nullptr
#define FirstInvestor(L) ((L).FirstInvestor)
#define nextInvestor(p) (p->Next)
#define infoInvestor(p) (p->info)
#define nextStartup(c) (c->Next)
#define infoStartup(c) (c->info)
#define FirstRelation(L) ((L).FirstRelation)
#define Investor(R) ((R)->investor)
#define Startup(R) ((R)->startup)
#define nextRelation(R) ((R)->Next)

adr_investor New_Element_Investor(investor data) {
    adr_investor elmBaru = new elm_investor;
    infoInvestor(elmBaru) = data;
    nextInvestor(elmBaru) = Nil;
    return elmBaru;
}

adr_startup New_Element_Startup(startup data) {
    adr_startup elmBaru = new elm_startup;
    infoStartup(elmBaru) = data;
    nextStartup(elmBaru) = Nil;
    return elmBaru;
}


void Create_list(mll& List) {
    FirstInvestor(List) = Nil;
    List.FirstStartup = Nil;
    List.FirstRelation = Nil;
}


void Insert_last_Investor(mll& List, adr_investor I) {
    if (FirstInvestor(List) == Nil) {
        FirstInvestor(List) = I;
    } else {
        adr_investor p = FirstInvestor(List);
        while (nextInvestor(p) != Nil) {
            p = nextInvestor(p);
        }
        nextInvestor(p) = I;
    }
}


void Insert_last_Startup(mll& List, adr_startup S) {
    if (List.FirstStartup == Nil) {
        List.FirstStartup = S;
    } else {
        adr_startup p = List.FirstStartup;
        while (nextStartup(p) != Nil) {
            p = nextStartup(p);
        }
        nextStartup(p) = S;
    }
}

/* Function to insert relation
void Insert_relation(mll& List, adr_investor I, adr_startup S) {
    adr_relation R = new elm_relation;
    Investor(R) = I; //
    Investor(R) = I; // Set the investor using the macro
    Startup(R) = S;  // Set the startup using the macro
    nextRelation(R) = Nil; // Initialize the next pointer to Nil


    if (FirstRelation(List) == Nil) {
        FirstRelation(List) = R; // If it's the first relation, set it as the first
    } else {
        adr_relation p = FirstRelation(List);
        while (nextRelation(p) != Nil) {
            p = nextRelation(p); // Traverse to the end of the list
        }
        nextRelation(p) = R; // Link the new relation at the end
    }
}*/
adr_relation New_Element_Relation(adr_investor I, adr_startup S) {
    adr_relation R = new elm_relation;
    Investor(R) = I;
    Startup(R) = S;
    nextRelation(R) = Nil;
    return R;
}

void Insert_relation(mll& List, adr_investor I, adr_startup S) {
    adr_relation R = New_Element_Relation(I, S);

    if (FirstRelation(List) == Nil) {
        FirstRelation(List) = R;
    } else {
        adr_relation p = FirstRelation(List);
        while (nextRelation(p) != Nil) {
            p = nextRelation(p);
        }
        nextRelation(p) = R;
    }
}

void Show_All_Investors(mll List) {
    adr_investor p = FirstInvestor(List);
    while (p != Nil) {
        cout << "ID Investor: " << p->info.id_investor
             << ", Nama: " << p->info.nama_investor
             << ", Investment Amount: " << p->info.investmentAmount << endl;
        p = nextInvestor(p);
    }
}

void Show_All_Startups(mll List) {
    adr_startup p = List.FirstStartup;
    while (p != Nil) {
        cout << "ID Startup: " << p->info.id_startup
             << ", Nama: " << p->info.nama_startup
             << ", Bidang: " << p->info.bidang_startup << endl;
        p = nextStartup(p);
    }
}

void Show_All_Relations(mll List) {
    adr_relation p = FirstRelation(List);
    while (p != Nil) {
        cout << "Investor: " << infoInvestor(Investor(p)).nama_investor
             << " is related to Startup: " << infoStartup(Startup(p)).nama_startup << endl;
        p = nextRelation(p);
    }
}

int main() {
    mll list;
    Create_list(list);

    adr_investor investor1 = New_Element_Investor({1, "Alex", 1000000000.0});
    adr_investor investor2 = New_Element_Investor({2, "Brody", 2000000000.0});
    adr_investor investor3 = New_Element_Investor({3, "Charlie", 1500000000.0});

    Insert_last_Investor(list, investor1);
    Insert_last_Investor(list, investor2);
    Insert_last_Investor(list, investor3);

    adr_startup startup1 = New_Element_Startup({1, "Enfidya", "Technology"});
    adr_startup startup2 = New_Element_Startup({2, "Gopei", "Finance"});
    adr_startup startup3 = New_Element_Startup({3, "Haidokter", "Health"});

    Insert_last_Startup(list, startup1);
    Insert_last_Startup(list, startup2);
    Insert_last_Startup(list, startup3);

    Insert_relation(list, investor1, startup1);
    Insert_relation(list, investor2, startup2);
    Insert_relation(list, investor3, startup3);
    Insert_relation(list, investor1, startup2);

    cout << "List of Investors:" << endl;
    Show_All_Investors(list);
    cout << endl;

    cout << "List of Startups:" << endl;
    Show_All_Startups(list);
    cout << endl;

    cout << "Relations between Investors and Startups:" << endl;
    Show_All_Relations(list);

    return 0;
}
