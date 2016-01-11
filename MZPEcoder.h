char DOSstring[] = "Only Win32";
conc(DOSstring,"$");

//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru) Vladikavkaz, Russia\nPacked...\n\n",
	conc (MZComStrOa[0],MZComStr[6]);
	conc (MZComStrOa[0],MZComStr[0]);
	conc (MZComStrOa[0],MZComStr[1]);
	conc (MZComStrOa[0],MZComStr[2]);
	conc (MZComStrOa[0],MZComStr[4]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru) Vladikavkaz, Russia\nPacked\n\n",
	conc (MZComStrOa[1],MZComStr[6]);
	conc (MZComStrOa[1],MZComStr[0]);
	conc (MZComStrOa[1],MZComStr[1]);
	conc (MZComStrOa[1],MZComStr[2]);
	conc (MZComStrOa[1],MZComStr[5]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru) RSO-A, RUS\nPacked...\n\n",
	conc (MZComStrOa[2],MZComStr[6]);
	conc (MZComStrOa[2],MZComStr[0]);
	conc (MZComStrOa[2],MZComStr[1]);
	conc (MZComStrOa[2],MZComStr[3]);
	conc (MZComStrOa[2],MZComStr[4]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru) RSO-A, RUS\nPacked\n\n",
	conc (MZComStrOa[3],MZComStr[6]);
	conc (MZComStrOa[3],MZComStr[0]);
	conc (MZComStrOa[3],MZComStr[1]);
	conc (MZComStrOa[3],MZComStr[3]);
	conc (MZComStrOa[3],MZComStr[5]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru)\nPacked...\n\n",
	conc (MZComStrOa[4],MZComStr[6]);
	conc (MZComStrOa[4],MZComStr[0]);
	conc (MZComStrOa[4],MZComStr[1]);
	conc (MZComStrOa[4],MZComStr[4]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru)\nPacked\n\n",
	conc (MZComStrOa[5],MZComStr[6]);
	conc (MZComStrOa[5],MZComStr[0]);
	conc (MZComStrOa[5],MZComStr[1]);
	conc (MZComStrOa[5],MZComStr[5]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij Vladikavkaz, Russia\nPacked\n\n",
	conc (MZComStrOa[6],MZComStr[6]);
	conc (MZComStrOa[6],MZComStr[0]);
	conc (MZComStrOa[6],MZComStr[2]);
	conc (MZComStrOa[6],MZComStr[5]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij (LodestaRgr@yandex.ru)\n\n",
	conc (MZComStrOa[7],MZComStr[6]);
	conc (MZComStrOa[7],MZComStr[0]);
	conc (MZComStrOa[7],MZComStr[1]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij RSO-A, RUS\nPacked...\n\n",
	conc (MZComStrOa[8],MZComStr[6]);
	conc (MZComStrOa[8],MZComStr[0]);
	conc (MZComStrOa[8],MZComStr[3]);
	conc (MZComStrOa[8],MZComStr[4]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij Vladikavkaz, Russia\n\n",
	conc (MZComStrOa[9],MZComStr[6]);
	conc (MZComStrOa[9],MZComStr[0]);
	conc (MZComStrOa[9],MZComStr[2]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij RSO-A, RUS\nPacked\n\n",
	conc (MZComStrOa[10],MZComStr[6]);
	conc (MZComStrOa[10],MZComStr[0]);
	conc (MZComStrOa[10],MZComStr[3]);
	conc (MZComStrOa[10],MZComStr[5]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij RSO-A, RUS\n\n",
	conc (MZComStrOa[11],MZComStr[6]);
	conc (MZComStrOa[11],MZComStr[0]);
	conc (MZComStrOa[11],MZComStr[3]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij\nPacked..\n\n",
	conc (MZComStrOa[12],MZComStr[6]);
	conc (MZComStrOa[12],MZComStr[0]);
	conc (MZComStrOa[12],MZComStr[4]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij\nPacked\n\n",
	conc (MZComStrOa[13],MZComStr[6]);
	conc (MZComStrOa[13],MZComStr[0]);
	conc (MZComStrOa[13],MZComStr[5]);
//		"\n\n\n(C) 2004 Zemlyakov Jurij\n\n"
	conc (MZComStrOa[14],MZComStr[6]);
	conc (MZComStrOa[14],MZComStr[0]);


	int DOS_adr = 64;

	union 
	{
		unsigned char h1[1];
		unsigned short h2[1];
		unsigned long h4[1];
		char hx[128];
	}bufC;
//---------------------------------------------------------------------

		PHPFileFunctions fpO;
		fpO.open(_of,"r");
		if (fpO.exist!=true)
		{
			echo("ERROR:		File (" << _of << ") is not found\n");
			goto _end;
		}

		echo("Read File:		" << _of << endl);

		GetMZPEInfo oa(_of, _disp);

////////////////////////////////////////////////////////////////////////////////
		for (int i = 0; i < oa.MZ_peNumSect; i++)
		{
			if (oa.MZ_peSizH > oa.MZ_SarRawD[i] && oa.MZ_SarSize[i] > 0)
				oa.MZ_peSizH = oa.MZ_SarRawD[i];
		}

echo("Meby start date (Size of) Adr: " << dec << oa.MZ_peSizH << " (" << hex << oa.MZ_peSizH << "h) - save: " << dec << MZ_Ndate << " (" << hex << MZ_Ndate << "h)" << endl);
//echo("Возможное начало даты (Size of) с адреса: " << dec << oa.MZ_peSizH << " (" << hex << oa.MZ_peSizH << "h) - запись: " << dec << MZ_Ndate << " (" << hex << MZ_Ndate << "h)" << endl);

////////////////////////////////////////////////////////////////////////////////

	int MZ_Rdate = diff(oa.MZ_peSizH,MZ_Ndate);
	int MZ_Ndd_;
		MZ_Ndd_ = oa.MZ_peNumSect - 1;

	if (oa.MZ_peNumRVA > oa.MZ_peNumSect)
		for (int i = 0; i < oa.MZ_peNumRVA; i++)
			if (oa.MZ_peRVA_VAar[i] > 0 || oa.MZ_peRVA_SZar[i] > 0)
				MZ_Ndd_ = i+1;

	if (!MZ_Ndd) MZ_Ndd = MZ_Ndd_;

echo("Meby need only MZ_Ndd_ or " << dec << (MZ_Ndd_-1) << " IMAGE_SECTION_HEADERs iz " << dec << oa.MZ_peNumRVA << " - save: " << dec << MZ_Ndd << " (" << hex << MZ_Ndd << "h)" << endl);
//ech2("\nВозможно нужно только $MZ_Ndd_ или ".($MZ_Ndd_-1)." IMAGE_SECTION_HEADERs из ".$oa[11]." - запись: $MZ_Ndd (".dec2hex($MZ_Ndd)."h)\n");

////////////////////////////////////////////////////////////////////////////////

//$fpO = fopen($o,"rb");

		PHPFileFunctions fpN;
		fpN.open(_nf,"n");

	fpN.write(&oa.MZ_mzhead,2);			//Save:	Magic - MZ		DosHeader

///SAVE DOS CODE////////////////////////////////////////////////////////////////
if (MZDosON){
	*bufC.h2 = 0x524c;			//'LR'
	fpN.write(&bufC.h2,2);		//Bytes on last page of file
	*bufC.h2 = 3;
	fpN.write(&bufC.h2,2);		//Pages in file
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//Relocations
	*bufC.h2 = 4;
	fpN.write(&bufC.h2,2);		//Size of header in paragraphs
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//Minimum extra paragraphs heeded

// strlen($DOSbase[x]) должен / ровно на 4.

	char DOSbase[3][128] = {
		"\x0E\x1F\xBA\x0E\x01\xB4\x09\xCD\x21\xB8\x01\x4C\xCD\x21",
		"\xB0\x13\xCD\x10\xBA\xD4\x03\xB8\x16\x0F\xEF\xB4\x09\xBA\x64\x01\xCD\x21\x68\x00\xA0\x1F\x33\xF6\xBF\x80\x01\xB5\x05\xF3\xA5\xB8\x03\x00\xCD\x10\x68\x00\xB8\x1F\x1E\x07\x89\x07\xBA\xDA\x03\xEC\xA8\x08"
		"\x74\xFB\xBF\x20\x03\xBE\x22\x03\xB5\x03\xF3\xA5\xBF\xBF\x03\xBE\x80\x01\xB1\x08\x2E\x8A\x00\x40\xC0\xE0\x03\xAA\x81\xC7\x9F\x00\x81\xC6\x40\x01\xE2\xEE\xFE\xC3\xE4\x60\x48\x75\xCD\xB0\x03\xCD\x10\xC3",
		"\xBA\x0D\x01\xB4\x09\xCD\x21\xB8\x01\x4C\xCD\x21"
	};
	conc(DOSbase[0],DOSstring);
//	conc(DOSbase[1],DOSstring);

	int DOSbaselen[3] = {
		(int) strlen(DOSbase[0])+3,
		(int) 100,
		(int) strlen(DOSbase[2])
	};

//		0x0E1FBA0E & 0x01B409CD & 0x21B8014C & 0xCD21 & *DOSstring & 0x000000,
//		0xB013CD10 & 0xBAD403B8 & 0x160FEFB4 & 0x09BA6401 & 0xCD216800 & 0xA01F33F6 & 0xBF8001B5 & 0x05F3A5B8 & 0x0300CD10 & 0x6800B81F & 0x1E078907 & 0xBADA03EC & 0xA80874FB & 0xBF2003BE & 0x2203B503 & 0xF3A5BFBF & 0x03BE8001 & 0xB1082E8A & 0x0040C0E0 & 0x03AA81C7 & 0x9F0081C6 & 0x4001E2EE & 0xFEC3E460 & 0x4875CDB0 & 0x03CD10C3 & *DOSstring,
//		0xBA0D01B4 & 0x09CD21B8 & 0x014CCD21

	*bufC.h2 = 65535;
	fpN.write(&bufC.h2,2);		//Maximum extra paragraphs heeded
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//Initial (relative) SS value
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//Initial SS value *
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//Checksum
	*bufC.h2 = 256;
	fpN.write(&bufC.h2,2);		//Initial IP value *
	*bufC.h2 = 65520;
	fpN.write(&bufC.h2,2);		//Initial (relative) CS value *
	fpN.write(&DOS_adr,2);		//File address of relocation
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//Overlay number
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);		//Reserved words
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);		
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//OEM identifie (for e_oeminfo)
	*bufC.h2 = 0;
	fpN.write(&bufC.h2,2);		//OEM information; e_oemid specific
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);		//Reserved words
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);		
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);		
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);
	*bufC.h4 = ((unsigned long)fpN.tell()+4+strlen(DOSbase[MZDosBase]));
	fpN.write(&bufC.h4,4);		//File address of new exe header
								//MS-DOS Stub
	fpN.write(DOSbase[MZDosBase],DOSbaselen[MZDosBase]);

}else{
	char logo_[11] = "=LodestaR=";
	fpN.write(&logo_,10);
}

////////////////////////////////////////////////////////////////////////////////

long PE_adr = fpN.tell();
	*bufC.h4 = oa.MZ_pehead;
	fpN.write(&bufC.h4,4);		//Save:	Signature - PE		IMAGE_NT_HEADERS
	*bufC.h2 = oa.MZ_peMachine;
	fpN.write(&bufC.h2,2);		//Save:	Machine				IMAGE_FILE_HEADER
	*bufC.h2 = oa.MZ_peNumSect;
	fpN.write(&bufC.h2,2);		//Save:	NumberOfSection
								//Save:	TimeDateStamp

		if (TDStamp == 1)
		{
	    __time64_t ltime;
	    _time64( &ltime );
	*bufC.h4 = (unsigned long)ltime;
	fpN.write(&bufC.h4,4);
		}
		else if (TDStamp == 0)
		{
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);
		}
		else
		{
	*bufC.h4 = ImX(oa.MZ_peTime);
	fpN.write(&bufC.h4,4);
		}
	fpO.seek(oa.MZ_peadr+4+2+2+4);

	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: PointToSymbolTable
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: NumberOfSymbol
	*bufC.h2 = (unsigned short)(oa.MZ_peSizeOH-(oa.MZ_peNumRVA*8)+(MZ_Ndd*8));
	fpN.write(&bufC.h2,2);		//Save:	SizeOfOptionalHeader
	fpO.seek(2,1);
	fpO.read(2);
	*bufC.h2 = (unsigned short)fpO.rb;
	fpN.write(&bufC.h2,2);		//Save: Characteristics
	*bufC.h2 = (unsigned short)oa.MZ_pe2head;
	fpN.write(&bufC.h2,2);		//Save:	Magic - (010B)			IMAGE_OPTIONAL_HEADER
	fpO.seek(2,1);
	*bufC.h1 = Im1(fpO);
	fpN.write(&bufC.h1,1);		//Save: MajorLinkerVersion
	*bufC.h1 = Im1(fpO);
	fpN.write(&bufC.h1,1);		//Save: MinorLinkerVersion
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: SizeOfCode
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: SizeOfInitializedDate
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: SizeOfUninitializedDate
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: AddressOfEntryPoint
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: BaseOfCode
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: BaseOfDate (C0)
//	fpO.seek(4,1);
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: ImageBase
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: SectionAlignment
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: FileAlignment
	fpO.read(2);
	*bufC.h2 = (unsigned short)fpO.rb;
	fpN.write(&bufC.h2,2);		//Save: MajorOperatingSystemVersion
	fpO.read(2);
	*bufC.h2 = (unsigned short)fpO.rb;
	fpN.write(&bufC.h2,2);		//Save: MinorOperatingSystemVersion
	*bufC.h2 = (unsigned short)Im2(fpO);
	fpN.write(&bufC.h2,2);		//Save: MajorImageVersion
	*bufC.h2 = (unsigned short)Im2(fpO);
	fpN.write(&bufC.h2,2);		//Save: MinorImageVersion
	fpO.read(2);
	*bufC.h2 = (unsigned short)fpO.rb;
	fpN.write(&bufC.h2,2);		//Save: MajorSubsystemVersion
	fpO.read(2);
	*bufC.h2 = (unsigned short)fpO.rb;
	fpN.write(&bufC.h2,2);		//Save: MinorSubsystemVersion
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: Win32VersionValue
	*bufC.h4 = oa.MZ_peSizI;
	fpN.write(&bufC.h4,4);		//Save:	SizeOfImage
//save in buffer Size of address #1
unsigned long MZSof_1 = fpN.tell();
	*bufC.h4 = MZ_Ndate;
	fpN.write(&bufC.h4,4);		//Save:	SizeOfHeaders
	fpO.seek(4+4,1);
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: CheckSum
	fpO.read(2);
	*bufC.h2 = (unsigned short)fpO.rb;
	fpN.write(&bufC.h2,2);		//Save: Subsystem
	*bufC.h2 = Im2(fpO);
	fpN.write(&bufC.h2,2);		//Save: DllCharacteristics
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: SizeOfStackReserve
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: SizeOfStackCommit
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: SizeOfHeapReserve
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: SizeOfHeapCommit
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: LoaderFlags
	*bufC.h4 = MZ_Ndd;
	fpN.write(&bufC.h4,4);		//Save:	NumberOfRvaAndSizes
unsigned long MZ_Ndd_adr = fpN.tell();

	for (int i = 0; i < MZ_Ndd; i++)
	{
		if (i > oa.MZ_peNumRVA - 1)
		{
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);
	fpN.write(&bufC.h4,4);
		}
		else
		{
	*bufC.h4 = oa.MZ_peRVA_VAar[i];
	fpN.write(&bufC.h4,4);		//Save:	IMAGE_DATA_DIRECTORYS - VirtualSize
	*bufC.h4 = oa.MZ_peRVA_SZar[i];
	fpN.write(&bufC.h4,4);		//Save:	IMAGE_DATA_DIRECTORYS - Size
		}
	}
	fpO.seek(4+(oa.MZ_peNumRVA*8),1);

	int MZSof_2[] = {0};
