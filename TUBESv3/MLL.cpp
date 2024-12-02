#include "MLL.h"


adr_investor New_Element_Investor(investor data) {
// Mengembalikan alamat elemen investor baru yang berisi data yang diberikan.
    adr_investor elmBaru = new elm_investor;
    infoInvestor(elmBaru) = data;
    nextInvestor(elmBaru) = Nil;
    return elmBaru;
}

adr_startup New_Element_Startup(startup data) {
// Mengembalikan alamat elemen startup baru yang berisi data yang diberikan.
    adr_startup elmBaru = new elm_startup;
    infoStartup(elmBaru) = data;
    nextStartup(elmBaru) = Nil;
    return elmBaru;
}


void Create_list(mll& List) {
 // I.S. : List belum terbentuk.
 // F.S. : List diinisialisasi dengan elemen pertama sebagai Nil.
    FirstInvestor(List) = Nil;
    FirstStartup(List) = Nil;
    FirstRelation(List) = Nil;
}


void Insert_last_Investor(mll& List, adr_investor I) {
// I.S. : list investor yang mungkin kosong.
// F.S. : Data investor I menjadi elemen terakhir dalam list investor.
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

void Insert_first_Investor(mll& List, adr_investor I) {
// I.S. : list investor yang mungkin kosong.
// F.S. : Data investor I menjadi elemen terakhir dalam list investor.
    if (FirstInvestor(List) == Nil) {
        FirstInvestor(List) = I;
    } else {
        nextInvestor(I) = FirstInvestor(List);
        FirstInvestor(List) = I;

    }
}


void Insert_last_Startup(mll& List, adr_startup S) {
// I.S. : Terdefinisi dengan kondisi list startup yang mungkin kosong.
// F.S. : Data startup S menjadi elemen terakhir dalam list startup.
    /*if (FirstStartup(List) == Nil) {
        FirstStartup(List) = S;
    } else {
        adr_startup p = FirstStartup(List);
        while (nextStartup(p) != Nil) {
            p = nextStartup(p);
        }
        nextStartup(p) = S;
    }*/

    if (FirstStartup(List) == Nil) {
        FirstStartup(List) = S;
        LastStartup(List) = S;

    } else {
        prevStartup(S) = LastStartup(List);
        nextStartup(LastStartup(List)) = S;
        LastStartup(List) = S;

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
  // Mengembalikan alamat elemen relasi baru yang menghubungkan investor dan startup.

    adr_relation R = new elm_relation;

    Investor(R) = I;

    Startup(R) = S;
    nextRelation(R) = Nil;
    return R;
}

void Insert_relation(mll& List, adr_investor I, adr_startup S) {
    // I.S. : list relasi yang mungkin kosong.
    // F.S. : Data relasi antara investor I dan startup S ditambahkan ke dalam list relasi.
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
    // I.S. : list investor yang mungkin tidak kosong.
    // F.S. : Menampilkan semua data investor yang ada dalam list.

    adr_investor p = FirstInvestor(List);
    while (p != Nil) {
        cout << "ID Investor: " << infoInvestor(p).id_investor
             << ", Nama: " << infoInvestor(p).nama_investor
             << ", Investment Amount: " << infoInvestor(p).investmentAmount << endl;
        p = nextInvestor(p);
    }
}

void Show_All_Startups(mll List) {
    // I.S. : list startup yang mungkin tidak kosong.
    // F.S. : Menampilkan semua data startup yang ada dalam list.
    adr_startup p = FirstStartup(List);
    while (p != Nil) {
        cout << "ID Startup: " << infoStartup(p).id_startup
             << ", Nama: " << infoStartup(p).nama_startup
             << ", Bidang: " << infoStartup(p).bidang_startup << endl;
        p = nextStartup(p);
    }
}

void Show_All_Relations(mll List) {
    // I.S. : list relasi yang mungkin tidak kosong.
    // F.S. : Menampilkan semua relasi antara investor dan startup yang ada dalam list.

    adr_relation p = FirstRelation(List);
    while (p != Nil) {
        cout << "Investor: " << infoInvestor(Investor(p)).nama_investor
             << " is invested on: " << infoStartup(Startup(p)).nama_startup << endl;
        p = nextRelation(p);
    }
}

adr_startup search_startup(mll L, string nama) {
    adr_startup cur;
    cur = FirstStartup(L);
    while (cur != Nil && infoStartup(cur ).nama_startup != nama) {
      cur = nextStartup(cur);
    }

    return cur;

 }


 adr_investor search_investor(mll L, string nama) {
    adr_investor cur;
    cur = FirstInvestor(L);
    while (cur != Nil && infoInvestor(cur ).nama_investor!= nama) {
      cur = nextInvestor(cur);
    }

    return cur;
 }




/*
TO DO:
-Delete
-Search address
-konversi DLL startup
-Menu
-Fungsi input data

*/
