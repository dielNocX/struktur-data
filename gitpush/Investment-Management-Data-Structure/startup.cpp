#include "MLL.h"

adrStartup newElementStartup(startup data) {
// Mengembalikan alamat elemen startup baru yang berisi data yang diberikan.
    adrStartup elmBaru = new elmStartup;
    infoStartup(elmBaru) = data;
    nextStartup(elmBaru) = Nil;
    prevStartup(elmBaru) = Nil;
    return elmBaru;
}

void createListStartup(mll& List) {
 // I.S. : List belum terbentuk.
 // F.S. : List diinisialisasi dengan elemen pertama sebagai Nil.
    FirstStartup(List) = Nil;
    LastStartup(List) = Nil;
}

void insertLastStartup(mll& List, adrStartup S) {
// I.S. : Terdefinisi dengan kondisi list startup yang mungkin kosong.
// F.S. : Data startup S menjadi elemen terakhir dalam list startup.
    /*if (FirstStartup(List) == Nil) {
        FirstStartup(List) = S;
    } else {
        adrStartup p = FirstStartup(List);
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

void deleteFirstStartup(mll& List, adrStartup& S) {
    S = FirstStartup(List);
  if (FirstStartup(List) != Nil){
    if (FirstStartup(List) != LastStartup(List)){

        FirstStartup(List) = nextStartup(S);
        nextStartup(S) = Nil;
        prevStartup(FirstStartup(List)) = Nil;
    } else {

        FirstStartup(List) = Nil;
        LastStartup(List) = Nil;
    }
  }
}

void deleteAfterStartup(mll& List, adrStartup Prec, adrStartup& S) {
    if (Prec != Nil && nextStartup(Prec) != Nil){
        S = nextStartup(Prec);
        nextStartup(Prec) = nextStartup(S);
        if (nextStartup(S) != Nil){
            prevStartup(nextStartup(S)) = Prec;
        } else {
            LastStartup(List) = Prec;
        };
        prevStartup(S) = Nil;
    } else {
        S = Nil;
    };
};

void deleteLastStartup(mll& List, adrStartup& S) {
    if (LastStartup(List) != Nil){
      S = LastStartup(List);
      if (FirstStartup(List) == LastStartup(List)){
          FirstStartup(List) = Nil;
          LastStartup(List) = Nil;
      } else {
          LastStartup(List) = prevStartup(LastStartup(List));
          prevStartup(S) = Nil;
          nextStartup(LastStartup(List)) = Nil;
      };
    }
};


adrStartup searchStartup(mll L, string nama) {
    adrStartup cur;
    cur = FirstStartup(L);
    while (cur != Nil && infoStartup(cur).nama_startup != nama) {
      cur = nextStartup(cur);
    }
    return cur;
 }




void deleteStartup(mll &List, adrStartup S){
  adrStartup temp;
  if (S != Nil) {
    deleteRelationStartup(List, S);
    if (nextStartup(S)==Nil){
      deleteLastStartup(List, temp);
    } else if (S == FirstStartup(List)) {
      deleteFirstStartup(List, temp);
    } else {
      adrStartup cur = FirstStartup(List);
      while (nextStartup(cur) != S){
        cur = nextStartup(cur);
      }
      deleteAfterStartup(List, cur, temp);
    }
    cout << "Delete berhasil"<<'\n';
  } /*else {
    cout << "Investor Tidak Ditemukan";
  }*/

}


void showAllStartup(mll List) {
    // I.S. : list startup yang mungkin tidak kosong.
    // F.S. : Menampilkan semua data startup yang ada dalam list.
    adrStartup p = FirstStartup(List);
    while (p != Nil) {
        cout << "ID Startup: " << infoStartup(p).id_startup
             << ", Nama: " << infoStartup(p).nama_startup
             << ", Bidang: " << infoStartup(p).bidang_startup << endl;
        p = nextStartup(p);
    }
}
