//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
float OneTick;
bool PlayerPaused = false; // or Stopped == true
bool AlreadyPlay = false;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::myPlayerClose(TObject *Sender,
      TCloseAction &Action)
{
        TrackBar->Position = 0;
        MediaPlayer->Close();
        MainForm->Enabled = true;
        Visible = false;
        PlayerLeft = Left;
        PlayerTop = Top;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
        TrackPlay();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
        if(MediaPlayer->Mode == mpStopped && PlayerPaused)
                TrackPlay();
        else if( MediaPlayer->Mode != mpStopped ){
                MediaPlayer->Stop();
                PlayerPaused = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button3Click(TObject *Sender)
{
        MediaPlayer->Stop();
        MediaPlayer->Position = 0;
        TrackBar->Position = 0;
        TimeLabel->Caption = "0:00";
        PlayerPaused = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::TrackBarScroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
        int MediaMode;
        if(ScrollCode == scEndScroll){
                MediaMode = MediaPlayer->Mode;
                MediaPlayer->Position = (int)(TrackBar->Position*OneTick);
                TimeLabel2->Visible = false;
                LengthLabel->Visible = false;
                PercentLabel->Visible = false;
                TimeLabel->Caption=TimeLabel->Caption.sprintf("%d:%02d",
                        (int)(MediaPlayer->Position/60000),(int)((MediaPlayer->Position%60000)/1000));
        }
        else {
                TimeLabel2->Caption = TimeLabel2->Caption.sprintf("%d:%02d",
                        (int)(ScrollPos*OneTick/60000),(int)(((int)(ScrollPos*OneTick)%60000)/1000));
                PercentLabel->Caption = PercentLabel->Caption.sprintf("(%d%)",
                        (int)(ScrollPos*100/TrackBar->Max));
                (int)(TrackBar->Position/TrackBar->Max)*100;
                TimeLabel2->Visible = true;
                LengthLabel->Visible = true;
                PercentLabel->Visible = true;
                return;
        }
        if(MediaMode == mpPlaying)
                MediaPlayer->Play();

}
//---------------------------------------------------------------------------


void __fastcall TForm3::TrackPlay()
{
        if(AlreadyPlay)
                return;
        MediaPlayer->Play();
        AlreadyPlay = true;
        while(MediaPlayer->Mode == mpPlaying ){
                TimeLabel->Caption=TimeLabel->Caption.sprintf("%d:%02d",
                        (int)(MediaPlayer->Position/60000),(int)((MediaPlayer->Position%60000)/1000));
                TrackBar->Position =(int)(MediaPlayer->Position/OneTick);
                Application->ProcessMessages();
        }
        AlreadyPlay = false;
}

//---------------------------------------------------------------------------

void __fastcall TForm3::myPlayerOpen()
{
        try{
                MediaPlayer->Open();
        }
        catch (...){
                Application->MessageBox(MediaPlayer->ErrorMessage.c_str(),"Error!!!", MB_OK);
                return;
        }
        Left = PlayerLeft;
        Top = PlayerTop;
        Visible = true;
        MainForm->Enabled = false;
        TrackBar->Max = MediaPlayer->Length>MAXBARTICK?MAXBARTICK:MediaPlayer->Length;
        OneTick = (float)(MediaPlayer->Length/TrackBar->Max);
        TimeLabel->Caption = "0:00";
        TimeLabel2->Caption = "0:00";
        PercentLabel->Caption = "(0%)";
        LengthLabel->Caption = "/" + LengthLabel->Caption.sprintf("%d:%02d",
                        (int)(MediaPlayer->Length/60000),(int)((MediaPlayer->Length%60000)/1000));
        Form3->TimeLabel2->Visible = false;
        Form3->LengthLabel->Visible = false;
        Form3->PercentLabel->Visible = false;
        TrackPlay();
}
//---------------------------------------------------------------------------

