#pragma once

class GetMZPEInfo
{
/*
 0		MZ_filsize
 1		MZ_mzhead
 2		MZ_peadr
 3		MZ_pehead
 4		MZ_peMachine
 5		MZ_peNumSect
 6		MZ_peTime
 7		MZ_peSizeOH
 8		MZ_pe2head
 9		MZ_peSizI
10		MZ_peSizH
11		MZ_peNumRVA
12		MZ_peRVAar		MZ_peRVA_VAar, MZ_peRVA_SZar
13		MZ_SarName
14		MZ_SarSize
15		MZ_SarRawD
*/
private:
	#define echo(c) if(_disp)cout << c;

public:
	int _disp;
	//= true;	//отоброжать текст на экран
	short MZ_mzhead, MZ_peMachine, MZ_peNumSect;
	long MZ_filsize, MZ_peadr, MZ_pehead,
		 MZ_peTime, MZ_peSizeOH, MZ_pe2head, MZ_peSizI, MZ_peSizH, MZ_peNumRVA,
		 *MZ_SarSize, *MZ_SarRawD, *MZ_peRVA_VAar, *MZ_peRVA_SZar;
	char (*MZ_SarName)[9];

//	char MZ_SarName[16][9];

	GetMZPEInfo(char *_fname, bool _disp = true){

		PHPFileFunctions fo;
		fo.open(_fname,"r");
		if (fo.exist!=true) return;
		MZ_filsize = fo.filesize();					//File size

	echo("File Size:		");
		if (MZ_filsize > 63)
		{
			echo(MZ_filsize << " byte" << endl);
		}
		else
		{
			echo("file very SMALL" << endl);
			return;
		}
			fo.seek(0);
			fo.read(2);
		MZ_mzhead = fo.rb;							//Signature - MZ

	echo("Signature MZ:		");
		if (MZ_mzhead == 23117)
		{
			echo("OK !" << "				(" << hex << MZ_mzhead << "h)" << endl);
		}
		else
		{
			echo("don`t exist." << "			(" << hex << MZ_mzhead << "h)" << endl);
			return;
		}
			fo.seek(60);
			fo.read(4);
		MZ_peadr = fo.rb;							//Addres PE header

	echo("Address - PE header:	");
		if (MZ_peadr > 2)
		{
			echo(dec << MZ_peadr << "				(" << hex << MZ_peadr << "h)" << endl);
		}
		else
		{
			echo("is not correct." << "			(" << hex << MZ_peadr << "h)" << endl);
			return;
		}
			fo.seek(MZ_peadr);
			fo.read(4);
		MZ_pehead = fo.rb;							//Signature - PE

	echo("Signature PE:		");
		if (MZ_pehead == 17744)
		{
			echo("OK !" << "				(" << hex << MZ_pehead << "h)" << endl);
		}
		else
		{
			echo("don`t exist." << "				(" << hex << MZ_pehead << "h)" << endl);
			return;
		}
			fo.read(2);
		MZ_peMachine = fo.rb;						//Machine

	echo("Machine:		");
		switch (MZ_peMachine)
		{
			case 332	:	echo("Intel 386");break;
			case 354	:	echo("MIPS (R2000, R3000)");break;
			case 358	:	echo("MIPS (R4000)");break;
			case 360	:	echo("MIPS (R10000)");break;
			case 361	:	echo("MIPS WCE v2");break;
			case 388	:	echo("DEC Alpha");break;
			case 496	:	echo("IBM PowerPC");break;
			case 418	:	echo("Hitachi SH-3");break;
			case 420	:	echo("Hitachi SH-3E");break;
			case 422	:	echo("Hitachi SH-4");break;
			case 448	:	echo("ARM");break;
			case 450	:	echo("Thumb");break;
			case 512	:	echo("Intel 64");break;
			case 614	:	echo("MIPS 16");break;
			case 870	:	echo("MIPS FPU");break;
			case 1126	:	echo("MIPS FPU 16");break;
			case 644	:	echo("Alpha 64/AXP 64");break;
			case 1312	:	echo("Tricore");break;
			case 34404	:	echo("AMD 64");break;
			case 36929	:	echo("M32R");break;
			case 3772	:	echo("EBC");break;
			case 3311	:	echo("CEF");break;
			case 49390	:	echo("CEE");break;
			default		:	echo("Unknown	");
       }
		echo("			(" << hex << MZ_peMachine << "h)" << endl);
			fo.read(2);
		MZ_peNumSect = fo.rb;						//Number Of Section

	echo("Number of Sections:	" << dec << MZ_peNumSect << "				(" << hex << MZ_peNumSect << "h)" << endl);
			fo.read(4);
		MZ_peTime = fo.rb;							//Time Data Stamp

	echo("Time Data Stamp:	" << time << MZ_peTime << "		(" << hex << MZ_peTime << "h)" <<endl);
			fo.seek(8,1);
			fo.read(2);
		MZ_peSizeOH = fo.rb;						//Size Of Optional Header

	echo("SizeOfOptionalHeader:	" << dec << MZ_peSizeOH << "				(" << hex << MZ_peSizeOH << "h)" << endl);
			fo.seek(2,1);
			fo.read(2);
		MZ_pe2head = fo.rb;							//Signature PE 2

	echo("Signature PE 2:		");
		if (MZ_pe2head == 267)
		{
			echo("exist (Magic Header)		(" << hex << MZ_pe2head << "h)" << endl);
		}
		else
		{
			echo("don`t exist." << endl);
			return;
		}
			fo.seek(13*4+2,1);
			fo.read(4);
		MZ_peSizI = fo.rb;							//Size Of Image

	echo("Size Of Image:		" << dec << MZ_peSizI << "				(" << hex << MZ_peSizI << "h)" << endl);
			fo.read(4);
		MZ_peSizH = fo.rb;							//Size Of Headers

	echo("Size Of Headers:	" << dec << MZ_peSizH << "				(" << hex << MZ_peSizH << "h)" << endl);
			fo.seek(7*4,1);
			fo.read(4);
		MZ_peNumRVA = fo.rb;						//Number Of RVA and Size

	echo("NumberOfRvaAndSize:	" << dec << MZ_peNumRVA << "				(" << hex << MZ_peNumRVA << "h)" << endl);

		long *MZ_peRVA_VAarb;
		MZ_peRVA_VAar = new long [MZ_peNumRVA];					//RVA Data Directory - VirtualAdress
		MZ_peRVA_VAarb = MZ_peRVA_VAar;

		long *MZ_peRVA_SZarb;
		MZ_peRVA_SZar = new long [MZ_peNumRVA];					//RVA Data Directory - Size
		MZ_peRVA_SZarb = MZ_peRVA_SZar;

			for (int i = 0; i < MZ_peNumRVA; i++){
//				fo.seek(8,1);
				fo.read(4);
				MZ_peRVA_VAarb[i] = fo.rb;
//				echo("[" << hex << fo.rb << "]");
//				echo("[" << hex << MZ_peRVA_VAar[i] << "]");
				fo.read(4);
				MZ_peRVA_SZarb[i] = fo.rb;
//				echo("[" << hex << fo.rb << "]");
//				echo("[" << hex << MZ_peRVA_SZar[i] << "]" << endl);
			}
//		delete [] MZ_peRVA_VAar;
//		delete [] MZ_peRVA_SZar;
//			char (*pchar)[10] = new char[][10];

		char (*MZ_SarNameb)[9] = new char [MZ_peNumSect][9];
		MZ_SarName = MZ_SarNameb;						//Section Name - Array

		long *MZ_SarSizeb;
		MZ_SarSize = new long [MZ_peNumSect];						//Section Address - Array
		MZ_SarSizeb = MZ_SarSize;

		long *MZ_SarRawDb;
		MZ_SarRawD = new long [MZ_peNumSect];						//Section Address - Array
		MZ_SarRawDb = MZ_SarRawD;

			for (int i = 0; i < MZ_peNumSect; i++)
			{
				fo.read(8);	
//					MZ_SarNameb[i] = fo.rc;
				for (int j=0;j<9;j++)
					MZ_SarNameb[i][j] = fo.rc[j];
				fo.seek(2*4,1);
				fo.read(4);
				MZ_SarSizeb[i] = fo.rb;			
				fo.read(4);
				MZ_SarRawDb[i] = fo.rb;
				fo.seek(4*4,1);
			}
//			delete [] MZ_SarRawDb;

		for (int i = 0; i < MZ_peNumSect; i++){
//		if (MZ_SarName[i]!=0x0)
//		{
	echo("Section " << dec << (i+1) << ":		");
	echo(MZ_SarName[i] << " (Adr: " << dec << MZ_SarRawD[i] << " - " << hex << MZ_SarRawD[i] << "h)");
	echo(" (Size: " << dec << MZ_SarSize[i] << " - " << hex << MZ_SarSize[i] << "h)" << endl);
//		}
		}
		fo.close();
	};
//	~GetMZPEInfo(void);
private:
	#undef echo
};
