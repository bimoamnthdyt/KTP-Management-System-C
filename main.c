#include <stdio.h> 
#include <conio.h>
#include <windows.h>

void tambahdata();
void tampildata();
void caridata();
void hapus();

struct datadiri {
    int id;
    char nik[50];
    char nama[50];
    char ttl[255];
    char jenis_kelamin[20];
    char alamat[225];
    char agama[20];
    char status_kawin[40];
    char pekerjaaan[50];
    char kewarganegaraan[30];
};


void main(){
    int pilih;
    system("cls");
    while (pilih!=5) {
        printf("\t\t===== MENU KARTU TANDA PENDUDUK =====");
        printf("\n\n\n\t\t 1. Tambah Data KTP \n");
        printf("\t\t 2. Tampil Data KTP \n");
        printf("\t\t 3. Cari Data KTP \n");
        printf("\t\t 4. Hapus Data KTP \n");
        printf("\t\t 5. Kembali \n");
        printf("\t\t____________________________________\n");
        printf("\n\t\t Pilih : ");
        scanf("%d", &pilih);

            switch (pilih)
            {
            case 1:
                system("cls");
                tambahdata();
                system("cls");
                break;

            case 2:
                system("cls");
                tampildata();
                printf("\t\t Tekan apa saja untuk kembali\n");
                getch();
                system("cls");
                break;

            case 3:
                system("cls");
                caridata();
                printf("\t\t Tekan apa saja untuk kembali\n");
                getch();
                system("cls");
                break;
            case 4:
                system("cls");
                hapus();
                printf("\t\t Tekan apa saja untuk kembali\n");
                getch();
                system("cls");
                break;
            }
    } 
}

void tambahdata(){
    char tambahlagi;
    FILE *fp;
    struct datadiri info;
    
    do  
    {
        system("cls");
        printf("\t\t============== Tambah Data KTP ==============");
        fp=fopen("data_ktp","a");
        printf("\n\t\t id \t: ");
        scanf("%d,", &info.id);
        printf("\n\t\tMasukan NIK \t\t\t: ");
        scanf("%s", &info.nik);
        printf("\n\t\tMasukan Nama \t\t\t: ");
        scanf(" %[^\n]", &info.nama);
        printf("\n\t\tMasukan Tempat/Tgl/Lahir \t: ");
        scanf(" %[^\n]", &info.ttl);
        printf("\n\t\tMasukan Jenis Kelamin \t\t: ");
        scanf(" %[^\n]", &info.jenis_kelamin);
        printf("\n\t\tMasukan Alamat \t\t\t: ");
        scanf(" %[^\n]", &info.alamat);
        printf("\n\t\tMasukan Agama \t\t\t: ");
        scanf("%s", &info.agama);
        printf("\n\t\tMasukan Status Kawin \t\t: ");
        scanf(" %[^\n]", &info.status_kawin);
        printf("\n\t\tMasukan Pekerjaan \t\t: ");
        scanf(" %[^\n]", &info.pekerjaaan);
        printf("\n\t\tMasukan Kewarganegaraan \t: ");
        scanf("%s", &info.kewarganegaraan);
        printf("\t\t __________________________ \n");

        if(fp==NULL){
            fprintf(stderr, "\t\tTidak ada File yang ditambahkan\n");
        }else{
            printf("\t\tBerhasil Menambahkan Data\n");
        }

        fwrite(&info,sizeof(struct datadiri),1,fp);
        fclose(fp);

        printf("\t\t Ingin Menambah data lagi?(y/n) : ");
        scanf("%s", &tambahlagi);

    } while (tambahlagi=='y' ||tambahlagi=='Y');
}


void tampildata(){
    FILE *fp;
    struct datadiri info;
    fp=fopen("data_ktp", "r");
    printf("\t\t=========== Data-data KTP ===========\n\n");

    if(fp==NULL){
         fprintf(stderr, "\t\tTidak ada Data yang ditambahkan\n");
    }else{
        // printf("\t\tData%d\n", data);
        printf("\t\t__________________________________________________\n"); 
        }

        while(fread(&info,sizeof(struct datadiri),1,fp)){
            printf("\n\t\tID \t: %d", info.id);
            printf("\n\t\tNIK \t\t\t: %s", info.nik);
            printf("\n\t\tNAMA \t\t\t: %s", info.nama);
            printf("\n\t\tTemoat/Tgl/Lahir \t: %s", info.ttl);
            printf("\n\t\tJenis Kelamin \t\t: %s", info.jenis_kelamin);
            printf("\n\t\tAlamat \t\t\t: %s", info.alamat);
            printf("\n\t\tAgama \t\t\t: %s", info.agama);
            printf("\n\t\tStatus Kawin \t\t: %s", info.status_kawin);
            printf("\n\t\tPekerjaan \t\t: %s", info.pekerjaaan);
            printf("\n\t\tKewarganegaraan \t: %s", info.kewarganegaraan);
            printf("\n\t\t__________________________________________________\n");
        }

        fclose(fp);
        getch();
}


void caridata(){

    FILE *fp;
    struct datadiri info;
    int id,found=0;

    fp=fopen("data_ktp", "r");

    printf("\t\t=========== Cari Data KTP ===========\n\n");
    printf("\t\t Masukan Id  : ");
    scanf("%d", &id);

     while(fread(&info,sizeof(struct datadiri),1,fp)){

        if(info.id==id){
            found=1;
            printf("\n\t\tID \t: %d", info.id);
            printf("\n\t\tNIK \t\t\t: %s", info.nik);
            printf("\n\t\tNAMA \t\t\t: %s", info.nama);
            printf("\n\t\tTemoat/Tgl/Lahir \t: %s", info.ttl);
            printf("\n\t\tJenis Kelamin \t\t: %s", info.jenis_kelamin);
            printf("\n\t\tAlamat \t\t\t: %s", info.alamat);
            printf("\n\t\tAgama \t\t\t: %s", info.agama);
            printf("\n\t\tStatus Kawin \t\t: %s", info.status_kawin);
            printf("\n\t\tPekerjaan \t\t: %s", info.pekerjaaan);
            printf("\n\t\tKewarganegaraan \t: %s", info.kewarganegaraan);
            printf("\n\t\t__________________________________________________\n");
        }
     }

        if(!found){
            printf("\t\tData tidak ditemukan!\n");
        }

        fclose(fp);
        getch();
}

void hapus(){
    FILE *fp, *fp1;
    struct datadiri info;
    int id,found=0;

    printf("\t\t=========== Hapus Data KTP ===========\n\n");
    fp=fopen("data_ktp","r");
    fp1=fopen("temp.txt", "w");
    printf("\t\t Masukan Id yang ingin dihapus : ");
    scanf("%d", &id);
    
     if(fp==NULL){
         fprintf(stderr, "\t\tTidak ada Data yang ditambahkan\n");
    }
    while(fread(&info,sizeof(struct datadiri),1,fp)){

        if(info.id==id){
            found=1;
        }else{
            fwrite(&info,sizeof(struct datadiri),1,fp1);
        }
    }

    fclose(fp);
    fclose(fp1);

    if(found){
        remove("data_ktp");
        rename("temp.txt", "data_ktp");
        printf("\n\t\t Data berhasil di hapus!\n");
    }
    if(!found){
        printf("\n\t\t Data tidak di temukan!\n");
    }

    getch();
}


