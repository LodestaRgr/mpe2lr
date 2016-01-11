#pragma once

class PHPFileFunctions
{
public:
	bool exist;
	unsigned long rb;
	char *rc;
//--ÎÒÊĞÛÂÀÅÒ ÔÀÉË ------------------------
	void open(char* _fname, char* _ctype)
	{
		int _type=0, _type2=0;
		if		(_ctype=="r")
		{
			_type=_O_RDONLY | _O_BINARY;
		}
		else if (_ctype=="w")
		{
			_type=	_O_CREAT |  _O_RDWR | _O_BINARY;
			_type2=	_S_IREAD | _S_IWRITE;
		}
		else if (_ctype=="n")
		{
			_type=	_O_TRUNC | _O_CREAT |  _O_RDWR | _O_BINARY;
			_type2=	_S_IREAD | _S_IWRITE;
		}
		else
            _type=	-1;
		
		if(_type == -1)
			fp = -1;
		else
			fp = _open(_fname, _type, _type2);

		if( fp == -1)
		{
			exist = false;
		}else
			exist = true;
	}
//--Ñ×ÈÒÛÂÀÅÒ ÈÇ ÔÀÉËÀ --------------------
	void read(int _len)
	{
		if		(_len == 1)
		{
			_read(fp,bufC.h1,1);
			rb = *bufC.h1;
		}
		else if	(_len == 2)
		{
			_read(fp,bufC.h2,2);
			rb = *bufC.h2;
		}
		else if	(_len == 4)
		{
			_read(fp,bufC.h4,4);
			rb = *bufC.h4;
		}
		else
		{
			_read(fp,bufC.hx,_len);
			rc = bufC.hx;
		}
	}
//--ÇÀÏÈÑÛÂÀÅÒ Â ÔÀÉËÀ --------------------
	void write(void* buffer, unsigned int _bufferl)
	{
		if((_write(fp, buffer, _bufferl))==-1){
			exist = false;
		}else
			exist = true;
	}
//--ÇÀÊĞÛÂÀÅÒ ÔÀÉË ------------------------
	void close()
	{
		_close(fp);
		exist = false;
	}
//--ÏÎÇÈÖÈß Â ÔÀÉËÅ -----------------------
	unsigned long tell()
	{
		return _tell(fp);
	}
//--ÓÑÒÀÍÎÂÈÒÜ ÊÓĞÑÎĞ Â ÔÀÉËÅ -------------
	void seek(long _pos,int _type=0)	//_type =	0  - îòñ÷åò ñ íà÷àëà ôàéëà
	{									//			1  - îò êóğñîğà
		_lseek(fp,_pos,_type);			//			2  - ñ êîíöà ôàéëà
	}
//-ĞÀÇÌÅĞ ÔÀÉËÀ ---------------------------
	unsigned long filesize()
	{
		return _lseek(fp,0L,SEEK_END);
	}
private:
	int fp;
	union 
	{
		unsigned char h1[1];
		unsigned short h2[1];
		unsigned long h4[1];
		char hx[128];
	}bufC;
};
