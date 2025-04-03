#include "MLL.h"

adrInvestor newElementInvestor(investor data) {
// Mengembalikan alamat elemen investor baru yang berisi data yang diberikan.
    adrInvestor elmBaru = new elmInvestor;
    infoInvestor(elmBaru) = data;
    nextInvestor(elmBaru) = Nil;
    return elmBaru;
}


void createListInvestor(mll& List) {
 // I.S. : List belum terbentuk.
 // F.S. : List diinisialisasi dengan elemen pertama sebagai Nil.
    FirstInvestor(List) = Nil;
}

void insertLastInvestor(mll& List, adrInvestor I) {
// I.S. : list investor yang mungkin kosong.
// F.S. : Data investor I menjadi elemen terakhir dalam list investor.
    if (FirstInvestor(List) == Nil) {
        FirstInvestor(List) = I;
    } else {
        adrInvestor p = FirstInvestor(List);
        while (nextInvestor(p) != Nil) {
            p = nextInvestor(p);
        }
        nextInvestor(p) = I;
    }
}

void insertFirstInvestor(mll& List, adrInvestor I) {
// I.S. : list investor yang mungkin kosong.
// F.S. : Data investor I menjadi elemen terakhir dalam list investor.
    if (FirstInvestor(List) == Nil) {
        FirstInvestor(List) = I;
    } else {
        nextInvestor(I) = FirstInvestor(List);
        FirstInvestor(List) = I;
    }
}

void deleteFirstInvestor(mll& List, adrInvestor& I){

    if (FirstInvestor(List) != Nil){

      I = FirstInvestor(List);
      if (nextInvestor(I) != Nil){
        FirstInvestor(List) = nextInvestor(I);
        nextInvestor(I) = Nil;
      } else {
        FirstInvestor(List) = Nil;
      }
    }
};

void deleteAfterInvestor(mll& List, adrInvestor Prec, adrInvestor& I){

    if (Prec != Nil){
      I = nextInvestor(Prec);
      nextInvestor(Prec) = nextInvestor(I);
      nextInvestor(I) = Nil;
    }
};

void deleteLastInvestor(mll& List, adrInvestor& I){

    if (FirstInvestor(List) != Nil){


      I = FirstInvestor(List);
      if (nextInvestor(I) == Nil){
        FirstInvestor(List) = Nil;
      }else{

        while (nextInvestor(nextInvestor(I)) != Nil){
            I = nextInvestor(I);
        }
        nextInvestor(I) = Nil;
      }
    }
};


void deleteInvestor(mll &List, adrInvestor I){
  adrInvestor temp;
  if (I != Nil) {
    deleteRelationInvestor(List, I);
    if (nextInvestor(I)==Nil){
      deleteLastInvestor(List, temp);
    } else if (I == FirstInvestor(List)) {
      deleteFirstInvestor(List, temp);
    } else {
      adrInvestor cur = FirstInvestor(List);
      while (nextInvestor(cur) != I){
        cur = nextInvestor(cur);
      }
      deleteAfterInvestor(List, cur, temp);
    }
    cout << "Delete berhasil"<<'\n';
  } /*else {
    cout << "Investor Tidak Ditemukan";
  }*/

}

adrInvestor searchInvestor(mll L, string nama) {
    adrInvestor cur;
    cur = FirstInvestor(L);
    while (cur != Nil && infoInvestor(cur).nama_investor != nama) {
      cur = nextInvestor(cur);
    }
    return cur;
 }

void showAllInvestor(mll List) {
    // I.S. : list investor yang mungkin tidak kosong.
    // F.S. : Menampilkan semua data investor yang ada dalam list.

    adrInvestor p = FirstInvestor(List);
    while (p != Nil) {
        cout << "ID Investor: " << infoInvestor(p).id_investor;
        cout << ", Nama: " << infoInvestor(p).nama_investor;
        cout << ", Investment Amount: " << infoInvestor(p).investmentAmount << endl;
        p = nextInvestor(p);
    }
}
