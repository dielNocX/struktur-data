#include "MLL.h"

void menuGlobal(mll &List){
    cout << endl;
    cout << "OO============================OO" << endl;
    cout << "||            MENU            ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "|| 1. Investor                ||" << endl;
    cout << "|| 2. Startup                 ||" << endl;
    cout << "|| 3. Relation                ||" << endl;
    cout << "|| 0. Exit                    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "Masukkan inputan (0/3): ";
    int opsi;
    cin >> opsi;

    if (opsi == 1){
        menuInvestor(List);
    } else if (opsi == 2){
        menuStartup(List);
    } else if (opsi == 3){
        menuRelation(List);
    }
}

void menuInvestor(mll &List) {
    cout << endl;
    cout << "OO============================OO" << endl;
    cout << "||        MENU INVESTOR       ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "|| 1. Insert data Investor    ||" << endl;
    cout << "|| 2. Delete data Investor    ||" << endl;
    cout << "|| 3. Search data Investor    ||" << endl;
    cout << "|| 4. Show data Investor      ||" << endl;
    cout << "|| 0. Back                    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "Masukkan inputan (0/4): ";
    int opsi;
    cin >> opsi;
    switch (opsi){
        case 0:
            menuGlobal(List);
            break;
        case 1: {
            menuInvestInsert(List);
            break;
        }
        case 2: {
            cout << endl;
            string nama;
            cout << "Masukkan nama investor yang ingin dihapus: ";
            cin >> nama;
            adrInvestor I, Prec;
            I = searchInvestor(List, nama);
            if (I != Nil){
                if (I == FirstInvestor(List)){
                    deleteFirstInvestor(List, I);
                } else {
                    Prec = FirstInvestor(List);
                    while (nextInvestor(Prec) != I){
                        Prec = nextInvestor(Prec);
                    }
                    if (nextInvestor(I) == Nil){
                        deleteLastInvestor(List, I);
                    } else {
                        deleteAfterInvestor(List, Prec, I);
                    }
                }
                cout << "Investor berhasil dihapus" << endl;
            } else {
                cout << "Nama tidak ditemukan" << endl;
            }
            menuInvestor(List);
            break;

        }
        case 3: {
            string nama;
            cout << "Masukkan nama investor yang ingin dicari: ";
            cin >> nama;
            adrInvestor ketemu = searchInvestor(List, nama);
            if (ketemu != Nil){
                cout << "ID : " << infoInvestor(ketemu).nama_investor << endl;
                cout << "Nama : " << infoInvestor(ketemu).nama_investor << endl;
                cout << "Nilai Investasi : " << infoInvestor(ketemu).investmentAmount<< endl;
            } else {
                cout << "Nama tidak ditemukan" << endl;
            }
            menuInvestor(List);
            break;
        }
        case 4:

            showAllInvestor(List);
            menuInvestor(List);
            break;
        default:
            menuInvestor(List);
            break;
    }
}

void menuInvestInsert(mll &List) {
    cout << endl;
    cout << "OO============================OO" << endl;
    cout << "||    MENU INSERT INVESTOR    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "|| 1. Insert First            ||" << endl;
    cout << "|| 2. Insert Last             ||" << endl;
    cout << "|| 0. Back                    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "Masukkan inputan (0/2): ";
    int opsi;
    cin >> opsi;
    //createListInvestor(List);
    if (opsi == 0){

        menuInvestor(List);
    } else if (opsi == 1){
        int n, i = 0;
        investor X;
        cout << "Berapa data investor yang ingin anda masukkan: ";
        cin >> n;
        cout << "OO============================OO" << endl;
        while (i < n){
            cout << "ID                : ";
            cin >> X.id_investor;
            cout << "Nama              : ";
            cin >> X.nama_investor;
            cout << "Investment Amount : ";
            cin >> X.investmentAmount;
            cout << "OO============================OO" << endl;
            i++;

            adrInvestor Y = newElementInvestor(X);
            insertFirstInvestor(List, Y);
            //showAllInvestor(List);

        }
        menuInvestInsert(List);

    } else if (opsi == 2){
        int n, i = 0;
        investor X;
        cout << "Berapa data investor yang ingin anda masukkan: ";
        cin >> n;
        cout << "OO============================OO" << endl;
        while (i < n){
            cout << "ID                : ";
            cin >> X.id_investor;
            cout << "Nama              : ";
            cin >> X.nama_investor;
            cout << "Investment Amount : ";
            cin >> X.investmentAmount;
            cout << "OO============================OO" << endl;
            i++;
            adrInvestor Y = newElementInvestor(X);
        insertLastInvestor(List, Y);

        }
        menuInvestInsert(List);

    } else {
        menuInvestInsert(List);
    }
}

