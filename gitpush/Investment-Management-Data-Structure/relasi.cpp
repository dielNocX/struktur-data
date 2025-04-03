#include "MLL.h"

adrRelation newElementRelation(adrInvestor I, adrStartup S) {
  // Mengembalikan alamat elemen relasi baru yang menghubungkan investor dan startup.

    adrRelation R = new elmRelation;

    Investor(R) = I;

    Startup(R) = S;
    nextRelation(R) = Nil;
    return R;
}

void createListRelation(mll& List) {
 // I.S. : List belum terbentuk.
 // F.S. : List diinisialisasi dengan elemen pertama sebagai Nil.
    FirstRelation(List) = Nil;
}

void insertRelation(mll& List, adrInvestor I, adrStartup S) {
    // I.S. : list relasi yang mungkin kosong.
    // F.S. : Data relasi antara investor I dan startup S ditambahkan ke dalam list relasi.

    if (I != Nil && S != Nil){
        adrRelation R = newElementRelation(I, S);

        if (FirstRelation(List) == Nil) {
            FirstRelation(List) = R;
        } else {
            adrRelation p = FirstRelation(List);
            while (nextRelation(p) != Nil) {
                p = nextRelation(p);
            }
            nextRelation(p) = R;
        }
    }
}



void showAllRelation(mll List) {
    // I.S. : list relasi yang mungkin tidak kosong.
    // F.S. : Menampilkan semua relasi antara investor dan startup yang ada dalam list.

    adrRelation p = FirstRelation(List);
    while (p != Nil) {
        cout << "Investor: " << infoInvestor(Investor(p)).nama_investor
             << " is invested on: " << infoStartup(Startup(p)).nama_startup << endl;
        p = nextRelation(p);
    }

}

void showInvestorRelation(mll List, adrInvestor I) {
    // I.S. : list relasi yang mungkin tidak kosong.
    // F.S. : Menampilkan semua relasi antara investor dan startup yang ada dalam list.

    adrRelation p = FirstRelation(List);
    while (p != Nil) {
        if (Investor(p) == I){
        cout << "Investor: " << infoInvestor(Investor(p)).nama_investor
             << " is invested on: " << infoStartup(Startup(p)).nama_startup << endl;

        }
        p = nextRelation(p);
    }

}

void showStartupRelation(mll List, adrStartup S) {
    // I.S. : list relasi yang mungkin tidak kosong.
    // F.S. : Menampilkan semua relasi antara investor dan startup yang ada dalam list.

    adrRelation p = FirstRelation(List);
    while (p != Nil) {
        if (Startup(p) == S){
        cout << "Investor: " << infoInvestor(Investor(p)).nama_investor
             << " is invested on: " << infoStartup(Startup(p)).nama_startup << endl;
        }
        p = nextRelation(p);
    }

}


adrRelation searchRelation(mll &List, adrInvestor I, adrStartup S){
    adrRelation R = FirstRelation(List);
    while (R != Nil && (Startup(R) != S || Investor(R) != I) ) {
      R = nextRelation(R);
    }
    return R;

}

void deleteOneRelation(mll &List, adrRelation I){

  adrRelation temp;
  if (I != Nil) {
    if (nextRelation(I)==Nil){
      deleteLastRelation(List, temp);
    } else if (I == FirstRelation(List)) {
      deleteFirstRelation(List, temp);
    } else {
      adrRelation cur = FirstRelation(List);
      while (nextRelation(cur) != I){
        cur = nextRelation(cur);
      }
      deleteAfterRelation(List, cur, temp);
    }
    cout << "Delete berhasil"<<'\n';
  }

}




void deleteRelationInvestor(mll &List, adrInvestor I) {
    adrRelation temp = Nil;
    adrRelation R = FirstRelation(List);

    while (R != Nil && Investor(R) == I) {
        deleteFirstRelation(List, temp);
        R = FirstRelation(List);
    }


    adrRelation prev = Nil;
    while (R != Nil) {
        if (Investor(R) == I) {

            deleteAfterRelation(List, prev, temp);
            R = nextRelation(prev);
        } else {
            prev = R;
            R = nextRelation(R);
        }
    }
}

void deleteRelationStartup(mll &List, adrStartup I) {
    adrRelation temp = Nil;
    adrRelation R = FirstRelation(List);

    while (R != Nil && Startup(R) == I) {
        deleteFirstRelation(List, temp);
        R = FirstRelation(List);
    }


    adrRelation prev = Nil;
    while (R != Nil) {
        if (Startup(R) == I) {

            deleteAfterRelation(List, prev, temp);
            R = nextRelation(prev);
        } else {
            prev = R;
            R = nextRelation(R);
        }
    }
}



void deleteFirstRelation(mll& List, adrRelation& I){

    if (FirstRelation(List) != Nil){

      I = FirstRelation(List);
      if (nextRelation(I) != Nil){
        FirstRelation(List) = nextRelation(I);
        nextRelation(I) = Nil;
      } else {
        FirstRelation(List) = Nil;
      }
    }
};

void deleteAfterRelation(mll& List, adrRelation Prec, adrRelation& I){

    if (Prec != Nil){
      I = nextRelation(Prec);
      nextRelation(Prec) = nextRelation(I);
      nextRelation(I) = Nil;
    }
};

void deleteLastRelation(mll& List, adrRelation& I){

    if (FirstRelation(List) != Nil){


      I = FirstRelation(List);
      if (nextRelation(I) == Nil){
        FirstRelation(List) = Nil;
      }else{

        while (nextRelation(nextRelation(I)) != Nil){
            I = nextRelation(I);
        }
        nextRelation(I) = Nil;
      }
    }
};