//unsigned long MZSof_2b;
//MZSof_2 = new unsigned long [];
//MZSof_2b = MZSof_2;
//PHP: $MZSof_2 = array();

	for (int i = 0; i < oa.MZ_peNumSect; i++)
	{
		if(!Cs)
	fpN.write(oa.MZ_SarName[i],8);
		else
		{
	*bufC.h4 = 0;
	fpN.write(&bufC.h4,4);		//Save: Name			IMAGE_SECTION_HEADERs	1-4 byte
	fpN.write(&bufC.h4,4);		//Save: Name			IMAGE_SECTION_HEADERs	5-8 byte
		}
	fpO.seek(8,1);

	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: VirtualSize
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: VirtualAddress
	*bufC.h4 = oa.MZ_SarSize[i];
	fpN.write(&bufC.h4,4);		//Save: SizeOfRawData
//save in buffer Size of address #2
*MZSof_2 += fpN.tell();
//PHP: $MZSof_2[] = ftell($fpN);

	*bufC.h4 = oa.MZ_SarRawD[i] + MZ_Rdate;
	fpN.write(&bufC.h4,4);		//Save: PointerToRawData
	fpO.seek(8,1);
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: PointerToRelocations
	*bufC.h4 = Im4(fpO);
	fpN.write(&bufC.h4,4);		//Save: PointerToLinenumbers
	*bufC.h2 = Im2(fpO);
	fpN.write(&bufC.h2,2);		//Save: NumberOfRelocations
	*bufC.h2 = Im2(fpO);
	fpN.write(&bufC.h2,2);		//Save: NumberOfLinenumbers
	fpO.read(4);
	*bufC.h4 = fpO.rb;
	fpN.write(&bufC.h4,4);		//Save: Characteristics
	};

