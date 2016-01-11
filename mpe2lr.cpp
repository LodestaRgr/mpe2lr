#include "stdafx.h"
using namespace std;
#define echo(c) if(_disp) cout << c;
 
void conc (char *c1, char *c2)
{
   for (int m=0;c1[m]!='\0';m++);
   // m - длина первой строки.
   for (int i=0; c2[i]!='\0';i++)
      c1[m+i]=c2[i];
   c1[m+i] = '\0';
}

//Перезапись байта
void freb(PHPFileFunctions &_f, unsigned long _adr, void* _val, int _len)
{
	long _tell = _f.tell();
	_f.seek(_adr);
	_f.write(_val, _len);
	_f.seek(_tell);

}

//Разница между oa.MZ_peSizH и MZ_Ndate
int diff(int _x, int _y)
{
	if (_x > _y)
		return -(_x - _y);
	else if (_x < _y)
		return (_y - _x);
	else
		return 0;
}

int Im = 1;

long ImX(long _buf){
	if(Im)	return _buf;
	else	return 0;
}
unsigned char Im1(PHPFileFunctions &_f){
	_f.read(1);	
	if(Im)	return (unsigned char)_f.rb;
	else	return 0;
}
unsigned short Im2(PHPFileFunctions &_f){
	_f.read(2);	
	if(Im)	return (unsigned short)_f.rb;
	else	return 0;
}
unsigned long Im4(PHPFileFunctions &_f){
	_f.read(4);	
	if(Im)	return (unsigned long)_f.rb;
	else	return 0;
}

extern char MZComStr[7][25] = {
	"(C) 2005 Zemlyakov Jurij",	//1
	" (LodestaRgr@yandex.ru)",	//2
	" Vladikavkaz, Russia",		//3
	" RSO-A, RUS",				//4
	"\nPacked...",				//5
	"\nPacked",					//6
	"\n\n\n"					//7
};

extern char MZComStrOa[15][90] = {};

//Информация об авторе
char* AULogo(int _reserv)
{
	for (int i = 0; i < 14; i++){
		if( (unsigned)_reserv >= strlen(MZComStrOa[i]) )
			break;
	}
			return MZComStrOa[i];
};

