//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <dir.h>

AnsiString MainPath; //см. "Unit2.h"
AnsiString PathString;  //см. "Unit2.h"

void FindFiles(TStrings *Filenames,const AnsiString PathFolder)
{
        int Attrib=0x2F;  //любые аттрибуты файлов (кроме папок)
        TSearchRec Recording;
        AnsiString TempFolder;
        for(int i=0;i<ExtNums;i++){  //Находим все поддерживаемые файлы
                TempFolder = PathFolder + Extens[i]; //Путь + расширение = Маска поиска файлов
                if(!FindFirst(TempFolder,Attrib,Recording)){ //Находим первый файл...
                        do{
                                Filenames->Add(Recording.Name);   //Добавляем найденный файл в Filenames
                        }while(!FindNext(Recording)) ;
                        FindClose(Recording); //Завершаем поиск
                }
        }
        return;
}
 //---------------------------------------------------------------------------

void FindFolders(TStrings *Folders,const AnsiString PathFolder)
{
        int Attrib=0x3f;     //любые аттрибуты файлов (кроме папок)
        TSearchRec Recording;
        if(!FindFirst(PathFolder + "*.*",Attrib,Recording)){ //Находим любой первый файл
                do{
                        if( (Recording.Attr & faDirectory) && Recording.Name != ".." )
                                //Если это каталог (и не родительский каталог)...
                                Folders->Add(Recording.Name); // ...заносим его в Folders
                }while(!FindNext(Recording)) ;
                FindClose(Recording); //Завершаем поиск
        }
        if(Folders->Count == 0 || Folders->Strings[0] != ".")
                //Если не было найдено папок В КОРНЕВОМ КАТАЛОГЕ ДИСКА...
                Folders->Add("."); //...добавляем корневой каталог
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
 