//- ReBuild ---------------------------------------------

int MZSof = fpN.tell();

if (MZSof > MZ_Ndate) {
echo("Change start date (Size of) s " << dec << MZ_Ndate << " (" << hex << MZ_Ndate << "h) na " << dec << (MZ_Ndate+512) << " (" << hex << (MZ_Ndate+512) << "h)" << endl);
// ech2("Замена начала даты (Size of) с $MZ_Ndate (".dec2hex($MZ_Ndate)."h) на ".($MZ_Ndate+512)." (".dec2hex($MZ_Ndate+512)."h)\n");

	MZ_Ndate += 512;

//rebuild: start

	MZ_Rdate = diff(oa.MZ_peSizH, MZ_Ndate);
	*bufC.h4 = MZ_Ndate;
	freb(fpN, MZSof_1, &bufC.h4, 4);	//ReSave: SizeOfHeaders
 for (int i = 0; i < sizeof(MZSof_2); i++){
	 *bufC.h4 = oa.MZ_SarRawD[i]+MZ_Rdate;
	 freb(fpN, MZSof_2[i], &bufC.h4, 4);	//ReSave: SizeOfHeaders
 }

	fpN.seek(MZSof);

//rebuild: end

}

//установка адреса PE header
	*bufC.h4 = DOS_adr;
	freb(fpN, 24, &bufC.h4, 4);
	*bufC.h4 = PE_adr;
	freb(fpN, 60, &bufC.h4, 4);
