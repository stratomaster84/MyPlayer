//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

#define ExtNums 6  //����������� �������������� ��������
          //�������������� �������
const char Extens[ExtNums][6] =  {"*.mp3","*.wav","*.mid","*.cda","*.wma","*.ogg"} ;

      //������� ���������� ������ (��������� � Filenames)
void FindFiles(TStrings *Filenames,const AnsiString PathFolder);
      //������� ���������� �����  (��������� � Folders)
void FindFolders(TStrings *Folders,const AnsiString PathFolder);

AnsiString GetMainPath(AnsiString myStr);
extern AnsiString MainPath; //�������� ������� ������� �����
extern AnsiString PathString;    //�������� ������� ������� ����� (���. ���� ������� � ���������)
//---------------------------------------------------------------------------
#endif
 