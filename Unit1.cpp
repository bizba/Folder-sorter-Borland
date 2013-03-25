//---------------------------------------------------------------------------

#include <vcl.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "filestruc.h"
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

filestruc files_mas[10000];
int mi;

void fsize(char *);
int sort_file_mas();


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    // просмотр дирректории
    ListBox1->Clear();
    ListBox2->Clear();

    mi = 0;
    fsize(mDir->Text.c_str());
    sort_file_mas();
    NumberStr->Caption = IntToStr(ListBox1->Count);
}
//---------------------------------------------------------------------------

void dirwalk(char *, void (*fcn) (char *));

void fsize(char *name)
{
    struct stat stbuf;

    if (stat(name, &stbuf) == -1)
    {
        ShowMessage("fsize: can't get stat");
        return;
    }


    if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);

    sprintf(files_mas[mi].name, "%s", name);
    files_mas[mi].size = stbuf.st_size;
    mi++;
    //printf ("%8ld %s\n", stbuf.st_size, name);
}


void dirwalk(char *dir, void (*fcn) (char *))
{
    char name[MAX_PATH_LENGTH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL)
    {
        ShowMessage("dirwalk: can't open dir");
        return;
    }

    while ((dp = readdir(dfd)) != NULL)
    {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;
        sprintf(name, "%s/%s", dir, dp->d_name);
        (*fcn)(name);

    }
    closedir(dfd);
}


int sort_file_mas()
{
	int j, a;
	int sum = 0;
        AnsiString str;

	for (j=0; j<mi-1; j++ )
	{
		for (a=j+1; a<mi; a++)
		{
			if (files_mas[j].size != 0 && files_mas[j].size == files_mas[a].size)
			{
				sum++;

                                str = files_mas[a].name;
                                Form1->ListBox1->Items->Add(str);
                                str = files_mas[j].name;
                                Form1->ListBox2->Items->Add(str);

			}
		}
	}


	return sum;
}


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
    int i;

    for (i = 0; i < ListBox1->Items->Count; i++)
    {
        if (ListBox1->Selected[i])
        {
            
            if (FileExists(ListBox1->Items->Strings[i]) && FileExists(ListBox2->Items->Strings[i]))
            {
                //MessageBeep(0);
                Image1->Picture->LoadFromFile(ListBox1->Items->Strings[i]);
                Image1->Show();
                FName1->Caption = ListBox1->Items->Strings[i];

                Image2->Picture->LoadFromFile(ListBox2->Items->Strings[i]);
                Image2->Show();
                FName2->Caption = ListBox2->Items->Strings[i];



            }
        }
    }


}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    mi = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if (FileExists(FName1->Caption))
    {
        remove(FName1->Caption.c_str());
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if (FileExists(FName2->Caption))
    {
        remove(FName2->Caption.c_str());
    }
}
//---------------------------------------------------------------------------