echo("Save: Dos Addres - " << dec << DOS_adr << " (" << hex << DOS_adr << "h), PE Addres - " << dec << PE_adr << " (" << hex << PE_adr << "h)" << endl);
//ech2("Запись: Dos Addres - $DOS_adr (".dec2hex($DOS_adr)."h), PE Addres - $PE_adr (".dec2hex($PE_adr)."h)\n");

//-------------------------------------------------------

// Save My _ LOGOS Information
int reserv;
if (MZComment){
	reserv = MZ_Ndate-(MZ_Ndate+diff(MZ_Ndate,fpN.tell()));

	char* MZComStrO = AULogo(reserv);
   if ( strlen(MZComStrO) > 1 && ((unsigned)reserv >= strlen(MZComStrO)) )
   {
	fpN.write(MZComStrO,(int)strlen(MZComStrO));	//Save: My Logos
	reserv = (MZ_Ndate-(MZ_Ndate+diff(MZ_Ndate,fpN.tell())));
	for (int i = 0; i < reserv;i++)
		fpN.write("\n",1);
echo("Save Autor information on " << dec << (int)strlen(MZComStrO) << " + " << dec << i << " = " << ((int)strlen(MZComStrO)+i) << " byte(s)." << endl);
//	ech2("Сохранена Информация об авторе на ".strlen($MZComStrO)." + $i = ".(strlen($MZComStrO)+$i)." байтах.\n");
   }
   else
   {
	MZComment = -1;
echo("Autor information MZPE-ReBuilder not size date" << endl);
//	ech2("Информация об авторе MZPE-ReBuilder неуместилась в файле.\n");
   }
}

