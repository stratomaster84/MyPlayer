//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <dir.h>

AnsiString MainPath; //��. "Unit2.h"
AnsiString PathString;  //��. "Unit2.h"

void FindFiles(TStrings *Filenames,const AnsiString PathFolder)
{
        int Attrib=0x2F;  //����� ��������� ������ (����� �����)
        TSearchRec Recording;
        AnsiString TempFolder;
        for(int i=0;i<ExtNums;i++){  //������� ��� �������������� �����
                TempFolder = PathFolder + Extens[i]; //���� + ���������� = ����� ������ ������
                if(!FindFirst(TempFolder,Attrib,Recording)){ //������� ������ ����...
                        do{
                                Filenames->Add(Recording.Name);   //��������� ��������� ���� � Filenames
                        }while(!FindNext(Recording)) ;
                        FindClose(Recording); //��������� �����
                }
        }
        return;
}
 //---------------------------------------------------------------------------

void FindFolders(TStrings *Folders,const AnsiString PathFolder)
{
        int Attrib=0x3f;     //����� ��������� ������ (����� �����)
        TSearchRec Recording;
        if(!FindFirst(PathFolder + "*.*",Attrib,Recording)){ //������� ����� ������ ����
                do{
                        if( (Recording.Attr & faDirectory) && Recording.Name != ".." )
                                //���� ��� ������� (� �� ������������ �������)...
                                Folders->Add(Recording.Name); // ...������� ��� � Folders
                }while(!FindNext(Recording)) ;
                FindClose(Recording); //��������� �����
        }
        if(Folders->Count == 0 || Folders->Strings[0] != ".")
                //���� �� ���� ������� ����� � �������� �������� �����...
                Folders->Add("."); //...��������� �������� �������
        return;
}

//---------------------------------------------------------------------------
AnsiString GetMainPath(AnsiString myStr)
{
        AnsiString _main;
        if( fnsplit(myStr.c_str(),0,0,0,0) & DRIVE)
                _main = myStr + "\\";
        else
                _main = GetCurrentDir() + "\\" + myStr + "\\";
        int i,j;
        for(i=1;i<_main.Length();i++)
                if(_main[i] == '\\'){
                        for(j=i+1;j<=_main.Length() && _main[j] == '\\';j++);
                        _main.Delete(i,j -=(i+1));
                }
        return _main;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
 