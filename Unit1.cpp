//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <dir.h>
#include <process.h>
#include <stdio.h>
#include <algorithm>
#include <FileCtrl.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;

TMainForm *MainForm;
int PlayerLeft=0;
int PlayerTop=0;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
	if (OpenDialog->Execute())
		Edit2->Text = OpenDialog->FileName;

}
//---------------------------------------------------------------------------

   void __fastcall TMainForm::Button6Click(TObject *Sender)
{
        if(!DirectoryExists(GetMainPath(Edit1->Text))){
                Application->MessageBox( "Can't Find Path!","Error!!!",MB_OK);
                return;
        }
        MainPath = GetMainPath( PathString = Edit1->Text );
        AnsiString TempPath = MainPath;

        BandList->Clear();
        AlbumList->Clear();
        SongList->Clear();

        FindFolders(BandList->Items,TempPath);
        TempPath += BandList->Items->Strings[0] + "\\";
        if(BandList->Items->Strings[0] == ".")
                AlbumList->Items->Add(".");
        else
                FindFolders(AlbumList->Items , TempPath);
        TempPath +=AlbumList->Items->Strings[0] + "\\";
        FindFiles(SongList->Items , TempPath);
        BandList->ItemIndex = 0;
        AlbumList->ItemIndex = 0;
        SongList->ItemIndex = 0;

        
        BandHoriz();
        AlbumHoriz();
        SongHoriz();

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BandListClick(TObject *Sender)
{
        AnsiString TempPath = MainPath;

        TempPath +=  BandList->Items->Strings[BandList->ItemIndex] + "\\";

        if(!DirectoryExists(TempPath )){
                Application->MessageBox( "Can't Find Path!","Error!!!",MB_OK);
                return;
        }

        AlbumList->Clear();
        SongList->Clear();

        if(BandList->Items->Strings[BandList->ItemIndex] == ".")
                AlbumList->Items->Add(".");
        else
                FindFolders(AlbumList->Items , TempPath);
        TempPath +=AlbumList->Items->Strings[0] + "\\";
        FindFiles(SongList->Items , TempPath);
        AlbumList->ItemIndex = 0;
        SongList->ItemIndex = 0;

        AlbumHoriz();
        SongHoriz();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AlbumListClick(TObject *Sender)
{
        AnsiString TempPath = MainPath;

        TempPath += BandList->Items->Strings[BandList->ItemIndex] +
                "\\" + AlbumList->Items->Strings[AlbumList->ItemIndex] + "\\";

        if(!DirectoryExists(TempPath )){
                Application->MessageBox( "Can't Find Path!","Error!!!",MB_OK);
                return;
        }

        SongList->Clear();

        FindFiles(SongList->Items , TempPath);
        SongList->ItemIndex = 0;

        SongHoriz();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Button4Click(TObject *Sender)
{
        if(SongList->Items->Count == 0)
                return;

        TStringList *_files = new TStringList;
        if ( FileExists(PLAYLIST) && (!CheckBox1->Checked)  )
                _files->LoadFromFile(PLAYLIST);

        AnsiString DosPromt = MainPath;
        DosPromt += BandList->Items->Strings [BandList->ItemIndex] +
                "\\" + AlbumList->Items->Strings [AlbumList->ItemIndex] + "\\"
                        + SongList->Items->Strings [SongList->ItemIndex];

        _files->Add(DosPromt);
        _files->SaveToFile(PLAYLIST);

        spawnl(P_NOWAIT , Edit2->Text.c_str() , Edit2->Text.c_str() , PLAYLIST, NULL);

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Button3Click(TObject *Sender)
{
        if(SongList->Items->Count == 0)
                return;

        TStringList *_files = new TStringList;
        if ( FileExists(PLAYLIST) && (!CheckBox1->Checked)  )
                _files->LoadFromFile(PLAYLIST);

        AnsiString DosPromt;
        AnsiString TempFile = MainPath;
        TempFile +=  BandList->Items->Strings [BandList->ItemIndex] +
                "\\" + AlbumList->Items->Strings [AlbumList->ItemIndex] + "\\";
        for (int i =0;i<SongList->Items->Count;i++){
                DosPromt = TempFile + SongList->Items->Strings[i];
                _files->Add(DosPromt);
        }

        _files->SaveToFile(PLAYLIST);

        spawnl(P_NOWAIT , Edit2->Text.c_str() , Edit2->Text.c_str() , PLAYLIST, NULL);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button5Click(TObject *Sender)
{
        if(SongList->Items->Count == 0)
                return;
        int i;
        bool err = 0;
        for(i = 0;i< SongList->Items->Count ;i++)
                err |= SongList->Checked[i];
        if(err == 0)
                return;

        TStringList *_files = new TStringList;
        if ( FileExists(PLAYLIST) && (!CheckBox1->Checked)  )
                _files->LoadFromFile(PLAYLIST);

        AnsiString DosPromt;
        AnsiString TempFile = MainPath;
        TempFile +=  BandList->Items->Strings [BandList->ItemIndex] +
                "\\" + AlbumList->Items->Strings [AlbumList->ItemIndex] + "\\";

        for (int i =0;i<SongList->Items->Count;i++)
                if ( SongList->Checked[i]){
                        DosPromt = TempFile + SongList->Items->Strings[i];
                        _files->Add(DosPromt);
                }

        _files->SaveToFile(PLAYLIST);

        spawnl(P_NOWAIT , Edit2->Text.c_str() , Edit2->Text.c_str() , PLAYLIST, NULL);

}
//---------------------------------------------------------------------------



void __fastcall TMainForm::myStart(TObject *Sender)
{

        if ( FileExists(CONFIG) ){

                TStringList *TempList = new TStringList;
                try{
                        TempList->LoadFromFile(CONFIG);

                        for(int i=0;i<TempList->Count-1;i++){
                                if(TempList->Strings[i].AnsiCompareIC(CFGPLAYER) == 0)
                                        Edit2->Text = TempList->Strings[++i];
                                else if(TempList->Strings[i].AnsiCompareIC(CFGDIR) == 0)
                                        Edit1->Text = TempList->Strings[++i];
                                else if(TempList->Strings[i].AnsiCompareIC(CFGLEFT) == 0)
                                        Left = atoi(TempList->Strings[++i].c_str());
                                else if(TempList->Strings[i].AnsiCompareIC(CFGTOP) == 0)
                                        Top = atoi(TempList->Strings[++i].c_str());
                                else if(TempList->Strings[i].AnsiCompareIC(CFGPLEFT) == 0)
                                        PlayerLeft = atoi(TempList->Strings[++i].c_str());
                                else if(TempList->Strings[i].AnsiCompareIC(CFGPTOP) == 0)
                                        PlayerTop = atoi(TempList->Strings[++i].c_str());
                                else if(TempList->Strings[i].AnsiCompareIC(CFGNEWPL) == 0)
                                        CheckBox1->Checked = (bool)atoi(TempList->Strings[++i].c_str());
                        }
                }
                __finally{
                        delete TempList;
                }
                Button6Click(Sender);
        }
        else
                Application->MessageBox( "Can't Find File \""CONFIG"\"","Error!!!",MB_OK);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button2Click(TObject *Sender)
{
        AnsiString Dir;
        if(SelectDirectory("","",Dir))
                Edit1->Text = Dir;

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::myFinish(TObject *Sender)
{
//      DeleteFile(PLAYLIST);
        if ( FileExists(CONFIG) )
                if(!DeleteFile(CONFIG)){
                        return;
                }
        TStringList *TempList = new TStringList;
        try{
                TempList->Add(CFGPLAYER);
                TempList->Add(Edit2->Text);

                TempList->Add(CFGDIR);
                TempList->Add(PathString);

                TempList->Add(CFGLEFT);
                TempList->Add(Left);

                TempList->Add(CFGTOP);
                TempList->Add(Top);

                TempList->Add(CFGPLEFT);
                TempList->Add(PlayerLeft);

                TempList->Add(CFGPTOP);
                TempList->Add(PlayerTop);

                TempList->Add(CFGNEWPL);
                TempList->Add((int)CheckBox1->Checked);

                TempList->SaveToFile(CONFIG);
        }
        __finally{
                delete TempList;
        }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Button7Click(TObject *Sender)
{
        if(SongList->Items->Count == 0)
                return;
        AnsiString _File = MainPath;
        _File += "\\" + BandList->Items->Strings [BandList->ItemIndex] +
                "\\" + AlbumList->Items->Strings [AlbumList->ItemIndex] + "\\"
                        + SongList->Items->Strings [SongList->ItemIndex];
        char Ext[256];
        fnsplit(_File.c_str(),0, 0, 0, Ext);
        if(AnsiStrIComp(Ext,".MP3") & AnsiStrIComp(Ext,".WAV") & AnsiStrIComp(Ext,".WMA"))
                return;
        Form3->MediaPlayer->FileName = _File;
        Form3->SongLabel->Caption = SongList->Items->Strings [SongList->ItemIndex];
        Form3->myPlayerOpen();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::BandHoriz()
{
        int maxWidth = 0;
        for (int i=0;i<BandList->Items->Count; i++)
        {
                AnsiString text = BandList->Items->Strings[i];
                int w = BandList->Canvas->TextWidth(text);
                maxWidth = max(w, maxWidth);
        }

        BandList->Perform(LB_SETHORIZONTALEXTENT, maxWidth+5,0);

}

void __fastcall TMainForm::AlbumHoriz()
{
        int maxWidth = 0;
        for (int i=0;i<AlbumList->Items->Count; i++)
        {
                AnsiString text = AlbumList->Items->Strings[i];
                int w = AlbumList->Canvas->TextWidth(text);
                maxWidth = max(w, maxWidth);
        }

        AlbumList->Perform(LB_SETHORIZONTALEXTENT, maxWidth+5,0);
}

void __fastcall TMainForm::SongHoriz()
{
        int maxWidth = 0;
        for (int i=0;i<SongList->Items->Count; i++)
        {
                AnsiString text = SongList->Items->Strings[i];
                int w = SongList->Canvas->TextWidth(text);
                maxWidth = max(w, maxWidth);
        }

        SongList->Perform(LB_SETHORIZONTALEXTENT, maxWidth + 20,0);
}
