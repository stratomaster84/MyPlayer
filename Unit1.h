//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#define PLAYLIST "Player.m3u"   //Плейлист

#define CONFIG "Config.ini"     //Файл Конфигурации

#define CFGPLAYER "[PLAYER]"    //Идентификатор Плеера в файле конфигурации
#define CFGDIR "[DIRECTORY]"    //Идентификатор Папки
#define CFGLEFT "[LEFT]"
#define CFGTOP "[TOP]"
#define CFGPLEFT "[PLEFT]"
#define CFGPTOP "[PTOP]"
#define CFGNEWPL "[NEWPL]"

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TListBox *BandList;  //Список групп
        TLabel *BandLabel;
        TListBox *AlbumList;   //Список альбомов
        TLabel *AlbumLabel;
        TLabel *SongLabel;
        TLabel *Label1;
        TCheckListBox *SongList;  //Список песен
        TOpenDialog *OpenDialog;
        TButton *Button1;
        TLabel *Label2;
        TEdit *Edit1;
        TButton *Button2;
        TEdit *Edit2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TCheckBox *CheckBox1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall BandListClick(TObject *Sender);
        void __fastcall AlbumListClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall myStart(TObject *Sender);  //Функция при загрузке
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall myFinish(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        void __fastcall BandHoriz();
        void __fastcall AlbumHoriz();
        void __fastcall SongHoriz();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
extern int PlayerLeft;
extern int PlayerTop;
//---------------------------------------------------------------------------
#endif
