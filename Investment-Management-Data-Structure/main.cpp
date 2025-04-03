#include "MLL.h"

mll list;

int main()
{
    adrInvestor I;
    adrStartup S;
    createList(list);

    menuGlobal(list);

    // MANUAL
     /*

    adrInvestor investor1 = newElementInvestor({1, "Alex", 1000000000});
    adrInvestor investor2 = newElementInvestor({2, "Brody", 2000000000});
    adrInvestor investor3 = newElementInvestor({3, "Charlie", 1500000000});
    adrInvestor investor4 = newElementInvestor({3, "Daren", 300000000});
    adrInvestor investor5 = newElementInvestor({3, "Elly", 7000000});
    adrInvestor investor6 = newElementInvestor({3, "Frank", 250000000});

    insertLastInvestor(list, investor1);
    insertLastInvestor(list, investor2);
    insertLastInvestor(list, investor3);
    insertLastInvestor(list, investor4);
    insertLastInvestor(list, investor5);
    insertLastInvestor(list, investor6);

    adrStartup startup1 = newElementStartup({1, "AND", "Technology"});
    adrStartup startup2 = newElementStartup({2, "Gopei", "Finance"});
    adrStartup startup3 = newElementStartup({3, "Haidokter", "Health"});
    adrStartup startup4 = newElementStartup({3, "Siawmi", "Technology"});
    adrStartup startup5 = newElementStartup({3, "DCA", "Finance"});
    adrStartup startup6 = newElementStartup({3, "Vesla", "Technology"});

    insertLastStartup(list, startup1);
    insertLastStartup(list, startup2);
    insertLastStartup(list, startup3);
    insertLastStartup(list, startup4);
    insertLastStartup(list, startup5);
    insertLastStartup(list, startup6);

    insertRelation(list, investor1, startup3);
    insertRelation(list, investor1, startup2);
    insertRelation(list, investor2, startup3);
    insertRelation(list, investor1, startup4);
    insertRelation(list, investor3, startup5);
    insertRelation(list, investor2, startup1);
    insertRelation(list, investor4, startup6);
    insertRelation(list, investor5, startup3);
    insertRelation(list, investor6, startup2);
    insertRelation(list, investor3, startup4);
    insertRelation(list, investor4, startup5);
    insertRelation(list, investor5, startup6);
    insertRelation(list, investor6, startup1);
    insertRelation(list, investor1, startup6);
    insertRelation(list, investor2, startup5);
    insertRelation(list, investor3, startup2);
    insertRelation(list, investor4, startup3);
    insertRelation(list, investor5, startup4);
    insertRelation(list, investor6, startup5);
    insertRelation(list, investor1, startup1);


    cout << "List of Investors:" << endl;
    showAllInvestor(list);
    cout << endl;

    cout << "List of Startups:" << endl;
    showAllStartup(list);
    cout << endl;

    cout << "Investment:" << endl;
    showAllRelation(list);
    cout << endl;


    deleteStartup(list, searchStartup(list, "Vesla"));
    cout << "Investment:" << endl;
    showAllRelation(list);
    cout << endl;


    showStartupRelation(list, searchStartup(list, "Haidokter"));
    cout << endl;

    deleteOneRelation(list, searchRelation(list, searchInvestor(list, "Alex"), searchStartup(list, "Haidokter")));

    showStartupRelation(list, searchStartup(list, "Haidokter"));
    cout << endl;
     // */

    return 0;
}

/*
TO DO:
- Menu Relasi (insert 1, search 2, delete 2, show 1, back)
- Debug menu
- ! DONE !
*/
