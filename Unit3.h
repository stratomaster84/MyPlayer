//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MPlayer.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TMediaPlayer *MediaPlayer;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TScrollBar *TrackBar;
        TLabel *SongLabel;
        TLabel *TimeLabel;
        TLabel *TimeLabel2;
        TLabel *LengthLabel;
        TLabel *PercentLabel;
        void __fastcall myPlayerClose(TObject *Sender,
          TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall TrackBarScroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall myPlayerOpen();

private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
        void __fastcall TrackPlay();
};

//---------------------------------------------------------------------------

extern PACKAGE TForm3 *Form3;
extern float OneTick;
extern bool PlayerPaused;
#define MAXBARTICK 100
//---------------------------------------------------------------------------
#endif
