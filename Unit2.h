//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#define ExtNums 6  //Колличество поддерживаемых форматов
          //Поддерживаемые форматы
const char Extens[ExtNums][6] =  {"*.mp3","*.wav","*.mid","*.cda","*.wma","*.ogg"} ;

      //Функция нахождения файлов (результат в Filenames)
void FindFiles(TStrings *Filenames,const AnsiString PathFolder);
      //Функция нахождения папок  (результат в Folders)
void FindFolders(TStrings *Folders,const AnsiString PathFolder);

AnsiString GetMainPath(AnsiString myStr);
extern AnsiString MainPath; //Содержит текущую рабочую папку
extern AnsiString PathString;    //Содержит текущую рабочую папку (кот. была введена в программе)
//---------------------------------------------------------------------------
#endif
 