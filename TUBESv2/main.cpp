#include "MLL.h"


int main() {
    mll list;
    Create_list(list);

    adr_investor investor1 = New_Element_Investor({1, "Alex", 1000000000});
    adr_investor investor2 = New_Element_Investor({2, "Brody", 2000000000});
    adr_investor investor3 = New_Element_Investor({3, "Charlie", 1500000000});

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

    cout << "Investment:" << endl;
    Show_All_Relations(list);

    return 0;
}
