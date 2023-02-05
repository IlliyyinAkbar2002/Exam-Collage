/**
 * @file index-fix.cpp
 * @author Illiyyin Akbar Ariyanto
 * @author Evi Fitriya
 * @brief Our Last Project, Program Shoops goods
 * @version 0.1
 * @date 2023-02-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// 4
int urut, isistok, isiharga, setelah, ulangi, hitungdel;
int panjang, tes;
// Node *cekisi;
//  4
string isinama, isiid, fillmenu, fillhapus, fillisi;

struct Goods
{
    string nama;
    string id;
    int stok;
    int harga;
};

struct Node
{
    Goods item;
    Node *next;
};

void Check_head(Node **ptrHead)
{
    panjang = 1;
    Node *temp;
    temp = *ptrHead;
    while (temp->next != *ptrHead)
    {
        panjang++;
        temp = temp->next;
    }
}

void printAll(Node *temp)
{

    tes = 0;
    cout << "\t\t=============================================" << endl;
    int urut2;
    urut2 = 1;

    Node *head = temp;
    do
    {
        temp = temp->next;
        tes++;
    } while (temp != head);

    if (tes == 1 && temp->item.nama == "kosong")
    {
        cout << "\t\tlist kosong" << endl;
    }
    else
    {
        cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
        do
        {

            if (temp->item.nama != "kosong")
            {

                cout << "\t\t [" << urut2 << "]";
                urut2++;
                cout << "\t\t" << temp->item.id;
                cout << "\t" << temp->item.nama;
                cout << "\t\t" << temp->item.stok;
                cout << "\t\t" << temp->item.harga;
                cout << endl;
            }
            temp = temp->next;
        } while (temp != head);
        // cout << "\n\n\t\tPrint all done yang ke : " << urut << endl;
        urut++;
        cout << "\t\tApakah ingin melihat barang berdasarkan stok tertinggi (y/n)" << endl;
        string ask9;
        cout << "\t\tMasukkan : ";
        cin >> ask9;
        if (ask9 == "y")
        {
            // UNTUK CARI SIZE
            Node *ukursize = head;
            int sizze = 0;
            do
            {
                if (ukursize->item.nama != "kosong")
                {
                    sizze++;
                }
                ukursize = ukursize->next;
            } while (ukursize != head);
            // size udh ktemu
            string savearrayid[sizze];
            int savearraystok[sizze];
            string savearraynama[sizze];
            int savearrayharga[sizze];
            Node *arrysv = temp;
            int i = 0;
            do
            {
                if (arrysv->item.nama != "kosong")
                {
                    savearrayid[i] = arrysv->item.id;
                    savearrayharga[i] = arrysv->item.harga;
                    savearraynama[i] = arrysv->item.nama;
                    savearraystok[i] = arrysv->item.stok;
                    i++;
                }
                arrysv = arrysv->next;
            } while (arrysv != temp);

            int smntrastok;
            int smntraharga;
            string smntranama;
            string smntraid;
            int sizzze = sizeof(savearraystok) / sizeof(savearraystok[0]);
            for (int d = 0; d < sizzze; d++)
            {
                for (int u = d + 1; u < sizzze; u++)
                {
                    if (savearraystok[u] > savearraystok[d])
                    {
                        // stok
                        smntrastok = savearraystok[u];
                        savearraystok[u] = savearraystok[d];
                        savearraystok[d] = smntrastok;
                        // harga
                        smntraharga = savearrayharga[u];
                        savearrayharga[u] = savearrayharga[d];
                        savearrayharga[d] = smntraharga;
                        // nama
                        smntranama = savearraynama[u];
                        savearraynama[u] = savearraynama[d];
                        savearraynama[d] = smntranama;
                        // id
                        smntraid = savearrayid[u];
                        savearrayid[u] = savearrayid[d];
                        savearrayid[d] = smntraid;
                    }
                }
            }
            cout << "\t\tNo urut data\tId\t\tNama item\tstok\t\tharga/item" << endl;
            int urt;
            urt = 1;
            for (int v = 0; v < sizzze; v++)
            {
                cout << "\t\t [" << urt << "]";
                urt++;
                cout << "\t\t" << savearrayid[v];
                cout << "\t\t" << savearraynama[v];
                cout << "\t\t" << savearraystok[v];
                cout << "\t\t" << savearrayharga[v] << endl;
            }
        }
    }
    cout << "\t\t=============================================" << endl;
}

void insertFirst(Node **ptrHead)
{
    cout << "\n\n\t\tinsert First";
    Node *newNode = new Node();
    cout << endl;
    cout << "\t\tnama item \t\t: ";
    cin >> isinama;
    cout << "\t\tid item \t\t: ";
    cin >> isiid;
    cout << "\t\tstok \t\t\t: ";
    cin >> isistok;
    cout << "\t\tharga per item \t\t: ";
    cin >> isiharga;
    cout << endl;

    newNode->item.nama = isinama;
    newNode->item.id = isiid;
    newNode->item.stok = isistok;
    newNode->item.harga = isiharga;

    Node *temp = *ptrHead;
    do
    {
        temp = temp->next;
    } while (temp->next != *ptrHead);

    newNode->next = *ptrHead;
    *ptrHead = newNode;

    temp->next = *ptrHead;
};

void insertLast(Node *temp)
{
    cout << "\n\n\t\tinsert Last" << endl;

    Node *newNode = new Node();
    // input :

    cout << "\t\tnama item \t\t: ";
    cin >> isinama;
    cout << "\t\tId item \t\t: ";
    cin >> isiid;
    cout << "\t\tstok \t\t\t: ";
    cin >> isistok;
    cout << "\t\tharga per item \t\t: ";
    cin >> isiharga;
    cout << endl;

    newNode->item.nama = isinama;
    newNode->item.id = isiid;
    newNode->item.stok = isistok;
    newNode->item.harga = isiharga;
    newNode->next = temp;

    Node *head = temp;

    do
    {
        temp = temp->next;
    } while (temp->next != head);

    temp->next = newNode;
};

void insertAfter(Node *temp)
{
    cout << "\n\n\t\tinsert After";
    Node *newNode = new Node();
    // input
    cout << "\n\t\tMau dijadikan list urut berapa :";
    cin >> setelah;
    cout << "\t\tnama item \t\t: ";
    cin >> isinama;
    cout << "\t\tid item \t\t: ";
    cin >> isiid;
    cout << "\t\tstok \t\t\t: ";
    cin >> isistok;
    cout << "\t\tharga per item \t\t: ";
    cin >> isiharga;
    cout << endl;

    newNode->item.nama = isinama;
    newNode->item.id = isiid;
    newNode->item.stok = isistok;
    newNode->item.harga = isiharga;

    for (int i = 1; i < setelah; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    cout << endl;
}

void deleteFirst(Node **ptrhead)
{
    if ((*ptrhead)->item.nama == "kosong")
    {
        (*ptrhead) = (*ptrhead)->next;
    }

    Node *trash;
    Node *movekos;
    Node *movekos2;
    trash = *ptrhead;

    // cout<<"trash === "<<trash->item.nama<<endl;
    Node *temp3 = *ptrhead;
    do
    {
        temp3 = temp3->next;

    } while (temp3->next != *ptrhead);

    temp3->next = trash->next;
    *ptrhead = temp3->next;
    free(trash);
}

void deleteLast(Node *temp)
{
    int countt;
    countt = 0;

    Node *trash;
    Node *head = temp;
    Node *nodekosong;
    Node *temp2;
    int itung;
    itung = 0;
    do
    {
        itung++;
        nodekosong = temp;
        temp2 = temp;
        temp = temp->next;
    } while (temp->next != head);
    if (temp->item.nama == "kosong")
    {
        for (int k = 1; k <= itung; k++)
        {
            temp2 = temp2->next;
            temp = temp->next;
        }
        for (int h = 1; h <= 1; h++)
        {
            nodekosong = nodekosong->next;
        }

        temp2->next = nodekosong;
        temp->next = trash;
    }
    else if (temp->item.nama != "kosong")
        temp2->next = head;
    temp->next = trash;
}

void deleteAfter(Node *temp)
{

    Node *temp2;
    Node *temp4;
    Node *temp3;
    int countdel;
    countdel = 0;
    Node *trash;
    Node *if1;
    Node *afterif1;
    Node *lasstohead;
    Node *forhead = temp;
    afterif1 = forhead;
    if1 = forhead;
    lasstohead = forhead;
    temp4 = forhead;
    temp3 = forhead;
    for (int i = 1; i <= setelah - 1; i++)
    {
        countdel++;
        temp2 = temp;
        temp = temp->next;
    }

    // cout<<"temp2 : "<<temp2->item.nama<<endl;
    // cout<<"temp : "<<temp->item.nama<<endl;
    if (temp->item.nama == "kosong")
    {
        for (int j = 1; j <= setelah; j++)
        {
            temp3 = temp3->next;
        }
        // cout<<"temp3 : "<<temp3->item.nama<<endl;
        for (int k = 1; k <= setelah + 1; k++)
        {
            temp4 = temp4->next;
        }
        // cout<<"temp4 : "<<temp4->item.nama<<endl;

        temp->next = temp4;
        temp3->next = NULL;
    }
    else if (temp->item.nama != "kosong")
    {
        temp2->next = temp->next;
        temp->next = NULL;
    }
}

void searchElement(Node *head)
{
    int urut2;
    urut2 = 1;
    Node *temp = head;
    int search = 1;
    string seacrhName;

    cout << "\t\tDaftar barang: \n";

    cout << "\t\tNo urut data\tId\tNama item" << endl;
    do
    {

        if (temp->item.nama != "kosong" && temp->item.stok != 0)
        {
            cout << "\t\t [" << urut2 << "]";
            urut2++;
            cout << "\t\t" << temp->item.id;
            cout << "\t\t" << temp->item.nama;
            cout << endl;
        }
        temp = temp->next;
        search++;
    } while (temp != head);

    cout << "\n\n\t\tMasukkan id/kode barang yang mau dicari : ";
    cin >> seacrhName;

    temp = head;
    search = 1;
    bool found = false;
    do
    {
        if (seacrhName == temp->item.id)
        {
            cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
            cout << "\t\t [" << search - 1 << "]";
            cout << "\t\t" << temp->item.id;
            cout << "\t\t" << temp->item.nama;
            cout << "\t\t" << temp->item.stok;
            cout << "\t\t" << temp->item.harga;
            cout << endl;
            found = true;
            break;
        }
        temp = temp->next;
        search++;
    } while (temp != head);
    if (!found)
    {
        cout << "\t\tItem tidak ditemukan." << endl;
    }
}

void mainmenu()
{
    cout << "\t\t=============================================================================" << endl;
    cout << "\t\t\t\tTOKO ANUGERAH" << endl;
    cout << "\t\t=============================================================================" << endl;
    cout << "\t\tPilih Menu : " << endl;
    cout << "\t\t1. Daftar Barang" << endl;
    cout << "\t\t2. Tambah Barang Baru\t(tolong lihat daftar menu dulu untuk melihat urutan)" << endl;
    cout << "\t\t3. Hapus Barang\t\t(tolong lihat daftar menu dulu untuk melihat urutan)" << endl;
    cout << "\t\t4. Transaksi" << endl;
    cout << "\t\t5. Cari Barang" << endl;
    cout << "\t\t6. Refill & Update Barang" << endl;
    cout << "\t\t7. Keluar" << endl;
    cout << "\t\t=============================================================================" << endl;
    cout << "\t\tmasukkan : ";
    cin >> fillmenu;
}

void deletemenu()
{

    cout << "\t\t=============================================" << endl;
    cout << "\t\tPilih Menu : " << endl;
    cout << "\t\t1. Hapus barang baris Pertama" << endl;
    cout << "\t\t2. Hapus barang tertentu" << endl;
    cout << "\t\t3. Hapus barang baris terakhir" << endl;
    cout << "\t\t4. Kembali" << endl;
    cout << "\t\t=============================================" << endl;
}

void isimenu()
{
    cout << "\t\t=============================================" << endl;
    cout << "\t\tPilih Menu : " << endl;
    cout << "\t\t1. Isi Barang dilist terdepan" << endl;
    cout << "\t\t2. Isi Barang di baris tertentu" << endl;
    cout << "\t\t3. isi barang baris terakhir" << endl;
    cout << "\t\t4. Kembali" << endl;
    cout << "\t\t=============================================" << endl;
}

int main()
{
    ulangi = 0;
    urut = 1;

    Node *kosong;

    kosong = new Node();

    kosong->item.nama = "kosong";
    kosong->item.stok = 0;
    kosong->item.harga = 0;
    kosong->item.id = "kosong";

    kosong->next = kosong;
    Node *head;
    head = kosong;

    do
    {

        mainmenu();
        Check_head(&head);

        if (fillmenu == "1" || fillmenu == "satu" || fillmenu == "Satu" || fillmenu == "SATU")
        {
            printAll(head);
        }
        else if (fillmenu == "2" || fillmenu == "dua" || fillmenu == "Dua" || fillmenu == "DUA")
        {
            isimenu();
            cout << "\t\tmasukkan : ";
            cin >> fillisi;
            if (fillisi == "1" || fillisi == "satu" || fillisi == "Satu" || fillisi == "SATU")
            {
                insertFirst(&head);
            }
            else if (fillisi == "2" || fillisi == "dua" || fillisi == "Dua" || fillisi == "DUA")
            {
                insertAfter(head);
            }
            else if (fillisi == "3" || fillisi == "tiga" || fillisi == "Tiga" || fillisi == "TIGA")
            {
                insertLast(head);
            }
        }
        else if (fillmenu == "3" || fillmenu == "tiga" || fillmenu == "Tiga" || fillmenu == "TIGA")
        {
            Check_head(&head);
            if (panjang > 1)
            {
                Node *sementara;
                sementara = head;
                hitungdel = 0;
                do
                {
                    sementara = sementara->next;
                    hitungdel++;
                } while (sementara != head);
                if (hitungdel > 2)
                {
                    deletemenu();
                    cout << "\t\tmasukkan : ";
                    cin >> fillhapus;
                    if (fillhapus == "1" || fillhapus == "satu" || fillhapus == "Satu" || fillhapus == "SATU")
                    {
                        if (head != 0)
                        {
                            deleteFirst(&head);
                            cout << "\t\tfirst list list have been deleted" << endl;
                        }
                        else if (head == 0)
                        {
                            cout << "\t\tNODE KOSONG, TOLONG DIISI DAHULU" << endl;
                        }
                    }
                    else if (fillhapus == "2" || fillhapus == "dua" || fillhapus == "Dua" || fillhapus == "DUA")
                    {
                        Node *cetak = head;
                        int angka = 1;
                        do
                        {

                            if (cetak->item.nama != "kosong")
                            {

                                cout << "\t\t [" << angka << "]";
                                angka++;
                                cout << "\t\t" << cetak->item.id;
                                cout << "\t\t" << cetak->item.nama;
                                cout << "\t\t" << cetak->item.stok;
                                cout << "\t\t" << cetak->item.harga;
                                cout << endl;
                            }
                            cetak = cetak->next;
                        } while (cetak != head);
                        cout << "\t\tingin menghapus nomor berapa : ";
                        cin >> setelah;
                        cout << "\t\tlist number " << setelah << " have been deleted" << endl;
                        if (setelah == 1)
                        {
                            deleteFirst(&head);
                        }
                        else if (setelah > 1 && setelah < panjang)
                        {

                            deleteAfter(head);
                        }
                        else if (setelah > panjang)
                        {
                            cout << "\t\t Melewati batas." << endl;
                        }
                    }
                    else if (fillhapus == "3" || fillhapus == "tiga" || fillhapus == "Tiga" || fillhapus == "TIGA")
                    {
                        deleteLast(head);
                        cout << "\t\tlast list have been deleted" << endl;
                    }
                }
                else if (hitungdel == 2)
                {
                    Node *tri;
                    tri = head;
                    if (tri->item.nama == "kosong")
                    {
                        deleteLast(head);
                        cout << "\t\tlast list have been deleted" << endl;
                    }
                    else if (tri->item.nama != "kosong")
                    {
                        deleteFirst(&head);
                        cout << "\t\tfirst list list have been deleted" << endl;
                    }
                }
            }
            else if (panjang == 1)
            {
                cout << "\t\tNODE KOSONG" << endl;
            }
        }
        else if (fillmenu == "4" || fillmenu == "empat" || fillmenu == "Empat" || fillmenu == "EMPAT")
        {
            Node *cekisi;
            int total;
            Node *cekisi1;
            Node *cekisi2;
            Node *cekisi3;
            cekisi = head;
            cekisi1 = head;
            cekisi2 = head;
            cekisi3 = head;
            hitungdel = 0;
            do
            {
                cekisi = cekisi->next;
                hitungdel++;
            } while (cekisi != head);
            if (hitungdel == 1)
            {
                cout << "\t\tMohon Maaf data list kosong, mohon melaporkan kepada pihak toko." << endl;
            }
            else if (hitungdel > 1)
            {

                cekisi = head;
                int urutbrg;
                int jumlahbeli;
                string pilihbeli;
                urutbrg = 1;
                cout << "\t\t-----------------DAFTAR BARANG---------------------" << endl;
                cout << "\t\tNo urut data\tId\tNama item" << endl;
                do
                {

                    if (cekisi->item.nama != "kosong")
                    {

                        cout << "\t\t [" << urutbrg << "]";
                        urutbrg++;
                        cout << "\t\t" << cekisi->item.id;
                        cout << "\t\t" << cekisi->item.nama;
                        cout << endl;
                    }
                    cekisi = cekisi->next;
                } while (cekisi != head);

            ulang:
                char tanya;
                total = 0;
                cekisi = head;
                bool ktemu = false;

                // cout<<"\t\tMaksimal 3 jenis barang dalam 1 transaksi"<<endl;
                cout << "\t\tMasukkan Id barang \t: ";
                cin >> pilihbeli;
                do
                {
                    cekisi = cekisi->next;
                    if (cekisi->item.id == pilihbeli)
                    {
                        ktemu = true;
                    }
                } while (cekisi != head);
                if (!ktemu)
                {
                    cout << "\t\tMaaf barang tersebut tidak ada" << endl;
                }
                else if (ktemu && cekisi->item.stok != 0)
                {
                    cekisi1 = head;
                    do
                    {
                        cekisi1 = cekisi1->next;
                    } while (cekisi1->item.id != pilihbeli);
                    cout << "\t\tJumlah barang \t: ";
                    cin >> jumlahbeli;

                    if (jumlahbeli > cekisi1->item.stok)
                    {
                        cout << "\t\tMohon maaf stok hanya sisa : " << cekisi1->item.stok << endl;
                    }
                    else
                    {
                        cekisi1->item.stok -= jumlahbeli;
                        cout << "\t\tKonfirmasi : " << endl;
                        cout << "\t\tBarang\tJumlah\tTotal" << endl;
                        cout << "\t\t" << cekisi1->item.nama << "\t" << jumlahbeli << "\t" << jumlahbeli * cekisi1->item.harga << endl;
                        total += (jumlahbeli * cekisi1->item.harga);
                        cout << "\t\t----------------------------" << endl;
                        cout << "\t\tTotal belanjaan anda : " << total << endl;
                        cout << "\t\tTanggal pembelian : 03 Februari 2023" << endl;
                    }
                }
                else if (ktemu && cekisi->item.stok == 0)
                {
                    cout << "\t\tMohon maaf persediaan barang ini sedang kosong" << endl;
                }
                cout << endl
                     << "\t\tApakah anda ingin melakukan transaksi lagi? (y/n) : ";
                cin >> tanya;
                cout << "\t\t----------------------------" << endl;
                if (tanya == 'y')
                {
                    goto ulang;
                }
            }
        }
        else if (fillmenu == "5" || fillmenu == "lima" || fillmenu == "Lima" || fillmenu == "LIMA")
        {
            Node *cari = head;
            int itg = 0;
            do
            {
                cari = cari->next;
                itg++;
            } while (cari != head);
            if (itg == 1)
            {
                cout << "\t\tMohon maaf tidak ada barang yang terdaftar" << endl;
            }
            else if (itg > 1)
            {
                searchElement(head);
            }
        }
        else if (fillmenu == "6" || fillmenu == "enam" || fillmenu == "Enam" || fillmenu == "ENAM")
        {
            Node *tes1kah = head;
            int ittung = 0;
            do
            {
                tes1kah = tes1kah->next;
                ittung++;
            } while (tes1kah != head);
            if (ittung > 1)
            {
                cout << "\t\t1. Menambah isi" << endl;
                cout << "\t\t2. Mengupdate (mengganti ke yg baru)" << endl;
                cout << "\t\t3. Ganti Nama" << endl;
                cout << "\t\t4. Ganti ID/Kode" << endl;
                cout << "\t\t5. Ganti Harga" << endl;
                cout << "\t\t6. Kembali" << endl;
                int ask6;
                cout << "\t\t Masukkan : ";
                cin >> ask6;
                if (ask6 == 1)
                {
                    cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
                    Node *cetak = head;
                    int angka = 1;
                    do
                    {

                        if (cetak->item.nama != "kosong")
                        {

                            cout << "\t\t [" << angka << "]";
                            angka++;
                            cout << "\t\t" << cetak->item.id;
                            cout << "\t\t" << cetak->item.nama;
                            cout << "\t\t" << cetak->item.stok;
                            cout << "\t\t" << cetak->item.harga;
                            cout << endl;
                        }
                        cetak = cetak->next;
                    } while (cetak != head);
                    cout << "\t\tNama barang yang akan ditambah stoknya : ";
                    string tambahnama6;
                    cin >> tambahnama6;
                    Node *fil6;
                    int fill6 = 0;
                    fil6 = head;
                    do
                    {

                        fil6 = fil6->next;
                        if (fil6->item.nama == tambahnama6)
                        {
                            fill6++;
                        }
                    } while (fil6 != head);

                    if (fill6 == 1)
                    {
                        fil6 = head;
                        do
                        {
                            fil6 = fil6->next;
                        } while (fil6->item.nama != tambahnama6);
                        cout << "\t\tingin ditambah berapa : ";
                        int tambahstok6;
                        cin >> tambahstok6;
                        fil6->item.stok += tambahstok6;
                        cout << "\t\tItem Berhasil ditambah" << endl;
                    }
                    else if (fill6 != 1)
                    {
                        cout << "\t\tMohon maaf Barang dengan nama itu tidak ada." << endl;
                    }
                }
                else if (ask6 == 2)
                {
                    cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
                    Node *cetak = head;
                    int angka = 1;
                    do
                    {

                        if (cetak->item.nama != "kosong")
                        {

                            cout << "\t\t [" << angka << "]";
                            angka++;
                            cout << "\t\t" << cetak->item.id;
                            cout << "\t\t" << cetak->item.nama;
                            cout << "\t\t" << cetak->item.stok;
                            cout << "\t\t" << cetak->item.harga;
                            cout << endl;
                        }
                        cetak = cetak->next;
                    } while (cetak != head);
                    cout << "\t\tNama barang yang akan diupdate stoknya : ";
                    string updatenama6;
                    cin >> updatenama6;
                    Node *fil7;
                    int fill7 = 0;
                    fil7 = head;
                    do
                    {
                        fil7 = fil7->next;
                        if (fil7->item.nama == updatenama6)
                        {
                            fill7++;
                        }
                    } while (fil7 != head);

                    if (fill7 == 1)
                    {
                        fil7 = head;
                        do
                        {
                            fil7 = fil7->next;
                        } while (fil7->item.nama != updatenama6);
                        cout << "\t\tStok yang baru : ";
                        int updatestok;
                        cin >> updatestok;
                        fil7->item.stok = updatestok;
                        cout << "\t\tItem Berhasil diupdate" << endl;
                    }
                    else if (fill7 == 0)
                    {
                        cout << "\t\tMohon maaf Barang dengan nama itu tidak ada." << endl;
                    }
                }
                else if (ask6 == 3)
                {
                    cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
                    Node *cetak = head;
                    int angka = 1;
                    do
                    {

                        if (cetak->item.nama != "kosong")
                        {

                            cout << "\t\t [" << angka << "]";
                            angka++;
                            cout << "\t\t" << cetak->item.id;
                            cout << "\t\t" << cetak->item.nama;
                            cout << "\t\t" << cetak->item.stok;
                            cout << "\t\t" << cetak->item.harga;
                            cout << endl;
                        }
                        cetak = cetak->next;
                    } while (cetak != head);
                    cout << "\t\tNama barang yang akan diupdate namanya : ";
                    string updateNAMA;
                    cin >> updateNAMA;
                    Node *fil8;
                    int fill8 = 0;
                    fil8 = head;
                    do
                    {
                        fil8 = fil8->next;
                        if (fil8->item.nama == updateNAMA)
                        {
                            fill8++;
                        }
                    } while (fil8 != head);

                    if (fill8 == 1)
                    {
                        fil8 = head;
                        do
                        {
                            fil8 = fil8->next;
                        } while (fil8->item.nama != updateNAMA);
                        cout << "\t\tNama yang baru : ";
                        string perbaruinamak;
                        cin >> perbaruinamak;
                        fil8->item.nama = perbaruinamak;
                        cout << "\t\tNama Item Berhasil diupdate" << endl;
                    }
                    else if (fill8 == 0)
                    {
                        cout << "\t\tMohon maaf Barang dengan nama itu tidak ada." << endl;
                    }
                }
                else if (ask6 == 4)
                {
                    cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
                    Node *cetak = head;
                    int angka = 1;
                    do
                    {

                        if (cetak->item.nama != "kosong")
                        {

                            cout << "\t\t [" << angka << "]";
                            angka++;
                            cout << "\t\t" << cetak->item.id;
                            cout << "\t\t" << cetak->item.nama;
                            cout << "\t\t" << cetak->item.stok;
                            cout << "\t\t" << cetak->item.harga;
                            cout << endl;
                        }
                        cetak = cetak->next;
                    } while (cetak != head);
                    cout << "\t\tNama barang yang akan diupdate idnya : ";
                    string updatenAma;
                    cin >> updatenAma;
                    Node *fil9;
                    int fill9 = 0;
                    fil9 = head;
                    do
                    {
                        fil9 = fil9->next;
                        if (fil9->item.nama == updatenAma)
                        {
                            fill9++;
                        }
                    } while (fil9 != head);

                    if (fill9 == 1)
                    {
                        fil9 = head;
                        do
                        {
                            fil9 = fil9->next;
                        } while (fil9->item.nama != updatenAma);
                        cout << "\t\tStok yang baru : ";
                        string perbaruiid;
                        cin >> perbaruiid;
                        fil9->item.id = perbaruiid;
                        cout << "\t\tID Item Berhasil diupdate" << endl;
                    }
                    else if (fill9 == 0)
                    {
                        cout << "\t\tMohon maaf Barang dengan nama itu tidak ada." << endl;
                    }
                }
                else if (ask6 == 5)
                {
                    cout << "\t\tNo urut data\tId\tNama item\tstok\t\tharga/item" << endl;
                    Node *cetak = head;
                    int angka = 1;
                    do
                    {

                        if (cetak->item.nama != "kosong")
                        {

                            cout << "\t\t [" << angka << "]";
                            angka++;
                            cout << "\t\t" << cetak->item.id;
                            cout << "\t" << cetak->item.nama;
                            cout << "\t" << cetak->item.stok;
                            cout << "\t" << cetak->item.harga;
                            cout << endl;
                        }
                        cetak = cetak->next;
                    } while (cetak != head);
                    cout << "\t\tNama barang yang akan diupdate harganya : ";
                    string updateharga;
                    cin >> updateharga;
                    Node *fil4;
                    int fill4 = 0;
                    fil4 = head;
                    do
                    {
                        fil4 = fil4->next;
                        if (fil4->item.nama == updateharga)
                        {
                            fill4++;
                        }
                    } while (fil4 != head);

                    if (fill4 == 1)
                    {
                        fil4 = head;
                        do
                        {
                            fil4 = fil4->next;
                        } while (fil4->item.nama != updateharga);
                        cout << "\t\tStok yang baru : ";
                        int perbaruiharga;
                        cin >> perbaruiharga;
                        fil4->item.harga = perbaruiharga;
                        cout << "\t\tID Item Berhasil diupdate" << endl;
                    }
                    else if (fill4 == 0)
                    {
                        cout << "\t\tMohon maaf Barang dengan nama itu tidak ada." << endl;
                    }
                }
                else if (ask6 == 6)
                {
                    cout << "\t\tSilahkan kembali ke main menu" << endl;
                }
            }
            else
            {
                cout << "\t\tMaaf Data Sedang Kosong" << endl;
            }
        }
        else if (fillmenu == "7" || fillmenu == "tujuh" || fillmenu == "Tujuh" || fillmenu == "TUJUH")
        {
            cout << "\t\tSELESAI" << endl;
            break;
        }
        else
        {
            cout << "\t\tMaaf masukan anda salah" << endl;
        }
    } while (true);
}
