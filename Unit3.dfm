object Form3: TForm3
  Left = 422
  Top = 391
  BorderStyle = bsDialog
  Caption = 'Internal Player'
  ClientHeight = 159
  ClientWidth = 473
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = myPlayerClose
  PixelsPerInch = 96
  TextHeight = 13
  object SongLabel: TLabel
    Left = 0
    Top = 0
    Width = 473
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Bookman Old Style'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object TimeLabel: TLabel
    Left = 24
    Top = 48
    Width = 78
    Height = 22
    Alignment = taRightJustify
    AutoSize = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold]
    ParentFont = False
    Transparent = True
  end
  object TimeLabel2: TLabel
    Left = 176
    Top = 64
    Width = 41
    Height = 17
    Alignment = taRightJustify
    AutoSize = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Bookman Old Style'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object LengthLabel: TLabel
    Left = 216
    Top = 64
    Width = 41
    Height = 17
    AutoSize = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Bookman Old Style'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object PercentLabel: TLabel
    Left = 256
    Top = 64
    Width = 41
    Height = 17
    AutoSize = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Bookman Old Style'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object MediaPlayer: TMediaPlayer
    Left = 112
    Top = 136
    Width = 253
    Height = 20
    Visible = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 104
    Width = 121
    Height = 25
    Caption = 'Играть'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 192
    Top = 104
    Width = 105
    Height = 25
    Caption = 'Пауза'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 320
    Top = 104
    Width = 105
    Height = 25
    Caption = 'Остановить'
    TabOrder = 3
    OnClick = Button3Click
  end
  object TrackBar: TScrollBar
    Left = 24
    Top = 80
    Width = 425
    Height = 9
    PageSize = 0
    TabOrder = 4
    OnScroll = TrackBarScroll
  end
end