int main(int argc,char *argv[], char *envp[])
{
	bool _disp = true;	//отоброжать текст на экран
	bool INFORMATION = false; //показать только информацию
	bool HELP_PAGE = false;	//страница с помощью
	bool HELP_MESSAGE = false;	//напоминание о том, что есть помощь
	bool IN_OUT_FILES = false; //проверка указания входящего и исходящего файла
	bool START = true;	//запуск кодировки


//- НАСТРОЙКИ ---------------------------------------------------------
int MZ_Ndate = 512;	//Начиналь дату (Size of) с 512 (200h)
int SoH = 0;		//Ручная установка копирования даты с SoH до конца (0-авто) Пример: с 1024 (400h)
int	Im = 1;			//Оставить миниматьную информацию (1-да, 0-нет)
int Cs = 1;			//Отчистить название секций (1-да, 0-нет)
int MZ_Ndd = 16;	//Число IMAGE_SECTION_HEADERs (0-авто)
					//Если MZ_Ndd < 16 тогда исчезает иконка
					//Если MZ_Ndd < 4 то неработает в Win 98
int MZDosON = 1;	//Записывает основу DOS (1-да, 0-нет)
					//Если 0 в Windows`е включается (Window console)
int MZDosBase = 2;	//Отображается только в Dos'е (0-Default,1-Graphic line,2-Default mini size)
 int MZDB2_v0 = 1;	//Парамитер для MZDosBase = 2: стиль записи 
					//Парамитер для MZDosBase = 2: 0 - в PE_head на Time Stamp и т.д.
					//Парамитер для MZDosBase = 2: 1 - в PE_head на IMAGE_SECTION_HEADERs
 int MZDB2_v1 = 5;	//Парамитер для MZDosBase = 2: запись текста с IMAGE_SECTION_HEADERs номер 
int MZComment = 1;	//Запись в файл информации об авторе MZPE-буилдера. (1-да, 0-нет)
int TDStamp = 2;	//Запись времени в файл (2-сохраненное, 1-текущее, 0-пусто)

	char *_of, *_nf, *argN;


	int argi = 1;

	while (argi<argc){
		if ((argv[argi][0] == char(*"/") || argv[argi][0] == char(*"-")) &&
			(strlen(argv[argi])>1)
			){	argN = argv[argi]+1;

			if (strcmp(argN, "dos" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=1){	
					MZDosON = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "dosb" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=2){	
					MZDosBase = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "dosb2" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=1){	
					MZDB2_v0 = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "dosb3" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=128){	
					MZDB2_v1 = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "ndd" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=512){	
					MZ_Ndd = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "comm" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=1){	
					MZComment = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "time" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=2){	
					TDStamp = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "ndat" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=102400){	
					MZ_Ndate = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "soh" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=102400){	
					SoH = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "im" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=1){	
					Im = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "cs" )==0)
			{
				if(atoi(argv[argi+1])>=0 && atoi(argv[argi+1])<=1){	
					Cs = atoi(argv[argi+1]);
				}
				argi++;
			}else
			if (strcmp(argN, "doff" )==0)
			{
					_disp = false;
			}else
			if (strcmp(argN, "i" )==0)
			{
					_of = (char*)argv[argi+1];
					INFORMATION = true;
					START = false;
				argi++;
			}else
			if (strcmp(argN, "?" )==0 || strcmp(argN, "h" )==0)
			{
					HELP_PAGE = true;
					HELP_MESSAGE = false;
			}
		}else{
			if(INFORMATION) break;
			else
			if(argc-argi == 2 && (argv[argi+1][0] != char(*"/") || argv[argi+1][0] == char(*"-")))
			{
				_of = (char*)argv[argi];
				_nf = (char*)argv[argi+1];
				IN_OUT_FILES = true;
			}
			else
			{
				HELP_MESSAGE = true;
				HELP_PAGE = false;
			}
			break;
		};
		argi++;
	};
//---------------------------------------------------------------------------------------
	echo("==[ MZ_PE 2 LR v1.0 ]=====[ (C) 2005 Zemlyakov Jurij (LodestaRgr@yandex.ru) ]==\n");

	if(HELP_MESSAGE || argc <= 1){
		echo("  mpe2lr /?\t- Help page\n");
		goto _end;
	}
	if(HELP_PAGE){
		echo("  Usage:\tmpe2lr\t-<options> [exec file] [out file]\n\n");
		echo("    dos [n]\t- MZDos mode on (1 - On, 0 - Off)\t\t<default: 1>\n");
		echo("    dosb [n]\t- MZDos base code\t\t\t\t<default: 2>\n");
		echo("\t\t  0 - Default (code)\n");
		echo("\t\t  1 - Graphics line (code)\n");
		echo("\t\t  2 - Default mini (code)\n");
		echo("    dosb2 [n]\t- only MZDos base 2 (dosb [2])\t\t\t<default: 1>\n");
		echo("\t\t  0 - in Time Stamp - string: Only win32\n");
		echo("\t\t  1 - in IMAGE_SECTION_HEADERs - string: Only win32\n");
		echo("    dosb3 [n]\t- only (dosb2 [1]) begin with (0 to IMG_SEC)\t<default: 5>\n");
		echo("    ndd [n]\t- Number IMAGE_SECTION_HEADERs (0 -Auto)\t<default: 16>\n");
		echo("\t\t  ndd < 16 - not visible a Icon\n");
		echo("\t\t  ndd < 4  - not work in Win 98/ME\n");
		echo("    comm [n]\t- MZ comments about Autor (1 - On, 0 - Off)\t<default: 1>\n");
		echo("    time [n]\t- save Date and Time create in file\t\t<default: 2>\n");
		echo("\t\t  0 - Original date\n");
		echo("\t\t  1 - Now date\n");
		echo("\t\t  2 - Empry code\n");
		echo("    ndat [n]\t- begin date (Size of)\t\t\t\t<default: 512>\n");
		echo("    soh [n]\t- manual set start copy date to end (0 - Auto)\t<default: 0>\n");
		echo("    im [n]\t- save minimal info in file (1 - On, 0 - Off)\t<default: 1>\n");
		echo("    cs [n]\t- clean names sections (1 - On, 0 - Off)\t<default: 1>\n");
		echo("    doff\t- not display on the screen\n");
		echo("\n  Example:\ttmpe2lr orig.exe new.exe\t\t<default configuration>\n");
		echo("\t\ttmpe2lr /dos 0 orig.exe new.exe\t\t<default configuration>\n");
		goto _end;
	}
	if(INFORMATION){
		echo("File Name:\t\t" << _of << "\n");
		GetMZPEInfo oa(_of, true);
		START = false;
	}else
	if(!IN_OUT_FILES){
		echo(" Error:\tNot specified in/out files.\n\n");
		START = false;
	}
	if (START){
		#include ".\MZPEcoder.h"	//Запуск кодировщика
	}
_end:
	echo("=================================================================[ complite ]==");
};

#undef echo