//MZDosBase - 2
if (MZDosON && MZDosBase == 2){
	int st_DBt = MZ_Ndd_adr + (8*(MZDB2_v1-1));
	if (MZComment<0 && MZDB2_v0==1 && MZ_Ndd>=MZDB2_v1+5){
			int Ndd_Reserv = MZ_Ndd;
		if (MZ_Ndd > 9) Ndd_Reserv = 9;
		reserv = (Ndd_Reserv*8)-((MZDB2_v1-1)*8)-11;
		*bufC.h2 = unsigned short (st_DBt-DOS_adr+256);
		freb(fpN,(DOS_adr+1),&bufC.h2,2);
//		echo(endl << AULogo(reserv) << endl);
		freb(fpN,st_DBt,AULogo(reserv),(int)strlen(AULogo(reserv)));

//		freb($fpN,$st_DBt,"Only Win32".AULogo($reserv)."$");
echo("MZDosBase " << dec << MZDosBase << ": saved Information on autor in IMAGE_SECTION_HEADERs - " << dec << MZDB2_v1 << endl << endl << "(Please TESTED)" << endl);
//ech2("MZDosBase $MZDosBase: записала Информацию об авторе в IMAGE_SECTION_HEADERs - $MZDB2_v1\n\n(необходим ТЕСТ)\n");
	}else if (MZDB2_v0==1 && MZ_Ndd>=MZDB2_v1+1){
		*bufC.h2 = unsigned short (st_DBt-DOS_adr+256);
		freb(fpN,(DOS_adr+1),&bufC.h2,2);
		freb(fpN,st_DBt,DOSstring,(int)strlen(DOSstring));
	}else{
		*bufC.h2 = unsigned short (PE_adr-DOS_adr+8+256);
		freb(fpN,(DOS_adr+1),&bufC.h2,2);
		freb(fpN,PE_adr+8,DOSstring,(int)strlen(DOSstring));
echo("WARNING!: MZDosBase " << dec << MZDosBase << "MEBY error in save!" << endl);
//ech2("ВНИМАНИЕ!: MZDosBase $MZDosBase ВОЗМОЖНО записана с ошибкой!\n");
	}
}
//-----------------------------------------------