void menuStartup(mll &List) {
    cout << endl;
    cout << "OO============================OO" << endl;
    cout << "||        MENU STARTUP        ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "|| 1. Insert data Startup     ||" << endl;
    cout << "|| 2. Delete data Startup     ||" << endl;
    cout << "|| 3. Search data Startup     ||" << endl;
    cout << "|| 4. Show data Startup       ||" << endl;
    cout << "|| 0. Back                    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "Masukkan inputan (0/4): ";
    int opsi;
    cin >> opsi;
    switch (opsi){
        case 0:
            menuGlobal(List);
            break;
        case 1: {
            int n, i = 0;
            startup X;
            cout << "Berapa data startup yang ingin anda masukkan: ";
            cin >> n;
            while (i < n){
                cout << "ID                : ";
                cin >> X.id_startup;
                cout << "Nama              : ";
                cin >> X.nama_startup;
                cout << "Bidang            : ";
                cin >> X.bidang_startup;
                i++;
                adrStartup Y = newElementStartup(X);
                insertLastStartup(List, Y);
            }
            menuStartup(List);
            break;
        }
        case 2: {
            string nama;
            cout << "Masukkan nama startup yang ingin dihapus: ";
            cin >> nama;
            adrStartup S, Prec;
            S = searchStartup(List, nama);
            if (S != Nil){
                deleteStartup(List, S);
                cout << "Startup berhasil dihapus" << endl;

            } else {
                cout << "Nama tidak ditemukan" << endl;
            }

            menuStartup(List);
            break;
        }
        case 3: {
            string nama;
            cout << "Masukkan nama startup yang ingin dicari: ";
            cin >> nama;
            adrStartup ketemu = searchStartup(List, nama);
            if (ketemu != Nil){
                cout << "ID : " << infoStartup(ketemu).id_startup << endl;
                cout << "Nama : " << infoStartup(ketemu).nama_startup << endl;
                cout << "Bidang : " << infoStartup(ketemu).bidang_startup << endl;
            } else {
                cout << "Nama tidak ditemukan" << endl;
            }

            menuStartup(List);
            break;
        }
        case 4:
            showAllStartup(List);
            menuStartup(List);
            break;
        default:
            menuStartup(List);
            break;
    }
}

void menuRelation(mll &List) {
    cout << endl;
    cout << "OO============================OO" << endl;
    cout << "||  MENU INVETASI (RELATION)  ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "|| 1. Insert data Investasi   ||" << endl;
    cout << "|| 2. Show data Investasi     ||" << endl;
    cout << "|| 3. Delete data Investasi   ||" << endl;
    cout << "|| 4. Search data Investasi   ||" << endl;
    cout << "|| 0. Back                    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "Masukkan inputan (0/2): ";
    int opsi;
    cin >> opsi;
    adrInvestor I;
    adrStartup S;
    string inv, sta;
    switch (opsi){
        case 0:
            menuGlobal(List);
            break;
        case 1:
            cout << "Investor \t:";
            cin >>inv;

            cout << "Startup \t:";
            cin >>sta;
            I = searchInvestor(List, inv);
            S =searchStartup(List, sta);
            if (I == Nil){
                cout << "Investor tidak ditemukan"<<endl;
            } else if (S == Nil){
                cout << "Startup tidak ditemukan"<<endl;
            } else if (searchRelation(List, I, S)==Nil){
                insertRelation(List, I , S);
                cout << "Relasi ditambahkan"<<endl;
            } else {
                cout << "Relasi sudah ada"<<endl;
            }
            menuRelation(List);
            break;
        case 2:
            menuRelationShow(List);
            break;
        case 3:
            cout << "Investor \t:";
            cin >>inv;

            cout << "Startup \t:";
            cin >>sta;
            I = searchInvestor(List, inv);
            S = searchStartup(List, sta);
            if (I == Nil){
                cout << "Investor tidak ditemukan"<<endl;
            } else if (S == Nil){
                cout << "Startup tidak ditemukan"<<endl;
            } else if (searchRelation(List, I, S)==Nil){
                cout << "Relasi tidak ada"<<endl;
            } else {
                deleteOneRelation(List, searchRelation(List, I, S));
            }
            menuRelation(List);
            break;
        case 4:
            cout << "Investor \t:";
            cin >>inv;
            cout << "Startup \t:";
            cin >>sta;
            I = searchInvestor(List, inv);
            S = searchStartup(List, sta);
            if (I == Nil){
                cout << "Investor tidak ditemukan"<<endl;
            } else if (S == Nil){
                cout << "Startup tidak ditemukan"<<endl;
            } else if (searchRelation(List, I, S)==Nil){
                cout << "Investasi tidak ditemukan"<<endl;
                cout << infoInvestor(I).nama_investor <<" tidak berinvestasi pada startup "<<infoStartup(S).nama_startup<<endl;
            } else {
                cout << "Investasi ditemukan"<<endl;
                cout << infoInvestor(I).nama_investor <<" berinvestasi pada startup "<<infoStartup(S).nama_startup<<" ("<<infoStartup(S).bidang_startup<<")"<<endl;
            }
            menuRelation(List);
            break;
        default:
            menuRelation(List);
            break;
    }
}

void menuRelationShow(mll &List) {
    cout << endl;
    cout << "OO============================OO" << endl;
    cout << "||     MENU SHOW INVETASI     ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "|| 1. Show Semua Investasi    ||" << endl;
    cout << "|| 2. Show Investasi Investor ||" << endl;
    cout << "|| 3. Show Investasi Startup  ||" << endl;
    cout << "|| 0. Back                    ||" << endl;
    cout << "OO============================OO" << endl;
    cout << "Masukkan inputan (0/2): ";
    int opsi;
    string inp;

    cin >> opsi;
    if (opsi == 0){
        menuRelation(List);
    } else if (opsi == 1){
        showAllRelation(List);
        menuRelation(List);
    } else if (opsi == 2) {

        cout <<"Investor :";
        cin >> inp;
        adrInvestor I = searchInvestor(List,inp);
        if (I != Nil){
          showInvestorRelation(List, I);
        } else {
          cout<<"Investor Tidak Ditemukan!"<<endl;
        }
        menuRelation(List);

    } else if (opsi == 3){
      cout <<"Startup :";
        cin >> inp;
        adrStartup S = searchStartup(List,inp);
        if (S != Nil){
          showStartupRelation(List, S);
        } else {
          cout<<"Startup Tidak Ditemukan!"<<endl;
        }
        menuRelation(List);

    } else {
        menuRelation(List);
    }
}
