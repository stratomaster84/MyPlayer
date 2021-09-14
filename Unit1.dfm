object MainForm: TMainForm
  Left = 217
  Top = 152
  BorderStyle = bsDialog
  Caption = 'Musical Player'
  ClientHeight = 480
  ClientWidth = 634
  Color = clBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = myStart
  OnDestroy = myFinish
  PixelsPerInch = 96
  TextHeight = 13
  object BandLabel: TLabel
    Left = 72
    Top = 15
    Width = 73
    Height = 19
    Caption = #1043#1088#1091#1087#1087#1099':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    Transparent = True
  end
  object AlbumLabel: TLabel
    Left = 248
    Top = 16
    Width = 84
    Height = 19
    Caption = #1040#1083#1100#1073#1086#1084#1099':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    Transparent = True
  end
  object SongLabel: TLabel
    Left = 464
    Top = 16
    Width = 58
    Height = 19
    Caption = #1055#1077#1089#1085#1080':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    Transparent = True
  end
  object Label1: TLabel
    Left = 24
    Top = 424
    Width = 57
    Height = 19
    Caption = #1055#1083#1077#1077#1088':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    Transparent = True
  end
  object Label2: TLabel
    Left = 24
    Top = 384
    Width = 141
    Height = 19
    Caption = #1056#1072#1073#1086#1095#1072#1103' '#1055#1072#1087#1082#1072':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    Transparent = True
  end
  object BandList: TListBox
    Left = 24
    Top = 40
    Width = 185
    Height = 209
    ItemHeight = 13
    Sorted = True
    TabOrder = 0
    OnClick = BandListClick
  end
  object AlbumList: TListBox
    Left = 224
    Top = 40
    Width = 185
    Height = 209
    ItemHeight = 13
    Sorted = True
    TabOrder = 1
    OnClick = AlbumListClick
  end
  object Edit2: TEdit
    Left = 168
    Top = 424
    Width = 345
    Height = 21
    TabOrder = 2
  end
  object SongList: TCheckListBox
    Left = 424
    Top = 40
    Width = 185
    Height = 209
    ItemHeight = 13
    Sorted = True
    TabOrder = 3
  end
  object Button1: TButton
    Left = 536
    Top = 424
    Width = 73
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 4
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 168
    Top = 384
    Width = 345
    Height = 21
    TabOrder = 5
  end
  object Button2: TButton
    Left = 536
    Top = 384
    Width = 73
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 24
    Top = 312
    Width = 105
    Height = 25
    Caption = #1048#1075#1088#1072#1090#1100' '#1072#1083#1100#1073#1086#1084
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 168
    Top = 312
    Width = 161
    Height = 25
    Caption = #1048#1075#1088#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1091#1102' '#1087#1077#1089#1085#1102
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 352
    Top = 312
    Width = 161
    Height = 25
    Caption = #1048#1075#1088#1072#1090#1100' '#1086#1090#1084#1077#1095#1077#1085#1085#1099#1077' '#1087#1077#1089#1085#1080
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 168
    Top = 352
    Width = 345
    Height = 25
    Caption = #1055#1077#1088#1077#1081#1090#1080' '#1085#1072' '#1085#1086#1074#1091#1102' '#1088#1072#1073#1086#1095#1091#1102' '#1087#1072#1087#1082#1091
    TabOrder = 10
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 168
    Top = 272
    Width = 345
    Height = 25
    Hint = #1058#1086#1083#1100#1082#1086' MP3, WMA '#1080' WAV '#1092#1086#1088#1084#1072#1090#1099
    BiDiMode = bdRightToLeft
    Caption = #1048#1075#1088#1072#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1091#1102' '#1087#1077#1089#1085#1102' '#1074#1089#1090#1088#1086#1077#1085#1085#1085#1099#1084'  '#1087#1083#1077#1077#1088#1086#1084
    ParentBiDiMode = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 11
    OnClick = Button7Click
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 272
    Width = 105
    Height = 25
    Caption = #1053#1086#1074#1099#1081' '#1087#1083#1077#1081#1083#1080#1089#1090
    TabOrder = 12
  end
  object OpenDialog: TOpenDialog
    Filter = #1055#1088#1080#1083#1086#1078#1077#1085#1080#1077' (*.exe)|*.exe'
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 8
    Top = 8
  end
end