fpN.seek(MZ_Ndate);
	if (SoH)
	{
echo("Manual reading date on " << dec << SoH << " (" << hex << SoH << "h)" << endl);
//ech2("Ручное чтение даты с $SoH (".dec2hex($SoH)."h)\n");
		fpO.seek(SoH);
	}
	else
	{
		echo("SETUP" << hex << oa.MZ_peSizH);
		fpO.seek(oa.MZ_peSizH);
	}

	int bufLINE = 128;
//echo(dec << oa.MZ_filsize << " - " << oa.MZ_peSizH << endl);

for (int i = 0; i < (oa.MZ_filsize-oa.MZ_peSizH); i=i+128){
	if (((oa.MZ_filsize-oa.MZ_peSizH)-i) < bufLINE) bufLINE = (oa.MZ_filsize-oa.MZ_peSizH)-i;
	fpO.read(bufLINE);
	fpN.write(fpO.rc, bufLINE);		//Save: All Data
}
	fpN.close();
	fpO.close();

echo("Poste preobrazovania file mojno vospolzovotsia utilitoi \"PE Tools\", \na imenno - \"Rebuild PE\" dlya dostijenia naibolee luchshego effecta sjatia.\nEnjoy." << endl);
//ech2("\nПосле преобразование файла можно воспользоваться \nутилитой \"PE Tools\", а именно - \"Rebuild PE\" \nдля достяжения наиболее лучшего эффекта сжатия.\nEnjoy.");

