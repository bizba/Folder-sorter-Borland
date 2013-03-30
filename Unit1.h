//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *mDir;
        TButton *Button1;
        TImage *Image1;
        TListBox *ListBox1;
        TImage *Image2;
        TListBox *ListBox2;
        TLabel *NumberStr;
        TLabel *FName1;
        TLabel *FName2;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
